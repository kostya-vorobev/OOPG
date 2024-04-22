#pragma once
#include <iostream>

class IReciept
{
public:
	virtual std::string GetReciept(std::string value) = 0;
};

class PDFReciept {
public:
    std::string ReadReciept() {
        return "PDF Reciept"; 
    }
    
};

// Адаптер
class Adapter : public IReciept {
private:
    PDFReciept pdfReciept; 
public:
    std::string GetReciept(std::string value) override {
        std::string pdfRecieptData = pdfReciept.ReadReciept();

        return pdfRecieptData;
    }
};
