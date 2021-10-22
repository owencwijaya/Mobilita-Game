#include <stdio.h>
#include "listpos.h"
#include "boolean.h"
/* 
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Selasa, 7 September 2021
    Topik Praktikum: ADT List
    Deskripsi: Membahas penggunaan abstract datatype list
    dan membuat implementasi fungsi di file listpos.h
*/


void CreateListPos(ListPos *l){
    /* Membuat ADT list dengan isi file berupa MARK */

    /* Kamus */
    int i = 0;
    int j = 0;

    /* Algoritma */
    for (i = 0; i < CAPACITY; i++){
        ELMT(*l, i) = VAL_UNDEF;
    }
}

int length(ListPos l){
    /* Menghitung panjang bagian list yang mengandung
    nilai efektif */

    /* Kamus */
    int i = 0;

    /* Algoritma */
    while (i < CAPACITY && ELMT(l, i) != VAL_UNDEF){
        i++;
    }
    return i;
}

boolean isIdxValid(ListPos l, int i){
    /* Mengembalikan true apabila nilai index valid */
    return ((i >= 0) && (i <= CAPACITY - 1));
}

boolean isIdxEff(ListPos l, int i){
    /* Mengembalikan true apabila elemen l di indeks i valid */
    return ((i >= 0) && (i <= length(l) - 1) && ELMT(l, i) != VAL_UNDEF);
}

boolean isEmpty(ListPos l){
    /* Mengembalikan true apabila list kosong */
    return length(l) == 0;
}


boolean isFull(ListPos l){
    /* Mengembalikan true apabila list penuh */
    return length(l) == CAPACITY;
}

void readList(ListPos *l){
    /* Menerima input untuk list berdasarkan panjang yang dimasukkkan */

    /* Kamus */
    int banyakElemen;
    int i;
    int element;

    /* Algoritma */
    CreateListPos(l);
    scanf("%d", &banyakElemen);

    while (banyakElemen < 0 || banyakElemen > 100){
        scanf("%d", &banyakElemen);
    }

    for (i = 0; i < banyakElemen; i++){
        scanf("%d", &element);
        ELMT(*l, i) = element;
    }
}

void displayList(ListPos l){
    /* Mengeluarkan output berupa list yang tidak kosong */

    /* Kamus */
    int i = 0;

    /* Algoritma */

    printf("[");
    while (i < CAPACITY && ELMT(l, i)!= VAL_UNDEF){
        if (ELMT(l, i + 1) == VAL_UNDEF || i == CAPACITY - 1){
            printf("%d", ELMT(l, i));
        } else {
            printf("%d,", ELMT(l, i));
        }
        i++;
    }
    printf("]");
}

ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus){
    /* Me-return list baru hasil penjumlahan/pengurangan l1 dan l2 */
    /* Kamus */
    ListPos result;
    CreateListPos(&result);
    int i;

    /* Algoritma */
  
    if (plus){
        for (i = 0; i < length(l1); i++){
            ELMT(result, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else {
        for (i = 0; i < length(l1); i++){
            ELMT(result, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    
    return result;
}

int indexOf(ListPos l, ElType val){
    /* Mengeluarkan input berupa indeks yang berisi val */

    /* Kamus */
    boolean isFound = false;
    int i = 0;
    int index = IDX_UNDEF;

    /* Algoritma */
    while (i < length(l) && isFound == false){
        if (ELMT(l, i) == val){
            isFound = true;
            index = i;
        }
        i++;
    }

    return index;
}

void extremes(ListPos l, ElType *max, ElType *min){
    /* Mengembalikan nilai maksimum dan minimum dari list */
    /* Kamus */
    int i = 0;
    int nilaiMax = ELMT(l, 0);
    int nilaiMin = ELMT(l, 0);

    /* Algoritma */
    for (i = 0; i < length(l); i++){
        if (ELMT(l, i) > nilaiMax){
            nilaiMax = ELMT(l, i);
        }
        if (ELMT(l, i) < nilaiMin){
            nilaiMin = ELMT(l, i);
        }
    }

    *max = nilaiMax;
    *min = nilaiMin;
}

boolean isAllEven(ListPos l){
    /* Mengembalikan true apabila keseluruhan list genap */
    /* Kamus */
    boolean isEven = true;
    int i = 0;

    /* Algoritma */
    while (i < length(l) && isEven == true){
        if (ELMT(l, i) % 2 != 0){
            isEven = false;
        }
        i++;
    }
   return isEven;
}

void sort(ListPos *l, boolean asc){
    /* Menyortir list berdasarkan boolean ascending */
    /* Kamus */
    int i = 0;
    int j = 0;
    int temp = 0;

    /* Algoritma */
    if (asc){
        for (i = 0; i < length(*l); i++){
            for(j = 0; j < (length(*l) - i - 1); j++){
                if(ELMT(*l, j) > ELMT(*l, j + 1)){
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }
            }
        }
    } else {
        for (i = 0; i < length(*l); i++){
            for(j = 0; j < (length(*l) - i - 1); j++){
                if(ELMT(*l, j) < ELMT(*l, j + 1)){
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }
            }
        }
    }
}

void insertLast(ListPos *l, ElType val){
    /* Memasukkan elemen list baru */
    if (length(*l) < CAPACITY){
        ELMT(*l, length(*l)) = val;
    }
    
}

void deleteLast(ListPos *l, ElType *val){
    /* Meng-assign nilai elemen terakhir ke variabel pointer
    val, kemudian menghapus elemen tersebut dari list */
    *val = ELMT(*l, length(*l) - 1);
    ELMT(*l, length(*l) - 1) = VAL_UNDEF;
}

boolean isListEqual(ListPos l1, ListPos l2){
    /* Mengembalikan true apabila l1 adalah list yang sama
    dengan l2 */

    /* Kamus */
    boolean equal = true;
    int i = 0;
    
    /* Algoritma */
    if (length(l1) == length(l2)){
        sort(&l1, true);
        sort(&l2, true);
        for (i = 0; i < length(l1); i++){
            if (ELMT(l1, i) != ELMT(l2, i)){
                equal = false;
            }
        }
    } else {
        equal = false;
    }
    
    return equal;
}
