#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "RoyalFlushChecker.h"

HandRank RoyalFlushChecker::check(const Hand& hand) {
    // 1. Kelompokkan kartu berdasarkan lambang (suit)
    std::map<char, std::vector<int>> suitToRanks;
    for (const auto& card : hand.cards) {
        suitToRanks[card.suit].push_back(card.rank);
    }

    bool hasRoyalFlush = false;

    // Rank spesifik yang dibutuhkan untuk Royal Flush (10, J, Q, K, A)
    std::vector<int> royalRanks = {10, 11, 12, 13, 14};

    // 2. Cek setiap kelompok lambang
    for (const auto& pair : suitToRanks) {
        const std::vector<int>& ranks = pair.second;

        // Harus ada minimal 5 kartu
        if (ranks.size() >= 5) {
            bool containsAllRoyalRanks = true;
            
            // Cek apakah 5 rank wajib tersebut ada di dalam kelompok lambang ini
            for (int r : royalRanks) {
                if (std::find(ranks.begin(), ranks.end(), r) == ranks.end()) {
                    containsAllRoyalRanks = false;
                    break; // Jika ada satu saja yang tidak ketemu, langsung gagal
                }
            }

            if (containsAllRoyalRanks) {
                hasRoyalFlush = true;
                break;
            }
        }
    }

    // KEPUTUSAN
    if (hasRoyalFlush) {
        std::cout << "Detected ROYAL FLUSH\n";
        return HandRank::ROYAL_FLUSH;
    }

    // JIKA GAGAL: Lempar ke checker selanjutnya
    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}