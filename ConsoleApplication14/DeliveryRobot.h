#pragma once
#include <iostream>
#include "RobotInterface.h"
class DeliveryRobot: public RobotInterface
{
public:
    void Action() {
        std::cout << "Delivery robot: Bring the order." << std::endl;
    }
};

