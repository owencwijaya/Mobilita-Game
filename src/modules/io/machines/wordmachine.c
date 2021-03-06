#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

boolean endWord = false;
Word currentWord;

void ignoreWBlank()
{
    while (isBlankCharacter(currentChar) && !eot)
    {
        adv();
    }
}

void readWord()
{
    ignoreWBlank();
    if (eot)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        copyWord();
    }
}

void readLine()
{
    if (eot)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        copyLine();
    }
}

void readNextWord()
{
    ignoreWBlank();
    if (eot)
    {
        endWord = true;
    }
    else
    {
        copyWord();
        ignoreWBlank();
    }
}

void copyWord()
{
    int i = 0;
    while (!eot && !isBlankCharacter(currentChar) && i < CAPACITY)
    {
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    if (i < CAPACITY)
    {
        currentWord.length = i;
    }
    else
    {
        currentWord.length = CAPACITY;
    }
}

void copyLine()
{
    int i = 0;
    while (!eot && currentChar != NEWLINE && i < CAPACITY)
    {
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    if (i < CAPACITY)
    {
        currentWord.length = i;
    }
    else
    {
        currentWord.length = CAPACITY;
    }
}