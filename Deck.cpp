#include "Deck.h"
#include "Suit.h"
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>

Deck::Deck() {
    resetAndShuffle();
}

void Deck::resetAndShuffle() {
    cards.clear();
    char availableSuits[] = {SUIT_SPADES, SUIT_HEARTS, SUIT_CLUBS, SUIT_DIAMONDS};
    
    for (char suit : availableSuits) {
        for (int rank = 2; rank <= 14; ++rank) { 
            cards.push_back(Card{rank, suit});
        }
    }

    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    
    std::cout << "[Deck Info] Deck telah di-reset dan di-shuffle (52 Kartu).\n";
}

Card Deck::drawCard() {
    
    if (cards.empty()) {
        std::cout << "[Deck Warning] Kartu habis! Melakukan reset Deck otomatis.\n";
        resetAndShuffle();
    }
    
    
    Card drawn = cards.back();
    cards.pop_back();
    return drawn;
}

int Deck::getRemainingCards() const {
    return cards.size();
}

void Deck::addCard(Card card) {
    cards.push_back(card);
}