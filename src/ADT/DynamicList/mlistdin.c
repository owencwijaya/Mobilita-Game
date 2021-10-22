#include <stdio.h>
#include "listdin.h"
/*
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Kamis, 16 September 2021
    Topik: ADT List (Array Dinamis)
    Deskripsi: Melakukan implementasi array dinamis di ADT list
*/

int main(){
    int CAPACITY = 0;

    int i = 0;
    int q = 0;
    int op = 0;
    int query = 0;
    ListDin L;
    scanf("%d", &CAPACITY);
    CreateListDin(&L, CAPACITY);
    readList(&L);
    scanf("%d", &q);
    for (i = 0; i < q; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &query);
            if(!isFull(L)){
                insertLast(&L, query);
                printf("%d ", CAPACITY(L));
                displayList(L);
            } else {
                printf("list sudah penuh");
            }
        } else if (op == 2){
            scanf("%d", &query);
            growList(&L, query);
            printf("%d ", CAPACITY(L));
            displayList(L);
        } else if (op == 3){
            scanf("%d", &query);
            if (CAPACITY(L) < query){
                printf("list terlalu kecil");
            } else {
                shrinkList(&L, query);
                printf("%d ", CAPACITY(L));
                displayList(L);
            }
            
        } else if (op == 4){
            compactList(&L);
            printf("%d ", CAPACITY(L));
            displayList(L);
        }
        printf("\n"); 
    }


    

    
}