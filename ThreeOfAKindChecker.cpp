#include <iostream>
#include "ThreeOfAKindChecker.h"
// dummy helper
bool isThreeOfAKind(const Hand& hand){

return hand.value == 2;
}
HandRank ThreeOfAKindChecker::check(const Hand& hand){
if (isThreeOfAKind(hand)){
std::cout << "Detected THREE OF A KIND\n";
return HandRank::THREE_OF_A_KIND;
}
if (nextChecker)
return nextChecker->check(hand);
return HandRank::HIGH_CARD;
}