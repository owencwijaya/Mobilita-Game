#include <stdlib.h>
#include "../models/shared/boolean.h"
#include "./machines/charmachine.h"
#include "./machines/wordmachine.h"

char *stringify(Word w);

boolean isStringEquals(char *str1, char *str2);

int parseInt(char *str);

int strlength(char *str);

char *concat(char *str1, char *str2);