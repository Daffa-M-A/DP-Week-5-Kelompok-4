#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "StraightFlushChecker.h"

HandRank StraightFlushChecker::check(const Hand& hand) {
    // 1. Kelompokkan kartu berdasarkan lambang (suit)
    std::map<char, std::vector<int>> suitToRanks;
    for (const auto& card : hand.cards) {
        suitToRanks[card.suit].push_back(card.rank);
    }

    bool hasStraightFlush = false;

    // 2. Cek setiap kelompok lambang
    for (auto& pair : suitToRanks) {
        std::vector<int>& ranks = pair.second;

        // Harus ada minimal 5 kartu dengan lambang ini untuk bisa Straight Flush
        if (ranks.size() >= 5) {
            
            // TRICK ACE: Sama seperti Straight, tambahkan 1 jika ada Ace (14)
            if (std::find(ranks.begin(), ranks.end(), 14) != ranks.end()) {
                ranks.push_back(1);
            }

            // Urutkan dan hapus duplikat (meski jarang ada duplikat di deck standar)
            std::sort(ranks.begin(), ranks.end());
            ranks.erase(std::unique(ranks.begin(), ranks.end()), ranks.end());

            int consecutiveCount = 1;

            // 3. Cek apakah ada 5 angka berurutan di dalam satu lambang ini
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
        
        if (hasStraightFlush) break; // Jika sudah ketemu, tidak perlu cek lambang lain
    }

    // KEPUTUSAN
    if (hasStraightFlush) {
        std::cout << "Detected STRAIGHT FLUSH\n";
        return HandRank::STRAIGHT_FLUSH;
    }

    // JIKA GAGAL: Lempar ke checker selanjutnya
    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}