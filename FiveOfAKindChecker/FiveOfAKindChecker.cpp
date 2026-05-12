#include <iostream>
#include <map>
#include "FiveOfAKindChecker.h"

HandRank FiveOfAKindChecker::check(const Hand& hand) {
    std::map<int, int> rankCount;
    
    // Hitung kemunculan setiap rank
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++;
    }

    bool hasFiveOfAKind = false;
    
    // Cek apakah ada satu rank yang muncul minimal 5 kali
    for (const auto& count : rankCount) {
        if (count.second >= 5) {
            hasFiveOfAKind = true;
            break;
        }
    }

    if (hasFiveOfAKind) {
        std::cout << "Detected FIVE OF A KIND\n";
        return HandRank::FIVE_OF_A_KIND;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}