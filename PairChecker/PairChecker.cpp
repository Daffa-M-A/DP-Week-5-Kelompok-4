#include <iostream>
#include <map>
#include "PairChecker.h"

HandRank PairChecker::check(const Hand& hand) {
    std::map<int, int> rankCount;
    
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++; 
    }

    bool hasPair = false;
    for (const auto& count : rankCount) {
        if (count.second >= 2) { 
            hasPair = true;
            break; 
        }
    }

    if (hasPair) {
        std::cout << "Detected PAIR\n";
        return HandRank::PAIR; 
    }

    if (nextChecker) {
        return nextChecker->check(hand); 
    }

    return HandRank::HIGH_CARD;
}