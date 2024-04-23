#pragma once
#include <vector>
#include <string>
#include <iostream>

class IEat {
public:
    virtual void about() = 0;
    virtual int size() = 0;
    virtual void addEat(IEat* eat) = 0;
};

class EatLeaf : public IEat {
private:
    std::string eat;
public:
    EatLeaf(std::string eat) : eat(eat) {}
    void about() override {
        std::cout << eat << "\n";
    }
    int size() override {
        return 1;
    }
    void addEat(IEat* eat) override {
        std::cout << "Cannot add to a leaf.\n";
    }
};

class EatComposite : public IEat {
private:
    std::string title;
    std::vector<IEat*> eats;
public:
    EatComposite(std::string title) : title(title) {}
    void about() override {
        std::cout << title << "\n";
    }
    int size() override {
        int total = 0;
        for (IEat* eat : eats)
            total += eat->size();
        return total;
    }
    void addEat(IEat* eat) override {
        eats.push_back(eat);
    }
    void removeEat(int index) {
        if (index < eats.size())
            eats.erase(eats.begin() + index);
    }
    IEat* getItem(int index) { // добавленный метод getItem
        if (index < eats.size())
            return eats[index];
        return nullptr;
    }
};

class IIterator
{
public:
    virtual IEat* begin() = 0;
    virtual IEat* next() = 0;
    virtual bool isEnd() = 0;
    virtual IEat* current() = 0;
};

class EatIterator : public IIterator {
private:
    std::vector<IEat*> eats;
    int index;
public:
    EatIterator(std::vector<IEat*> eats) : eats(eats), index(0) {}
    IEat* begin() override {
        index = 0;
        return current();
    }
    IEat* next() override {
        if (!isEnd())
            ++index;
        return current();
    }
    bool isEnd() override {
        return index >= eats.size();
    }
    IEat* current() override {
        if (!isEnd())
            return eats[index];
        return nullptr;
    }
};

// Адаптер для совместимости итератора с IEat
class EatIteratorAdapter : public IEat {
private:
    EatIterator* iterator;
public:
    EatIteratorAdapter(EatIterator* iterator) : iterator(iterator) {}
    void about() override {
        for (IEat* eat = iterator->begin(); !iterator->isEnd(); eat = iterator->next())
            eat->about();
    }
    int size() override {
        return iterator->isEnd() ? 0 : 1;
    }
    void addEat(IEat* eat) override {
        std::cout << "Cannot add to an iterator.\n";
    }
};


