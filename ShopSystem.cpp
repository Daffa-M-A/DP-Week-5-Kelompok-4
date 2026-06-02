
#include "ShopSystem.h"
#include <iostream>

ShopSystem::ShopSystem(JokerManager& jm)
    : jokerManager(jm) {
    loadItemDatabase();
}

void ShopSystem::loadItemDatabase() {
    itemDatabase["JOKER_ADDCHIPS"]  = {"JOKER_ADDCHIPS", "Add Chips Joker", 6, ItemType::JOKER, "Memberikan +80 Chips", 80, 0};
    itemDatabase["JOKER_PAIR"]  = {"JOKER_PAIR", "Pair Joker", 5, ItemType::JOKER, "Memberikan +15 Multiplier jika mendeteksi kombinasi kartu Pair", 0, 15};
    itemDatabase["JOKER_DIAMOND"] = {"JOKER_DIAMOND", "Diamond Joker", 7, ItemType::JOKER, "Memberikan +4 Multiplier untuk setiap kartu berlambang Diamond yang dimainkan", 0, 4};
}

void ShopSystem::generateShopFront(const std::vector<std::string>& itemIds) {
    inventory.clear();
    std::cout << "[ShopSystem] [DEBUG] Merestock Item Toko Baru...\n";
    
    for (const auto& id : itemIds) {
        if (itemDatabase.find(id) != itemDatabase.end()) {
            auto item = ShopFactory::createItem(itemDatabase[id], jokerManager);
            inventory.addItem(std::move(item));
        }
    }
}

void ShopSystem::displayShop(const Money& playerWallet) {
    std::cout << "\n=================== INDEPENDENT SHOP ===================\n";
    std::cout << " Dompet Pemain: $" << playerWallet.getBalance() << "\n--------------------------------------------------------\n";
    const auto& items = inventory.getItems();
    for (size_t i = 0; i < items.size(); ++i) {
        const auto& data = items[i]->getData();
        std::cout << " [" << i << "] " << data.name << " | Harga: $" << data.cost;
        std::cout << "\n";
    }
    std::cout << "========================================================\n";
}

void ShopSystem::buyItem(int index, Money& playerWallet) {
    const auto& items = inventory.getItems();
    if (index < 0 || index >= items.size()) {
        std::cout << "[ShopSystem] [ERROR] Indeks item tidak valid!\n";
        return;
    }

    int cost = items[index]->getData().cost;
    std::string itemName = items[index]->getData().name;

    if (purchaseService.processTransaction(playerWallet, cost)) {
        std::cout << "[ShopSystem] [SUCCESS] Membeli " << itemName << " seharga $" << cost << ".\n";
        auto purchasedItem = inventory.extractItem(index);
        purchasedItem->triggerEffect();
    } else {
        std::cout << "[ShopSystem] [FAIL] Uang tidak cukup! (Butuh $" << cost << ")\n";
    }
}