#include "GameManager.h"  // PENTING: Ini baris kunci agar eror "undefined" hilang!
#include <iostream>

// FUNGSI UTAMA: Menjalankan jalannya sesi ronde game (PLAY Blind)
void GameManager::runSession() {
    
    // 1. GENERATE KARTU: Memanggil objek handGenerator
    // Menggunakan variabel handCounter sebagai ID unik, lalu meminta dibuatkan 5 kartu acak
    Hand currentHand = handGenerator.generateRandomHand(handCounter++, numCards);
    // 2. TAMPILKAN KARTU: Membaca isi list kartu hasil generate dan mencetaknya ke layar
    std::cout << "[Manager Info]: Kartu berhasil dibagikan ke tangan:\n";
    for (const auto& card : currentHand.cards) {
        std::cout << "  - Kartu Rank [" << card.rank << "] Lambang [" << card.suit << "]\n";
    }

    // 3. CETAK STATUS: Mengambil nama string ronde aktif (Small/Big/Boss) dari objek blindRule
    std::cout << "Status: Sesi " << blindRule.getBlindName() << " Selesai Dimainkan!\n";

    // 4. UPDATE STATUS: Memanggil fungsi internal untuk mengubah ronde ke tahap selanjutnya
    updateGameState();
}

// FUNGSI INTERNAL: Mengatur alur panah otomatis (Small -> Big -> Boss -> Next Ante)
void GameManager::updateGameState() {
    // Mengecek 'currentState' yang berada di dalam objek blindRule 
    switch (blindRule.currentState) {
        
        case BlindState::SmallBlind:
            // Selesai Small Blind, status di dalam objek blindRule diganti ke Big Blind
            blindRule.currentState = BlindState::BigBlind;
            std::cout << "[Sistem Log]: Berhasil melewati Small Blind. Target berikutnya: Big Blind.\n";
            break;

        case BlindState::BigBlind:
            // Selesai Big Blind, status di dalam objek blindRule diganti ke Boss Blind
            blindRule.currentState = BlindState::BossBlind;
            std::cout << "[Sistem Log]: Berhasil melewati Big Blind. Target berikutnya: Boss Blind!\n";
            break;

        case BlindState::BossBlind:
            // Selesai Boss Blind (Siklus Ante selesai). Naikkan level Ante dan reset ronde ke awal
            std::cout << "[Sistem Log]: Boss Blind Dikalahkan! Siklus Ante " << blindRule.currentAnte << " Selesai.\n";
            
            blindRule.currentAnte++;                         // Level Ante bertambah 1 (misal Ante 1 jadi Ante 2)
            blindRule.currentState = BlindState::SmallBlind; // Reset status balik ke Small Blind lagi
            
            std::cout << "\n>>> SIKLUS MANAGER: KINI NAIK KE LEVEL ANTE " << blindRule.currentAnte << " <<<\n";
            break;
    }
}