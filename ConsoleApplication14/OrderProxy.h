#pragma once
#include "OrderInfo.h"
#include <iostream>

class OrderProxy : public IOrder
{
private:
	OrderInfo* prox;
	void log() { std::cout << "It's proxy!" << std::endl; }
public:
	void getOrder(int check)
	{
		log();
		if (check == prox->numberOrder)
			std::cout << "Order code: " << prox->numberOrder << std::endl << "Client info: " << prox->client << std::endl;
		else std::cout << "No any orders" << std::endl;
	}

	OrderProxy(int numberGoods, std::string clientInfo)
	{
		prox = new OrderInfo(numberGoods, clientInfo);
	}
	~OrderProxy() { delete prox; }
};

