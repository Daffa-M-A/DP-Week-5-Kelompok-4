#include <iostream>
#include <map>
#include "ThreeOfAKindChecker.h"

HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    std::map<int, int> rankCount;
    
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++;
    }

    bool hasThreeOfAKind = false;
    
    
    for (const auto& count : rankCount) {
        if (count.second >= 3) {
            hasThreeOfAKind = true;
            break;
        }
    }

    if (hasThreeOfAKind) {
        std::cout << "Detected THREE OF A KIND\n";
        return HandRank::THREE_OF_A_KIND;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}