#include <iostream>
#include <map>
#include <utility> // Untuk std::pair
#include "FlushFiveChecker.h"

HandRank FlushFiveChecker::check(const Hand& hand) {
    // Map ini menyimpan kombinasi spesifik: {Rank, Suit} -> Jumlah kemunculan
    std::map<std::pair<int, char>, int> exactCardCount;
    
    // Hitung kartu yang benar-benar identik secara rank dan lambang
    for (const auto& card : hand.cards) {
        exactCardCount[{card.rank, card.suit}]++;
    }

    bool hasFlushFive = false;
    
    // Cek apakah ada kombinasi kartu identik yang jumlahnya 5
    for (const auto& count : exactCardCount) {
        if (count.second >= 5) {
            hasFlushFive = true;
            break;
        }
    }

    if (hasFlushFive) {
        std::cout << "Detected FLUSH FIVE\n";
        return HandRank::FLUSH_FIVE;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}