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
#include "Menu.h"
#include "OrderDelivery.h"
#include "Facade.h"
#include "OrderDel.h"
#include "IOrderDelivery.h"
#include "BeverageFactory.h"
#include "IFactory.h"
#include "BillSystem.h"
#include "IReciept.h"
#include "IIterator.h"
#include "IMenu.h"

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

    // Создадим меню и добавим в него несколько блюд
    Menu* menu = new Menu();
    menu->addDish("Dish1", 500.0);
    menu->addDish("Dish2", 600.0);
    menu->addDish("Dish3", 700.0);

    // Задаём тип заказа
    IOrderDelivery* typeOrder = new OrderDel();
    typeOrder->SetTypeOrder("Delivery");

    // Задаем настройки для доставки заказа
    OrderDelivery* orderDelivery = new OrderDelivery(typeOrder);

    // Создаём экземпляр класса Facade
    Facade facade(menu, orderDelivery);

    // Создаём заказ
    facade.createOrder("Dish1");
    facade.createOrder("Dish3");

    // Завершаем заказ и выводим общую стоимость
    double totalCost = facade.finishOrder();
    std::cout << "Sum cost order: " << totalCost << std::endl;

    // сначала мы создаем фабрику чая
    BeverageFactory* factory = new TeaFactory();
    // затем берем оттуда объект Tea
    IBeverage* tea = factory->createBeverage();
    // узнаем его имя и цену
    cout << tea->getName() << " costs " << tea->getPrice() << "\n";

    // затем меняем фабрику на кофейную
    factory = new CoffeeFactory();
    IBeverage* coffee = factory->createBeverage();
    cout << coffee->getName() << " costs " << coffee->getPrice() << "\n";


    IFactory* aFactory = new Combo1();
    // Создание продукта и напитка с помощью фабрики Combo1
    IProduct* cookie = aFactory->CreateProduct1();
    IBeverage* beverage = factory->createBeverage();
    // Вывод информации о продукте и напитке
    cout << "Combo1: " << cookie->getName() << " costs " << cookie->getPrice() << "\n";
    cout << "Combo1: " << beverage->getName() << " costs " << beverage->getPrice() << "\n";

    // Освобождение памяти
    delete factory;
    // Использование другой фабрики для создания нового комплекта продуктов и напитков.
    aFactory = new Combo2();
    cookie = aFactory->CreateProduct1();
    beverage = aFactory->CreateProduct2();
    // Вывод информации о прудукте и напитке
    cout << "Combo2: " << cookie->getName() << " costs " << cookie->getPrice() << "\n";
    cout << "Combo2: " << beverage->getName() << " costs " << beverage->getPrice() << "\n";


    BillSystem* billSystem = BillSystem::GetInstance();
    // Создание чеков и добавление продуктов
    Bill bill1("001");
    bill1.addProduct(new Cookie("Oat Cookies", 100.0));
    bill1.addProduct(new Tea("Green Tea", 150.0));
    // Добавление чека  в систему учета
    billSystem->AddBill(bill1);

    // Создание другого чека и добавление продуктов
    Bill bill2("002");
    bill2.addProduct(new Cookie("Chocolate Chip Cookies", 120.0));
    bill2.addProduct(new Coffee("Espresso", 200));
    // Добавление второго чека в систему учета
    billSystem->AddBill(bill2);

    // Вывод всех чеков
    billSystem->PrintBills();

    IMenu* steakDish = new Steak();
    std::cout << steakDish->printInfo() << std::endl;
    IMenu* pepperSteak = new Pepper(steakDish);
    std::cout << pepperSteak->printInfo() << std::endl;

    IReciept* adapter = new Adapter();
    std::cout << adapter->GetReciept("Reciept") << std::endl;

    EatComposite* lunchMenu = new EatComposite("Lunch Menu");
    lunchMenu->addEat(new EatLeaf("Hamburger"));
    lunchMenu->addEat(new EatLeaf("Fries"));
    lunchMenu->addEat(new EatLeaf("Coke"));

    std::vector<IEat*> lunchItems;
    for (int i = 0; i < lunchMenu->size(); i++)
        lunchItems.push_back(lunchMenu->getItem(i));

    EatIterator* lunchIterator = new EatIterator(lunchItems);
    lunchIterator->begin();
    while (!lunchIterator->isEnd()) {
        lunchIterator->current()->about();
        lunchIterator->next();
    }

    delete adapter;


    // удаление объектов
    delete orderPhone;
    delete orderRobot;

    // удалить старый заказ перед созданием нового
    delete order;

    // удалить объекты информации о заказе и прокси
    delete orderInfo;
    delete orderProxy;

    // удалить элементы меню
    delete menu;

    // удалить тип заказа
    delete typeOrder;

    // удалить настройки доставки заказа
    delete orderDelivery;

    // удаление напитков
    delete tea;
    delete coffee;

    // удалить фабрику и созданный ею продукт
    delete aFactory;
    delete cookie;
    delete beverage;

    system("pause");
    return 0;
}

