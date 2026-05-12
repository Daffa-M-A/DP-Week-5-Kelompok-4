#include <iostream>
#include <map>
#include <vector>
#include "FlushHouseChecker.h"

HandRank FlushHouseChecker::check(const Hand& hand) {
    // 1. Kelompokkan kartu berdasarkan lambangnya dulu
    std::map<char, std::vector<int>> suitToRanks;
    for (const auto& card : hand.cards) {
        suitToRanks[card.suit].push_back(card.rank);
    }

    bool hasFlushHouse = false;

    // 2. Cek setiap kelompok lambang
    for (const auto& pair : suitToRanks) {
        const std::vector<int>& ranks = pair.second;

        // Harus ada minimal 5 kartu dengan lambang ini
        if (ranks.size() >= 5) {
            std::map<int, int> rankCount;
            
            // Hitung kemunculan rank DI DALAM lambang yang sama ini
            for (int rank : ranks) {
                rankCount[rank]++;
            }

            bool hasThreeOfAKind = false;
            bool hasPair = false;

            for (const auto& count : rankCount) {
                if (count.second >= 3) {
                    if (hasThreeOfAKind) {
                        hasPair = true; // Jika ada dua set isi 3, set kedua dihitung Pair
                    } else {
                        hasThreeOfAKind = true;
                    }
                } else if (count.second >= 2) {
                    hasPair = true;
                }
            }

            // Jika dalam satu lambang terdapat Full House, berarti ini Flush House!
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