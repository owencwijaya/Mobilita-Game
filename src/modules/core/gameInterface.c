#include <stdio.h>
#include "../models/shared/macros.h"
#include "../io/word_utils.h"
#include "../colorizer/colorizer.h"
#include "commands/commands.h"
#include "globals.h"

void help();
void stats();
int mainMenu();

void gameMenu()
{
    LocationList adjlocation = getAdjacentLocations(locList(gameState.gameMap), gameState.currentLocation, adjMatrix(gameState.gameMap));
    for (int i = 0; i < length(adjlocation); i++)
    {
        setAsReachable(&gameState.gameMap._locationMatrix.contents[adjlocation.buffer[i].coordinate.x][adjlocation.buffer[i].coordinate.y]);
    }
    printf("Ketikkan perintah HELP untuk melihat daftar perintah!");
    boolean playing = true;
    boolean win = false;
    printf("\n\n");
    while (playing)
    {
        printf("\nLokasi Mobita: ");
        changeToOrangeColor();
        printf("%c ", symbol(gameState.currentLocation));
        displayPoint(coord(gameState.currentLocation));
        resetColor();
        printf("\n");
        printf("Waktu: ");
        changeToGreenColor();
        printf("%d\n", gameState.time);
        resetColor();
        printf("Uang: ");
        changeToGreenColor();
        printf("%d Yen\n", gameState.cash);
        resetColor();
        if (gameState.gameMap._locationMatrix.contents[gameState.currentLocation.coordinate.x][gameState.currentLocation.coordinate.y].isPickUpPlace)
        {
            printf("Ada pesanan yang dapat");
            changeToRedColor();
            printf(" di-pickup ");
            resetColor();
            printf("di sini");
            if (gameState.abs.TodoVIP)
            {
                printf(", namun ada");
                changeToOrangeColor();
                printf(" VIP Item ");
                resetColor();
                printf("yang harus diambil terlebih dahulu!\n");
            }
            else
            {
                printf("!\n");
            }
        }
        if (gameState.gameMap._locationMatrix.contents[gameState.currentLocation.coordinate.x][gameState.currentLocation.coordinate.y].isDropOffPlace)
        {
            printf("Ada pesanan yang dapat");
            changeToBlueColor();
            printf(" di-dropoff ");
            resetColor();
            printf("di sini!\n");
        }
        if (gameState.currentLocation.symbol == '8')
        {
            printf("Anda sedang berada di");
            changeToOrangeColor();
            printf(" Headquarters.\n");
            resetColor();
        }
        printf("Banyak pesanan tersisa: %d\n", itemListLength(gameState.todoList));
        printf("\nENTER COMMAND: ");
        changeToGreenColor();
        readConsoleInput();
        readWord();

        char *cmd = stringify(currentWord);
        resetColor();
        if (isStringEquals(cmd, "MOVE"))
        {
            printf("MOVE selected.\n\n");
            move(gameState);
        }
        else if (isStringEquals(cmd, "PICK_UP"))
        {
            printf("PICK_UP selected.\n\n");
            pick_up();
        }
        else if (isStringEquals(cmd, "DROP_OFF"))
        {
            printf("DROP_OFF selected.\n\n");
            drop_off();
        }
        else if (isStringEquals(cmd, "MAP"))
        {
            printf("MAP selected.\n\n");
            displayGameMap(gameState.gameMap);
        }
        else if (isStringEquals(cmd, "TO_DO"))
        {
            printf("TO_DO selected.\n\n");
            to_do();
        }
        else if (isStringEquals(cmd, "IN_PROGRESS"))
        {
            printf("IN_PROGRESS selected.\n\n");
            in_progress();
        }
        else if (isStringEquals(cmd, "BUY"))
        {
            printf("BUY selected.\n\n");
            buy();
        }
        else if (isStringEquals(cmd, "INVENTORY"))
        {
            printf("INVENTORY selected.\n\n");
            inventory();
        }
        else if (isStringEquals(cmd, "HELP"))
        {
            printf("HELP selected.\n\n");
            help();
        }
        else if (isStringEquals(cmd, "RETURN"))
        {
            printf("RETURN selected.\n\n");
            returnToSender();
        }
        else if (isStringEquals(cmd, "SAVE"))
        {
            printf("SAVE selected.\n\n");
            save_file();
        }
        else if (isStringEquals(cmd, "STATS"))
        {
            printf("STATS selected.\n\n");
            stats();
        }
        else if (isStringEquals(cmd, "MENU"))
        {
            printf("Apakah Anda ingin menyimpan save file? (Y/N)\n");
            readConsoleInput();
            readWord();
            char *option = stringify(currentWord);
            if (isStringEquals(option, "Y"))
            {
                save_file();
            }
            else
            {
                printf("MENU selected.\n\n");
                mainMenu();
            }
        }
        else if (isStringEquals(cmd, "EXIT"))
        {
            printf("Apakah Anda ingin menyimpan save file? (Y/N)\n");
            readConsoleInput();
            readWord();
            char *option = stringify(currentWord);
            if (isStringEquals(option, "Y"))
            {
                save_file();
            }
            else
            {
                printf("EXIT selected.\n\n");
                playing = false;
            }
        }
        else
        {
            printf("Command tidak dikenali!\n");
            printf("Ketik 'HELP' untuk bantuan.\n\n");
        }
        if ((isItemListEmpty(gameState.todoList) && isItemListEmpty(gameState.inProgressList) && gameState.time > 0 && isEmpty(gameState.order)))
        {
            printf("Semua pesanan telah terantar!\n");
            printf("Kembalilah ke ");
            changeToOrangeColor();
            printf("Headquarters");
            resetColor();
            printf(".\n");
            Location hq = getLocationById(gameState.gameMap, 0);
            if (isLocationIdentical(hq, gameState.currentLocation))
            {
                playing = false;
                win = true;
            }
        }
    }
    if (win)
    {
        printf("\n\nSelamat! Kamu berhasil membantu Mobilita mengantarkan semua pesanan!");
        changeToOrangeColor();
        printf("\nWaktu: %d - Uang: %d Yen\n", gameState.time, gameState.cash);
        resetColor();
        printf("Terima kasih telah membantu Mobita!\n\n");
        printf("Ketik tombol apapun untuk menutup program...");
        readConsoleInput();
    }
}

