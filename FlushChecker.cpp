#include <iostream>
#include "FlushChecker.h"
// dummy helper
bool isFlush(const Hand& hand){
return hand.value == 6;
}
HandRank FlushChecker::check(const Hand& hand){
if (isFlush(hand)){
std::cout << "Detected FLUSH\n";
return HandRank::FLUSH;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}