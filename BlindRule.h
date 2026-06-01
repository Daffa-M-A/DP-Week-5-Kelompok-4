#ifndef BLINDRULE_H
#define BLINDRULE_H

#include <string>

// Status tingkatan Blind di dalam game
enum class BlindState {
    SmallBlind,
    BigBlind,
    BossBlind
};

class BlindRule {
private:
    // Menyimpan status Blind ronde saat ini
    BlindState currentState; 

public:
    // Constructor untuk set status Blind di awal
    BlindRule(BlindState state); 

    // Mengecek apakah skor pemain berhasil mencapai target
    bool checkBlind(int score);

    // Mengambil nama teks dari Blind yang aktif (untuk UI / Log)
    std::string getBlindName();

    // Mengambil target skor minimal yang harus dicapai pemain
    int getTargetScore(); 
};

#endif