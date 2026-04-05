#include <iostream>
#include "TwoPairChecker.h"
// dummy helper
bool isTwoPair(const Hand& hand){

return hand.value == 2;
}
HandRank TwoPairChecker::check(const Hand& hand){
if (isTwoPair(hand)){
std::cout << "Detected TWO PAIR\n";
return HandRank::TWO_PAIR;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}