#include <stdio.h>
#include "queue.h"

/*
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Jum'at, 1 Oktober 2021
    Topik: ADT Queue
    Deskripsi: Implementasi ADT Queue
*/

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q){
    return ((IDX_HEAD(q) == 0) && (IDX_TAIL(q) == CAPACITY - 1));
}

int length(Queue q){
    if (isEmpty(q)){
        return 0;
    } else {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    
}

void enqueue (Queue *q, ElType val){
    int i = 0;
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        if (IDX_TAIL(*q) == (CAPACITY - 1)){
            for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++){
                (*q).buffer[i - IDX_HEAD(*q)] = (*q).buffer[i];
            }
            IDX_TAIL(*q) = IDX_TAIL(*q) - IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }
        
        IDX_TAIL(*q) = IDX_TAIL(*q) + 1;
    }
    
    TAIL(*q) = val;
}

void dequeue (Queue *q, ElType *val){
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q) = IDX_HEAD(*q) + 1;
    }
}

void displayQueue(Queue q){
    int i = 0;
    if (isEmpty(q)){
        printf("[]");
    }else {
        printf("[");
        for(i = IDX_HEAD(q); i <= IDX_TAIL(q); i++){
            printf("%d", q.buffer[i]);
            if (i != IDX_TAIL(q)){
                printf(",");
            }
        }
        printf("]");
    }      
}