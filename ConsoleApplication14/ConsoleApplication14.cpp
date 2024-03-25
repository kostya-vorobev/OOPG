// ConsoleApplication14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Robot.h"
#include "RobotWaiter.h"
#include "OrderPhone.h"
#include "OrderRobot.h"
#include "DeliveryRobot.h"
#include "Order.h"
#include "OrderProxy.h"

int main()
{
    OrderPhone* orderPhone = new OrderPhone;
    OrderRobot* orderRobot = new OrderRobot;
    RobotInterface* deliveryRobot = new DeliveryRobot();
    RobotInterface* robotWaiter = new RobotWaiter();
    Order* order = new Order(orderRobot);
    Robot robot1(deliveryRobot);
    Robot robot2(robotWaiter);
    robot1.Action();
    order->PrintTypeOrder();
    robot2.Action();
    order = new Order(orderPhone);
    order->PrintTypeOrder();
    OrderInfo* orderInfo = new OrderInfo(1, "Ivanov I.I.");
    OrderProxy* orderProxy = new OrderProxy(1, "Ivanov I.I.");
    orderInfo->getOrder(1);
    orderProxy->getOrder(1);
    delete deliveryRobot;
    delete robotWaiter;
    system("pause");
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
