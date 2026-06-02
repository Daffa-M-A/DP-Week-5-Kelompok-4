
#pragma once
#include <string>

enum class ItemType { 
    JOKER
};

struct ShopItemData {
    std::string id;
    std::string name;
    int cost;
    ItemType type;
    std::string effectTarget; 
    int valA = 0;              
    int valB = 0;              
};

class Money {
private:
    int balance;
public:
    explicit Money(int initial) : balance(initial) {}
    int getBalance() const { return balance; }
    bool canAfford(int amount) const { return balance >= amount; }
    void deduct(int amount) { balance -= amount; }
    void add(int amount) { balance += amount; }
};