#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/*
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Selasa, 14 September 2021
    Topik: ADT List (Array Dinamis)
    Deskripsi: Melakukan implementasi array dinamis di ADT list
*/


void CreateListDin(ListDin *l, int capacity){
    /* Membuat dynamic list sesuai kapasitas yang di-input*/
    BUFFER(*l) = (int *) malloc (capacity * sizeof(int));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocate(ListDin *l){
    /* Membebaskan memori dari array dan mengubah
    capacity dan nEff array menjadi 0 */
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int length(ListDin l){
    /* Mengembalikan panjang efektif array */
    return NEFF(l);
}

IdxType getLastIdx(ListDin l){
    /* Mengirimkan indeks elemen l terakhir */
    return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, int i){
    /* Mengirimkan true jika indeks ada di antara 0 dan CAPACITY */
    return ((i >= 0) && (i <= CAPACITY(l) - 1));
}

boolean isIdxEff(ListDin l, int i){
    /* Mengirimkan true apabila indeks berada di antara 0 dan NEFF */
    return ((i >= 0) & (i <= NEFF(l) - 1));
}

boolean isEmpty(ListDin l){
    /* Mengirimkan true apabila list kosong (tidak ada NEFF) */
    return (NEFF(l) == 0);
}

boolean isFull(ListDin l){
    /* Mengirimkan true apabila list penuh sebanyak elemen sebanyak
    CAPACITY */
    return (NEFF(l) == CAPACITY(l));
}


void readList(ListDin *l){
    /* Menerima input untuk list berdasarkan panjang yang dimasukkkan */

    /* Kamus */
    int banyakElemen;
    int i;
    int element;

    /* Algoritma */

    scanf("%d", &banyakElemen);

    while (banyakElemen < 0 || banyakElemen > CAPACITY(*l)){
        scanf("%d", &banyakElemen);
    }
    NEFF(*l) = banyakElemen;

    for (i = 0; i < banyakElemen; i++){
        scanf("%d", &element);
        ELMT(*l, i) = element;
    }

}

void displayList(ListDin l){
    /* Mengeluarkan output berupa list yang tidak kosong */

    /* Kamus */
    int i = 0;

    /* Algoritma */
    printf("[");
    while (i < length(l)){
        if (i == NEFF(l) - 1 || i == CAPACITY(l) - 1){
            printf("%d", ELMT(l, i));
        } else {
            printf("%d,", ELMT(l, i));
        }
        i++;
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    /* Mengembalikan list baru yang isinya adalah hasil penjumlahan/
    pengurangan l1 dan l2 berdasarkan boolean plus */

    /* Kamus */
    int i = 0;
    ListDin result;
    
    /* Algoritma */
    CreateListDin(&result, NEFF(l1));
    NEFF(result) = NEFF(l1);

    if (plus) {
        for(i = 0; i < NEFF(result); i++){
            ELMT(result, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else {
        for(i = 0; i < NEFF(result); i++){
            ELMT(result, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return result;
}

IdxType indexOf(ListDin l, ElType val){
    /* Mengembalikan indeks dari val di array */

    /* Kamus */
    boolean isFound = false;
    int i = 0;
    IdxType index = IDX_UNDEF;
    
    /* Algoritma */

    while(i < NEFF(l) && isFound == false){
        if (ELMT(l, i) == val){
            isFound = true;
            index = i;
            }
        i++;
    }
    return index;

}

void extremes(ListDin l, ElType *max, ElType *min){
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

void copyList(ListDin lIn, ListDin *lOut){
    /* Mengembalikan list baru yang merupakan
    hasil salinan list masukan */

    /* Kamus */
    int i = 0;

    /* Algoritma */
    CreateListDin(lOut, CAPACITY(lIn));
    CAPACITY(*lOut) = CAPACITY(lIn);
    NEFF(*lOut) = NEFF(lIn);
    for(i = 0; i < NEFF(*lOut); i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l){
    /* Mengembalikan hasil penjumlahan integer di list */
    
    /* Kamus */
    ElType sum = 0;
    int i = 0;

    /*Algoritma */
    for (i = 0; i < length(l); i++){
        sum = sum + ELMT(l, i);
    }

    return sum;
}

int countVal(ListDin l, ElType val){
    /* Menghitung jumlah kemunculan val
    di list l */

    /* Kamus */
    int i = 0;
    int count = 0;

    /* Algoritma */

    for (i = 0; i < NEFF(l); i++){
        if (ELMT(l, i) == val){
            count++;
        }
    }
   
    return count;
}

boolean isAllEven(ListDin l){
    /* Mengembalikan true apabila keseluruhan list genap */
    
    /* Kamus */
    boolean isEven = true;
    int i = 0;

    /* Algoritma */
    while (i < NEFF(l) && isEven == true){
        if (ELMT(l, i) % 2 != 0){
            isEven = false;
        }
        i++;
    }
   return isEven;
}

void sort(ListDin *l, boolean asc){
    /* Menyortir list berdasarkan boolean ascending */
    /* Kamus */
    int i = 0;
    int j = 0;
    int temp = 0;

    /* Algoritma */
    if (asc){
        for (i = 0; i < NEFF(*l); i++){
            for(j = 0; j < (NEFF(*l) - i - 1); j++){
                if(ELMT(*l, j) > ELMT(*l, j + 1)){
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }
            }
        }
    } else {
        for (i = 0; i < NEFF(*l); i++){
            for(j = 0; j < (NEFF(*l) - i - 1); j++){
                if(ELMT(*l, j) < ELMT(*l, j + 1)){
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }
            }
        }
    }
}

boolean isListEqual(ListDin l1, ListDin l2){
    /* Mengembalikan true apabila l1 adalah list yang sama
    dengan l2 */

    /* Kamus */
    boolean equal = true;
    int i = 0;
    
    /* Algoritma */
    if (NEFF(l1) == NEFF(l2)){
        sort(&l1, true);
        sort(&l2, true);
        for (i = 0; i < NEFF(l1); i++){
            if (ELMT(l1, i) != ELMT(l2, i)){
                equal = false;
            }
        }
    } else {
        equal = false;
    }
    
    return equal;
}

void insertLast(ListDin *l, ElType val){
    /* Memasukkan elemen baru di akhir list */
    if (NEFF(*l) < CAPACITY(*l)){
        NEFF(*l) = NEFF(*l) + 1;
        ELMT(*l, NEFF(*l) - 1) = val; 
    }
}

void deleteLast(ListDin *l, ElType *val){
    /* Menghapus elemen terakhir list */
    *val = ELMT(*l, length(*l) - 1);
    NEFF(*l) = NEFF(*l) - 1;
}

void growList(ListDin *l, int num){
    /* Menambah CAPACITY dengan num */
    ListDin tempList;
    CAPACITY(*l) = CAPACITY(*l) + num;
    copyList(*l, &tempList);
    dealocate(l);
    copyList(tempList, l);
    dealocate(&tempList);
}

void shrinkList(ListDin *l, int num){
    /* Mengurangi CAPACITY dengan num */
    ListDin tempList;
    CAPACITY(*l) = CAPACITY(*l) - num;
    if (NEFF(*l) > CAPACITY(*l)){
        NEFF(*l) = CAPACITY(*l);
    }
    copyList(*l, &tempList);
    dealocate(l);
    copyList(tempList, l);
    dealocate(&tempList);
}

void compactList(ListDin *l){
    /* Menyamakan CAPACITY dengan NEFF */
    CAPACITY(*l) = NEFF(*l);
}
