// ShopItem.h
#pragma once
#include "ShopData.h"
#include "PurchaseCommands.h"
#include <memory>

class ShopItem {
private:
    ShopItemData data;
    std::unique_ptr<Command> purchaseEffect;
public:
    ShopItem(ShopItemData d, std::unique_ptr<Command> effect);
    const ShopItemData& getData() const;
    void triggerEffect();
};

class ShopFactory {
public:
    static std::unique_ptr<ShopItem> createItem(
        const ShopItemData& data, 
        JokerManager& jm, 
        HandScoreTable& hst, 
        Deck& dk);
};