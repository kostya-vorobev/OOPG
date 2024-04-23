#pragma once
#include <string>
#include <iostream>

class IMenu
{
    public:
        virtual std::string printInfo() = 0;
        virtual int getCost() = 0;
};
class Steak : public IMenu {
public:
    std::string printInfo() override {
        return "Steak";
    }
    int getCost() override {
        return 20;
    }
};

class Pasta : public IMenu {
public:
    std::string printInfo() override {
        return "Pasta";
    }
    int getCost() override {
        return 15;
    }
};

class AddEat : public IMenu {
protected:
    IMenu* menu;
public:
    AddEat(IMenu* menu) : menu(menu) {}
    std::string printInfo() override {
        return menu->printInfo();
    }
    int getCost() override {
        return menu->getCost();
    }
};

class Salt : public AddEat {
public:
    Salt(IMenu* menu) : AddEat(menu) {}
    std::string printInfo() override {
        return menu->printInfo() + ", with Salt";
    }
    int getCost() override {
        return menu->getCost() + 1;
    }
};

class Pepper : public AddEat {
public:
    Pepper(IMenu* menu) : AddEat(menu) {}
    std::string printInfo() override {
        return menu->printInfo() + ", with Pepper";
    }
    int getCost() override {
        return menu->getCost() + 1;
    }
};
