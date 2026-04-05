#pragma once
#include "PokerHandChecker.h"
class FullHouseChecker : public PokerHandChecker{
public:
HandRank check(const Hand& hand) override;
};