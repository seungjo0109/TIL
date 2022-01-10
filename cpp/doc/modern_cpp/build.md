# C++ - Build

## 1. Build Process
* Preprocessor가 `#include, #define 등을 통해 선언된 곳으로 가져와서 translation unit`을 만든다
* Compiler가 `translation unit을 object 파일`로 만든다.
    * machine 코드 형태로 작성되어 있고, global 변수 등이 data 형식으로 들어가 있음 
* `Linker가 object 파일을 연결해서 실행가능한 파일`로 만든다.
    * 실행가능한 파일은 code, data, 실행을 위한 정보들을 포함하여 생성되고, executable 파일이 실행되면 프로세스가 생성된다.

* Build process를 진행해주는 프로그램을 컴파일러라고 함
    * 컴파일러 종류 중, gcc, clang, visual c++ 등이 있음

* g++을 사용한 빌드
    * ex) g++ main.cpp
    * 출력 이름 설정 -> g++ main.cpp -o <출력 이름>
    * `실행과정 중 발생할 수 있는 에러를 컴파일 시간에 warning하기 위한 옵션 -> -Wall`
    * `Warning이 될 경우, 컴파일이 되지 않도록 하는 옵션 -> -Werror`
    * c++17 사용법 -> -std=c++17
    * 디버그 정보를 같이 넣고자 할 경우, -g
    * 컴파일 과정을 자세히 확인하고자 할 경우, -v
    * `Optimization 옵션 -O` < level > -> 5단계가 있음( ex) -O0(사용안함) -O1 , -O2 ..)
        * 자세한 내용은 gcc optimization 검색 
    * 바이너리의 타겟 설정: -march
        * compilation에 의존하는 것보다 직접 profile을 찍는 것이 정확함
    * object 파일 생성: -c
    * 어셈블리 파일 생성: -S

* Clang은 특성상 cross compile을 잘 지원해줌

<br/>

## 2. Header의 의미
* 프로그래밍 시, declaration을 header 파일, definition을 cpp 파일에 넣어주는 것이 일반적임
* c++ 프로젝트의 build process는 cpp 파일 별로 object 파일을 생성함
* cpp 파일에서 필요한 내용이 있을 경우, header를 include 하고, preprocessor에서 translation unit을 생성함
* 각 cpp에서는 필요한 내용에 대한 header를 include를 하고 빌드를 진행하면 되기 때문에 독립적인 빌드가 가능함

<br/>

