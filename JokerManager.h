#pragma once
#include "Joker.h"
#include <vector>

class JokerManager {
private:
    std::vector<Joker*> activeJokers;

public:
    void equipJoker(Joker* joker);
    void addJoker(const std::string& name);
    int calculateFinalScore(const Hand& playedHand, int baseChips, int baseMult);
    ~JokerManager();
};