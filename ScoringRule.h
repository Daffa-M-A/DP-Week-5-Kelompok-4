#pragma once
#include "Hand.h"
#include "PokerHandChecker.h"
#include "HighCardChecker.h"
#include "PairChecker.h"
#include "TwoPairChecker.h"
#include "ThreeOfAKindChecker.h"
#include "StraightChecker.h"
#include "FlushChecker.h"
#include "FullHouseChecker.h"
#include "FourOfAKindChecker.h"
#include "StraightFlushChecker.h"
#include "RoyalFlushChecker.h"
#include "FiveOfAKindChecker.h"
#include "FlushHouseChecker.h"
#include "FlushFiveChecker.h"

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
FlushHouseChecker flushFiveChecker;
FlushFiveChecker flushFiveChecker;

int convertRankToScore(HandRank rank);
};