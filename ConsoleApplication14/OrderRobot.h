#pragma once
#include "OrderInterface.h"
#include <iostream>
class OrderRobot: public OrderInterface
{
	void PrintTypeOrder() {
		std::cout << "Ordering via robot" << std::endl;
	}
};

