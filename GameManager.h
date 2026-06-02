#pragma once
#include "hand.h"
#include "Deck.h"
#include "HandGenerator.h"
#include "RuntimeSessionState.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "JokerManager.h"
#include "ShopSystem.h"

class GameManager {
public:
    GameManager();
    void startInteractiveSession();
    void playBlind();
    void skipBlind();
    void updateGameState();

    int numCards = 8;

private:
    Hand persistentHand;
    Deck gameDeck;
    HandGenerator handGenerator;
    RuntimeSessionState sessionState;
    HandPlayer playerInterface;
    ScoringRule scoringSystem;
    JokerManager jokerManager;
    ShopSystem shopSystem;
    int handCounter = 0;
};