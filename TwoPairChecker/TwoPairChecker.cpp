#include <iostream>
#include <map>
#include "TwoPairChecker.h"

HandRank TwoPairChecker::check(const Hand& hand) {
    std::map<int, int> rankCount;
    
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++;
    }

    int pairCount = 0; 
    
    for (const auto& count : rankCount) {
        if (count.second >= 2) {
            pairCount++; 
        }
    }

    if (pairCount >= 2) {
        std::cout << "Detected TWO PAIR\n";
        return HandRank::TWO_PAIR;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}