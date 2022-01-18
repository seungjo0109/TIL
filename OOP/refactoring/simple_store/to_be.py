# 1번. 다른 Store가 들어오면 어떻게 될까?
# 개선점
# 1. Store를 추상화한다.
# 2. 의존성 주입을 한다.

# 2번. Store의 상품과 돈에 대해 마음대로 접근 가능
# 개선점
# 1. Store의 책임을 정의하고 캡슐화
# 2. User의 결재 로직을 수정
# 3. User 캡슐화

# 3번. User가 많은 행위를 책임지고 있음. Store가 판매하는 책임을 가져야 하지 않을까?
# 개선점
# 1. 상점에서 상품을 판매하는 행위를 추상화하고 구체적인 로직을 해당 메서드로 옮긴다.

# 4번. product가 책임을 가져야하지 않을까?
# 개선점
# 1. 딕셔너리 타입을 클래스(데이터클래스) 객체로 변환하자.

@dataclass
class Product:
    name: str
    price: int

# Product(name=name, price=price)
# Product.name

# Abstraction class
from abc import ABC

class Store(ABC):
    @abstractmethod
    def __init__(self):
        self._money = 0
        self.name = ""
        self._product = {}

    # encapsulation
    @abstractmethod
    def show_product(self, product_id):
        pass

    # as-is
    # @abstractmethod
    # def give_product(self, product_id):
    #     pass

    # @abstractmethod
    # def take_money(self, money):
    #     pass

    # to-be
    @abstractmethod
    def sell_product(self, product_id, money):
        pass

class ITStore(Store):
    def __init__(self, products):
        self.money = 0
        self.name = "ITStore"
        self.products = products
    
    def set_money(self, money : int):
        self._money = money

    def set_products(self, products)
        self._products = products

    # encapsulation
    def show_product(self, product_id):
        return self._products[product_id]

    def sell_product(self, product_id, money):
        # 참고: validation 코드는 최소화 하는 방향으로 작성됨(simple example)
        product = self.show_product(product_id=product_id)
        if not product:
            raise Exception("상품이 존재하지 않음")

        self._take_money(money=money)
        try:
            _product = self._take_out_product(product_id = product_id)
            return _product
        except Exception as e:
            self._return_money(money)
            raise e

    def _take_out_product(self, product_id):
        return self._products.pop(product_id)

    def _take_money(self, money)
        self._money += money

    def _return_money(self, money):
        self._money -= money

class FruiteStore(Store):
    def __init__(self, products):
        self.money = 0
        self.name = "FruiteStore"
        self.products = products
    
    def set_money(self, money):
        self._money = money

    def set_products(self, products)
        self._products = products

    # encapsulation
    def show_product(self, product_id):
        return self._products[product_id]

    def sell_product(self, product_id, money):
        # 참고: validation 코드는 최소화 하는 방향으로 작성됨(simple example)
        product = self.show_product(product_id=product_id)
        if not product:
            raise Exception("상품이 존재하지 않음")

        self._take_money(money=money)
        try:
            _product = self._take_out_product(product_id = product_id)
            return _product
        except Exception as e:
            self._return_money(money)
            raise e

    def _take_out_product(self, product_id):
        return self._products.pop(product_id)

    def _take_money(self, money)
        self._money += money

    def _return_money(self, money):
        self._money -= money

class User:
    def __init__(self, money, store : Store)):
        self._money = money
        # self.store = ITStore()    # 의존성 주입으로 대체  
        self.store = store
        self.belongs = []

    def get_money(self):
        return _money

    def get_belongs(self):
        return belongs

    def get_store(self):
        return store

    def see_product(self, product_id):
        # products = self.store.get_products                        # as-is
        product = self.store.show_product(product_id=product_id)    # to-be
        return products[product_id]

    def purchase_product(self, product_id):
        # product_id = self.see_product(product_id)                 # as-is
        product_id = self.see_product(product_id = product_id)      # to-be : keyword parameter
        price = product.price
        
        if self._check_money_enough(price=price):
            # self.store.products.pop(product_id)
            self._give_money(money=price)
            # self.store.money += product["price"]                  # as-is 
            try:    
                my_product = self.store.sell_product(product_id=product_id.money=price)
                self._add_belong(my_product)
                return my_product
            except Exception as e:
                self._take_money(money=price)
                print(f"구매중 문제가 발생했습니다. {str(e)}")
            
        else:
            raise Exception("잔돈이 부족합니다")

    def _check_money_enough(self, price):
        return self._money >= price

    def _give_money(self, money):
        return self._money -= money

    def _take_money(self, money):
        self._money += money

    def _add_belong(self, product):
        self.belongs.append(product)

if __name__=="__main__":

    store = ITStore(
        products={
            1: Product(name="키보드", price=30000),
            2: Product(name="모니터", price=50000),
        }
    )

    user = User(money=100000, store=store)
    uset.purchase_product(product_id=1)