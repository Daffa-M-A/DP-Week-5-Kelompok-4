#pragma once
#include "Card.h"  
#include <vector>

struct Hand {
    int id;
    std::vector<Card> cards;
};

class HandPlayer {
private:
    Hand finalHand; 
    std::vector<Card> selectedCards;

public:
    void playHand(const Hand &availableHand);

    void showSelected() const;

    Hand getChosenHand() const { 
        return finalHand; 
    }
};