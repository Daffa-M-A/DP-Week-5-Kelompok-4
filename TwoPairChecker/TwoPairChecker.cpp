#include <iostream>
#include <map>
#include "TwoPairChecker.h"

HandRank TwoPairChecker::check(const Hand& hand) {
    std::map<int, int> rankCount;
    
    // Hitung kemunculan setiap kartu
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++;
    }

    int pairCount = 0; // Variabel untuk menghitung jumlah pasangan yang ketemu
    
    // Cek ada berapa pasang kartu di tangan
    for (const auto& count : rankCount) {
        if (count.second >= 2) {
            pairCount++; 
        }
    }

    // KEPUTUSAN: Apakah ketemu minimal 2 pasang?
    if (pairCount >= 2) {
        std::cout << "Detected TWO PAIR\n";
        return HandRank::TWO_PAIR;
    }

    // JIKA GAGAL: Lempar ke checker selanjutnya (misal: PairChecker)
    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}