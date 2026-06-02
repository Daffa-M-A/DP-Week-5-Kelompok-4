# TDD - Balatro-like Game

## Bab 1: Arsitektur Sistem

### 1.1 Ringkasan Arsitektur
Sistem ini menggunakan arsitektur berbasis objek dengan pemisahan tanggung jawab yang ketat (*Separation of Concerns*). Komponen utama dibagi menjadi:
*   **Orchestrator (`GameManager`)**: Mengatur alur interaktif sesi permainan.
*   **State Holder (`RuntimeSessionState`)**: Pusat data sesi yang bersifat *Single Source of Truth*.
*   **Logic Engine**: Mencakup `ScoringRule`, `PokerHandChecker`, dan `JokerManager`.

### 1.2 Teknologi yang Digunakan
*   **Bahasa Pemrograman**: C++ (Standar C++17 atau lebih tinggi).
*   **Paradigma**: Object-Oriented Programming (OOP) dengan penggunaan *Design Patterns* yang intensif.

## Bab 2: Perancangan Rinci

### 2.1 Perancangan Struktural (Class Diagram)
Sistem ini mengimplementasikan beberapa pola desain kunci:

#### 2.1.1 State Pattern (Sistem Blind)
Digunakan untuk mengelola transisi fase permainan tanpa menggunakan percabangan besar.
*   **Base Class**: `BlindState`
*   **Concrete States**: `SmallBlindState`, `BigBlindState`, `BossBlindState`.
*   **Fungsi**: Menentukan `targetScore`, `rewardMoney`, dan transisi via `getNextState()`.

#### 2.1.2 Chain of Responsibility (Hand Evaluation)
Digunakan untuk mengevaluasi kombinasi kartu poker secara sekuensial.
*   **Chain**: `FlushFiveChecker` → `FlushHouseChecker` → ... → `HighCardChecker`.
*   **Keuntungan**: Memungkinkan penambahan kombinasi kartu baru dengan hanya menyisipkan *checker* baru ke dalam rantai.

#### 3.1.3 Observer Pattern (Joker System)
Joker bertindak sebagai observer yang mengamati proses perhitungan skor dan memberikan modifikasi secara dinamis.
*   **Interface**: `Joker::onEvaluateScore(ScoreContext&)`
*   **Mekanisme**: `JokerManager` melakukan iterasi pada setiap Joker aktif untuk mengubah nilai `Chips` dan `Mult` di dalam `ScoreContext` saat evaluasi skor berlangsung.

### 2.2 Perancangan Perilaku (Behavioral Design)

#### 2.2.1 Sequence Diagram: Perhitungan Skor
1.  `GameManager` memanggil `ScoringRule::scoreHand`.
2.  `ScoringRule` mengirimkan kartu ke `PokerHandChecker` (Chain).
3.  `PokerHandChecker` mengembalikan `HandRank`.
4.  `ScoringRule` menentukan skor dasar (Chips & Mult).
5.  `ScoringRule` meminta `JokerManager` untuk memodifikasi skor.
6.  `JokerManager` memanggil `onEvaluateScore` pada setiap Joker.
7.  Hasil akhir dikembalikan ke `GameManager`.

#### 2.2.2 Command Pattern: Skip Reward & Shop
Aksi yang memerlukan penundaan eksekusi atau pemisahan logika transaksi dibungkus dalam objek `Command`.
*   **Skip Blind**: Menghasilkan `RewardCommand` yang disimpan di antrean `pendingCommands`.
*   **Shop**: Menggunakan `BuyJokerCommand` untuk memisahkan proses pembayaran dengan penambahan status Joker.

## Bab 3: Perancangan Data

### 3.1 Struktur Data Internal
*   **`RuntimeSessionState`**: Menyimpan variabel kritis seperti `currentAnte`, `totalScore`, `playerMoney`, dan daftar `pendingCommands`.
*   **`Deck`**: Koleksi 52 objek `Card` yang dikelola secara dinamis.
*   **`Hand`**: Vektor kartu yang mewakili kartu di tangan pemain.

### 3.2 Kamus Data (Data Dictionary)
| Atribut | Tipe Data | Deskripsi |
| :--- | :--- | :--- |
| `totalScore` | `int` | Akumulasi skor pemain dalam satu Blind. |
| `playerMoney` | `Money` | Saldo pemain untuk transaksi di Toko. |
| `remainingPlays` | `int` | Jatah memutar kartu yang tersisa. |
| `pendingCommands` | `std::vector` | Antrean perintah reward yang menunggu eksekusi. |

## Bab 4: Perancangan Antarmuka

### 4.1 Antarmuka Pengguna
Karena game ini berbasis terminal, antarmuka dirancang menggunakan menu berbasis teks:
*   **Menu Utama**: Opsi *Play Blind*, *Skip Blind*, atau *Exit*.
*   **Fase Gameplay**: Menampilkan sisa *Plays/Discards*, kartu di tangan, dan menu aksi kartu.
*   **Antarmuka Toko**: Menampilkan daftar Joker yang tersedia beserta harganya.

### 4.2 Alur Navigasi
`Main Menu` → `Gameplay Loop` (Repeat) → `Win Evaluation` → `Shop Screen` → `Next Blind Selection`.

## Bab 5: Aturan Tambahan dan Batasan
1.  **Hand Persistence**: Kartu di tangan tidak di-*reset* saat *play* atau *discard* kecuali digantikan kartu baru dari *Deck*.
2.  **Deck Shuffling**: *Deck* hanya dikocok ulang di awal setiap Blind baru.
3.  **Encapsulation**: Semua modifikasi status sesi harus melalui metode di `RuntimeSessionState`.
