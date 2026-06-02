#include <iostream>
#include <map>
#include <utility> 
#include "FlushFiveChecker.h"

HandRank FlushFiveChecker::check(const Hand& hand) {
    std::map<std::pair<int, char>, int> exactCardCount;
    
    for (const auto& card : hand.cards) {
        exactCardCount[{card.rank, card.suit}]++;
    }

    bool hasFlushFive = false;
    
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