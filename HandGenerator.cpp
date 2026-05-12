#include "HandGenerator.h"
#include "Rank.h" 
#include "Suit.h" 
#include <cstdlib> 
#include <ctime>   

Hand HandGenerator::generateRandomHand(int numCards) {
    std::vector<Card> randomCards;
    char availableSuits[] = {SUIT_SPADES, SUIT_HEARTS, SUIT_CLUBS, SUIT_DIAMONDS};

    for (int i = 0; i < numCards; ++i) {
        int randomRank = (std::rand() % 13) + 2; 
        char randomSuit = availableSuits[std::rand() % 4];
        randomCards.push_back(Card{randomRank, randomSuit});
    }

    int currentId = nextHandId;
    
    nextHandId++;

    return Hand{currentId, randomCards};
}