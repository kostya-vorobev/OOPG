#pragma once
#include <iostream>
#include <string>
using namespace std;

class IOrderDelivery
{
public:
    virtual void SetTypeOrder(string type) = 0;
    virtual string GetTypeOrder() = 0;
    virtual void PrintType() = 0;
};

