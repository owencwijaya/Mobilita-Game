#include <stdlib.h>
#include "./machines/charmachine.h"
#include "./machines/wordmachine.h"
#include "../../models/boolean.h"
#include "word_utils.h"

char *stringify(Word w)
{
    int length = w.length;
    char *str = (char *)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++)
    {
        str[i] = w.contents[i];
    }
    str[length] = NULL_CHAR;
    return str;
}

boolean isStringEquals(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] == str2[i] && str1[i] != NULL_CHAR && str2[i] != NULL_CHAR)
    {
        i++;
    }
    return str1[i] == NULL_CHAR && str2[i] == NULL_CHAR;
}

int parseInt(char *str)
{
    int i = 0;
    int value = 0;
    // char c = str[i];
    while (str[i] != NULL_CHAR)
    {
        value = value * 10 + (int)str[i] - 48;
        i++;
    }
    return value;
}