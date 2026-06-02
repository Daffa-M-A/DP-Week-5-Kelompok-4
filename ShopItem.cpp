
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
    const ShopItemData& data, JokerManager& jm) 
{
    std::unique_ptr<Command> effectCmd;

    switch (data.type) {
        case ItemType::JOKER:
            effectCmd = std::make_unique<BuyJokerCommand>(jm, data.name);
            break;
    }

    return std::make_unique<ShopItem>(data, std::move(effectCmd));
}