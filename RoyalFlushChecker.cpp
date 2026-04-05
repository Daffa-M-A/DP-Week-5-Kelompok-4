#include <iostream>
#include "RoyalFlushChecker.h"
// dummy helper
bool isRoyalFlush(const Hand& hand){

return hand.value == 2;
}
HandRank RoyalFlushChecker::check(const Hand& hand){
if (isRoyalFlush(hand)){
std::cout << "Detected ROYAL FLUSH\n";
return HandRank::ROYAL_FLUSH;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}