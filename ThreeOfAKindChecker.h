#pragma once
#include "PokerHandChecker.h"
class ThreeOfAKindChecker : public PokerHandChecker{
public:
HandRank check(const Hand& hand) override;
};