#include "Card.h"
#include <string>

std::string Card::toString() const {
    std::string rankStr;
    std::string suitStr;

    if (rank >= 2 && rank <= 10) {
        rankStr = std::to_string(rank);
    } else {
        switch (rank) {
            case 11: rankStr = "Jack"; break;
            case 12: rankStr = "Queen"; break;
            case 13: rankStr = "King"; break;
            case 14: rankStr = "Ace"; break;
            default: rankStr = "Unknown"; break;
        }
    }

    switch (suit) {
        case 'S': suitStr = "Spades"; break;
        case 'H': suitStr = "Hearts"; break;
        case 'C': suitStr = "Clubs"; break;
        case 'D': suitStr = "Diamonds"; break;
        default: suitStr = "Unknown"; break;
    }

    return rankStr + " of " + suitStr;
}