#include <iostream>
#include <map>
#include "ThreeOfAKindChecker.h"

HandRank ThreeOfAKindChecker::check(const Hand& hand) {
    std::map<int, int> rankCount;
    
    // Hitung kemunculan setiap kartu
    for (const auto& card : hand.cards) {
        rankCount[card.rank]++;
    }

    bool hasThreeOfAKind = false;
    
    // Cek apakah ada kartu yang kembar tiga
    for (const auto& count : rankCount) {
        if (count.second >= 3) {
            hasThreeOfAKind = true;
            break; // Kembar tiga ditemukan, berhenti mencari
        }
    }

    // KEPUTUSAN: Apakah ketemu Three of a Kind?
    if (hasThreeOfAKind) {
        std::cout << "Detected THREE OF A KIND\n";
        return HandRank::THREE_OF_A_KIND;
    }

    // JIKA GAGAL: Lempar ke checker selanjutnya (misal: TwoPairChecker)
    if (nextChecker) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}