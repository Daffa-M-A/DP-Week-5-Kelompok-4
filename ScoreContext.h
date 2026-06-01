#pragma once
#include "hand.h"

struct ScoreContext {
    const Hand& playedHand;
    int chips;
    int mult;

    ScoreContext(const Hand& hand, int baseChips, int baseMult) 
        : playedHand(hand), chips(baseChips), mult(baseMult) {}
};