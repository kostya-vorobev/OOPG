#pragma once
#include <iostream>
#include <string>

class Dish
{
private:
    double price;
    std::string name;

public:
    Dish(std::string name, double price)
    {
        this->name = name;
        this->price = price;
    }

    double getCost()
    {
        return this->price;
    }

    std::string getName()
    {
        return this->name;
    }
};

