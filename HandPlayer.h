#pragma once
#include "hand.h"
#include <vector>

class HandPlayer {
private:
    Hand finalHand; 
    std::vector<Card> selectedCards;
    std::vector<int> chosenIndices;

public:
    void playHand(const Hand &availableHand);

    void showSelected() const;

    Hand getChosenHand() const { return finalHand; }
    std::vector<int> getChosenIndices() const { return chosenIndices; }
};