#pragma once
#include "Hand.h"
#include <vector>

class HandPlayer {
private:
    // Menggunakan objek Hand untuk menyimpan hasil akhir pemilihan
    Hand finalHand; 
    // Vector sementara untuk menampung kartu saat proses pemilihan
    std::vector<Card> selectedCards;

public:
    // Fungsi untuk memulai proses pemilihan
    void playHand(const Hand &availableHand);

    // Menampilkan kartu yang sudah dipilih (mirip displayHand di image_d4c0b8.png)
    void showSelected() const;

    // Getter untuk mengambil objek Hand hasil pilihan
    Hand getChosenHand() const { return finalHand; }
};