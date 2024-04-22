#pragma once
#include <iostream>
using namespace std;

class IBeverage
{
public:
    virtual string getName() = 0;
    virtual double getPrice() = 0;
};

class Coffee : public IBeverage {
private:
    string name;
    double price;
public:
    Coffee(string name, double price) : name(name), price(price) {}
    string getName() override { return name; }
    double getPrice() override { return price; }
    void brew() { cout << "Brewing coffee..." << "\n"; }
};

class Tea : public IBeverage {
private:
    string name;
    double price;
public:
    Tea(string name, double price) : name(name), price(price) {}
    string getName() override { return name; }
    double getPrice() override { return price; }
    void brew() { cout << "Brewing tea..." << "\n"; }
};
