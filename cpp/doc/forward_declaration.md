# C++ - forward declaration

* 전방선언이란 h에서 사용하려는 클래스를 먼저 선언하고 cpp에서 사용하려는 객체의 h를 include 하는 방식

``` c++
// header
class UtilClass;

class Core{

private UtilClass* util;
}
```

``` c++
#include UtilClass.h

init{
	util = new UtilClass;
}
```

* 전방선언을 사용하면 h에는 객체의 포인터만을 사용해야 함(프로그램 실행 구조에 의해)
* 모든 포인터는 4byte의 메모리를 필요로 하므로 우선 메모리만 확보해 두면 runtime에 생성되는 개체의 주소 값을 저장할 수 있음
* 포인터가 아닌 객체의 인스턴스가 사용된다면 컴파일러는 클래스의 구조를 알아야 하므로 include된 header 파일이 필요하게 됨
* 전방선언을 사용해서 얻게 되는 이점은 `컴파일 시간이 단축된다는 장점이 있음`
* 전방선언이 아니라 h를 include했을 경우, UtilClass가 수정될 때마다 컴파일러는 h를 다시 분석하고, 만약 UtilClass가 다른 h를 포함하고 Core 클래스가 다른 곳에서 사용되면 의존성이 증가되어 컴파일 시간이 증가됨

* 전방선언은 A객체가 B를 사용하고 B객체가 A를 사용하는 상호참조에서도 유용하게 사용됨
* API 개발 등에서 불필요한 h를 포함하지 않을 수 있다는 장점이 있음
* 단, 인라인 함수는 사용할 수 없음
