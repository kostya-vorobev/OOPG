#pragma once
#include <iostream>
#include "OrderInterface.h"
class Order
{
	OrderInterface* _orderInterface;
public:
	Order(OrderInterface* orderInterface)
	{
		_orderInterface = orderInterface;
	}

	void PrintTypeOrder()
	{
		_orderInterface->PrintTypeOrder();
	}
};

