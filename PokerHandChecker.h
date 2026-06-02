#pragma once
#include "hand.h"
enum class HandRank {
HIGH_CARD,
PAIR,
TWO_PAIR,
THREE_OF_A_KIND,
STRAIGHT,
FLUSH,
FULL_HOUSE,
FOUR_OF_A_KIND,
STRAIGHT_FLUSH,
ROYAL_FLUSH,
FIVE_OF_A_KIND,
FLUSH_HOUSE,
FLUSH_FIVE
};
class PokerHandChecker{
public:
virtual ~PokerHandChecker() = default;
virtual HandRank check(const Hand& hand) = 0;
void setNext(PokerHandChecker* next);
protected:
PokerHandChecker* nextChecker = nullptr;
};