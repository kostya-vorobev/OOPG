#pragma once
#include "OrderInterface.h"
#include "Order.h"
#include <iostream>
class OrderProxy: public OrderInterface {
    private:
        Order* _order;
        void GetStatus() {
            std::cout << "Order in process" << std::endl;
        }

    public:
        OrderProxy(Order* order) {
            _order = order;
        }

        void PrintTypeOrder() {
            GetStatus();
            _order->PrintTypeOrder();
        }
        ~OrderProxy()
        {
            delete _order;
        }
};

