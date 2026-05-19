// ShopServices.h
#pragma once
#include "ShopItem.h"
#include <vector>

class ShopInventory {
private:
    std::vector<std::unique_ptr<ShopItem>> items;
public:
    void addItem(std::unique_ptr<ShopItem> item);
    const std::vector<std::unique_ptr<ShopItem>>& getItems() const;
    std::unique_ptr<ShopItem> extractItem(int index);
    void clear();
};

class PurchaseService {
public:
    bool processTransaction(Money& wallet, int cost);
};