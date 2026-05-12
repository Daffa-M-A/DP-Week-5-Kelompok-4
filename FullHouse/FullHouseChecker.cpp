#include <iostream>
#include <map>
#include "FullHouseChecker.h"

HandRank FullHouseChecker::check(const Hand& hand) {
    std::map<int, int> rankCount;
    
    // Hitung kemunculan setiap kartu
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++;
    }

    bool hasThreeOfAKind = false;
    bool hasPair = false;

    // Evaluasi kemunculan kartu
    for (const auto& count : rankCount) {
        if (count.second >= 3) {
            if (hasThreeOfAKind) {
                // Jika sistem mengecek lebih dari 5 kartu (misal tangan berisi 6+ kartu), 
                // dan ada DUA set "Three of a Kind", set kedua kita hitung sebagai Pair.
                hasPair = true; 
            } else {
                hasThreeOfAKind = true;
            }
        } else if (count.second >= 2) {
            // Jika kartunya tepat 2 (atau lebih tapi syarat Three of a Kind sudah terpenuhi)
            hasPair = true;
        }
    }

    // KEPUTUSAN: Syarat Full House adalah keduanya harus ada
    if (hasThreeOfAKind && hasPair) {
        std::cout << "Detected FULL HOUSE\n";
        return HandRank::FULL_HOUSE;
    }

    // JIKA GAGAL: Lempar ke checker selanjutnya
    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}