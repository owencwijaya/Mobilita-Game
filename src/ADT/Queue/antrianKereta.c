#include <stdio.h>
#include "queue.h"

/* 
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Kamis, 7 Oktober 2021
    Topik: ADT Queue
    Deskripsi: Implementasi queue dalam urutan prioritas
*/

float avgElmt(Queue q){
    int i = 0;
    float sum = 0;
    float length = 0;
    for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++){
        sum += (q).buffer[i];
        length += 1;
    }
    return (sum / length);
}

int main() {
    int option = 0;
    ElType query = 0;
    ElType val = 0;
    Queue q;
    CreateQueue(&q);
    scanf("%d", &option);
    while (true){
        if (option == 1){
            scanf("%d", &query);
            if (isFull(q)){
                printf("Queue penuh\n");
            } else {
                enqueue(&q, query);
            }
        } else if (option == 2){
            if (isEmpty(q)){
                printf("Queue kosong\n");
            } else {
                dequeue(&q, &val);
            }
        } else if (option == 0){
            printf("%d\n", length(q));
            if (isEmpty(q)){
                printf("Tidak bisa dihitung\n");
            } else {
                printf("%.2f\n", avgElmt(q));
            }
            break;
        }
        scanf("%d", &option);
    }
    
    return 0;
}