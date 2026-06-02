#include "HandGenerator.h"

Hand HandGenerator::generateHand(Deck& deck, int id, int numCards) {
    std::vector<Card> drawnCards;
    
    
    
    for (int i = 0; i < numCards; ++i) {
        drawnCards.push_back(deck.drawCard());
    }

    return Hand{id, drawnCards};
}