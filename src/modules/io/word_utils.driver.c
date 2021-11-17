#include <stdio.h>
#include <stdlib.h>
#include "word_utils.h"
#include "./machines/wordmachine.h"

int main()
{
    printf("Enter word\n>>> ");
    readConsoleInput();
    readLine();
    printf("String parsed from word : %s\n\n", stringify(currentWord));

    printf("Enter 1st string\n>>> ");
    char str1[256];
    scanf("%s", &str1);
    printf("Enter 2nd string\n>>> ");
    char str2[256];
    scanf("%s", &str2);
    printf("Both strings are %sequal.\n\n", isStringEquals(str1, str2) ? "" : "not ");

    printf("Enter string\n>>> ");
    char str[256];
    scanf("%s", &str);
    printf("Integer parsed from string : %d\n\n", parseInt(str));

    printf("Enter string\n>>> ");
    scanf("%s", &str);
    printf("String length : %d\n\n", strlength(str));

    printf("Enter 1st string\n>>> ");
    scanf("%s", &str1);
    printf("Enter 2nd string\n>>> ");
    scanf("%s", &str2);
    char *strc = concat(str1, str2);
    printf("Concatenated string : %s", strc);
    free(strc);

    return 0;
}