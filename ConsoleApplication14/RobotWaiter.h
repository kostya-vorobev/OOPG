#pragma once
#include <iostream>
#include "RobotInterface.h"
class RobotWaiter: public RobotInterface{
public:
    void Action() {
        std::cout << "Robot Waiter: Take the order" << std::endl;
    }
};

