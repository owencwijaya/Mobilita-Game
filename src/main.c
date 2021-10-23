#include <stdio.h>
#include "configInput.c"
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
    gameMatrix MainGM; //ini nanti sesuaiin sama struct Raden
    startToken();
    option = currentToken.val;
    if (option == 1){
        /* printf("\nMasukkan direktori file konfigurasi:\nmis. .//config/config.txt\n>>>  ");
            char fileName[100];
            scanf("%s", &fileName);*/
        MainGM = configInput("placeholder");
        gameMenu(&MainGM); //ini nanti sesuaiin sama struct Raden
    }
}

void title()
{
    printf("  __                         \n");
    printf(" /  )  _ _ _ _      (   //   \n");
    printf("/(_/()/ (-(///)()/) |/|//)(/ \n");
    printf("                          /  \n");
}

