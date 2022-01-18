class Store:
    def __init__(self):
        self.money = 0
        self.name = "Market"
        self.products = {
            1: {"name": "keyboard", "price": 30000},
            2: {"name": "Monitor", "price": 50000},
        }
    
    def set_money(self, money):
        self.money = money

    def set_products(self, products)
        self.products = products

    def get_money(self):
        return self.money

    def get_products(self):
        return self.products

class User:
    def __init__(self):
        self.money = 0
        self.store = Store()
        self.belongs = []

    def set_money(self, money):
        self.money = money

    def set_belongs(self, belongs):
        self.belongs = belongs

    def get_money(self):
        return money

    def get_belongs(self):
        return belongs

    def get_store(self):
        return store

    def see_product(self, product_id):
        products = self.sotre.get_products
        return products[product_id]

    def purchase_product(self, product_id):
        product_id = self.see_product(product_id)
        if self.money >- products["price"]:
            self.store.products.pop(product_id)
            self.money -= products["price"]
            self.store.money += product["price"]
            self.belongs.append(products)
            return product
        else:
            raise Exception("잔돈이 부족합니다")

if __name__=="__main__":
    user = User()
    user.set_money(100000)
    uset.purchase_product(product_id=1)