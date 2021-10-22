#include <stdio.h>
#include "listdinpos.c"
#define endl printf("\n")
/*
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Selasa, 14 September 2021
    Topik: ADT List (Array Dinamis)
    Deskripsi: Melakukan implementasi array dinamis di ADT list
*/

int main(){
    ListDin l;
    int min = 0; 
    int max = 0;
    CreateListDin(&l, 5);
    readList(&l);
    displayList(l);endl;4
    isEmpty(l) ? printf("yes"):printf("no");endl;
    isFull(l) ? printf("yes"):printf("no");endl;
    ListDin l2 = l;
    displayList(l);endl;
    printf("a %d", indexOf(l, 4));endl;
    extremes(l, &max, &min);
    printf("%d %d", max, min);endl;
    ListDin lOut;
    copyList(l, &lOut);
    displayList(lOut);endl;
    printf("%d %d", CAPACITY(lOut), length(lOut));endl;
    printf("b %d", sumList(l));endl;
    printf("%d", countVal(l, 1));endl;
    isAllEven(lOut) ? printf("yes") : printf("no");endl;
    sort(&l, false);
    displayList(l);endl;
    sort(&l, true);
    displayList(l);endl;
    isListEqual(l, lOut) ? printf("yes") : printf("no");endl;
    insertLast(&l, 5);
    displayList(l);endl;
    printf("%d", length(l));endl;

    int val;
    deleteLast(&l, &val);
    displayList(l);endl;
    printf("%d", length(l));endl;
    ListDin testing = plusMinusList(l, lOut, true);
    displayList(testing);

}
