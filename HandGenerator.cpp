#include "HandGenerator.h"
#include "Rank.h" // Mengambil RANK_2 sampai RANK_ACE
#include "Suit.h" // Mengambil SUIT_SPADES, dll
#include <cstdlib> // Untuk rand()
#include <ctime>   // Untuk time()

Hand HandGenerator::generateRandomHand(int id, int numCards) {
    std::vector<Card> randomCards;
    
    // Daftar suit yang tersedia berdasarkan konstanta di Suit.h
    char availableSuits[] = {SUIT_SPADES, SUIT_HEARTS, SUIT_CLUBS, SUIT_DIAMONDS};

    for (int i = 0; i < numCards; ++i) {
        // 1. Pilih Rank acak (antara 2 sampai 14/RANK_ACE)
        int randomRank = (std::rand() % 13) + 2; 
        
        // 2. Pilih Suit acak dari array
        char randomSuit = availableSuits[std::rand() % 4];

        // 3. Masukkan ke dalam list kartu
        randomCards.push_back(Card{randomRank, randomSuit});
    }

    // Kembalikan objek Hand yang sudah terisi
    return Hand{id, randomCards};
}