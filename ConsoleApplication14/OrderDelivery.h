#pragma once
#include "IOrderDelivery.h"
#include <string>
using namespace std;

class OrderDelivery
{
private:
    IOrderDelivery* iODeliv;

public:
    OrderDelivery(IOrderDelivery* ODeliv)
    {
        iODeliv = ODeliv;
    }
    void SetSettings(string settings) {
        iODeliv->SetTypeOrder(settings);
    }

    void PrintSettings() {
        iODeliv->PrintType();
    }
};

