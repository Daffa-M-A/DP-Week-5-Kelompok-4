#pragma once
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "RewardRule.h"
#include "JokerManager.h"
#include "ShopSystem.h"
#include "ShopData.h" 
#include "GameSystemsMock.h" 

class GameManager {
public:
    GameManager();
    void runSession();

private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    RewardRule rewardRule;
    JokerManager jokerManager;
    HandScoreTable handTable;
    Deck gameDeck;
    ShopSystem shopSystem;
    Money playerWallet; 
};