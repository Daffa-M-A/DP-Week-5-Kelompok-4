#include <iostream>
#include "BlindRule.h"
bool BlindRule::checkBlind(int score)
{
std::cout << "Checking blind requirement...\n";
if (score >= 5)
{
std::cout << "Result: WIN\n";
return true;
}
std::cout << "Result: LOSE\n";
return false;
}