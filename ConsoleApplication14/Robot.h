#pragma once
#include "RobotInterface.h"
#include "Order.h"
typedef RobotInterface* prtRobotInterface;

class Robot {
private:
    typedef void (RobotInterface::* ActionDelegate)();

    RobotInterface* _robotInterface;
    ActionDelegate _actionDelegate;

public:
    Robot(RobotInterface* robotInterface) {
        _robotInterface = robotInterface;
        _actionDelegate = &RobotInterface::Action;
    }

    void Action() {
        (_robotInterface->*_actionDelegate)();
    }
};
