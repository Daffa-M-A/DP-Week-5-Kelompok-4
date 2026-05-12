#include "HandPlayer.h"
#include <iostream>
#include <algorithm>
#include <vector>

void HandPlayer::playHand(const Hand &availableHand) {
    selectedCards.clear();
    
    std::vector<int> chosenIndices; 

    std::cout << "PEMILIHAN KARTU\n";
    std::cout << "Kartu di tanganmu saat ini:\n";
    for (int i = 0; i < (int)availableHand.cards.size(); ++i) {
        std::cout << "[" << i << "] " << availableHand.cards[i].toString() << "\n";
    }
    std::cout << "-----------------------------------\n";

    std::cout << "Pilih indeks kartu (0 - " << availableHand.cards.size() - 1 << ")\n";
    std::cout << "Maksimal 5 kartu. Ketik -1 jika sudah selesai lebih awal.\n";

    int choice;
    
    while (selectedCards.size() < 5) { 
        std::cout << "\nMasukkan Indeks (terpilih " << selectedCards.size() << "/5): ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Input tidak valid! Harap masukkan angka.\n";
            std::cin.clear(); 
            std::cin.ignore(1000, '\n'); 
            continue;
        }

        if (choice == -1) break;

        if (choice >= 0 && choice < (int)availableHand.cards.size()) {
            
            if (std::find(chosenIndices.begin(), chosenIndices.end(), choice) != chosenIndices.end()) {
                std::cout << "Kartu di indeks [" << choice << "] sudah kamu pilih! Silakan pilih yang lain.\n";
            } else {
                selectedCards.push_back(availableHand.cards[choice]);
                chosenIndices.push_back(choice);
                
                std::cout << "=> Menambahkan " << availableHand.cards[choice].toString() << " ke dalam pilihanmu.\n";
            }
            
        } else {
            std::cout << "Indeks di luar batas! Masukkan angka antara 0 sampai " << availableHand.cards.size() - 1 << ".\n";
        }
    }

    finalHand = Hand{1, selectedCards};
    
    std::cout << "\n=== PEMILIHAN SELESAI ===\n";
    std::cout << "Kamu telah mengamankan " << selectedCards.size() << " kartu untuk dievaluasi oleh sistem.\n";
}

void HandPlayer::showSelected() const {
    if (selectedCards.empty()) {
        std::cout << "Belum ada kartu yang dipilih.\n";
        return;
    }

    std::cout << "\nKartu yang akan kamu mainkan:\n";
    for (const auto& card : selectedCards) {
        std::cout << "- " << card.toString() << "\n";
    }
}