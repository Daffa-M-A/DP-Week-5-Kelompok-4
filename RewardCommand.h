#pragma once
#include "RewardTiming.h"

class RuntimeSessionState; 

class RewardCommand {
public:
    virtual ~RewardCommand() = default;

    // Mengeksekusi logika atau efek dari reward ke dalam state permainan (RuntimeSessionState).
    virtual void execute(RuntimeSessionState& session) = 0;

    // Mengembalikan waktu (timing) spesifik kapan reward ini harus dieksekusi (contoh: di awal permainan, atau di blind berikutnya).
    virtual RewardTiming getTiming() const = 0;
};