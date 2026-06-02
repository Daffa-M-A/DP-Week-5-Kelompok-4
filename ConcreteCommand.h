#pragma once
#include "RewardCommand.h"
#include "RuntimeSessionState.h"
#include <iostream>

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
        std::cout << "[REWARD EXECUTED] Kartu gratis '" << cardName << "' berhasil disuntikkan ke dalam Deck pemain!\n";
    }

    RewardTiming getTiming() const override {
        return RewardTiming::Start; 
    }
};