# SOLID - Dependecy Inversion

## 1. 개념
`Dependency Inversion Principle(의존성 역전 원칙)`은 의존성을 항상 고수준으로 향하게 하여 예측할 수 있는 의존성의 변화를 줄이자는 원칙

일반적으로 의존성을 가지는 대상이 변경되면 의존하는 주체도 함께 변경됨. 만약 자주 바뀌는 구현체(저수준)를 의존하게 된다면 코드의 변경이 잦을 것이며, 버그와 사이드 이펙트가 발생할 확률이 높아짐. 이때 코드가 덜 바뀌는 인터페이스나 추상 클래스(고수준)를 의존한다면 상대적으로 안정적인 코드를 작성할 수 있음

<br/>

> TIP <br/>
고수준은 상위 수준 + 추상화되어 있는 개념. 일반적으로 잘 변하지 않는 특성을 가짐. 코드 개념에서 고수준은 인터페이스, 추상클래스 등을 예로 들 수 있음
<br/><br/>
저수준은 추상화된 개념을 구체적으로 구현하는 개념. 인터페이스, 추상클래스를 구현하는 구현체(클래스)나 함수 등 실제 동작에 관여하는 코드라고 생각하면 됨

<br/>

## AS-IS
```python
class App():
    def __init__(self)::
        self.inmemory_db = InMemoryDatabase() # 구현체에 의존하고 있음

def save_user(self, data):
    self.inmemory_db.store(data)

if __name__ == "__main__":
    app = App()
    app.save_user({"id":1, "name":"grab"})
```

<br/>

만약 App에서 다른 데이터베이스를 사용하고 싶다면, 코드를 직접 변경해야 함. 또한 App을 테스트하는 코드를 작성할 때도 의존성이 강하게 결합되어 테스트가 쉽지 않음

<br/>

## TO-BE(의존성 주입과 함께)

<br/>

일반적으로 의존성 역전을 하면서 의존성 주입을 함께 사용

의존성 주입을 사용하게 되면 객체의 생성을 외부에 맡기게 됨. 그러면 해당 클래스는 외부 의존성에 조금 더 자유로울 수 있게 되며 테스트를 작성할 때도 용이

<br/>

```python
class App()
    def __init__(self, database: Database): #고수준에 의존
        self.database = database

    def save_user(self, data):
        self.database.store_data(data)

if __name__ == "__main__":
    inmemory_db = InMemoryDatabase()
    app = App(inmemory_db)
    app.save_user({"id"=1, "name":"grab"})
```

<br/>

> TIP
의존성 주입을 해주기 위해선 결국 이를 사용하는 클라이언트에서 의존성들을 일일이 넣어줘야 함. 만약 잘못 코드를 작성하면 의존성 관계가 복잡해질 수 있음<br/>
그래서 보통 의존성 주입을 별도로 관리해주는 라이브러리나 프레임워크를 사용