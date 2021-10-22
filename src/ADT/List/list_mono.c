#include <stdio.h>
#include "listpos.h"

/* 
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Kamis, 9 September 2021
    Topik Praktikum: ADT List
    Deskripsi: Membahas implementasi fungsi ADT List
*/
int main(){
    ListPos list;
    int NDML = 0, NAML = 0, SML = 0;
    readList(&list);

    int i = 0;
    for (i = 0; i < length(list) - 1; i++){
        if(ELMT(list, i) == ELMT(list, i + 1)){
            SML++;
        }
        if(ELMT(list, i) >= ELMT(list, i + 1)){
            NAML++;
        }
        if(ELMT(list, i) <= ELMT(list, i + 1)){
            NDML++;
        }
        
    }

    if ((SML == length(list) - 1 && SML == NDML && NDML == NAML && NAML == SML) || length(list) == 1){
        printf("Static Monotonic List\n");
    }

    else if (NAML == length(list) - 1|| length(list) == 1){
        printf("Non-ascending Monotonic List\n");
    }
    else if (NDML == length(list) - 1 || length(list) == 1){
        printf("Non-descending Monotonic List\n");
    }
    
    else if(NAML != length(list) - 1 && NDML != length(list) - 1 && SML != (length(list) - 1)){
        printf("Non-monotonic List\n");
    }

    return 0;
}