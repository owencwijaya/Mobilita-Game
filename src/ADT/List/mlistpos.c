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
    int max, min, median, x;

    readList(&list);
    displayList(list);printf("\n");
    scanf("%d", &x);

    if (indexOf(list, x) != -1){
        printf("%d\n", indexOf(list, x));

        sort(&list, true);

        if ((length(list)) % 2 != 0){
            median = ELMT(list, ((length(list) / 2)));
        } else {
            median = ELMT(list, ((length(list) / 2) - 1));
        }

        max = ELMT(list, 0);
        min = ELMT(list, 0);
        extremes(list, &max, &min);

        if (x == max){
            printf("maksimum\n");
        } 
        if (x == min){
            printf("minimum\n");
        }
        if (x == median){
            printf("median\n");
        }

    } else {
        printf("%d tidak ada\n", x);
    }
    
    return 0;
}
