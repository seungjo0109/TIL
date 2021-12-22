# Clean Code - Naming


## 1. Convention

네이밍 convention으로 아래의 4가지 케이스로 분류될 수 있음
* snake_case: Python, Ruby 등에서 권장
* camelCase: Java, Javascript 등에서 권장
* PascalCase: 대부분의 프로그래밍 언어에서 클래스를 네이밍할 때 사용
* kebab-case: HTML Element를 표현할 때 사용

<br/>

## 2. 변수와 상수
일반적으로 변수와 상수를 네이밍할 때, `명사` 혹은 `형용사` 구문 형태로 지음

~~~c++
int user_data = ...; // 명사
bool is_valid = ...; // 형용사
~~~

## 3. 함수와 메서드
일반적으로 함수와 메서드를 네이밍할 때, `동사` 혹은 `형용사` 구문 형태로 지음
~~~c++
int send_data(){
    ...
}

bool input_is_valid(){
    ...
}
~~~

## 4. 클래스
일반적으로 클래스 이름을 네이밍할 때, `명사` 구문 형태로 지음
~~~c++
class Client{
    ...
};
~~~

## 5. Tips
1 . 구체적이고 명시적으로 적을 것(암시적인 네이밍은 회피)
~~~c++
//as-is
string dt = "20210101KST";

//to-be
string datetime = "20210101KST";
~~~
<br/>

2 . 불필요한 표현은 제거할 것
~~~ c++
//as-is
string the_message = " ... ";
string name_string = "name";

//to-be
string message = " ... ";
string name = "name";
~~~
<br/>

> **TIP** <br/>
길다고 나쁜 네이밍이 아니고, 애매한 표현보다 `직관적인 표현이 낫다.`
<br/>대충 읽어봐도 `이해할 수 있는 코드가 좋은 코드이다.`
<br/>암기가 필요한 코드는 좋은 코드가 아니다.






