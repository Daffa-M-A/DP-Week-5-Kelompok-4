#include <iostream>
#include <map>
#include "FullHouseChecker.h"

HandRank FullHouseChecker::check(const Hand& hand) {
    std::map<int, int> rankCount;
    
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++;
    }

    bool hasThreeOfAKind = false;
    bool hasPair = false;

    for (const auto& count : rankCount) {
        if (count.second >= 3) {
            if (hasThreeOfAKind) {
                hasPair = true; 
            } else {
                hasThreeOfAKind = true;
            }
        } else if (count.second >= 2) {
            hasPair = true;
        }
    }

    if (hasThreeOfAKind && hasPair) {
        std::cout << "Detected FULL HOUSE\n";
        return HandRank::FULL_HOUSE;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}