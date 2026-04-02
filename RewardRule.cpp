#include <iostream>
#include "RewardRule.h"
int RewardRule::earnMoney(bool win, int score)
{
std::cout << "Calculating reward...\n";
if (win)
{
return score;

}
return 0;
}