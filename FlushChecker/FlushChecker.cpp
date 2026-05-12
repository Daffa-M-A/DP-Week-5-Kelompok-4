#include <iostream>
#include <map>
#include "FlushChecker.h"

HandRank FlushChecker::check(const Hand& hand) {
    std::map<char, int> suitCount;
    
    for (const auto& card : hand.cards) {
        suitCount[card.suit]++;
    }

    bool hasFlush = false;
    
    for (const auto& count : suitCount) {
        if (count.second >= 5) {
            hasFlush = true;
            break; 
        }
    }

    if (hasFlush) {
        std::cout << "Detected FLUSH\n";
        return HandRank::FLUSH;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}