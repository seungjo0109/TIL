# SOLID - Open Closed

## 1. 개념
`Open Closed Principle(개방 폐쇄 원칙)`은 객체의 확장에는 열려있고, 수정에는 닫혀있게 해야 한다는 원칙

**기존의 코드를 변경하지 않으면서 기능을 추가할 수 있도록 설계가 되어야 함.** OCP에서 중요한 부분은 요구사항이 변경되었을 때 코드의 변경되어야 할 부분과 그렇지 않아야 할 부분이 명확하게 구분되어 있어야 한다는 점

보통 이를 지키기 위해서 **인터페이스나 추상 클래스를 통해 추상화시키고 이를 상속, 구현하게 됨.** 새로운 기능을 추가한다고 할 때, 다형성을 사용해 기존 코드를 변경하지 않으면서(변경에 닫혀있음), 추상 클래스를 상속받아 쉽게 코드를 추가할 수 있음(확장에 열여있음)

<br/>

## AS-IS

```python
class Developer:
    def coding(self):
        print("coding")

class Designer:
    def design(self):
        print("design")

class Analyst:
    def analye(self):
        print("analyze")

class Company:
    def __init__(self, employees):
        self.employees = employees

    # employee가 다양할수록 코드를 계속 변경해야 함
    def make_work(self):
        for employee in self.employees:
            if type(employee) == Developer:
                employeee.coding()
            elif type(employee) == Designer:
                employee.desing()
            elif type(employee) == Analyst:
                employee.analyze()
```

<br/>

## TO-BE
```python
# 객체들의 역할을 아우르는 추상 클래스(고수준)을 생성
class Employee(metaclass=abc.ABCMeta):
    @abc.abstractionmethod
    def work(self):
        ...

class Developer(self):
    def work(self):
        print("coding")

class Designer(self):
    def work(self):
        print("design")

class Analyst(self):
    def work(self):
        print("analyze")

class Company:
    def __init__(self, employees: List[Employee]):
        self.employees = employees

    # employee가 늘어나더라도 변경에는 닫혀있음
    def make_work(self):
        for employee in self.employees:
            employee.work()
```