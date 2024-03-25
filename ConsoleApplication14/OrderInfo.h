#pragma once
#include "OrderInterface.h"
#include <iostream>
class IOrder
{
public:
	virtual void getOrder(int check) = 0;
};

class OrderInfo: public IOrder
{
private:
public:
	std::string client;
	int numberOrder;

	void getOrder(int check)
	{
		if (check == numberOrder)
			std::cout << "Order code: " << numberOrder << std::endl << "Client info: " << client << std::endl;
		else std::cout << "No any orders" << std::endl;
	}

	OrderInfo(int numberGoods, std::string clientInfo) {
		client = clientInfo;
		numberOrder = numberGoods;
	}
	~OrderInfo() {

	};
};


