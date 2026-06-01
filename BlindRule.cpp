#include <iostream>
#include "BlindRule.h"

bool BlindRule::checkBlind(int score)  // digunakan untuk mengecek apakah score pemain
                                       // memenuhi syarat untuk memenangkan Blind.
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

std::string BlindRule::getBlindName()
{
    switch (currentState)
    {
        case BlindState::SmallBlind:
            return "SMALL BLIND";

        case BlindState::BigBlind:
            return "BIG BLIND";

        case BlindState::BossBlind:
            return "BOSS BLIND";

        default:
            return "UNKNOWN";
    }
}