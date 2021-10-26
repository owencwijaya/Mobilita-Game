#include <stdio.h>
#include "modules/io/config_parser.c"
#include "modules/core/globals.c"
#include "gameInterface.c"
/* prototype fungsi */
int mainMenu();
void title();

/* Fungsi utama yang akan di-run */
void main(){
    mainMenu();
}

/* Fungsi mainMenu */
int mainMenu()
{
    title();
    printf("========MENU========\n");
    printf("1. New Game\n");
    printf("0. Exit Game\n");
    printf("Masukkan pilihan: \n>>> ");

    int option;
    readConsoleInput();
    option = currentChar;
    adv();
    if (option == '1'){
        /* printf("\nMasukkan direktori file konfigurasi:\nmis. .//config/config.txt\n>>>  ");
            char fileName[100];
            scanf("%s", &fileName);*/
        parseConfig(".//config/dummyConfig.txt");
        gameMenu(); //struct Raden masukin ke sini
    }
}

void title()
{
    printf("  __                         \n");
    printf(" /  )  _ _ _ _      (   //   \n");
    printf("/(_/()/ (-(///)()/) |/|//)(/ \n");
    printf("                          /  \n");
}

