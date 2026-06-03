#pragma once
#include "RewardCommand.h"
#include "RuntimeSessionState.h"
#include "Suit.h"
#include <iostream>
#include <random>
#include <chrono>

class BonusHandCommand : public RewardCommand {
public:
    void execute(RuntimeSessionState& session) override {
        std::cout << "[REWARD EXECUTED] Mengaktifkan Bonus Hand! Pemain mendapatkan +1 jatah bermain.\n";
        session.addRemainingPlays(1); 
    }

    RewardTiming getTiming() const override {
        return RewardTiming::NextBlind; 
    }
};

class FreePlayingCardCommand : public RewardCommand {
private:
    std::string cardName;
public:
    FreePlayingCardCommand(std::string card) : cardName(card) {}

    void execute(RuntimeSessionState& session) override {
        // Setup random generator
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 gen(seed);
        std::uniform_int_distribution<> rankDist(2, 14);
        std::uniform_int_distribution<> suitDist(0, 3);

        int randomRank = rankDist(gen);
        char suits[] = {SUIT_SPADES, SUIT_HEARTS, SUIT_CLUBS, SUIT_DIAMONDS};
        char randomSuit = suits[suitDist(gen)];

        Card bonusCard{randomRank, randomSuit};
        std::cout << "[REWARD EXECUTED] Kartu gratis '" << bonusCard.toString() << "' berhasil disuntikkan ke dalam Deck pemain!\n";
        
        session.addExtraCard(bonusCard);
    }

    RewardTiming getTiming() const override {
        return RewardTiming::Start; 
    }
};