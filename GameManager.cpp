#include "GameManager.h"
#include <iostream>
#include <algorithm>

GameManager::GameManager() : shopSystem(jokerManager) {
    sessionState.setCurrentBlind(std::make_unique<SmallBlindState>());
}

void GameManager::startInteractiveSession() {
    bool gameRunning = true;
    while (gameRunning) {
        BlindState* currentBlind = sessionState.getCurrentBlind();
        std::cout << "\n=========================================\n";
        std::cout << ">>> Saat ini berada di: " << currentBlind->getName() << "\n";
        std::cout << ">>> Target Skor: " << currentBlind->getTargetScore(sessionState.getCurrentAnte()) << "\n";
        std::cout << ">>> Uang Hadiah: $" << currentBlind->getRewardMoney() << "\n";
        std::cout << "=========================================\n";
        
        std::cout << "Pilih aksi Anda:\n";
        std::cout << "[1] PLAY BLIND\n";
        std::cout << "[2] SKIP BLIND\n";
        std::cout << "[3] KELUAR GAME\n";
        std::cout << "Pilihan: ";

        int action;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Input tidak valid.\n";
            continue;
        }

        if (action == 1) {
            playBlind();
            if (sessionState.getRemainingPlays() == 0 && sessionState.getTotalScore() < currentBlind->getTargetScore(sessionState.getCurrentAnte())) {
                 std::cout << "\n[GAME OVER] Anda kehabisan jatah Plays!\n";
                 gameRunning = false;
            }
        } else if (action == 2) {
            skipBlind();
        } else if (action == 3) {
            gameRunning = false;
        } else {
            std::cout << "Pilihan tidak ada.\n";
        }
    }
}

void GameManager::playBlind() {
    BlindState* currentBlind = sessionState.getCurrentBlind();
    int targetScore = currentBlind->getTargetScore(sessionState.getCurrentAnte());
    
    bool blindCleared = false;
    
    persistentHand.cards.clear();
    gameDeck.resetAndShuffle();

    sessionState.checkAndExecuteCommands(RewardTiming::Start);
    
    auto extraCards = sessionState.getAndClearExtraCards();
    for (const auto& card : extraCards) {
        gameDeck.addCard(card);
    }

    while (sessionState.getRemainingPlays() > 0 && !blindCleared) {
        std::cout << "\n=== Sisa Plays: " << sessionState.getRemainingPlays() 
                  << " | Sisa Discards: " << sessionState.getRemainingDiscards() << " ===\n";
                  
        int cardsNeeded = numCards - persistentHand.cards.size();
        if (cardsNeeded > 0) {
            Hand newCards = handGenerator.generateHand(gameDeck, handCounter++, cardsNeeded);
            persistentHand.cards.insert(persistentHand.cards.end(), newCards.cards.begin(), newCards.cards.end());
            persistentHand.id = handCounter; 
        }
        
        playerInterface.playHand(persistentHand);
        Hand chosenHand = playerInterface.getChosenHand();
        std::vector<int> chosenIndices = playerInterface.getChosenIndices();
        
        if (chosenHand.cards.empty()) {
            std::cout << "Anda tidak memainkan kartu apapun.\n";
            continue;
        }

        std::cout << "\nPilihan Aksi Kartu:\n";
        std::cout << "[1] Play Kartu\n";
        std::cout << "[2] Discard Kartu (Sisa Discard: " << sessionState.getRemainingDiscards() << ")\n";
        std::cout << "[3] Batal / Ulangi Pilihan\n";
        std::cout << "Pilihan: ";

        int action;
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Input tidak valid.\n";
            continue;
        }

        if (action == 3) {
            continue;
        } else if (action == 2) {
            if (sessionState.useDiscard()) {
                std::sort(chosenIndices.rbegin(), chosenIndices.rend());
                for (int index : chosenIndices) {
                    persistentHand.cards.erase(persistentHand.cards.begin() + index);
                }
                std::cout << "Kartu berhasil dibuang.\n";
            }
            continue;
        } else if (action == 1) {
            int scoreGained = scoringSystem.scoreHand(chosenHand, jokerManager);
            sessionState.addScore(scoreGained);
            sessionState.usePlay();

            std::sort(chosenIndices.rbegin(), chosenIndices.rend());
            for (int index : chosenIndices) {
                persistentHand.cards.erase(persistentHand.cards.begin() + index);
            }

            if (sessionState.getTotalScore() >= targetScore) {
                blindCleared = true;
                std::cout << "\n[WIN] Sesi " << currentBlind->getName() << " Selesai Dimainkan (Menang)!\n";
                int reward = currentBlind->getRewardMoney();
                std::cout << "Mendapatkan uang hadiah sebesar: $" << reward << "\n";

                sessionState.getPlayerMoney().add(reward);

                std::vector<std::string> itemsToRestock = {"JOKER_ADDCHIPS", "JOKER_PAIR", "JOKER_DIAMOND"};
                shopSystem.generateShopFront(itemsToRestock);

                while(true) {
                    shopSystem.displayShop(sessionState.getPlayerMoney());
                    std::cout << "Pilih index barang untuk dibeli (Ketik -1 untuk keluar toko): ";
                    int shopChoice;
                    if (std::cin >> shopChoice) {
                        if (shopChoice == -1) break;
                        shopSystem.buyItem(shopChoice, sessionState.getPlayerMoney());
                    } else {
                        std::cin.clear(); std::cin.ignore(1000, '\n'); break;
                    }
                }

                sessionState.resetScore(); 
                updateGameState();
            }
 else {
                std::cout << "\n[INFO] Skor belum mencukupi. Target: " << targetScore 
                          << ", Saat ini: " << sessionState.getTotalScore() << "\n";
            }
        } else {
            std::cout << "Pilihan tidak ada.\n";
            continue;
        }
    }
}

void GameManager::skipBlind() {
    BlindState* currentBlind = sessionState.getCurrentBlind();

    std::cout << "\n=== SKIP: " << currentBlind->getName() << " ===\n";
    std::cout << "[Manager Info]: Pemain memilih untuk SKIP Blind ini!\n";
    
    auto skipCommand = currentBlind->generateSkipReward();
    sessionState.storeCommand(std::move(skipCommand));

    updateGameState();
}

void GameManager::updateGameState() {
    BlindState* currentBlind = sessionState.getCurrentBlind();
    auto nextBlind = currentBlind->getNextState(sessionState);
    sessionState.setCurrentBlind(std::move(nextBlind));
    
    sessionState.resetForNewBlind();

    sessionState.checkAndExecuteCommands(RewardTiming::NextBlind);
    if (sessionState.getCurrentBlind()->getName() == "Small Blind") {
        sessionState.checkAndExecuteCommands(RewardTiming::NextAnte);
    }
}