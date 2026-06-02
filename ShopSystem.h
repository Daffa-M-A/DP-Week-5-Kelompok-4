
#pragma once
#include "ShopServices.h"
#include <map>

class ShopSystem {
private:
    ShopInventory inventory;
    PurchaseService purchaseService;
    
    JokerManager& jokerManager;

    std::map<std::string, ShopItemData> itemDatabase;
    void loadItemDatabase();

public:
    ShopSystem(JokerManager& jm);
    void generateShopFront(const std::vector<std::string>& itemIds);
    void displayShop(const Money& playerWallet);
    void buyItem(int index, Money& playerWallet);
};