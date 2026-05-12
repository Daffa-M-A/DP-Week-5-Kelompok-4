#include <iostream>
#include <vector>
#include <algorithm> 
#include "StraightChecker.h"

HandRank StraightChecker::check(const Hand& hand) {
    std::vector<int> ranks;
    
    for (const auto& card : hand.cards) {
        ranks.push_back(card.rank);
    }

    if (std::find(ranks.begin(), ranks.end(), 14) != ranks.end()) {
        ranks.push_back(1);
    }

    std::sort(ranks.begin(), ranks.end());

    ranks.erase(std::unique(ranks.begin(), ranks.end()), ranks.end());

    bool hasStraight = false;
    int consecutiveCount = 1;

    for (size_t i = 1; i < ranks.size(); i++) {
        if (ranks[i] == ranks[i - 1] + 1) {
            consecutiveCount++;
            if (consecutiveCount >= 5) {
                hasStraight = true;
                break;
            }
        } else {
            consecutiveCount = 1;
        }
    }

    if (hasStraight) {
        std::cout << "Detected STRAIGHT\n";
        return HandRank::STRAIGHT;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}