#pragma once
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "RewardRule.h"
class GameManager{
public:
void runSession();
private:
HandGenerator handGenerator;
HandPlayer handPlayer;
ScoringRule scoringRule;
BlindRule blindRule;
RewardRule rewardRule;
};