#pragma once
#include "RewardTiming.h"

class RuntimeSessionState; 

class RewardCommand {
public:
    virtual ~RewardCommand() = default;

    virtual void execute(RuntimeSessionState& session) = 0;

    virtual RewardTiming getTiming() const = 0;
};