// ShopItem.cpp
#include "ShopItem.h"

ShopItem::ShopItem(ShopItemData d, std::unique_ptr<Command> effect) 
    : data(std::move(d)), purchaseEffect(std::move(effect)) {}

const ShopItemData& ShopItem::getData() const { 
    return data; 
}

void ShopItem::triggerEffect() {
    if (purchaseEffect) {
        purchaseEffect->execute();
    }
}

std::unique_ptr<ShopItem> ShopFactory::createItem(
    const ShopItemData& data, JokerManager& jm, HandScoreTable& hst, Deck& dk) 
{
    std::unique_ptr<Command> effectCmd;

    switch (data.type) {
        case ItemType::JOKER:
            effectCmd = std::make_unique<BuyJokerCommand>(jm, data.name);
            break;
        case ItemType::PLANET_CARD:
            effectCmd = std::make_unique<UpgradeHandCommand>(hst, data.effectTarget, data.valA, data.valB);
            break;
        case ItemType::TAROT_CARD:
            effectCmd = std::make_unique<ModifyDeckCommand>(dk, data.effectTarget);
            break;
    }

    return std::make_unique<ShopItem>(data, std::move(effectCmd));
}