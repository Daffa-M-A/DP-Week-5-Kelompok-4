#include <iostream>
#include "BlindRule.h"

// Fungsi untuk mengecek apakah score pemain memenuhi syarat target score yang dinamis
bool BlindRule::checkBlind(int score) 
{
    // Mengambil target score saat ini (berdasarkan state)
    int targetScore = getTargetScore();

    std::cout << "Checking blind requirement (Target: " << targetScore << ")...\n";

    // Mengecek score pemain terhadap targetScore dinamis, bukan hardcoded angka 5 lagi
    if (score >= targetScore)
    {
        std::cout << "Result: WIN\n";
        return true;
    }

    std::cout << "Result: LOSE\n";
    return false;
}

// Fungsi untuk mendapatkan nama string dari status Blind saat ini
std::string BlindRule::getBlindName()
{
    switch (currentState)
    {
        case BlindState::SmallBlind:
            return "SMALL BLIND";
            
        case BlindState::BigBlind:
            return "BIG BLIND";
            
        case BlindState::BossBlind:
            return "BOSS BLIND";
            
        default:
            return "UNKNOWN";
    }
}

// FUNGSI TAMBAHAN: Menentukan target score berdasarkan currentState
int BlindRule::getTargetScore()
{
    switch (currentState)
    {
        case BlindState::SmallBlind:
            return 300;   // Target score untuk Small Blind
            
        case BlindState::BigBlind:
            return 450;   // Target score untuk Big Blind
            
        case BlindState::BossBlind:
            return 600;   // Target score untuk Boss Blind
            
        default:
            return 0;
    }
}