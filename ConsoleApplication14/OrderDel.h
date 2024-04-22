#pragma once
#include "IOrderDelivery.h"
using namespace std;

class OrderDel :
    public IOrderDelivery
{
private:
    string type;

public:
    void SetTypeOrder(string type) {
        this->type = type;
    }

    string GetTypeOrder() {
        return this->type;
    }

    void PrintType() {
        cout << "Order type: " << this->type << endl;
    }

};

