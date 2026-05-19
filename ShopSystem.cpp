// ShopSystem.cpp
#include "ShopSystem.h"
#include <iostream>

ShopSystem::ShopSystem(JokerManager& jm, HandScoreTable& hst, Deck& dk)
    : jokerManager(jm), handTable(hst), gameDeck(dk) {
    loadItemDatabase();
}

void ShopSystem::loadItemDatabase() {
    itemDatabase["JOKER_ICE"]  = {"JOKER_ICE", "Ice Joker", 6, ItemType::JOKER, "", 0, 0};
    itemDatabase["PLNT_MERC"]  = {"PLNT_MERC", "Mercury (Planet)", 3, ItemType::PLANET_CARD, "Pair", 2, 15};
    itemDatabase["TAROT_FOOL"] = {"TAROT_FOOL", "The Fool (Tarot)", 4, ItemType::TAROT_CARD, "Bonus Ace of Spades", 0, 0};
}

void ShopSystem::generateShopFront(const std::vector<std::string>& itemIds) {
    inventory.clear();
    std::cout << "[ShopSystem] [DEBUG] Merestock Item Toko Baru...\n";
    
    for (const auto& id : itemIds) {
        if (itemDatabase.find(id) != itemDatabase.end()) {
            auto item = ShopFactory::createItem(itemDatabase[id], jokerManager, handTable, gameDeck);
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
        if (data.type == ItemType::PLANET_CARD) std::cout << " (Target: " << data.effectTarget << ")";
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