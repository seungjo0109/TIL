# Cleancode - Comment & Formatting
* 모든 내용을 주석으로 넣을 경우, 코드의 가독성이 떨어질 수 있음
* 대부분은 좋은 Naming으로 충분히 대체 가능

* Naming으로 표현할 수 없는 영역은 주석으로 표현해주면 됨

```python
# 1.법적인 정보를 담을 때
# Copyright (C) 2022 ...

# 2. 의도를 명확하게 설명할 때
# throughput을 늘리기 위해 스레드를 10개까지 늘린다.
for idx in range(10):
    thread = threading.Thread(target=...)
    thread.start()

# 3. 중요성을 표현할 때
# 최종 결제를 진행하기 전에 진행해야 하는 validation 함수
def validate_buyable(wallet, price, ...):
    ...

# 4. 결과를 경고할 때
# WARNING: API 서버가 항상 양호한지 알 수 없음
def connect_api_server():
    ...
```

<br/>

## 관용적으로 사용되는 키워드
`TODO` : 당장은 아니지만 다음에 해야할 때

`FIXME`: 치명적인 에러를 발생하는 코드는 아니지만 수정해야 할 때

`XXX` : 더 생각해볼 필요가 있을 때

```python
# TODO@grab: 객체의 책임 더 분리하기
class GrabStore:
    ...
    # FIXME: 반복문의 depth 줄이기
    def sell_food(self):
        for food in food_list:
            for discount in discount_list:
                ...
```

<br/>

## 포멧팅

### Vertical Formatting
* 한 파일에 코드를 다 넣지 말고, 개념에 맞게 파일을 나눠서 사용

* 다른 개념의 코드는 Spacing으로 분리

* 비슷한 개념의 코드는 붙여서 사용하기

```python
def test_user_buy_product():
    user = User()
    product = Product()

    product.set_solid_out(true):
    uset.get(product)

    assert result == "success"
```

<br/>

### Horizontal Formatting
* 한 줄에 코드를 다 넣기보다는 변수 등을 활용해서 가독성 높이기
* 네이밍 잘해서 길이 줄이기
```python
# as-is
user_with_name_and_email = User()

# to-be
user = User()
```

