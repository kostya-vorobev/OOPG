#pragma once
#include "IProduct.h"
#include "IBeverage.h"
#include <vector>
#include <string>

class Bill
{

private:
    string id;
    vector<IProduct*> products;
    vector<IBeverage*> beverages;
    double total;
public:
    Bill(string id) : id(id), total(0) {}
    void addProduct(IProduct* product) {
        products.push_back(product);
        total += product->getPrice();
    }
    void addProduct(IBeverage* beverage) {
        beverages.push_back(beverage);
        total += beverage->getPrice();
    }
    string toString() {
        string billDetails = "Bill ID: " + id + "\nProducts:\n";
        for (auto product : products) {
            billDetails += "- " + product->getName()
                + " costs " + to_string(product->getPrice()) + "\n";
        }
        for (auto beverage : beverages) {
            billDetails += "- " + beverage->getName()
                + " costs " + to_string(beverage->getPrice()) + "\n";
        }
        billDetails += "Total: " + to_string(total);
        return billDetails;
    }
};

