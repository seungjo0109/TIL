# 스레드 풀의 적정 크기는? 적절한 사이즈는?

스레드 풀의 적절한 사이즈는 어느정도가 적절할까? 실제로 overhead는 사용하는 플랫폼에 따라 다를 것이다. 스레드 생성해는 시간이 소요되고 요청 처리에 따른 대기시간 도 발생될 것이다.

스레드 풀은 이전에 생성된 스레드를 재사용하여 사이클 오버헤드 및 자원 낭비를 막을 수 있음
(자원 낭비: problem of resource thrasing - thrasing은 CPU가 프로세스 수행 시간보다 페이징 교체에 더 많은 시간을 소모하는 것을 의미. 즉 page fault가 많은 상황에 발생)

잘 조정된 스레드 풀은 시스템의 최대치를 이끌어낼 수 있으며 최대 부하의 경우에도 올바르게 동작할 수 있음. 반면에 수치가 엉망인 스레드 풀을 사용할 경우, 스레드 풀이 있음에도 병목현상이 발생하거나 스레드 풀로 인해 프로그램이 죽을 수 있음.

<br/>

## 스레드 풀에 제한을 걸어야 하는 이유는?
<br/>

사전에 구성된 아래와 같은 스레드 풀이 있을 때, 사용할 것인가? 사용하지 않을 것인가?'
``` Java
/** Thread Pool constructor */
public ThreadPoolExecutor(int corePoolSize,
              int maximumPoolSize,
              long keepAliveTime,
              TimeUnit unit,
              BlockingQueue workQueue) {...}

/** Cached Thread Pool */
public static ExecutorService newCachedThreadPool() {
              return new ThreadPoolExecutor(0, Integer.MAX_VALUE,
                                                      60L, TimeUnit.SECONDS,
                                                      new SynchronousQueue());
}
```
SynchronousQueue가 보이는가? 이는 현재 존재하는 모든 스레드가 사용 중일 때, 새로운 작업이 발생하면 신규 스레드가 생성되는 것을 의미함. 만약 엄청나게 많은 작업이 발생할 경우, OOM(Out Of Memory)이 발생할 것임
결국 서버는 클라이언트가 'DDOS'처럼 들어오지 못하도록 해야 한다.

<br/>

## 스레드 풀의 한계를 알라
<br/>

스레드 풀의 사이즈를 조정하기 전에 현재 주어진 환경의 제약 사항을 확실히 이해해야 한다. 이는 하드웨어만을 의미하는 것이 아니다. 예를들어 Worker 스레드가 DB 의존적인 작업을 할 경우, 스레드 풀은 DB의 Connection Pool size에 영향을 받을 것이다. 100개의 동시접속이 가능한 DB에 크기가 1000인 스레드 풀이 있다고 하면, 효율적으로 동작할 수 있을까?

그리고 worker 스레드가 n개 까지의 동시 요청을 처리할 수 있는 외부 서비스를 호출할 때, 스레드 풀의 크기는 이 '외부 서비스'의 성능에 따라 좌우된다.

__이는 당연하지만 우리가 종종 잊는 것이다.__

물론, 스레드 풀에게 중요한 자원 중 하나는 CPU다. 우리는 CPU 전체 개수를 다음과 같이 구할 수 있다.

``` Java
//Java

int numOfCores = Runtime.getRuntime().availableProcessors();
```
``` C
//C

#include <stdio.h>
#include <sys/sysinfo.h>

printf("%d processors configured and %d processors available.\n",
        get_nprocs_conf(), get_nprocs());
```
``` python
#Python

import multiprocessing

multiprocessing.cpu_count()

```
이들은 우리가 이전부터 CPU의 개수를 구할 때 써온 방법이다. __하지만 Docker와 같은 컨테이너 환경에서 실행해야 하는 경우라면 이 명령어를 사용할 때 주의해야 한다.__
* 제약 조건을 지정하지 않고 containerized된 프로세스의 경우, host OS의 하드웨어를 볼 수 있음

> 관련 기사:<br/> https://mjg123.github.io/2018/01/10/Java-in-containers-jdk10.html <br/>https://jaxenter.com/nobody-puts-java-container-139373.html

메모리와 File handler, Socket Handler 역시 중요하게 고려되어야 한다.

## 절대 공식
Brian Goetz의 유명한 책인 "Java Concurrency in Practice"에서는 다음과 같은 공식이 등장함

