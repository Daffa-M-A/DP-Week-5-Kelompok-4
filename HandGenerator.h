#pragma once
#include "hand.h" // Agar HandGenerator tahu apa itu 'Hand'

class HandGenerator {
public:
    // Fungsi untuk membuat Tangan berisi kartu acak
    // id: nomor identitas tangan, numCards: jumlah kartu yang mau dibuat
    static Hand generateRandomHand(int id, int numCards);
};