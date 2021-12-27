# Single Responsibility Principle

## 1. 개념
`Single Responsibility Principle(단일 책임 원칙)`: 객체가 하나의 책임만을 지녀야 한다는 원칙

여러 책임을 동시에 가지는 객체는 코드가 복잡해질수록 에러가 발생할 확률이 높아지고 직관적으로 코드를 이해하기 어렵게 만든다. 따라서 객체를 설계하기 전, 책임을 확실하게 부여하는 것이 중요


## AS-IS
```python
#하나의 클래스(객체)가 여러 책임을 가지고 있음
class Employee:
    def coding(self):
        print("Coding")

    def design(self):
        print("Deisgn")

    def analyze(self):
        print("analyze")
```

## TO-BE
```python
#객체가 역할을 나눠서 가지고 있음
class Developer:
    def coding(self):
        print("Coding")

class Designer:
    def design(self):
        print("Design")

class Analyzer:
    def analyze(self):
        print("Analyze")
```