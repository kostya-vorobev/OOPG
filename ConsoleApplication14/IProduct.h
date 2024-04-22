#pragma once
#include <iostream>
using namespace std;

class IProduct
{
public:
    virtual string getName() = 0;
    virtual double getPrice() = 0;
};

class Cookie : public IProduct {
private:
    string name;
    double price;
public:
    Cookie(string name, double price) : name(name), price(price) {}
    string getName() override { return name; }
    double getPrice() override { return price; }
};
