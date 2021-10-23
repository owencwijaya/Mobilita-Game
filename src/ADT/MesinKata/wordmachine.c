#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

boolean endWord = false;
Word currentWord;


void ignoreWBlank(){
    while (currentChar == BLANK){
        adv();
    }
} 

void startWord(){
    start();
    ignoreWBlank();
    if (currentChar == MARK){
        endWord = true;
    } else {
        endWord = false;
        copyWord();
    }
    
}

void advWord(){
    ignoreWBlank();
    if (currentChar == MARK){
        endWord = true;
    } else {
        copyWord();
        ignoreWBlank();
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