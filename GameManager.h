#pragma once
#include "hand.h"
#include "HandGenerator.h"
#include "BlindRule.h"

class GameManager {
public:
    void runSession();
    void updateGameState();

    int numCards = 5;  // ← tambahkan baris ini

private:
    HandGenerator handGenerator;
    BlindRule blindRule;
    int handCounter = 0;
};