#include <iostream>
#include <map>
#include "PairChecker.h"

HandRank PairChecker::check(const Hand& hand) {
    // 1. Kita buat alat untuk menghitung kemunculan setiap rank
    std::map<int, int> rankCount;
    
    // 2. Lakukan perulangan untuk setiap kartu yang ada di tangan (hand)
    // Asumsi: struct Hand memiliki member std::vector<Card> cards;
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++; 
    }

    // 3. Cek apakah ada rank yang muncul tepat 2 kali (atau lebih)
    bool hasPair = false;
    for (const auto& count : rankCount) {
        if (count.second >= 2) { 
            hasPair = true;
            break; // Pasangan ditemukan, berhenti mencari
        }
    }

    // 4. KEPUTUSAN: Apakah ketemu Pair?
    if (hasPair) {
        std::cout << "Detected PAIR\n";
        return HandRank::PAIR; // Proses berhenti di sini, tidak diteruskan ke bawah
    }

    // 5. JIKA GAGAL: Lempar ke checker selanjutnya (misalnya HighCardChecker)
    if (nextChecker) {
        return nextChecker->check(hand); 
    }

    // Fallback darurat (idealnya tidak akan pernah tersentuh jika rantainya benar)
    return HandRank::HIGH_CARD;
}