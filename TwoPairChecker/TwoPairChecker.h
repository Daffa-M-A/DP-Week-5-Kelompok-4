#pragma once
#include "PokerHandChecker.h"
class TwoPairChecker : public PokerHandChecker{
public:
HandRank check(const Hand& hand) override;
};