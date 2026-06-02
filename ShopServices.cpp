
#include "ShopServices.h"

void ShopInventory::addItem(std::unique_ptr<ShopItem> item) {
    items.push_back(std::move(item));
}

const std::vector<std::unique_ptr<ShopItem>>& ShopInventory::getItems() const {
    return items;
}

std::unique_ptr<ShopItem> ShopInventory::extractItem(int index) {
    if (index < 0 || index >= items.size()) return nullptr;
    auto item = std::move(items[index]);
    items.erase(items.begin() + index);
    return item;
}

void ShopInventory::clear() { 
    items.clear(); 
}

bool PurchaseService::processTransaction(Money& wallet, int cost) {
    if (wallet.canAfford(cost)) {
        wallet.deduct(cost);
        return true;
    }
    return false;
}