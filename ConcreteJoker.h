#pragma once
#include "Joker.h"
#include "Suit.h" 
#include <iostream>

class AddChipsJoker : public Joker {
public:
    AddChipsJoker() : Joker("Add Chips Joker") {}

    void onEvaluateScore(ScoreContext& context) override {
        context.chips += 80;
        std::cout << "[" << name << "] Aktif! +80 Chips.\n";
    }
};


class PairJoker : public Joker {
public:
    PairJoker() : Joker("Pair Joker") {}

    void onEvaluateScore(ScoreContext& context) override {
        bool hasPair = false;
        const auto& cards = context.playedHand.cards;
        
        for (size_t i = 0; i < cards.size(); ++i) {
            for (size_t j = i + 1; j < cards.size(); ++j) {
                if (cards[i].rank == cards[j].rank) {
                    hasPair = true;
                    break;
                }
            }
            if (hasPair) break;
        }

        if (hasPair) {
            context.mult += 15; 
            std::cout << "[" << name << "] Joker mendeteksi pair, +15 Mult.\n";
        }
    }
};

class DiamondJoker : public Joker {
public:
    DiamondJoker() : Joker("Diamond Joker") {}

    void onEvaluateScore(ScoreContext& context) override {
        int diamondCount = 0;
        
        for (const auto& card : context.playedHand.cards) {
            if (card.suit == SUIT_DIAMONDS) {
                diamondCount++;
            }
        }

        if (diamondCount > 0) {
            context.mult += (diamondCount * 4);
            std::cout << "[" << name << "] Aktif Menghitung " << diamondCount 
                      << " kartu Diamond. +" << (diamondCount * 4) << " Mult.\n";
        }
    }
};