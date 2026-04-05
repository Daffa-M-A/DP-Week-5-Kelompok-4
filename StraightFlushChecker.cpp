#include <iostream>
#include "StraightFlushChecker.h"
// dummy helper
bool isStraightFlush(const Hand& hand){

return hand.value == 2;
}
HandRank StraightFlushChecker::check(const Hand& hand){
if (isStraightFlush(hand)){
std::cout << "Detected STRAIGHT FLUSH\n";
return HandRank::STRAIGHT_FLUSH;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}