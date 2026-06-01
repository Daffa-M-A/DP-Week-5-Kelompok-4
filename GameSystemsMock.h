#pragma once
#include <iostream>
#include <string>

class JokerManager {
public:
    void addJoker(const std::string& name) {
        std::cout << "[JokerManager] [DEBUG] Joker '" << name << "' ditambahkan ke slot aktif.\n";
    }
};

class HandScoreTable {
public:
    void upgradeHand(const std::string& handType, int multBonus, int chipsBonus) {
        std::cout << "[HandScoreTable] [DEBUG] Upgrade " << handType 
                  << ": +" << multBonus << " Mult, +" << chipsBonus << " Chips.\n";
    }
};

class Deck {
public:
    void addCardToDeck(const std::string& cardRankSuit) {
        std::cout << "[Deck] [DEBUG] Kartu '" << cardRankSuit << "' dimasukkan ke dalam Deck.\n";
    }
};