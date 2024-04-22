#pragma once
#include <vector>
#include "Dish.h"

class Menu
{
private:
    std::vector<Dish> dishes;

public:
    void addDish(std::string name, double price)
    {
        Dish newDish(name, price);
        dishes.push_back(newDish);
    }

    double GetPrice(std::string name)
    {
        for (int i = 0; i < dishes.size(); ++i)
        {
            if (dishes[i].getName() == name)
            {
                return dishes[i].getCost();
            }
        }
        return -1.0; // возвращаем отрицательное значение, если блюдо не найдено
    }
};

