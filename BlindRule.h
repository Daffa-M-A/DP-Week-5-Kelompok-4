#pragma once
#include <string>

enum class BlindState {  /// Enum untuk menyimpan jenis-jenis Blind
    SmallBlind,
    BigBlind,
    BossBlind
};

class BlindRule {  // Class BlindRule digunakan untuk mengatur sistem Blind
public:
    int currentAnte = 1;   // Menyimpan nilai Ante saat ini
    // Nilai awal = 1
    BlindState currentState = BlindState::SmallBlind;   // Menyimpan Blind yang sedang aktif
    // Saat pertama kali dibuat dimulai dari SmallBlind

    bool checkBlind(int score); //fungsi untuk mengecek
    // apakah score pemain memenuhi syarat Blind

    std::string getBlindName();
};