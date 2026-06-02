#pragma once
#include <string>
#include <memory>
#include "RewardCommand.h"

class RuntimeSessionState; 

class BlindState {
public:
    virtual ~BlindState() = default;

    virtual std::string getName() const = 0;
    virtual int getTargetScore(int currentAnte) const = 0;
    virtual int getRewardMoney() const = 0;

    
    virtual std::unique_ptr<BlindState> getNextState(RuntimeSessionState& session) const = 0;

    
    virtual std::unique_ptr<RewardCommand> generateSkipReward() const = 0;
};

class SmallBlindState : public BlindState {
public:
    std::string getName() const override;
    int getTargetScore(int currentAnte) const override;
    int getRewardMoney() const override;
    std::unique_ptr<BlindState> getNextState(RuntimeSessionState& session) const override;
    std::unique_ptr<RewardCommand> generateSkipReward() const override;
};

class BigBlindState : public BlindState {
public:
    std::string getName() const override;
    int getTargetScore(int currentAnte) const override;
    int getRewardMoney() const override;
    std::unique_ptr<BlindState> getNextState(RuntimeSessionState& session) const override;
    std::unique_ptr<RewardCommand> generateSkipReward() const override;
};

class BossBlindState : public BlindState {
public:
    std::string getName() const override;
    int getTargetScore(int currentAnte) const override;
    int getRewardMoney() const override;
    std::unique_ptr<BlindState> getNextState(RuntimeSessionState& session) const override;
    std::unique_ptr<RewardCommand> generateSkipReward() const override;
};