#pragma once
#include "Card.h"  // PENTING: Harus include Card.h agar kenal class Card
#include <vector>

// 1. Definisikan dulu apa itu "Hand" (Tangan)
// Jika kamu sudah punya struct Hand di file lain, pastikan include-nya benar.
// Jika belum, kamu bisa mendefinisikannya seperti ini:
struct Hand {
    int id;
    std::vector<Card> cards;
};

// 2. Baru definisikan HandPlayer yang menggunakan Hand
class HandPlayer {
private:
    Hand finalHand; 
    std::vector<Card> selectedCards;

public:
    // Gunakan "Hand" di sini (sekarang sudah tidak undefined)
    void playHand(const Hand &availableHand);

    void showSelected() const;

    Hand getChosenHand() const { 
        return finalHand; 
    }
};