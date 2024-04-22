#include "BillSystem.h"

BillSystem* BillSystem::instance = nullptr;

BillSystem* BillSystem::GetInstance() {
    if (instance == nullptr) {
        instance = new BillSystem();
    }
    return instance;
}

void BillSystem::AddBill(Bill bill) {
    bills.push_back(bill);
}

void BillSystem::PrintBills() {
    for (auto bill : bills) {
        cout << bill.toString() << "\n";
    }
}