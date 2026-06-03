#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "RewardCommand.h"
#include "BlindRule.h"
#include "ShopData.h"
#include "Card.h"

class RuntimeSessionState {
private:
    int currentAnte = 1;
    int remainingPlays = 4;
    int remainingDiscards = 3;
    int totalScore = 0;
    Money playerMoney{4}; // Start with $4
    
    std::unique_ptr<BlindState> currentBlind;
    std::vector<std::unique_ptr<RewardCommand>> pendingCommands;
    std::vector<Card> extraCardsToInject;

public:
    
    int getCurrentAnte() const { return currentAnte; }
    int getRemainingPlays() const { return remainingPlays; }
    int getRemainingDiscards() const { return remainingDiscards; }
    int getTotalScore() const { return totalScore; }
    Money& getPlayerMoney() { return playerMoney; }

    
    void incrementAnte() { currentAnte++; }

    void resetForNewBlind() {
        remainingPlays = 4;
        remainingDiscards = 3;
        std::cout << "[RuntimeState] State di-reset untuk Blind baru (Plays: 4, Discards: 3).\n";
    }
    
    void addRemainingPlays(int amount) {
        remainingPlays += amount;
        std::cout << "[RuntimeState] Jatah memutar kartu (plays) ditambah: " << amount << ". Total plays: " << remainingPlays << "\n";
    }

    void addExtraCard(Card card) {
        extraCardsToInject.push_back(card);
    }

    std::vector<Card> getAndClearExtraCards() {
        std::vector<Card> cards = std::move(extraCardsToInject);
        extraCardsToInject.clear();
        return cards;
    }

    void addScore(int amount) {
        totalScore += amount;
        std::cout << "[RuntimeState] Skor bertambah " << amount << ". Total: " << totalScore << "\n";
    }

    void resetScore() {
        totalScore = 0;
    }

    void usePlay() {
        if (remainingPlays > 0) remainingPlays--;
    }

    bool useDiscard() {
        if (remainingDiscards > 0) {
            remainingDiscards--;
            return true;
        }
        std::cout << "[RuntimeState] Jatah Discard sudah habis!\n";
        return false;
    }

    
    BlindState* getCurrentBlind() const {
        return currentBlind.get();
    }

    void setCurrentBlind(std::unique_ptr<BlindState> newBlind) {
        currentBlind = std::move(newBlind);
    }

    
    void storeCommand(std::unique_ptr<RewardCommand> command) {
        if (command != nullptr) {
            pendingCommands.push_back(std::move(command));
            std::cout << "[RuntimeState] Reward Command berhasil disimpan ke dalam antrean.\n";
        }
    }

    void checkAndExecuteCommands(RewardTiming timing) {
        for (auto it = pendingCommands.begin(); it != pendingCommands.end(); ) {
            if ((*it)->getTiming() == timing) {
                (*it)->execute(*this);
                it = pendingCommands.erase(it);
            } else {
                ++it;
            }
        }
    }
};