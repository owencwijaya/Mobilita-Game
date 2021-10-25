/* File: charmachine.h */
/* Definisi Character Engine */

#ifndef CHAR_ENGINE_H
#define CHAR_ENGINE_H

#include "../../../models/boolean.h"

#define WHITESPACE ' '
#define NEWLINE '\n'
#define NULL_CHAR '\0'

/* Char Engine State */
extern char currentChar;
extern boolean eot;

void readConsoleInput();
void readFile(char *path);
void adv();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
boolean isBlankCharacter(char c);

#endif