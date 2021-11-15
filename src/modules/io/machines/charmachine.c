/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean eot;

static FILE *tape;
static int retval;
static boolean isReadingConsole;

void readConsoleInput()
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    isReadingConsole = true;
    tape = stdin;
    adv();
}

void readFile(char *path)
{
    isReadingConsole = false;
    tape = fopen(path, "r");
    adv();
}

void adv()
{
    /* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

    /* Algoritma */
    retval = fscanf(tape, "%c", &currentChar);
    eot = isReadingConsole ? (currentChar == NEWLINE) : (retval == EOF);
}

boolean isBlankCharacter(char c)
{
    return (c == WHITESPACE) || (!isReadingConsole && c == NEWLINE);
}