# ABI & EABI

`응용 프로그램 이진 인터페이스(Application Binary Interface, ABI)` : 응용 프로그램과 운영 체제 또는 응용 프로그램과 해당 라이브러리, 마지막으로 응용 프로그램의 구성요소 간에서 사용되는 low-level의 인터페이스

* 바이너리 수준의 인터페이스 규약
* 서로 다른 컴파일러가 소스 코드를 컴파일하더라도 오브젝트 파일끼리 링킹이 될 수 있도록 함

<br/>

`임베디드 응용 프로그램 이진 인터페이스(Embedded-Application Binary Interface)`는 임베디드 소프트웨어 프로그램을 수행하는 파일 형식, 자료형, 레지스터 사용, 스택 프레임 조직, 명령 변수를 위한 표준 변환을 정의

* 임베디드 환경의 ABI
* 권한 명령이 응용 프로그램 코드 안에서 실행
* 동적 링크를 요구하지 않으며 허용되지 않을 수 있음(__Windows의 .dll, Linux의 .so와 같은 동적 라이브러리를 EABI에서는 사용할 수 없음__)
* 메모리 저장을 위해 더 작은 스택 프레임을 가짐

## none-eabi?
'none'의 의미는 특정 __벤더에 특화된 eabi가 아니다__ 라는 의미. 즉, 특정 툴 체인 회사 전용 바이너리를 생성하지 않는 다는 것
~~~
ex) arm-none-eabi-gcc
~~~
<br/>

## 툴 체인 명명 규칙
~~~
arch-vendor-(os-)abi
~~~
* arch: 타깃 아키텍처
* vendor: 툴 체인 공급사
* os: 타깃 운영체제
* abi: ABI 방식

위의 규칙에서 os는 생략 가능 

~~~
arm-none-linux-eabi
~~~
위는 ARM 아키텍처에 벤더가 없으며 리눅스 OS에 맞춘 EABI 방식으로 컴파일
~~~
x86_64-w64-mingw32
~~~
위는 x86_64(=AMD64) 아키텍처의 w64(mingw-w64)라는 벤더에 mingw32(win32 API as seen by GCC) 방식으로 컴파일 할 수 있는 툴 체인

</br>

## API와 차이점
* API는 `source code level에서 Programming 관점에서의 인터페이스`
* ABI는 `Binary level(컴파일된 상태)에서 인터페이스`
* 즉, ABI는 binary 결과물(주로 Object) 간의 연결에 중점을 둔 Binary Level에서의 호환성을 의미한다고 생각하면 됨


<br/>

## Reference
* https://ko.wikipedia.org/wiki/%EC%9D%91%EC%9A%A9_%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8_%EC%9D%B4%EC%A7%84_%EC%9D%B8%ED%84%B0%ED%8E%98%EC%9D%B4%EC%8A%A4
* https://stackoverflow.com/questions/5731495/can-anyone-explain-the-gcc-cross-compiler-naming-convention
* https://jakupsil.tistory.com/40
* https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=dong880510&logNo=140156760753