#pragma once
#include "PokerHandChecker.h"
class PairChecker : public PokerHandChecker{
public:
HandRank check(const Hand& hand) override;
};