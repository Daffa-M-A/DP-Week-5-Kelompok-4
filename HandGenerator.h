#pragma once
#include "hand.h"
#include <vector>

class HandGenerator
{
private:
    int nextHandId = 1;

public:
    Hand generateRandomHand(int id, int numCards);
};