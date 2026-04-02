#include <iostream>
#include "ScoringRule.h"
ScoringRule::ScoringRule(){
fullHouseChecker.setNext(&flushChecker);
flushChecker.setNext(&pairChecker);
}
int ScoringRule::scoreHand(const Hand& hand){
std::cout << "Calculating hand score...\n";
HandRank rank = fullHouseChecker.check(hand);
int score = convertRankToScore(rank);
std::cout << "Final score = " << score << "\n";
return score;
}
int ScoringRule::convertRankToScore(HandRank rank){
switch (rank){
case HandRank::FULL_HOUSE:
return 25;
case HandRank::FLUSH:
return 20;
case HandRank::PAIR:
return 10;
case HandRank::HIGH_CARD:
default:
return 5;
}
} 