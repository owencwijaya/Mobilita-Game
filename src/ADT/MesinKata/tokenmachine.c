#include <stdio.h>
#include "tokenmachine.h"
#include "charmachine.h"

/*
    NIM: 13520124
    Nama: Owen Christian Wijaya
    Tanggal: Kamis, 23 September 2021
    Topik: Mesin Kata
    Deskripsi: Implementasi Mesin Kata Versi 1
*/


boolean endToken;
Token currentToken;

void ignoreBlank(){
    while (currentChar == BLANK){
        adv();
    }
} 

void startToken(){
    start();
    ignoreBlank();
    if (currentChar == MARK){
        endToken = true;
    } else {
        endToken = false;
        advToken();
    }
}

void advToken(){
    ignoreBlank();
    if (currentChar == MARK){
        endToken = true;
    } else {
        salinToken();
        ignoreBlank();
    }
}

void salinToken(){
    int content = 0;
    int i = 0;
    int ans = 0;

    ignoreBlank();

    if (currentChar == MARK){
        endToken = true;
    } else if (currentChar == '+' || currentChar == '-' || currentChar == '^' || currentChar == '*' || currentChar == '/'){
        currentToken.tkn = currentChar;
        currentToken.val = -1;
        adv();
    } else {
        currentToken.tkn = 'b';
        while ((currentChar != MARK) && (currentChar != BLANK) && (i < CAPACITY)){
            if (currentChar == '0'){
                content = 0;
            } else if (currentChar == '1'){
                content = 1;
            } else if (currentChar == '2'){
                content = 2;
            } else if (currentChar == '3'){
                content = 3;
            } else if (currentChar == '4'){
                content = 4;
            } else if (currentChar == '5'){
                content = 5;
            } else if (currentChar == '6'){
                content = 6; 
            } else if (currentChar == '7'){
                content = 7;
            } else if (currentChar == '8'){
                content = 8;
            } else if (currentChar == '9'){
                content = 9;
            }
            ans = (ans * 10) + content;
            i++;
            adv();
        }
        currentToken.val = ans;
    }
}