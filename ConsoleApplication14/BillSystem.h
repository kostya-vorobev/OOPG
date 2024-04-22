#pragma once
#include "Bill.h"

class BillSystem
{
private:
    static BillSystem* instance;
    vector<Bill> bills;
    BillSystem() {}

public:
    static BillSystem* GetInstance();
    void AddBill(Bill bill);
    void PrintBills();
};



