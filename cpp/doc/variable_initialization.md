# C++ - variable initialization

* 변수가 정의될 때, 즉시 해당 변수에 값을 지정할 수 있음. 이를 `변수 초기화(variable initialization)` 혹은 `초기화(initialization)`이라고 함

* C++은 변수를 초기화하는 세 가지 방법을 지원함

### 1. 대입 연산자(=)를 사용한 복사 초기화(copy initialization)
``` c++
int value = 5;
```

### 2. 괄호()를 사용한 직접 초기화(direct initialization)
``` c++
int value(5);
```

* 직접 초기화는 함수 호출과 유사하지만, 컴파일러는 어떤 이름이 변수이고 어떤 이름이 함수인지를 잘 추적하여 컴파일
* 직접 초기화는 일부 데이터 타입에서 복사 초기화보다 성능이 더 뛰어날 수 있음
* 클래스의 관점에서 볼 때, 초기화와 할당을 구분하는 데 도움이 됨.
* 따라서 복사 초기화보다 직접 초기화를 사용하는 것이 좋음

### 3. C++ 11의 유니폼 초기화(Uniform initialization in C++11)
* 중괄호({})를 사용한 `유니폼 초기화(uniform initialization)`
* 복사 초기화 및 직접 초기화는 일부 타입의 변수에 대해서만 작동
* 모든 데이터 타입에서 작동하는 단일 초기화 메커니즘을 제공하기 위해 C++ 11은 유니폼 초기화(uniform initialization)라는 새로운 형태의 초기화 메커니즘을 추가
* `brace initialization`이라고도 함.

``` c++
int value{5};
```

* 빈 {}로 변수를 초기화하면 기본 초기화(default initialization)가 된다.
* 기본 초기화는 변수를 0으로 초기화 한다.
``` c++
int value{};
```

* 유니폼 초기화는 형 변환을 허용하지 않는다는 이점이 있음. 변수를 다른 자료형의 값으로 초기화하려고 하면 컴파일러에서 경고 또는 오류가 발생
```c++
int value{4.5}; //error: an integer variable can not hole a non-integer value
```

## Reference
* https://boycoding.tistory.com/181
