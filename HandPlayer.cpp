#include "HandPlayer.h"
#include <iostream>
#include <algorithm>

void HandPlayer::playHand(const Hand &availableHand) {
    // 1. Reset pilihan sebelumnya agar tidak menumpuk
    selectedCards.clear();

    std::cout << "\n=== MODE PEMILIHAN KARTU ===\n";
    std::cout << "Pilih indeks kartu (0 - " << availableHand.cards.size() - 1 << ")\n";
    std::cout << "Ketik -1 jika sudah selesai.\n";

    int choice;
    while (true) {
        std::cout << "Masukkan Indeks: ";
        
        // Validasi: Cek apakah input berupa angka
        if (!(std::cin >> choice)) {
            std::cout << "Input harus angka!\n";
            std::cin.clear(); // Bersihkan status error
            std::cin.ignore(1000, '\n'); // Buang input yang salah
            continue;
        }

        if (choice == -1) break;

        // Validasi: Cek jangkauan indeks
        if (choice >= 0 && choice < (int)availableHand.cards.size()) {
            selectedCards.push_back(availableHand.cards[choice]);
            std::cout << "Berhasil menambahkan kartu ke-index " << choice << "\n";
        } else {
            std::cout << "Indeks tidak tersedia!\n";
        }
    }

    // 2. Bungkus vector hasil pilihan ke dalam objek finalHand
    // Asumsi: Constructor Hand menerima (id, vector_card)
    finalHand = Hand{1, selectedCards};
    
    std::cout << "Selesai! " << selectedCards.size() << " kartu telah dipilih.\n";
}