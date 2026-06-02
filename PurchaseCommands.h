
#pragma once
#include "JokerManager.h"
#include <string>
#include <utility>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};


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