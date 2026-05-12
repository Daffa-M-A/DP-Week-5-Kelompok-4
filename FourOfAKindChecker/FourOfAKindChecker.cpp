#include <iostream>
#include <map>
#include "FourOfAKindChecker.h"

HandRank FourOfAKindChecker::check(const Hand& hand) {
    std::map<int, int> rankCount;
    
    // Hitung kemunculan setiap kartu
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++;
    }

    bool hasFourOfAKind = false;
    
    // Cek apakah ada satu rank yang muncul minimal 4 kali
    for (const auto& count : rankCount) {
        if (count.second >= 4) {
            hasFourOfAKind = true;
            break;
        }
    }

    // KEPUTUSAN
    if (hasFourOfAKind) {
        std::cout << "Detected FOUR OF A KIND\n";
        return HandRank::FOUR_OF_A_KIND;
    }

    // JIKA GAGAL: Lempar ke checker selanjutnya
    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}