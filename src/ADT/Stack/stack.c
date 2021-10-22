#include <stdio.h>
#include "stack.h"

/* 
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Jum'at, 15 Oktober 2021
    Topik: ADT Stack
    Deskripsi: Implementasi fungsi-fungsi primitif
    ADT Stack
*/


void CreateStack(Stack *s){
    IDX_TOP(*s) = IDX_UNDEF;
}

boolean isEmpty(Stack s){
    return IDX_TOP(s) == IDX_UNDEF;
}

boolean isFull(Stack s){
    return (IDX_TOP(s) == CAPACITY - 1);
}

void push(Stack *s, ElType val){
    IDX_TOP(*s) = IDX_TOP(*s) + 1;
    TOP(*s) = val;
}

void pop(Stack *s, ElType *val){
    *val = TOP(*s);
    IDX_TOP(*s) = IDX_TOP(*s) - 1;
}