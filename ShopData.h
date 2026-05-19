// ShopData.h
#pragma once
#include <string>

enum class ItemType { 
    JOKER, 
    PLANET_CARD, 
    TAROT_CARD 
};

struct ShopItemData {
    std::string id;
    std::string name;
    int cost;
    ItemType type;
    std::string effectTarget; // Contoh: "Flush", "Ace of Spades"
    int valA = 0;              // Variabel kustom 1 (misal: bonus Mult)
    int valB = 0;              // Variabel kustom 2 (misal: bonus Chips)
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