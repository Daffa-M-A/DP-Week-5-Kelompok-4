#pragma once
#include "Hand.h"
#include "PokerHandChecker.h"
#include "HighCardChecker/HighCardChecker.h"
#include "PairChecker/PairChecker.h"
#include "TwoPairChecker/TwoPairChecker.h"
#include "ThreeOfAKindChecker/ThreeOfAKindChecker.h"
#include "StraightChecker/StraightChecker.h"
#include "FlushChecker/FlushChecker.h"
#include "FullHouseChecker/FullHouseChecker.h"
#include "FourOfAKindChecker/FourOfAKindChecker.h"
#include "StraightFlushChecker/StraightFlushChecker.h"
#include "RoyalFlushChecker/RoyalFlushChecker.h"
#include "FiveOfAKindChecker/FiveOfAKindChecker.h"
#include "FlushHouseChecker/FlushHouseChecker.h"
#include "FlushFiveChecker/FlushFiveChecker.h"

class ScoringRule{
public:
ScoringRule();
int scoreHand(const Hand& hand);
private:
HighCardChecker highCardChecker;
PairChecker pairChecker;
TwoPairChecker twoPairChecker;
ThreeOfAKindChecker threeOfAKindChecker;
StraightChecker straightChecker;
FlushChecker flushChecker;
FullHouseChecker fullHouseChecker;
FourOfAKindChecker fourOfAKindChecker;
StraightFlushChecker straightFlushChecker;
RoyalFlushChecker royalFlushChecker;
FiveOfAKindChecker fiveOfAKindChecker;
FlushHouseChecker flushHouseChecker;
FlushFiveChecker flushFiveChecker;

int convertRankToScore(HandRank rank);
};