# SOLID - Liskov Substitution

## 1. 개념
`Liskov Substitution Principle(리스코브 치환 원칙)`은 부모 객체의 역할은 자식 객체도 할 수 있어야 된다는 원칙

B 객체가 A 객체의 자식이라면 B객체의 타입을 A로 바꾸더라도 작동에 문제가 없어야 한다. 상위 타입에서 정한 명세를 하위 타입에서도 그대로 지킬 수 있을 때 상속을 해야 함

일반적으로 Liskov Substitution Principle이 지켜지지 않으면 Open Closed Principle을 위반하게 됨

상속을 할때는 항상 부모 객체와 자식 객체가 상속을 해야하는 구조인지 확인해봐야 함(`자식 객체가 부모 객체의 역할을 위임받을 수 있는지 확인해봐야 함`)

## 위반 사례
```python
class Employee(metaclass=abc.ABCMeta):
    @abc.abstractionmethod
    def work(self):
        ...


class Developer(Employee):
    def work(self):
        print("coding")
        return ["if..", "for..."]

class FrontEndDeveloper(Developer):
    def work(self):
        print("frontend")
        # 결과를 반환하지 않음

if __name__ == "__main__":
    def make_code(developer: Developer):
        code = developer.work()
        print(f"총 {len(code)}줄의 코드를 작성")

    make_code(Developer())
    make_code(FrontEndDeveloper())
```

> 속성이 일치하지 않음에도 상속을 할 경우, 결합도가 증가하고 오류가 발생할 확률이 높아짐(code smell)<br/>
상속(Inheritance)보다는 구성(Composition)

## 위반 사레2
```python
# 유명한 Rectangle, Square 문제
class Rectangle:
    def get_width(self):
        return self.width

    def get_height(self):
        return self.height

    def set_width(self):
        self.width = width 

    def set_height(self):
        self.height = height

class Square(Rectangle):
    def set_width(self, width):
        self.width = width
        self.height = width

    def set_height(self, heihgt):
        self.width = height
        self.height = height

if __name__ == "__main__":
    square = Square()
    square.set_width(20)
    square.set_height(30)
    check = square.get_width() == 20 && square.get_height() == 30 #부모의 명세와 다름
```

> 자식 is 부모 관계가 성립될 때, 상속을 많이 하는데, 위의 경우는 LSV를 지키지 못한 경우임<br/>
상속을 안받거나 더 추상화된 추상클래스를 상속받는 등의 방법을 고려할 수 있음

> 어떤 함수가 기반 클래스 A의 레퍼런스를 요구하는데, A의 파생 클래스 B가 함수에 넘겨져서 잘못된 동작을 하게 된다면, 파생클래스 B는 LSV를 위반한 것
