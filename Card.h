#pragma once
#include "Rank.h"
#include "Suit.h"
#include <string>

struct Card {
    int rank;  
    char suit; 

    Card(int r, char s) : rank(r), suit(s) {}

    std::string toString() const;
};