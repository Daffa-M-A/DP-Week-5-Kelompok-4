#include <iostream>
#include "GameManager.h"
#include "ConcreteJoker.h" 

GameManager::GameManager() 
    : shopSystem(jokerManager, handTable, gameDeck), playerWallet(10) {}

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";

    Hand hand = handGenerator.generateRandomHand(8);
    handPlayer.playHand(hand);
    Hand chosenHand = handPlayer.getChosenHand();
    int score = scoringRule.scoreHand(chosenHand, jokerManager);
    bool win = blindRule.checkBlind(score);
    int reward = rewardRule.earnMoney(win, score);
    std::cout << "Money gained from round: $" << reward << "\n";
    
    playerWallet.add(reward);
    
    std::cout << "\nSHOP\n";
    
    std::vector<std::string> itemToStock = {"JOKER_ADDMULT", "JOKER_PAIR", "JOKER_DIAMOND"};
    shopSystem.generateShopFront(itemToStock);
    
    shopSystem.displayShop(playerWallet);
    
    std::cout << "[Player Action] Mencoba membeli item indeks 0...\n";
    shopSystem.buyItem(0, playerWallet);
    
    std::cout << "========================================\n\n";
    std::cout << "=== Run Ended ===\n";
}