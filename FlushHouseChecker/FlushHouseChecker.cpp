#include <iostream>
#include <map>
#include <vector>
#include "FlushHouseChecker.h"

HandRank FlushHouseChecker::check(const Hand& hand) {
    std::map<char, std::vector<int>> suitToRanks;
    for (const auto& card : hand.cards) {
        suitToRanks[card.suit].push_back(card.rank);
    }

    bool hasFlushHouse = false;

    for (const auto& pair : suitToRanks) {
        const std::vector<int>& ranks = pair.second;

        if (ranks.size() >= 5) {
            std::map<int, int> rankCount;
            
            for (int rank : ranks) {
                rankCount[rank]++;
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
                hasFlushHouse = true;
                break;
            }
        }
    }

    if (hasFlushHouse) {
        std::cout << "Detected FLUSH HOUSE\n";
        return HandRank::FLUSH_HOUSE;
    }

    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}