> 스레드 수 = 사용 가능한 코어 수 * (1+대기시간/서비스 시간)<br/> (대기시간/서비스 시간)의 값은 block 계수라고도 한다.

여기서 대기 시간은 작업 하나가 오나료되기까지 소모되는 대기 시간, 즉 I/O waiting, 원격 서비스에 대한 HTTP response waiting 등을 의미한다. 그리고 서비스 시간은 작업이 실제로 동작 중인 시간, 즉 I/O waiting 이후 전달받은 데이터를 처리하는 과정을 의미하는데, 서비스 시간에는 대기 시간이 포함되지 않는다.

CPU를 많이 쓰는 계산 작업의 경우 대기를 거의 하지 않으므로 (대기시간/서비스 시간)의 값이 0에 수렴한다. 이 경우, 스레드의 수는 사용 가능한 코어의 수와 동일하다. 만약 모든 작업이 계산 작업이라면 이 정도면 충분하다. 그 이상의 스레드는 불필요하다.

예)
worker 스레드는 '요청에 대한 응답을 JSON으로 변환하고 몇 가지 규칙을 실행하는 'microservice'(이하 micro)'를 호출한다. micro의 응답 시간은 50ms, 서비스 시간은 5ms이며 worker 스레드를 실행시키는 프로그램은 듀얼 코어 cpu에서 동작한다고 가정하다.

이떄 적절한 스레드 풀 사이즈는 2*(1+50/5) = 22가 된다.

하지만 위의 예시는 너무 단순화되었다. 단순히 처리에만 중점을 두었기 때문에 HTTP 응답을 하는 서버의 Connection Pool, JMS(자바 메시지 서비스)로부터의 요청, JDBC Connection Pool과 같은 어플리케이션 외의 영역을 고려하지 않았다.

만약 여러 클래스에서 각각의 스레드풀, 즉 한 프로세스에서 여러 개의 스레드풀이 존재하는 경우, 각자의 워크로드에 따라 이 수치가 조정될 수 있다. 이 경우엔 CPU 목표 사용량을 추가하기만 하면 된다. 이때 CPU 목표 사용량은 0에서 1 사이 값이다.

> 스레드 수 = 사용가능한 코어 수 * CPU 목표 사용량 * (1+대기시간/서비스시간)

## 리틀의 법칙

이 장에서는 최적화된 스레드 풀의 사이즈를 구할 것이다. 우리는 이론적인 최대치와 측정할 수 있는 항목이 있다. 하지만 어떻게 병렬 worker의 수가 지연 시간과 처리량을 변경할 수 있을까?

리틀의 법칙은 이 질문에 대한 답이 될 수 있다. 이 법칙에서 시스템의 요청 수는 도착한 비율과 개별 요청을 처리하는 데 걸리는 평균 시간을 곱한 값과 같다. 이 공식을 사용하여 특정 대기 시간 수준에서 사전 정의된 처리량을 처리할 병렬 work의 스레드의 수를 계산할 수 있을 것이다.


L = lamda * W

L - 동시에 처리된 요청 수

lamda - 평균 도착 시간

W - 요청이 처리되기까지의 평균 시간

이 공식을 이용하면, 우리는 시스템의 용량을 계산할 수 있다. 또는 안정적인 응답 시간이 보장되는 1초당 발생하는 요청들을 다루기 위해 얼마의 인스턴스가 동시에 동작해야 하는지 계산할 수 있다.

우리의 예로 돌아가 보자. 우리는 평균 응답 시간이 55ms이며 스레드 풀의 크기가 22인 서비스를 갖고 있다.

이 서비스에 대해 리틀의 법칙을 적용하면

22 / 0.055 = 400 (우리 서비스가 안정적인 응답 시간으로 처리할 수 있는 1초당 요청의 수)의 결과를 얻을 수 있다.

## 결론
* 이 공식은 silver bullet이 아니며 마술처럼 어떤 프로젝트에도 적합하지 않지만 프로젝트의 훌륭한 출발점이 될 수 있음
* 공식의 단점은 시스템의 평균 요청 수에 초점을 맞추고 다양한 taffic burst pattern에 적합하지 않을 수도 있음
* 이 공식으로 계산된 값으로 시작한 다음 부하 테스트 후, 스레드 풀 속성을 조정할 수 있음


 
## Reference
* https://engineering.zalando.com/posts/2019/04/how-to-set-an-ideal-thread-pool-size.html?gh_src=4n3gxh1?gh_src=4n3gxh1
* https://yaaam.tistory.com/6