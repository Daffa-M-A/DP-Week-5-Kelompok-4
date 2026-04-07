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
    case HandRank::FLUSH_FIVE:
    return 65;
    case HandRank::FLUSH_HOUSE:
    return 60;
    case HandRank::FIVE_OF_A_KIND:
    return 55;
    case HandRank::ROYAL_FLUSH:
    return 50;
    case HandRank::STRAIGHT_FLUSH:
    return 45;
    case HandRank::FOUR_OF_A_KIND:
    return 40;
    case HandRank::FULL_HOUSE:
    return 35;
    case HandRank::FLUSH:
    return 30;
    case HandRank::STRAIGHT:
    return 25;
    case HandRank::THREE_OF_A_KIND:
    return 20;
    case HandRank::TWO_PAIR:
    return 15;
    case HandRank::PAIR:
    return 10;
    case HandRank::HIGH_CARD:
    default:
    return 5;
}
} 