// ShopSystem.h
#pragma once
#include "ShopServices.h"
#include <map>

class ShopSystem {
private:
    ShopInventory inventory;
    PurchaseService purchaseService;
    
    JokerManager& jokerManager;
    HandScoreTable& handTable;
    Deck& gameDeck;

    std::map<std::string, ShopItemData> itemDatabase;
    void loadItemDatabase();

public:
    ShopSystem(JokerManager& jm, HandScoreTable& hst, Deck& dk);
    void generateShopFront(const std::vector<std::string>& itemIds);
    void displayShop(const Money& playerWallet);
    void buyItem(int index, Money& playerWallet);
};