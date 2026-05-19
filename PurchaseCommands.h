// PurchaseCommands.h
#pragma once
#include "GameSystemsMock.h"
#include <string>
#include <utility>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

// Command untuk menambah kartu Joker
class BuyJokerCommand : public Command {
private:
    JokerManager& manager;
    std::string jokerName;
public:
    BuyJokerCommand(JokerManager& mgr, std::string name) 
        : manager(mgr), jokerName(std::move(name)) {}

    void execute() override {
        manager.addJoker(jokerName);
    }
};

// Command untuk upgrade Poker Hand (Planet Card)
class UpgradeHandCommand : public Command {
private:
    HandScoreTable& table;
    std::string handType;
    int mult;
    int chips;
public:
    UpgradeHandCommand(HandScoreTable& tbl, std::string hand, int m, int c) 
        : table(tbl), handType(std::move(hand)), mult(m), chips(c) {}
    
    void execute() override {
        table.upgradeHand(handType, mult, chips);
    }
};

// Command untuk memodifikasi Deck kartu biasa (Tarot Card)
class ModifyDeckCommand : public Command {
private:
    Deck& deck;
    std::string cardToAdd;
public:
    ModifyDeckCommand(Deck& dk, std::string card) 
        : deck(dk), cardToAdd(std::move(card)) {}

    void execute() override {
        deck.addCardToDeck(cardToAdd);
    }
};