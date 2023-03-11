#include <iostream>
#include <string>

//抽象产品类
class Calculator {
    public:
    virtual ~Calculator() {}
    virtual int calculate(int a, int b) const = 0;
};

//具体产品类
class AddCalculator : public Calculator {
    public:
    int calculate(int a, int b) const override {
        return a + b;
    }
};

class SubCalculator : public Calculator {
    public:
    int calculate(int a, int b) const override {
        return a - b;
    }
};

class MultiCalculator : public Calculator {
    public:
    int calculate(int a, int b) const override {
        return a * b;
    }
};

class DivideCalculator : public Calculator {
    public:
    int calculate(int a, int b) const override {
        if(b == 0) {
            throw std::invalid_argument("cannot divide by zero");
        }
        return a / b;
    }
};

//工厂类
class CalculatorFactory {
    public:
    virtual ~CalculatorFactory() {}
    virtual Calculator* createCalculator() = 0;
};

//具体工厂类
class AddCalculatorFactory : public CalculatorFactory {
    public:
    Calculator* createCalculator() override {
        return new AddCalculator();
    }
};

class SubCalculatorFactory : public CalculatorFactory {
    public:
    Calculator* createCalculator() override {
        return new SubCalculator();
    }
};

class MultiCalculatorFactory : public CalculatorFactory {
    public:
    Calculator* createCalculator() override {
        return new MultiCalculator();
    }
};

class DivideCalculatorFactory : public CalculatorFactory {
    public:
    Calculator* createCalculator() override {
        return new DivideCalculator();
    }
};

int main() {
 //使用工厂模式创建计算器对象

 CalculatorFactory* factoryDiv = new DivideCalculatorFactory();
 Calculator* calculatorDiv = factoryDiv->createCalculator();
 std::cout << "result = " << calculatorDiv->calculate(5,1) << std::endl;


 delete calculatorDiv;
 delete factoryDiv;
 
 return 0;
}
