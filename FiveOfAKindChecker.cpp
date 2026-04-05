#include <iostream>
#include "FiveOfAKindChecker.h"
// dummy helper
bool isFiveOfAKind(const Hand& hand){
return hand.value == 6;
}
HandRank FiveOfAKindChecker::check(const Hand& hand){
if (isFiveOfAKind(hand)){
std::cout << "Detected FIVE OF A KIND\n";
return HandRank::FIVE_OF_A_KIND;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}