#pragma once
#include "Card.h"  
#include <vector>

struct Hand {
    int id;
    std::vector<Card> cards;
};