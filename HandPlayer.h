#pragma once
#include "Hand.h"
#include <vector>

class HandPlayer {
private:
    Hand finalHand; 
    std::vector<Card> selectedCards;

public:
    void playHand(const Hand &availableHand);

    void showSelected() const;

    Hand getChosenHand() const { return finalHand; }
};