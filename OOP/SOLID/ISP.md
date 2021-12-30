# SOLID - Interface Segregation

## 1. 개념
`Interface Segregation Principle(인터페이스 분리 원칙)`은 클라이언트가 자신이 이용하지 않는 매서드는 의존하지 않아야 한다는 원칙

SOLID의 1원칙인 Single Responsibility Principle은 객체가 하나의 책임만을 가져야 한다는 원칙인데, 여기서는 인터페이스(혹은 추상 클래스)가 하나의 책임만을 가져야 한다고 보면 됨

인터페이스를 책임에 맞게 잘 쪼개둔다면, 클라이언트 입장에서는 필요한 역할만 구현(혹은 상속)하여 사용할 수 있음

## AS-IS
```python
fome abc import *

class Smartphone(metaclass=ABCMeta)
    @abstractionmethod
    def call(self):
        ...

    @abstractionmethod
    def send_massage(self):
        ...

    @abstractionmethod
    def see_youtube(self):
        ...

    @abstractionmethod
    def take_picture(self):
        ...

#카메라가 없는 클래스에서 take_picture는 불필요한 매서드가 됨
class PhoeWithNoCamera(Smartphone):
    ...
```

## TO-BE
```python
class Telephone(metaclass=ABCMeta):
    @abstractionmethod
    def call(self):
        ...

    @abstractionmethod
    def send_message(self):
        ...

class Camera(metaclass=ABCMeta):
    @abstractionmethod
    def take_picture(self):
        ...

class Application(metaclass=ABCMeta):
    @abstractionmethod
    def see_youtube(self):
        ...

class PhoneWithNoCamera(Telephone, Application):
    ...
```

> Interface segregation은 결국 인터페이스의 단일 책임 원칙이라고 생각하면 될듯