void help()
{
    printf("1. MOVE -> Untuk berpindah ke lokasi selanjutnya\n");
    printf("2. PICK_UP -> Untuk mengambil item di lokasi sekarang\n");
    printf("3. DROP_OFF -> Mengantarkan item ke lokasi sesuai tumpukan pesanan\n");
    printf("4. MAP -> Untuk melihat peta\n");
    printf("5. TO_DO -> Untuk melihat pesanan yang masuk ke to-do list\n");
    printf("6. IN_PROGRESS -> Untuk melihat pesanan yang sedang dikerjakan\n");
    printf("7. BUY -> Untuk membeli item (hanya bisa dipanggil di HQ)\n");
    printf("8. INVENTORY -> Untuk melihat isi inventory\n");
    printf("9. HELP -> Untuk menampilkan bantuan\n");
    printf("10. SAVE -> Untuk menyimpan file permainan\n");
    printf("11. STATS -> Untuk menampilkan efek dari item yang sedang aktif\n");
    printf("12. MENU -> Untuk kembali ke menu utama\n");
    printf("13. RETURN -> Untuk mengembalikan item ke to-do list (hanya saat efek aktif)\n");
    printf("14. EXIT -> Untuk keluar dari game\n");
}

void stats()
{
    printf("=============== Efek Drop-Off ===============\n\n");
    printf("Efek Speedboost:");
    gameState.abs.SpeedBoost ? printf(" AKTIF, Sisa pemakaian: %d\n", gameState.abs.SpeedBoostStack) : printf(" TIDAK AKTIF\n");
    printf("Efek Return:");
    gameState.abs.IsReturnOn ? printf(" AKTIF, sisa pemakaian: %d\n", gameState.abs.ReturnStack) : printf(" TIDAK AKTIF\n");
    printf("\n");
    printf("=============== Efek Gadget ===============\n");
    printf("(Berlaku untuk gadget yang tidak langsung dipakai)\n\n");
    printf("Senter Pengecil:");
    gameState.abs.IsSenterPengecilOn ? printf(" AKTIF\n") : printf(" TIDAK AKTIF\n");
    printf("Pintu Kemana Saja:");
    gameState.abs.PintuKemanaSaja ? printf(" AKTIF\n") : printf(" TIDAK AKTIF\n");
}