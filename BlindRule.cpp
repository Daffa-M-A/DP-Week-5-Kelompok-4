#include "BlindRule.h"
#include "ConcreteCommand.h"
#include "RuntimeSessionState.h"
#include <iostream>


std::string SmallBlindState::getName() const { return "Small Blind"; }
int SmallBlindState::getTargetScore(int currentAnte) const { return 50 * currentAnte; }
int SmallBlindState::getRewardMoney() const { return 3; }
std::unique_ptr<BlindState> SmallBlindState::getNextState(RuntimeSessionState& session) const {
    std::cout << "[Blind Progression] Pindah ke Big Blind.\n";
    return std::make_unique<BigBlindState>();
}

std::unique_ptr<RewardCommand> SmallBlindState::generateSkipReward() const {
    std::cout << "[Skip Reward] Memilih Skip! Membuat Command 'Bonus Hand'.\n";
    return std::make_unique<BonusHandCommand>();
}

std::string BigBlindState::getName() const { return "Big Blind"; }
int BigBlindState::getTargetScore(int currentAnte) const { return 75 * currentAnte; }
int BigBlindState::getRewardMoney() const { return 4; }
std::unique_ptr<BlindState> BigBlindState::getNextState(RuntimeSessionState& session) const {
    std::cout << "[Blind Progression] Pindah ke Boss Blind.\n";
    return std::make_unique<BossBlindState>();
}

std::unique_ptr<RewardCommand> BigBlindState::generateSkipReward() const {
    std::cout << "[Skip Reward] Memilih Skip! Membuat Command 'Free Playing Card'.\n";
    return std::make_unique<FreePlayingCardCommand>("Random Spectral Card");
}

std::string BossBlindState::getName() const { return "Boss Blind"; }
int BossBlindState::getTargetScore(int currentAnte) const { return 100 * currentAnte; }
int BossBlindState::getRewardMoney() const { return 5; }
std::unique_ptr<BlindState> BossBlindState::getNextState(RuntimeSessionState& session) const {
    session.incrementAnte();
    std::cout << "[Blind Progression] Boss Blind dikalahkan! Ante naik menjadi " 
              << session.getCurrentAnte() << ". Kembali ke Small Blind.\n";
    return std::make_unique<SmallBlindState>();
}

std::unique_ptr<RewardCommand> BossBlindState::generateSkipReward() const {
    std::cout << "[Skip Reward] Boss Blind dilewati (Hanya test command).\n";
    return std::make_unique<BonusHandCommand>();
}