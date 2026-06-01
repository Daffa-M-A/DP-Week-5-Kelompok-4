#pragma once
#include <string>

// Enum untuk menentukan jenis Blind
enum class BlindState {
    SmallBlind,
    BigBlind,
    BossBlind
};

// Class BlindRule
class BlindRule {
public:

    // Nilai ante saat ini
    int currentAnte = 1;

    // State awal Blind adalah SmallBlind
    BlindState currentState = BlindState::SmallBlind;

    // Fungsi untuk mendapatkan nama Blind dalam bentuk teks
    std::string getBlindName() {

        // Mengecek state Blind saat ini
        switch (currentState) {

            case BlindState::SmallBlind:
                return "SMALL BLIND";

            case BlindState::BigBlind:
                return "BIG BLIND";

            case BlindState::BossBlind:
                return "BOSS BLIND";

            default:
                return "UNKNOWN";
        }
    }
};