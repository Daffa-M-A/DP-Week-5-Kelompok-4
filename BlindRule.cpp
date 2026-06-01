#pragma once
#include <string>

enum class BlindState {
    SmallBlind,
    BigBlind,
    BossBlind
};

class BlindRule {
public:
    int currentAnte = 1;
    BlindState currentState = BlindState::SmallBlind;

    // Tambahkan ini
    bool checkBlind(int score);

    std::string getBlindName() {
        switch (currentState) {
            case BlindState::SmallBlind: return "SMALL BLIND";
            case BlindState::BigBlind:   return "BIG BLIND";
            case BlindState::BossBlind:  return "BOSS BLIND";
            default:                     return "UNKNOWN";
        }
    }
};