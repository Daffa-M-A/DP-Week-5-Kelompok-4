#include <iostream>
#include "PairChecker.h"
// dummy helper
bool isPair(const Hand& hand){

return hand.value == 2;
}
HandRank PairChecker::check(const Hand& hand){
if (isPair(hand)){
std::cout << "Detected PAIR\n";
return HandRank::PAIR;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}