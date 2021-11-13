#include <stdio.h>
#include "modules/io/config_parser.h"
#include "modules/io/loadfile_parser.h"
#include "modules/core/globals.h"
#include "gameInterface.h"

/* prototype fungsi */
int mainMenu();
void title();

/* Fungsi utama yang akan di-run */
void main()
{
    mainMenu();
}

/* Fungsi mainMenu */
int mainMenu()
{
    title();
    printf("========MENU========\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("0. Exit Game\n");
    printf("Masukkan pilihan: \n>>> ");

    int option;
    // printf("bp1");
    readConsoleInput();
    option = currentChar;
    adv();
    if (option == '1')
    {
        /* printf("\nMasukkan direktori file konfigurasi:\nmis. .//config/config.txt\n>>>  ");
            char fileName[100];
            scanf("%s", &fileName);*/
        parseConfig("./src/config/dummyConfig.txt");
        gameMenu();
    } else if (option == '2'){
        parseLoad("./src/config/dummySavefile.txt");
        gameMenu();
    }
}

void title()
{
    printf(".-.   .-. .----. .----. .-..-.   .-. .---.  .--.  \n");
    printf("|  `.'  |/  {}  \\| {}  }| || |   | |{_   _}/ {} \\ \n");
    printf("| |\\ /| |\\      /| {}  }| || `--.| |  | | /  /\\  \\ \n");
    printf("`-' ` `-' `----' `----' `-'`----'`-'  `-' `-'  `-'\n");
}
