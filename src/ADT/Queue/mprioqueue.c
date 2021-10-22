#include <stdio.h>
#include "prioqueue.h"

/* 
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Kamis, 7 Oktober 2021
    Topik: ADT Queue
    Deskripsi: Implementasi queue dalam urutan prioritas
*/

int main(){
    int N;
    int i = 0;
    int tempID = 0;
    int tempArrival = 0;
    int tempScore = 0;
    int tempDService = 0;
    int timeComp = 0;
    ElType val;
    PrioQueue studentQ;
    
    CreatePrioQueue(&studentQ);
    scanf("%d", &N);
    if (N != 0){
        for(i = 0; i < N; i++){
            ElType studentData;
            scanf("%d %d %d %d", &tempArrival, &tempID, &tempScore, &tempDService);
            studentData.id = tempID;
            studentData.tArrival = tempArrival;
            studentData.score = tempScore;
            studentData.dService = tempDService;

            while (studentData.tArrival > timeComp){
                if (isEmpty(studentQ)){
                    timeComp = studentData.tArrival;
                } else {
                    dequeue(&studentQ, &val);
                    printf("%d %d %d\n", timeComp, val.id, timeComp - val.tArrival);
                    timeComp = timeComp + val.dService;
                }
            }
            enqueue(&studentQ, studentData);
        }

        while (!isEmpty(studentQ)){
            dequeue(&studentQ, &val);
            printf("%d %d %d\n", timeComp, val.id, timeComp - val.tArrival);
            timeComp = timeComp + val.dService;
        }
       
    } else {
        printf("Tidak ada layanan\n");
    }
    
}