## 3. Preprocesser
* #include, #define, #ifdef, #pragma once 등 #이 포함되는 것은 preprocessor가 개입하는 것으로 보면 됨
* preprocess는 컴파일러에게 전달하기 전에 진행됨
* `modern c++에서는 #define을 최소화하는 것이 좋음`
    *  ex) #define MAX_UINT16 65535 대신 <limits>를 include하여 `std::numeric_limits<uint16_t>::max()를 사용하는 것이 좋음`
    * ex) MAX(a,b) (((a)>(b)?(a):(b))를 사용하는 것 대신 `std::max(a,b) 사용`
    * `#define ABCD=2 대신 constexpr int ABCD = 2 를 사용`

* \_\_FILE__, \_\_LINE__, \_\_DATE__, \_\_TIME__ 등의 옵션도 있음
    * DATE, TIME은 컴파일 시간을 알고자 할 경우, 유용함
    * 컴파일러마다 \_\_LINUX\_\_, \_\_APPLE\_\_ 등의 옵션도 있음

* `기본적으로 #include는 cpp 파일에 넣고, header 파일에서 정보가 필요할 경우에만 header 파일에 넣어줌`

* `#ifndef를 사용하는 것보다 #pragma once를 사용하는 것을 추천`

* `modern c++에서는 #define 대신 constexpr, #ifdef 대신 constexpr if 를 사용하는 것을 추천`

<br/>

## 4. Extern, Static
* extern과 static은 Linking 프로세스와 연관이 있는데, extern은 외부에서 링크를 찾아라, static은 안쪽으로만 링크를 열어라 라는 표현
* 자세한 내용을 알기 위해서 cppreference에서 linkage 메뉴를 확인해볼 것
* static 함수의 경우, object 내에서만 링크를 제공하기 때문에 바깥에서 호출할 경우, 컴파일 과정에서 오류가 발생할 수 밖에 없음
* `함수 혹은 변수가 하나의 object 파일 혹은 translation unit 바깥으로 링크를 주지 않는다는 확신이 있을 경우, static을 붙여줌으로써 더 안전한 빌드 프로세스를 가져갈 수 있음`
* 클래스 맴버 함수에서 사용되는 함수가 어떤 맴버내의 변수에도 접근하지 않을 경우, private으로 굳이 만들지 않고, `prefunction으로 만들어주고 static 키워드만 붙여주면 private 함수로 만들지 않아도 사용 가능`
    * `function이 object와 직접적인 관련이 없다고 생각될 경우, static을 붙여준 prefunction으로 만들어주는 것이 일반적으로 더 맞는 방법임`
* extern "C" 
    * `name mangling의 가장 근본적인 이유는 function overloading`
    * pure C에서는 function overloading이 없음 -> name mangling 기능을 사용하지 않음
    * `C 인터페이스를 가진 바이너리를 제공하기 위해서는 mangling 기능을 없애야 함`
    * extern "C"를 사용함으로써 mangling 기능을 없앨 수 있음

<br/>

## 5. Assembly Code
* Assembly Code 를 확인함으로써 컴파일러에서 C++를 어떻게 Optimization 하는지 아키텍처마다 machine code가 generation 되는지 확인할 수 있음
* Assembly Code를 쉽게 확인하는 방법 -> `compiler explorer 검색하여 사용`

<br/>

## 6. C++ 디버그
* g++ -g 옵션을 사용할 경우, debug info를 얻을 수 있음
    * 바이너리 코드를 cpp 코드와 연결하는 information을 같이 넣어줌
    * `변수에 어떤 값이 써있는지, break pointer를 통해 프로그램의 실행을 특정 시점에서 멈출 수 있고, 현재 Call stack을 back trace를 통해 알 수 있음`
    * GDB, vsCode 등을 사용 가능
* `vsCode의 start debugging을 통해 디버그 모드 진입` 가능

## 7. Library
* 이미 만들어진 코드, 바이너리를 가지고 와서 사용할 수 있는 collections
* header only, static library, dynamic library로 분류될 수 있음
    * header only 라이브러리의 경우, 코드의 모든게 library에 정의되어 있기 때문에 header를 include해서 사용하면 됨
    * Static 라이브러리의 경우, 윈도우에서는 .lib, 리눅스의 경우 .a로 나타남. -> `빌드프로세스에서 가져다 링크`를 시켜서 사용
    * Dynamic 라이브러리의 경우, `load time(프로그램이 실행될 때)` 혹은 `runtime`에 바인딩해서 사용하게 됨(윈도우 .dll, 리눅스 .so)

<br/>

* __Staic library__
    * 링커가 실행파일을 만들 때, 모든 오브젝트 파일이 하나의 실행파일로 들어가는 것이 아니고, code 및 data에 relocation, selection이 들어감
        * 실제로 사용되는 사용되는 code(function call)와 data 부분이 optimization rule에 따라 재배치를 하게 됨
    * `링커가 하나의 실행파일을 만들기 전에 오브젝트 파일을 모아서(archive) 하나의 파일로 만들게 됨(libxxxx.a) 이것이 static library` 
    * `링커가 static library에서 실제로 호출되는 code와 data를 relocation, selection해서 실행파일`을 만든다.
    * `g++ -c 를 사용해서 오브젝트 파일을 만들고 ar(linux 명령어) -rs를 사용해서 static library를 생성`
        * ex) ar -rs libtest.a test.o
    * static library를 가리키기 위해 g++ main.cpp -L.(.을 사용하지 않을 경우, usr/bin/ld에서 찾음) -ltest(test는 라이브러리 이름) 
