#pragma once
#include "Menu.h"

class OrderCost
{
public:
    double CalculateCost(Menu& menu, std::vector<std::string> order)
    {
        double total_cost = 0.0;
        for (int i = 0; i < order.size(); i++)
        {
            double price = menu.GetPrice(order[i]);
            if (price >= 0)
            {
                total_cost += price;
            }
        }
        return total_cost;
    }
};

