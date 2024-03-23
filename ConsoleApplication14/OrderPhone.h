#pragma once
#include "OrderInterface.h"
#include <iostream>
class OrderPhone: public OrderInterface
{
	void PrintTypeOrder() {
		std::cout << "Ordering via phone" << std::endl;
	}
};

