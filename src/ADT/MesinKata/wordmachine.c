#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

boolean endWord = false;
Word currentCWord;


void ignoreCBlank(){
    while (currentChar == BLANK){
        adv();
    }
} 

void startWord(){
    start();
    ignoreCBlank();
    if (currentChar == MARK){
        endWord = true;
    } else {
        endWord = false;
        copyCWord();
    }
    
}

void advWord(){
    ignoreCBlank();
    if (currentChar == MARK){
        endWord = true;
    } else {
        copyWord();
        ignoreCBlank();
    }
}

void copyCWord(){
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