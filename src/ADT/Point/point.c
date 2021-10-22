#include <stdio.h>
#include <math.h>
#include "point.h"
#define M_PI 3.14159265358979323846
/* 
    Nama: Owen Christian Wijaya
    NIM: 13520124
    File Body point.c
    Pra-Praktikum 2 Alstrukdat
*/
POINT MakePOINT(float X, float Y){
    /* Membentuk point P dari float X dan Y */

    /* Kamus */ 
    POINT p; /* Deklarasi variabel */

    /* Algoritma */
    Absis(p) = X;
    Ordinat(p) = Y;
    return p;
}

void BacaPOINT(POINT *P){
    /* Menerima input x dan y kemudian melanjutkan ke
    fungsi MakePOINT */

    /* Kamus */
    float x, y;

    /* Algoritma */
    scanf("%f %f", &x, &y);
    *P = MakePOINT(x, y);
}

void TulisPOINT(POINT P){
    /* Mencetak point menggunakan selektor dalam format 2 angka
    di belakang koma */
    printf("(%.2f, %.2f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2){
    /* Mengirimkan nilai benar apabila absis dan ordinat kedua titik sama */
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ(POINT P1, POINT P2){
    /* Mengirimkan nilai benar apabila absis atau ordinat dua titik berbeda */
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

boolean IsOrigin(POINT P){
    /* Mengirimkan nilai benar apabila absis dan ordinat titik = <0,0> */
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX(POINT P){
    /* Mengirimkan nilai benar apabila absis titik = 0 */
    return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P){
    /* Mengirimkan nilai benar apabila ordinattitik = 0 */
    return (Absis(P) == 0);
}

int Kuadran (POINT P){
    /* Mengirimkan integer yang mewakili kuadran apabila absis
    dan ordinat memenuhi syarat kuadran */
    if (Absis(P) > 0 && Ordinat(P) > 0){
        return 1;
    } else if (Absis(P) > 0 && Ordinat(P) < 0){
        return 2;
    } else if (Absis(P) < 0 && Ordinat(P) < 0 ){
        return 3;
    } else if (Absis(P) < 0 && Ordinat(P) > 0){
        return 4;
    } else {
        return 0;
    }
}

POINT NextX (POINT P){
    /* Menambah nilai absis titik */
    Absis(P) = Absis(P) + 1;
    return P;
}

POINT NextY (POINT P){
    /* Menambah nilai ordinat titik */
    Ordinat(P) = Ordinat(P) + 1;
    return P;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY){
    /* Menambah nilai absis dan ordinat titik sesuai argumen
    deltaX dan deltaY */
    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;
    return P;
}

POINT MirrorOf(POINT P, boolean SbX){
    /* Mencerminkan titik sesuai sumbu x/y */
    if (SbX){
        Ordinat(P) = Ordinat(P) * -1;
    } else {
        Absis(P) = Absis(P) * -1;
    }
    return P;
}

float Jarak0(POINT P){
    /* Menghitung jarak dari titik P ke titik pusat (0,0) */
    /* Kamus */
    int total;


    /* Algoritma */
    total = Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P);

    return sqrt(total);
}

float Panjang(POINT P1, POINT P2){
    /* Menghitung panjang garis yang terbentuk antar dua titik
    dengan mencari selisih jarak titik dan mengaplikasikan
    hukum Pythagoras */

    /* Kamus */
    int selisihX, selisihY, total;

    /* Algoritma */
    selisihX = Absis(P1) - Absis(P2);
    selisihY = Ordinat(P1) - Ordinat(P2);
    total = selisihX * selisihX + selisihY * selisihY;
    return sqrt(total);
}

void Geser(POINT *P, float deltaX, float deltaY){
    /* Mengubah nilai absis dan ordinat sesuai argumen
    deltaX dan deltaY, namun menggunakan pointer sehingga
    nilai variabel di driver juga berubah */
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}

void GeserKeSbX(POINT *P){
    /* Menggeser nilai absis ke 0 menggunakan pointer */
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P){
    /* Menggeser nilai ordinat ke 0 menggunakan pointer */
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
    /* Mencerminkan titik sesuai sumbu x/y menggunakan pointer */
    if (SbX){
        Ordinat(*P) = Ordinat(*P) * -1;
    } else {
        Absis(*P) = Absis(*P) * -1;
    }
}

void Putar(POINT *P, float Sudut){
    /* Memutar titik p sesuai sudut yang di-input */

    /* Kamus */
    /*Nilai sudut dikali (-1) karena diputar searah jarum jam*/
    float rad = -1* Sudut * (M_PI/180);
    float x = Absis(*P);
    float y = Ordinat(*P);

    /* Algoritma */
    Absis(*P) = x * cos(rad) - y * sin(rad);
    Ordinat(*P) = x * sin(rad) + y * cos(rad);
}

