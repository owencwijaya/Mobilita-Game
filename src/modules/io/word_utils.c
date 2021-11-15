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
    boolean positive = true;
    if (str[i] == '-')
    {
        positive = false;
        i++;
    }
    while (str[i] != NULL_CHAR)
    {
        value = value * 10 + (int)str[i] - 48;
        i++;
    }
    return positive ? value : value * -1;
}

int strlength(char *str)
{
    int i = 0;
    while (str[i] != NULL_CHAR)
    {
        i++;
    }
    return i;
}

char *concat(char *str1, char *str2)
{
    int length1 = strlength(str1);
    int length2 = strlength(str2);
    char *str = (char *)malloc((length1 + length2 + 1) * sizeof(char));
    for (int i = 0; i < length1; i++)
    {
        str[i] = str1[i];
    }
    for (int i = 0; i < length2; i++)
    {
        str[i + length1] = str2[i];
    }
    str[length1 + length2] = '\0';
    return str;
}