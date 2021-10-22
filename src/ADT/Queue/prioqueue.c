#include <stdio.h>
#include "prioqueue.h"

/* 
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Kamis, 7 Oktober 2021
    Topik: ADT Queue
    Deskripsi: Implementasi queue dalam urutan prioritas
*/

void CreatePrioQueue(PrioQueue *pq){
    /* Membuat PrioQueue baru */
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq){
    /* Mengembalikan true jika IDX_HEAD dan IDX_TAIL == IDX_UNDEF */
    return (IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF);
}

boolean isFull(PrioQueue pq){
    /* Mengembalikan true jika IDX_HEAD di 0 dan IDX_TAIL di CAPACITY - 1 */
    return ((IDX_HEAD(pq) == 0) && (IDX_TAIL(pq) == CAPACITY - 1));
}

int length (PrioQueue pq){
    /* Mengembalikan nilai panjang PrioQueue */
    if (isEmpty(pq)){
        return 0;
    } else {
        return (IDX_TAIL(pq) - IDX_HEAD(pq) + 1);
    }
}

void enqueue(PrioQueue *pq, ElType val) {
    int i = 0;
    int j = 0;
    int k = 0;
    int index = 0;
    if (IDX_TAIL(*pq) == CAPACITY - 1) {
        
        PrioQueue tempQueue;
        ElType tempVal;

        CreatePrioQueue(&tempQueue);
        for (i = IDX_HEAD(*pq); i <= IDX_TAIL(*pq); i++) {
            dequeue(pq, &tempVal);
            enqueue(&tempQueue, tempVal);
        }
        *pq = tempQueue;
    } else if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = -1;
    }

    j = IDX_HEAD(*pq);
    index = IDX_UNDEF;

    while ((index == IDX_UNDEF) && (j <= IDX_TAIL(*pq))) {
        if (((*pq).buffer[j].score < val.score) || (((*pq).buffer[j].score < val.score) && ((*pq).buffer[j].tArrival > val.tArrival))) {
            index = j;
        } else {
            j++;
        }
    }  
    IDX_TAIL(*pq) += 1;

    if (index == IDX_UNDEF) {
        TAIL(*pq) = val;
    } else {
        for (i = index; i <= IDX_TAIL(*pq) - 1; i++) {
            (*pq).buffer[i + 1] = (*pq).buffer[i];
        }
        (*pq).buffer[index] = val;
    }
}

void dequeue (PrioQueue *pq, ElType *val){
    /* Menghapus nilai paling depan dari queue */
    *val = HEAD(*pq);
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)){
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        IDX_HEAD(*pq) = IDX_HEAD(*pq) + 1;
    }
}