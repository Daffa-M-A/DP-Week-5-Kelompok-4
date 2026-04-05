#include <iostream>
#include "FullHouseChecker.h"
// dummy helper
bool isFullHouse(const Hand& hand){
return hand.value == 6;
}
HandRank FullHouseChecker::check(const Hand& hand){
if (isFullHouse(hand)){
std::cout << "Detected FULL HOUSE\n";
return HandRank::FULL_HOUSE;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}