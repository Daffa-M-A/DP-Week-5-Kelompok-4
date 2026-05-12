#include <iostream>
#include <map>
#include "FlushChecker.h"

HandRank FlushChecker::check(const Hand& hand) {
    // Kita gunakan char karena tipe data suit di Card.h adalah char
    std::map<char, int> suitCount;
    
    // Hitung kemunculan setiap lambang (Spade, Heart, Club, Diamond)
    for (const auto& card : hand.cards) {
        suitCount[card.suit]++;
    }

    bool hasFlush = false;
    
    // Cek apakah ada satu lambang yang terkumpul minimal 5 buah
    for (const auto& count : suitCount) {
        if (count.second >= 5) {
            hasFlush = true;
            break; 
        }
    }

    // KEPUTUSAN: Apakah ketemu Flush?
    if (hasFlush) {
        std::cout << "Detected FLUSH\n";
        return HandRank::FLUSH;
    }

    // JIKA GAGAL: Lempar ke checker selanjutnya
    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}