#include "BlindRule.h"
#include "ConcreteCommand.h"
#include "RuntimeSessionState.h"
#include <iostream>


// Mengembalikan nama representasi untuk fase Small Blind.
std::string SmallBlindState::getName() const { return "Small Blind"; }

// Mengembalikan target skor yang harus dicapai pada Small Blind, berskala dengan currentAnte.
int SmallBlindState::getTargetScore(int currentAnte) const { return 50 * currentAnte; }

// Mengembalikan jumlah uang hadiah yang didapatkan setelah menyelesaikan Small Blind.
int SmallBlindState::getRewardMoney() const { return 3; }

// Menangani transisi state menuju Big Blind setelah Small Blind diselesaikan.
std::unique_ptr<BlindState> SmallBlindState::getNextState(RuntimeSessionState& session) const {
    std::cout << "[Blind Progression] Pindah ke Big Blind.\n";
    return std::make_unique<BigBlindState>();
}

// Menghasilkan perintah reward (Bonus Hand) jika pemain memilih untuk melewati (skip) Small Blind.
std::unique_ptr<RewardCommand> SmallBlindState::generateSkipReward() const {
    std::cout << "[Skip Reward] Memilih Skip! Membuat Command 'Bonus Hand'.\n";
    return std::make_unique<BonusHandCommand>();
}



// Mengembalikan nama representasi untuk fase Big Blind.
std::string BigBlindState::getName() const { return "Big Blind"; }

// Mengembalikan target skor yang harus dicapai pada Big Blind, berskala dengan currentAnte.
int BigBlindState::getTargetScore(int currentAnte) const { return 75 * currentAnte; }

// Mengembalikan jumlah uang hadiah yang didapatkan setelah menyelesaikan Big Blind.
int BigBlindState::getRewardMoney() const { return 4; }

// Menangani transisi state menuju Boss Blind setelah Big Blind diselesaikan.
std::unique_ptr<BlindState> BigBlindState::getNextState(RuntimeSessionState& session) const {
    std::cout << "[Blind Progression] Pindah ke Boss Blind.\n";
    return std::make_unique<BossBlindState>();
}

// Menghasilkan perintah reward (Free Playing Card) jika pemain memilih untuk melewati (skip) Big Blind.
std::unique_ptr<RewardCommand> BigBlindState::generateSkipReward() const {
    std::cout << "[Skip Reward] Memilih Skip! Membuat Command 'Free Playing Card'.\n";
    return std::make_unique<FreePlayingCardCommand>("Random Spectral Card");
}



// Mengembalikan nama representasi untuk fase Boss Blind.
std::string BossBlindState::getName() const { return "Boss Blind"; }

// Mengembalikan target skor yang harus dicapai pada Boss Blind, berskala dengan currentAnte.
int BossBlindState::getTargetScore(int currentAnte) const { return 100 * currentAnte; }

// Mengembalikan jumlah uang hadiah yang didapatkan setelah mengalahkan Boss Blind.
int BossBlindState::getRewardMoney() const { return 5; }

// Mengatur transisi setelah Boss Blind selesai, yaitu menaikkan level Ante dan me-reset rotasi kembali ke Small Blind.
std::unique_ptr<BlindState> BossBlindState::getNextState(RuntimeSessionState& session) const {
    session.incrementAnte();
    std::cout << "[Blind Progression] Boss Blind dikalahkan! Ante naik menjadi " 
              << session.getCurrentAnte() << ". Kembali ke Small Blind.\n";
    return std::make_unique<SmallBlindState>();
}

// Menghasilkan objek perintah reward standar jika pemain melewati Boss Blind (digunakan untuk testing).
std::unique_ptr<RewardCommand> BossBlindState::generateSkipReward() const {
    std::cout << "[Skip Reward] Boss Blind dilewati (Hanya test command).\n";
    return std::make_unique<BonusHandCommand>();
}