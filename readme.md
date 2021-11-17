# Mobilita
> Permainan simulasi pengantaran barang berbasis CLI dengan memanfaatkan _abstract dataypes_
> sebagai Tugas Besar mata kuliah IF2110 Algoritma dan Struktur data
> Program Studi Teknik Informatika ITB 2020/2021

## Table of Contents
* [General Information](#general-information)
* [Setup](#setup)
* [Usage](#usage)
* [Contacts](#contacts)


## General Information
**Mobilita** adalah sebuah permainan berbasis CLI yang mensimulasikan suatu sistem pengantaran barang. Barang-barang yang ada memanfaatkan konsep _abstract data-types_, yaitu tipe-tipe data dengan akses khusus yang diimplementasikan oleh pengguna. Ada beberapa daftar _abstract data-types_ yang digunakan (selengkapnya di `docs`):
* ADT Mesin Karakter dan Mesin Kata: untuk memproses _input_ pengguna
* ADT List Statis
* ADT Matriks: untuk menyimpan peta dan matriks _adjacency_
* ADT Queue: untuk menyimpan daftar pesanan yang masuk
* ADT Stack: untuk menyimpan daftar pesanan yang diamblik
* ADT Point dan Location: untuk mewakili lokasi pemain dan lokasi-lokasi lainnya
* ADT Gadget: untuk penggunaan _gadget_
* ADT Item: untuk mewakili sebuah _item_ (mengandung tipe item, lokasi _pick-up_ dan _drop-off_, dan lain-lain
* ADT Linked List: untuk menampilkan daftar pesanan yang bisa diambil (to-do list) dan sedang diambil (in-progress list)
* ADT List Dinamis: untuk menampung data lokasi
* ADT Peta: untuk mewakili peta
* ADT State: sebagai _global state_ yang merupakan gabungan dari ADT-ADT sebelumnya

Bahasa yang digunakan: C (implementasi permainan dan ADT), Python (untuk kompilasi file)

## Structure
* `build`: folder konfigurasi kompilasi
* `dist`: folder untuk _executable_ (akan muncul setelah kompilasi)
* `src`: folder berisi _source code_
  * `commands`: folder berisi algoritma-algoritma untuk perintah pada permainan
  * `config`: folder berisi file konfigurasi permainan (sampel dari spesifikasi)
  * `models`: folder berisi ADT yang digunakan beserta _driver code_
    * `colorizer`: module pewarnaan
    * `core`: module berisi file _global state_
    * `io`: module berisi loadfile/config parser dan mesin kata (I/O)
  * `modules`: folder berisi modul-modul penting di permainan
  * `gameInterface.c`: file menu utama untuk bermain
  * `main.c`: file utama permainan
  
## Setup
* Dari _VSCode/Terminal_
  * Pastikan anda berada di folder `root` (`../IF2110_TB_10_03`)
  * Jalankan perintah `py build/all.py` untuk melakukan kompilasi terhadap file-file yang ada
  * Setelah kompilasi selesai, ketikkan perintah `./dist/mobilita` untuk memulai _executable_
* Secara otomatis
  * Jalankan `run.bat` untuk memulai _executable_ dari `root` (`run.ps1` untuk menjalankan di PowerShell)
  
## Usage
* Saat _executable_ dimulai, akan ada empat opsi:
  * NEW: untuk memulai permainan baru
  * LOAD: untuk memulai permainan dari _save file_ sebelumnya
  * HELP: untuk menampilkan menu awal
  * EXIT: keluar dari program
  * 
* **[IMPORTANT]** Pastikan direktori file konfigurasi/savefile relatif terhadap folder di mana program dijalankan. Apabila program dijalankan di `root`:
  * Apabila file berada di folder `src/config`, maka input file `src/config/<nama_file>.txt`
  * Apabila file berada di `root`, maka input `<nama_file>`.txt
* Pemain akan masuk ke menu utama dan permainan akan dimulai.
* Pemain harus mengantarkan semua pesanan hingga tidak ada pesanan lagi. Setelah permainan selesai, pemain harus kembali ke posisi awal.

## Contacts
* [13520166 Raden Rifqi Rahman](https://github.com/Radenz)
* [13520124 Owen Christian Wijaya](https://github.com/clumsyyyy)
* [13520121 Nicholas Budiono](https://github.com/nicholass25)
* [13520120 Afrizal Sebastian](https://github.com/afrizalsebastian)
* [13520127 Adzka Ahmadetya Zaidan](https://github.com/Voguelish)
