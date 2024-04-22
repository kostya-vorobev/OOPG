#pragma once
#include "IBeverage.h"
#include "IProduct.h"
class IFactory
{
public:
    virtual IProduct* CreateProduct1() = 0;
    virtual IBeverage* CreateProduct2() = 0;
};

class Combo1 : public IFactory {
public:
    IProduct* CreateProduct1() override {
        return new Cookie("Oat Cookies", 100.0);
    }
    IBeverage* CreateProduct2() override {
        return new Tea("Green Tea", 150.0);
    }
};

class Combo2 : public IFactory {
public:
    IProduct* CreateProduct1() override {
        return new Cookie("Chocolate Chip Cookies", 120.0);
    }
    IBeverage* CreateProduct2() override {
        return new Coffee("Espresso", 200);
    }
};


/*
class Combo {
public:
    IProduct* cookie;
    IBeverage* beverage;
    Combo(IProduct* cookie, IBeverage* beverage) : cookie(cookie), beverage(beverage) {}

    void getComboDetails() {
        cout << "Combo: " << cookie->getName() << " costs " << cookie->getPrice() << "\n";
        cout << "Combo: " << beverage->getName() << " costs " << beverage->getPrice() << "\n";
    }
};

class IComboFactory {
public:
    virtual Combo* createCombo() = 0;
};

class Combo1Factory : public IComboFactory {
public:
    Combo* createCombo() override {
        return new Combo(new Cookie("Oat Cookies", 100.0), new Tea("Green Tea", 150.0));
    }
};

class Combo2Factory : public IComboFactory {
public:
    Combo* createCombo() override {
        return new Combo(new Cookie("Chocolate Chip Cookies", 120.0), new Coffee("Espresso", 200));
    }
};

int main() {
    IComboFactory* factory = new Combo1Factory();
    Combo* combo1 = factory->createCombo();
    combo1->getComboDetails();

    delete factory;
    factory = new Combo2Factory();
    Combo* combo2 = factory->createCombo();
    combo2->getComboDetails();

    return 0;
}*/