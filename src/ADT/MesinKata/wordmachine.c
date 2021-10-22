#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"


/*
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Kamis, 23 September 2021
    Topik: Mesin Kata
    Deskripsi: Implementasi Mesin Kata Versi 1
*/

boolean endWord;
Word currentWord;


void ignoreBlank(){
    while (currentChar == BLANK){
        adv();
    }
} 

void startWord(){
    start();
    ignoreBlank();
    if (currentChar == MARK){
        endWord = true;
    } else {
        endWord = false;
        copyWord();
    }
    
}

void advWord(){
    ignoreBlank();
    if (currentChar == MARK){
        endWord = true;
    } else {
        copyWord();
        ignoreBlank();
    }
}

void copyWord(){
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK) && (i < CAPACITY)){
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    if (i < CAPACITY){
        currentWord.length = i;
    } else {
        currentWord.length = CAPACITY;
    }
}