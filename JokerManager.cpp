#include "JokerManager.h"
#include "ConcreteJoker.h"
#include <iostream> 

void JokerManager::addJoker(const std::string& name) {
    if (name == "Add Chips Joker") equipJoker(new AddChipsJoker());
    else if (name == "Pair Joker") equipJoker(new PairJoker());
    else if (name == "Diamond Joker") equipJoker(new DiamondJoker());
    else std::cout << "[JokerManager] [ERROR] Joker '" << name << "' tidak dikenali!\n";
}

void JokerManager::equipJoker(Joker* joker) {
    if (joker != nullptr) {
        activeJokers.push_back(joker);
        std::cout << "[SYSTEM] " << joker->getName() << " berhasil dipasang.\n";
    }
}

int JokerManager::calculateFinalScore(const Hand& playedHand, int baseChips, int baseMult) {
    ScoreContext context(playedHand, baseChips, baseMult);

    std::cout << "\n--- MEMULAI EVALUASI JOKER ---\n";
    for (Joker* joker : activeJokers) {
        joker->onEvaluateScore(context);
    }

    int finalScore = context.chips * context.mult;

    std::cout << "-----------------------------------\n";
    std::cout << "FINAL SCORE : " << finalScore << "\n\n";

    return finalScore;
}

JokerManager::~JokerManager() {
    for (Joker* j : activeJokers) {
        delete j;
    }
    activeJokers.clear();
}