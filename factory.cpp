#include <iostream>
#include <string>

// 基类
class Product {
public:
    virtual ~Product() { }
    virtual std::string getName() const = 0;
};

//具体产品类
class ConcreteProduct1 : public Product {
public:
    std::string  getName( ) const override {
       return "Concrete Product 1";
    } 
};

class ConcreteProduct2 : public Product {
public:
    std::string getName() const override {
        return "Concrete Product 2";
    }
};

//工厂类
class Factory {
public: 
     virtual ~Factory() {}
     virtual Product* createProduct() = 0;
};

//具体工厂类
class ConcreateFactory1 : public Factory {
    public:
    Product* createProduct() override {
        return new ConcreteProduct1();
    }
};

class ConcreateFactory2 : public Factory {
  public:
     Product* createProduct() override {
        return new ConcreteProduct2();
     }
};

int main()
{
    Factory* factory = new ConcreateFactory1();
    Product* product = factory->createProduct();
    std::cout << product->getName() << std::endl;
    Factory* factory2 = new ConcreateFactory2();
    Product* product2 = factory2->createProduct();
    std::cout << product2->getName() << std::endl;

    delete product;
    delete factory;
   delete product2;
    delete factory2;
     return 0;
}