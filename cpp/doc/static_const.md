# Static-Const

* C++에서의 static은 세 가지 다른 용도로 사용됨

<br/>

## 1. 클래스 내의 static 멤버, 함수
* static 멤버 변수와 함수는 객체별로 따로 존재하지 않음
* 클래스 수준에서 모든 객체에 공통으로 속하는 단 하나만을 가짐
* 따라서, 객체를 만들지 않고 사용 가능하며, 마치 클래스 이름으로 한 번 감싸놓은 전역변수 및 함수와 같음
* static 멤버 함수는 해당 클래스와 유사한 작업을 하지만 딱히 객체와는 연관없는 일을 처리할 때 유용함

> static 멤버 변수는 사용하기가 조금 까다롭다. (선언하는 것은 어렵지 않으나 정의하는 작업이 필요)

* `static 멤버 변수의 정의는 한 개의 소스코드(.cpp)에서만 이루어져야 함`
* 만약 클래스를 header에서 만든 뒤, static 멤버 변수도 header 파일에서 정의하면, 해당 header 파일을 두 군데 이상의 cpp에서 include 할 경우, 컴파일 시 '중복되는 심볼 에러(duplicated symbol error)가 발생'
* 이러한 현상은 static 링킹과 관련이 있음

<br/>

## 2. static 링킹
* C++ 프로그램을 컴파일하면 **C++ 소스파일 별로 독립적인 오브젝트 파일이 생성되고 이 오브젝트 파일들을 하나로 연결(Linking)하여 실행하일을 만든다.**
* 이때 함수나 변수 이름을 기준으로 함수 호출, 변수 참조 등을 연결하는데, 같은 소스파일 안에서 연결되는 것을 `내부 링킹`이라고 하고 외부 소스파일과 연결하는 것을 `외부 링킹`이라고 함.
* 일반적인 함수나 전역 변수는 외부 링킹이 적용되지만 명시적으로 static을 적용해 내부 링킹으로도 만들 수 있다.

* 다음과 같이 main.cpp와 some_lib.cpp가 있을 경우,

``` c++
//main.cpp
#include <iostream>

void foo(){
    std::cout << "main.cpp's foo()" << std::endl;
}

int main(){
    foo();

    return 0;
}
```

``` c++
//some_lib.cpp
#include <iostream>

void foo(){
    std::cout << "some_lib's foo()" << std::endl;
}
```

* C++ 프로그램은 main() 함수부터 시작하므로 프로그램은 foo()를 호출
* 하지만 foo라는 이름의 함수가 두 가지가 존재하므로 `링크 에러가 발생`함
* 이를 해결하기 위해 main.cpp의 foo()함수를 static으로 바꾼다면 컴파일러 입장에서는 main() 함수에서 호출된 foo()는 내부링킹을 할 수 있음(에러 발생 X)
* 그렇게 되면 main.cpp의 foo()는 main.cpp에서만 쓰이는 함수로 간주

> static 함수는 header-only 라이브러리를 설계할 때 많이 사용됨

* C++에서도 내부 링킹을 위해 static을 붙이는 것을 대체하기 위한 방법으로 무명 네임스페이스 도입(anonymous namespaces)

<br/>

## 3. 함수 내 static 변수
* static의 마지막 사용 예는 static 로컬 변수이다.
* 한번 초기화되고 변하지 않고 다른 함수와는 연관이 전혀 없으며, 단지 이 함수를 위해 존재하는 값을 static으로 만들어 캐시해둘 수 있음

> Singleton 패턴을 구현할 때도 사용됨

``` c++
class Singleton{

public: 
    static Singleton& get_instance()
    {
        static Singleton instance;
        return instance;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
private:
    Singleton() = default;
} 
```

* C++11 부터 static 변수는 초기화 시, thread-safety를 보장하기 때문에 위와 같이 쓰이곤 한다.

* 모든 전역 변수, static 클래스 멤버 변수는 main() 함수가 실행되기 전에 초기화 되며, 한 소스파일 안에 선언된 변수들은 선언 순서대로 초기화됨

* 반대로 여러 개의 소스파일에 나뉘어 선언된 전역 변수라면 초기화 순서가 보장되지 않음.
    * 때문에 가능하면 이런 변수들이 서로 간 초기화 순서에 의존하고 있는 로직을 작성하지 말고, 무슨 짓을 해도 이를 피할 수 없다면 하나의 소스 파일에 전역 변수를 몰아넣어 순서를 맞추는 방법도 생각할 수 있음

## Reference
* https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=njh0602&logNo=221484123841