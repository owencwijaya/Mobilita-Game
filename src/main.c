#include <stdio.h>
#include "modules/io/config_parser.h"
#include "modules/io/loadfile_parser.h"
#include "modules/core/globals.h"
#include "gameInterface.h"
#include "modules/colorizer/colorizer.h"
#include "models/boolean.h"

/* prototype fungsi */
int mainMenu();
void title();

/* Fungsi utama yang akan di-run */
void main()
{
    /**
     * Uncomment the line below to enable ANSI escape
     * sequence rendering in windows console
     * @see "./modules/colorizer/colorizer.c"
     */
    // enableAnsiRendering();
    mainMenu();
}

/* Fungsi mainMenu */
int mainMenu()
{
    title();

    boolean end = false;
    while (!end)
    {
        printf("ENTER COMMAND: ");
        changeToGreenColor();
        readConsoleInput();
        readLine();
        resetColor();
        char *cmd = stringify(currentWord);
        if (isStringEquals(cmd, "NEW GAME"))
        {
            printf("Masukkan file konfigurasi\n");
            printf(">>> ");
            changeToGreenColor();
            readConsoleInput();
            readLine();
            resetColor();
            char *cfgpath = stringify(currentWord);
            parseConfig(cfgpath);
            incrementTime(&gameState, 0);
            gameMenu();
            end = true;
        }
        else if (isStringEquals(cmd, "LOAD GAME"))
        {
            printf("Masukkan save file\n");
            printf(">>> ");
            changeToGreenColor();
            readConsoleInput();
            readLine();
            resetColor();
            char *cfgpath = stringify(currentWord);
            parseConfig(cfgpath);
            gameMenu();
            end = true;
        }
        else if (isStringEquals(cmd, "EXIT"))
        {
            end = true;
        }
        else if (isStringEquals(cmd, "HELP"))
        {
            printf("NEW GAME -> Memulai permainan baru\n");
            printf("LOAD GAME -> Memuat data yang tersimpan dalam save file\n");
            printf("HELP -> Menampilkan pesan bantuan ini\n");
            printf("EXIT -> Keluar game\n");
        }
        else
        {
            printf("Command tidak dikenali!\n");
            printf("Ketik 'HELP' untuk melihat bantuan.\n");
        }
    }
}

void title()
{
    printf(".-.   .-. .----. .----. .-..-.   .-. .---.  .--.  \n");
    printf("|  `.'  |/  {}  \\| {}  }| || |   | |{_   _}/ {} \\ \n");
    printf("| |\\ /| |\\      /| {}  }| || `--.| |  | | /  /\\  \\ \n");
    printf("`-' ` `-' `----' `----' `-'`----'`-'  `-' `-'  `-'\n");
}
