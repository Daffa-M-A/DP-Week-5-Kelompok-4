#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "HandGenerator.h"

Hand HandGenerator::generateHand()
{
    std::cout << "Generating random hand from 52 cards deck...\n";

    // 1. Definisikan lambang (Suit) yang digunakan
    char suits[] = {'S', 'H', 'C', 'D'}; // Spade, Heart, Clover, Diamond
    
    // 2. Buat seluruh dek (52 kartu)
    std::vector<Card> deck;
    for (char suit : suits) {
        for (int rank = 1; rank <= 14; ++rank) {
            deck.push_back({rank, suit});
        }
    }

    // 3. Acak seluruh deck menggunakan Mersenne Twister engine
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));

    // 4. Ambil 5 kartu teratas untuk hand pemain
    Hand hand;
    for (int i = 0; i < 5; ++i) {
        hand.cards.push_back(deck[i]);
    }

    // Tampilkan hasil kartu yang di-generate ke console
    std::cout << "Selected Hand Cards:\n";
    for (const auto& card : hand.cards) {
        std::cout << "Rank: " << card.rank << ", Suit: " << card.suit << "\n";
    }

    return hand;
}
