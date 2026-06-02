#pragma once
#include "hand.h"
#include "Deck.h"

class HandGenerator {
public:
    
    Hand generateHand(Deck& deck, int id, int numCards);
};