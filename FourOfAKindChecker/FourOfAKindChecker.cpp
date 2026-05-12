#include <iostream>
#include <map>
#include "FourOfAKindChecker.h"

HandRank FourOfAKindChecker::check(const Hand& hand) {
    std::map<int, int> rankCount;
    
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++;
    }

    bool hasFourOfAKind = false;
    
    for (const auto& count : rankCount) {
        if (count.second >= 4) {
            hasFourOfAKind = true;
            break;
        }
    }

    if (hasFourOfAKind) {
        std::cout << "Detected FOUR OF A KIND\n";
        return HandRank::FOUR_OF_A_KIND;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}