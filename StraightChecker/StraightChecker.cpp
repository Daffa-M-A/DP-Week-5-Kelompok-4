#include <iostream>
#include <vector>
#include <algorithm> // Untuk std::sort dan std::unique
#include "StraightChecker.h"

HandRank StraightChecker::check(const Hand& hand) {
    std::vector<int> ranks;
    
    // Kumpulkan semua nilai rank ke dalam vector baru
    for (const auto& card : hand.cards) {
        ranks.push_back(card.rank);
    }

    // TRICK ACE: Jika ada Ace (14), kita tambahkan juga angka '1' ke dalam vector.
    // Ini agar Straight A-2-3-4-5 bisa terdeteksi.
    if (std::find(ranks.begin(), ranks.end(), 14) != ranks.end()) {
        ranks.push_back(1);
    }

    // Urutkan kartu dari yang terkecil hingga terbesar
    std::sort(ranks.begin(), ranks.end());

    // Hapus rank duplikat (misal tangan berisi 4,5,5,6,7,8 -> kita ubah jadi 4,5,6,7,8 agar mudah dicek)
    ranks.erase(std::unique(ranks.begin(), ranks.end()), ranks.end());

    bool hasStraight = false;
    int consecutiveCount = 1;

    // Cek apakah ada 5 angka yang berurutan
    for (size_t i = 1; i < ranks.size(); i++) {
        // Jika angka saat ini adalah angka sebelumnya ditambah 1
        if (ranks[i] == ranks[i - 1] + 1) {
            consecutiveCount++;
            if (consecutiveCount >= 5) {
                hasStraight = true;
                break;
            }
        } else {
            // Reset perhitungan jika urutannya terputus
            consecutiveCount = 1;
        }
    }

    // KEPUTUSAN: Apakah ketemu Straight?
    if (hasStraight) {
        std::cout << "Detected STRAIGHT\n";
        return HandRank::STRAIGHT;
    }

    // JIKA GAGAL: Lempar ke checker selanjutnya
    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}