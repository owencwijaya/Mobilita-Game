# Mobilita
> Permainan simulasi pengantaran barang berbasis CLI dengan memanfaatkan _abstract dataypes_
> sebagai Tugas Besar mata kuliah IF2110 Algoritma dan Struktur data
> Program Studi Teknik Informatika ITB 2020/2021

## Daftar Isi
* [Penjelasan Ringkas](#penjelasan-ringkas)
* [Cara Kompilasi](#cara-kompilasi)
* [Cara Menjalankan Program](#cara-menjalankan-program)
* [Fitur](#fitur)
* [Anggota](#anggota)


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

Isi dari file:
* `build`: folder konfigurasi kompilasi
* `docs`: folder dokumen
* `dist`: folder untuk _executable_ (akan muncul setelah kompilasi)
* `src`: folder berisi _source code_
  * `commands`: folder berisi algoritma-algoritma untuk perintah pada permainan
  * `config`: folder berisi file konfigurasi permainan (sampel dari spesifikasi)
  * `modules`: folder berisi modul-modul penting di permainan
    * `colorizer`: module pewarnaan
    * `core`: module inti dari keseluruhan program permainan
      * `commands`: submodule yang menangani alur permainan
    * `io`: module berisi loadfile/config parser dan mesin kata (I/O)
      * `machines`: submodule yang menangani masukan pengguna
    * `models`: module ADT yang digunakan beserta _driver code_
      * `inventory`: koleksi tipe data inventory permainan
      * `item`: koleksi tipe data item dan pesanan dalam permainan
      * `map`: koleksi tipe data map permainan
        * `location`: koleksi tipe data lokasi (gedung) dalam permainan
      * `shared`: koleksi tipe data yang digunakan tipe data lain
      * `state`: tipe data state permainan
  * `main.c`: file utama permainan
  
## Cara Kompilasi
* Dari _Terminal Visual Studio Code_
  * Pastikan anda berada di folder `root` (`../IF2110_TB_03_10`)
  * Jalankan perintah `py build/all.py` untuk melakukan kompilasi terhadap file-file yang ada
  * Setelah kompilasi selesai, ketikkan perintah `./dist/mobilita` untuk memulai _executable_
* Secara otomatis (dari _command prompt_ atau _PowerShell_)
  * Jalankan `run.bat` untuk memulai _executable_ dari `root` (`run.ps1` untuk menjalankan di PowerShell)
  * **[IMPORTANT]** Supaya pewarnaan dapat dilihat dari _command prompt_, nilai dari Registry harus diubah melalui Regedit
    * Buka Registry Editor (`regedit`) di komputer Anda  
    * Navigasikan ke `HKEY_CURRENT_USER -> Console`
    * Klik kanan di folder `Console`, lalu gunakan opsi `New -> DWORD (32-bit Value)`
    * Tambahkan kunci baru dengan spesifikasi:
      * Nama kunci: `VirtualTerminalLevel`
      * Nilai kunci: `1`
    * Simpan hasil pengubahan kunci. Apabila program dijalankan di *command prompt* , pewarnaan seharusnya berjalan.
* Dari Linux (diuji di WSL2, Ubuntu 20.04)
  * Pastikan anda berada di folder `root` (`..IF2110/TB_03/10`)
  * Jalankan perintah `python3 build/all.py` untuk melakukan kompilasi terhadap file-file yang ada 
  * Setelah kompilasi selesai, ketikkan perintah `./dist/mobilita` untuk memulai _executable_
 
## Cara Menjalankan Program
* Saat _executable_ dimulai, akan ada empat opsi:
  * NEW: untuk memulai permainan baru
  * LOAD: untuk memulai permainan dari _save file_ sebelumnya
  * HELP: untuk menampilkan menu awal
  * EXIT: keluar dari program
   
* **[IMPORTANT]** Pastikan direktori file konfigurasi/savefile relatif terhadap folder di mana program dijalankan. Apabila program dijalankan di `root`:
  * Apabila file berada di folder `src/config`, maka input file `src/config/<nama_file>.txt`
  * Apabila file berada di `root`, maka input `<nama_file>`.txt
  * Pastikan juga **tipe _newline_ di file save sudah sesuai dengan _platform_** (CR/LF untuk Windows, LF untuk Linux), karena apabila file CR/LF dijalankan di Linux, maka akan muncul error _segmentation fault_ atau file tidak terbaca.
* Pemain akan masuk ke menu utama dan permainan akan dimulai.
* Pemain harus mengantarkan semua pesanan hingga tidak ada pesanan lagi. Setelah permainan selesai, pemain harus kembali ke posisi awal.

## Fitur
Status pengerjaan: **[SELESAI]**
* Fitur _save file_ dan _load gameplay_ dari _save file_
* Pewarnaan di _gameplay_
* Dapat dikompilasi dan dijalankan baik dari _code editor_ maupun _terminal `cmd`_ atau _PowerShell_
* Implementasi ADT yang dimodifikasi dalam permainan
* Simulasi pengantaran dan pengiriman barang berbasis lokasi dan CLI dengan akses lokasi dan informasi berbasis pewarnaan

## Anggota
* [13520166 Raden Rifqi Rahman](https://github.com/Radenz)
  * Pembuatan ADT dasar + driver ADT
  * Pembuatan script kompilasi
  * Pembuatan groundwork pengerjaan dan state algoritma
  * Pengecekan ulang algoritma
  * Debugging dan update source code
* [13520124 Owen Christian Wijaya](https://github.com/clumsyyyy)
  * Integrasi algoritma ke program utama
  * Algoritma fungsi buy dan inventory
  * Debugging dan update source code
  * Konfigurasi loading awal dan save file
  * Pembagian tugas awal
* [13520121 Nicholas Budiono](https://github.com/nicholass25)
  * Algoritma move
  * Petanggungjawab laporan
  * Pengecekan ulang algoritma
* [13520120 Afrizal Sebastian](https://github.com/afrizalsebastian)
  * Algoritma in-progress dan pick-up 
  * Debugging dan update source code
  * Pengecekan ulang algoritma
* [13520127 Adzka Ahmadetya Zaidan](https://github.com/Voguelish)
  * Algoritma  to-do dan drop-off
  * Notulis asistensi
  * Pengecekan ulang algoritma
