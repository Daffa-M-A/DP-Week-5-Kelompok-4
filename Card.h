#pragma once
#include "Rank.h"
#include "Suit.h"
#include <string>

struct Card {
    // Menggunakan tipe data dari header yang kamu include
    Rank rank; 
    Suit suit;

    // Constructor agar mudah membuat objek Card
    Card(Rank r, Suit s) : rank(r), suit(s) {}

    // Fungsi untuk mendapatkan nama kartu dalam bentuk string (misal: "Ace of Spades")
    std::string toString() const;
};