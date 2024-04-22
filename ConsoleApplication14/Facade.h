#pragma once
#include "Menu.h"
#include "IorderDelivery.h"
#include "OrderCost.h"
#include "OrderDelivery.h"

class Facade
{
private:
    OrderDelivery* orderDelivery;
    Menu* menu;
    std::vector<std::string> dishes;

public:
    Facade(Menu* menu, OrderDelivery* delivery) : menu(menu), orderDelivery(delivery) {}

    void createOrder(std::string dish)
    {
        if (menu->GetPrice(dish) >= 0)
        {
            dishes.push_back(dish);
        }
    }

    double finishOrder()
    {
        OrderCost costCalculator;
        double totalCost = costCalculator.CalculateCost(*menu, dishes);
        orderDelivery->PrintSettings();

        dishes.clear();

        return totalCost;
    }
};

