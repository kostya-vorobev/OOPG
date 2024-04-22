#pragma once
#include "IBeverage.h"

class BeverageFactory
{
public:
	virtual IBeverage* createBeverage() = 0;
};

class CoffeeFactory : public BeverageFactory {
public:
    IBeverage* createBeverage() override {
        return new Coffee("Espresso", 200.0);
    }
};

class TeaFactory : public BeverageFactory {
public:
    IBeverage* createBeverage() override {
        return new Tea("Green Tea", 150.0);
    }
};

