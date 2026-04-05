#include <iostream>
#include "FlushFiveChecker.h"
// dummy helper
bool isFlushFive(const Hand& hand){
return hand.value == 6;
}
HandRank FlushFiveChecker::check(const Hand& hand){
if (isFlushFive(hand)){
std::cout << "Detected FLUSH FIVE\n";
return HandRank::FLUSH_FIVE;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}