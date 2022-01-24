# Cleancode - Function

## 함수의 역할은 하나만 할 수 있도록 하자
* 함수의 역할이 많아진다면, 오류가 날 가능성이 커지고 가독성이 떨어짐. 또한 함수에 대한 테스트를 진행하기 어려움

```python
#as-is
def create_user(email, password):
    # validation 로직
    if "@" not in email or len(password) < 6 :
        raise Exception("유저 정보를 제대로 입력하세요")

    user = {"email": email, "password": password}

    database = Database("mysql")
    database.add(user)

    email_client = EmailClient()
    email_client.set_config(...)
    email_client.send(email, "회원가입을 축하합니다.")

    return True

```

```python
#to-be
def create_user(email, password):
    validate_create_user(email, password)

    user = build_user(email, password)

    save_user(user)
    send_email(email)

    return    
```

<br/>

## 반복하지 말자
* DRY(Don't Repeat Yourself), 관심사를 잘 분리하고 반복되는 코드를 하나의 함수로 만들어 사용

```python
#as-is
def create_user(email, password):
    if "@" not in email or len(password) < 6: 
        raise Exception("유저 정보를 제대로 입력하세요")

def update_user(email, password):
    if "@" not in email or len(password) < 6:
        raise Exception("유저 정보를 제대로 입력하세요")
```

```python
#to-be
**def validate_create_user(email, password):
    if "@" not in email or len(password) < 6 :
        raise Exception("유저 정보를 제대로 입력하세요.")**

def create_user(email, password):
    validate_create_user(email, password)

def update_user(email, password):
    validate_create_user(email, password)
```

<br/>

## 파라미터 수는 적게 유지하자
```python
#as-is
def save_user(user_name, email, password, created_at):
    ...

#to-be
def save_user(user:User):
    ...
```

<br/>

## 사이드 이펙트를 잘 핸들링하자
* 사이드 이펙트(side effect)는 함수가 실핼됐을 때 함수 이외의 어떤 것들에 변화를 주는 것을 뜻함
* 사이드 이펙트를 잘 다루지 못하면, 예측하지 못하는 문제들이 발생할 수 있음

```python
#사이드 이펙트가 없음
def get_user_instance(email, password):
    user = User(email, password)
    return user

#사이드 이펙트가 있음
def update_user_instance(user):
    user.email = "new email"
    return user

#사이트 이펙트가 있음
def create_user(email, password):
    user = User(email, password)
    start_db_session()
```
* 잘 핸들링 하는 방법
1. 코드를 통해 충분히 예측할 수 있도록 네이밍을 잘하는 것이 중요
* update, set 같은 직관적인 prefix를 붙여서 사이드 이펙트가 있을 수 있음을 암시
2. 함수의 사이드 이펙트가 있는 부분과 없는 부분으로 잘 나눠서 관리
* 명령(side effect O)과 조회(side effect X)를 분리하는 `CQRS` 방식이 있음
3. 일반적으로 update를 남발하기 보다 순수 함수 형태로 사용하는 것이 더 직관적이고 에러를 방지할 수 있음(`함수형 프로그래밍`)

```python
#as-is

carts = []

#사이드 이펙트를 발생시킴
def add_cart(product):
    carts.append(product)

product = Product(...)
add_cart(product)
```

```python
#to-be
carts = []

def get_added_cart(product):
    return [...carts, product]

product = Product(...)
carts = get_added_cart(product)
```