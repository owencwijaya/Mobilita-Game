#include <stdio.h>
#include "modules/io/config_parser.h"
#include "modules/io/loadfile_parser.h"
#include "modules/core/globals.h"
#include "modules/colorizer/colorizer.h"
#include "modules/models/shared/boolean.h"
#include "modules/core/gameInterface.h"

/* prototype fungsi */
int mainMenu();
void title();
void option();
/* Fungsi utama yang akan di-run */
void main()
{
    /**
     * Uncomment the line below to enable ANSI escape
     * sequence rendering in windows console
     * @see "./modules/colorizer/colorizer.c"
     */
    enableAnsiRendering();
    mainMenu();
}

/* Fungsi mainMenu */
int mainMenu()
{
    title();
    option();
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
            printf("Masukkan file konfigurasi (0 jika ingin kembali)\n");
            printf(">>> ");
            changeToGreenColor();
            readConsoleInput();
            readLine();
            resetColor();
            char *cfgpath = stringify(currentWord);
            if (!isStringEquals(cfgpath, "0"))
            {
                FILE *file;
                if ((file = fopen(cfgpath, "r")))
                {
                    fclose(file);
                    readFile(cfgpath);
                    readWord();
                    if (!isStringEquals(stringify(currentWord), "SAVE"))
                    {
                        parseConfig(cfgpath);
                        incrementTime(&gameState, 0);
                        gameMenu();
                        end = true;
                    }
                    else
                    {
                        printf("File config invalid! (File yang dimasukkan adalah file SAVE)\n");
                    }
                }
                else
                {
                    printf("Nama / direktori file tidak sesuai!\n");
                }
            }
        }
        else if (isStringEquals(cmd, "LOAD GAME"))
        {
            printf("Masukkan save file (0 jika ingin kembali)\n");
            printf(">>> ");
            changeToGreenColor();
            readConsoleInput();
            readLine();
            resetColor();
            char *cfgpath = stringify(currentWord);
            if (!isStringEquals(cfgpath, "0"))
            {
                FILE *file;
                if ((file = fopen(cfgpath, "r")))
                {
                    fclose(file);
                    readFile(cfgpath);
                    readWord();
                    if (isStringEquals(stringify(currentWord), "SAVE"))
                    {
                        parseLoad(cfgpath);
                        incrementTime(&gameState, 0);
                        gameMenu();
                        end = true;
                    }
                    else
                    {
                        printf("File save invalid! (File yang dimasukkan bukan file save)\n");
                    }
                }
                else
                {
                    printf("Nama / direktori file tidak sesuai!\n");
                }
            }
        }
        else if (isStringEquals(cmd, "EXIT"))
        {
            end = true;
        }
        else if (isStringEquals(cmd, "HELP"))
        {
            printf("1. NEW -> Memulai permainan baru\n");
            printf("2. LOAD -> Memuat data yang tersimpan dalam save file\n");
            printf("3. HELP -> Menampilkan pesan bantuan ini\n");
            printf("4. EXIT -> Keluar game\n");
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

void option()
{
    printf("==============================================\n");
    printf("Selamat datang di MOBILITA!\n\n");
    printf("Ketikkan:\n");
    printf("1. NEW GAME untuk memulai permainan baru!\n");
    printf("2. LOAD GAME untuk membuka file penyimpanan!\n");
    printf("3. HELP untuk menampilkan menu bantuan\n");
    printf("4. EXIT untuk keluar dari game!\n");
    printf("===============================================\n");
}