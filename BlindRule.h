#ifndef BLINDRULE_H
#define BLINDRULE_H

#include <string>

// Pastikan enum class ini sudah ada di atas kelas BlindRule
enum class BlindState {
    SmallBlind,
    BigBlind,
    BossBlind
};

class BlindRule {
private:
    // SOLUSI ERROR 3: Daftarkan currentState di sini agar dikenali di file .cpp
    BlindState currentState; 

public:
    // Constructor (Jika kamu menggunakannya untuk set awal currentState)
    BlindRule(BlindState state); 

    bool checkBlind(int score);
    std::string getBlindName();

    // SOLUSI ERROR 1 & 2: Daftarkan getTargetScore di sini
    int getTargetScore(); 
};

#endif