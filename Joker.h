#pragma once
#include "ScoreContext.h"
#include <string>

class Joker {
protected:
    std::string name;

public:
    Joker(std::string jokerName) : name(jokerName) {}
    virtual ~Joker() = default; 

    std::string getName() const { return name; }

    virtual void onEvaluateScore(ScoreContext& context) = 0;
};