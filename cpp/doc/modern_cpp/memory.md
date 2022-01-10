* Memory

## 1. Variables & Memory

* 컴퓨터는 생성된 변수에 대해 변수명으로 인식하는 것이 아닌 매모리맵에서의 위치로 기억하고 찾음 

* UNIX 기반의 GCC 혹은 Clang 컴파일러는 메모리를 할당할 때, `Stack 메모리는 큰 주소부터 주소가 감소하는 방향으로 저장함`
    *  실제 메모리의 끝단에는 Environment에 대한 정보가 저장됨

<br/>

## 2. Variable

* 변수의 사이즈를 확인하는 방법은 sizeof() 함수를 사용하면 됨
    * ex) sizeof(int)
* 변수의 사이즈는 컴파일러 혹은 아키텍처에 따라 다를 수 있음
    * cppreference에서 확인해보면 int는 at least 16비트
    * 아키텍처에 따라 다른 현상을 해결하기 위해 compilation assertion을 사용하거나(`static_assert()`) fixed type(int32_t)를 사용하는 방법이 있음  

* 기타: C++에서 Array를 사용할 때, \<array>를 사용할 것을 권장 

* 포인터의 경우, `가르키는 변수의 타입에 관계없이 일정한 크기를 가짐(64bit 운영체제에서는 8바이트)`
* Struct는 내부의 변수에 따라 크기가 달라짐
    * Struct 내부 변수의 크기가 서로 다를 경우, 매모리 엑세스 패턴으로 인해 사이에 패딩을 넣어줌

* Class는 `struct와 유사하게 내부 변수에 따라 달라지고, 내부 함수와는 관계 없음`

<br/>

## 3. 스택 프레임
* 스택은 메모리를 쌓을 때, 스택 프레임 단위로 스택을 쌓음(스택프레임은 function call에 따라)
    * C에서는 function call을 할 경우, 함수에서 사용되는 변수를 포함해서 argument와 return address 까지 생성하여 스택 메모리를 할당
    * C++에서는 멤버 variable을 control하기 위해 멤버를 가리키기 위한 address(this)까지 포함됨

<br/>

## 4. 힙 메모리
* C++는 사용자가 메모리 관리를 수행해야 하는 unmanaged language
    * 사용자가 메모리 관리를 실패할 경우, Memory leak, Memory fragmentation이 발생할 수 있음

* Heap의 메모리를 관리하기 위해서 Stack메모리에 존재하는 포인터를 통해 Heap 메모리를 가리켜서 관리

* Heap 메모리를 사용하는 이유
    1. life cycle
        * Stack 메모리는 함수가 끝나면서 사라지게 되면서  life cycle 문제가 발생할 수 있음
    2. large size
        * stack 메모리를 사용하면서 큰 메모리를 할당하는 데 한계가 있음
    3. dynamic allocation
        * stack frame은 컴파일 시간에 결정되는데, 컴파일 시간에 알 수 없는 정보들이 있음
        * 프로그램 실행 과정에서 Heap을 사용하여 dynamic allocation이 가능함

<br/>

## 5. Heap 메모리 예제
``` C
// C style
#include <stdlib.h>

int main()
{
    //C style heap int
    int * ip = (int *)malloc(sizeof(int));
    *ip = 100;
    free(ip); // 해제하지 않을 경우, memory leak 발생

    //C style heap array
    int *iap = (int *)malloc(sizeof(int)*5);
    free(iap);    
}
```

``` C++
// C++ style
#include <iostream>
#include <vector>

class Cat
{
public:
    Cat(){
        std::cout << "Cat" << std::endl;
    };
    ~Cat(){};
private:
    int mAge;
};

int main()
{
    // C++에서는 malloc, calloc 사용하지 말 것

    // C++ Style
    Cat *catp = new Cat();
    delete catp;    // 해제하지 않을 경우, memory leak이 발생

    Cat* catap = new Cat[5];
    delete [] catap;

    /*
        Memory leak 방지를 위해 smart pointer를 사용하는 것이 좋음
        원천적으로 memory leak을 막을 수 있는 방법을 사용
    */
    // Safer C++ style
    std::unique_ptr<Cat> catsp = std::make_unique<Cat>;

    // array의 경우, vector를 사용
    std::vector<Cat> cata(5);
    std::vector<int> ints(5);
}
```

<br/>

## 6. 메모리 Leak
* C++ 프로그램을 작성할 때, Memory leak이 발생하지 않도록 작성하는 것이 중요
    * Safer C++ style로 코드를 작성하여 Heap 메모리 관리
    * `리눅스에서 Valgrind Tool`을 사용할 수 있음
    * 컴파일 모드에서 -g 옵션을 주어 디버그 모드로 컴파일을 진행하고 valgrind의 --leak-check=full 을 사용하여 메모리 leak 체크 가능
    * Visual Studio를 사용해서도 Memory leak 체크 가능

* 프로세스 메모리 
    * Stack 메모리는 높은 주소부터 빽빽하게 저장하고 Heap은 아래쪽 주소에서 드문드문(Memory allocator가 결정) 저장

<br/>

## 7. 힙 메모리 사용 이유
* Stack vs Heap
    * Stack은 Stack frame 단위로 allocation & disallcoation이 되고 할당/해제 속도가 빠름
    * Heap은 메모리 할당을 위해 할당 위치를 찾아야 하고 할당 크기를 결정해야 함(프로그램 실행 과정 중에 일어남)
    * `멀티스레드 프로그램의 경우, 스레드가 Heap 메모리에 대한 접근 권한을 얻게 되는데 race condition을 없애기 위해 복잡하게 할당/해제`가 수행됨(속도가 느림)
    * Heap은 dynamic allocation이 가능함
    * Stack은 컴파일 시간에 결정해줘야 함
    * Stack은 큰 object를 할당할 경우, stack overflow가 발생함
        * 따라서, Large size는 Heap에 할당해주는 것이 좋음

<br/>

> 몇백 KB, 몇 MB 부터는 Stack보다는 Heap을 사용하는 것이 좋음<br/>
    ex) 작은 배열의 경우, std::array,<br/> 큰 배열의 경우, std::vector

<br/>
* C++에서는 `총 용량이 몇 kb 미만인 object인 경우, stack을 사용하는 것이 맞음`
    * `많은 수의 object를 생성하는 경우, vector를 사용해서 Heap에 할당`해주는 것이 맞음

* Computation Critical한 프로그램일 경우, 미리 함수 내에서 array로 여유롭게 할당하는 것이 vector로 할당하는 것보다 좋을 수 있음

* Static, Global의 경우, Heap보다 더 아래에 위치하고 있고, 프로그램 실행과 동시에 가지고 있음