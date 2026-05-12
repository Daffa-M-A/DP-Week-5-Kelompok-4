#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "StraightFlushChecker.h"

HandRank StraightFlushChecker::check(const Hand& hand) {
    std::map<char, std::vector<int>> suitToRanks;
    for (const auto& card : hand.cards) {
        suitToRanks[card.suit].push_back(card.rank);
    }

    bool hasStraightFlush = false;

    for (auto& pair : suitToRanks) {
        std::vector<int>& ranks = pair.second;

        if (ranks.size() >= 5) {
            
            if (std::find(ranks.begin(), ranks.end(), 14) != ranks.end()) {
                ranks.push_back(1);
            }

            std::sort(ranks.begin(), ranks.end());
            ranks.erase(std::unique(ranks.begin(), ranks.end()), ranks.end());

            int consecutiveCount = 1;

            for (size_t i = 1; i < ranks.size(); i++) {
                if (ranks[i] == ranks[i - 1] + 1) {
                    consecutiveCount++;
                    if (consecutiveCount >= 5) {
                        hasStraightFlush = true;
                        break;
                    }
                } else {
                    consecutiveCount = 1;
                }
            }
        }
        
        if (hasStraightFlush) break; 
    }

    if (hasStraightFlush) {
        std::cout << "Detected STRAIGHT FLUSH\n";
        return HandRank::STRAIGHT_FLUSH;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}