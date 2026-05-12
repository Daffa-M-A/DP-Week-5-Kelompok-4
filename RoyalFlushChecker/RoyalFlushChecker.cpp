#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "RoyalFlushChecker.h"

HandRank RoyalFlushChecker::check(const Hand& hand) {
    std::map<char, std::vector<int>> suitToRanks;
    for (const auto& card : hand.cards) {
        suitToRanks[card.suit].push_back(card.rank);
    }

    bool hasRoyalFlush = false;

    std::vector<int> royalRanks = {10, 11, 12, 13, 14};

    for (const auto& pair : suitToRanks) {
        const std::vector<int>& ranks = pair.second;

        if (ranks.size() >= 5) {
            bool containsAllRoyalRanks = true;
            
            for (int r : royalRanks) {
                if (std::find(ranks.begin(), ranks.end(), r) == ranks.end()) {
                    containsAllRoyalRanks = false;
                    break; 
                }
            }

            if (containsAllRoyalRanks) {
                hasRoyalFlush = true;
                break;
            }
        }
    }

    if (hasRoyalFlush) {
        std::cout << "Detected ROYAL FLUSH\n";
        return HandRank::ROYAL_FLUSH;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}