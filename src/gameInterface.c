#include <stdio.h>
#include "modules/core/globals.h"
#include "models/macros.h"
#include "commands/commands.h"
#include "modules/io/word_utils.h"
#include "modules/colorizer/colorizer.h"
void help();

void gameMenu()
{
    boolean playing = true;
    while (playing)
    {

        printf("\n\nLokasi Mobita: ");
        changeToOrangeColor();printf("%c ", symbol(gameState.currentLocation));
        displayPoint(coord(gameState.currentLocation));resetColor();
        printf("\n");
        printf("Waktu: ");
        changeToGreenColor();printf("%d\n", gameState.time);resetColor();
        printf("Uang: ");
        changeToGreenColor();printf("%d\n", gameState.cash);resetColor();
        if (gameState.gameMap._locationMatrix.contents[gameState.currentLocation.coordinate.x][gameState.currentLocation.coordinate.y].isPickUpPlace){
            printf("Ada pesanan yang dapat");
            changeToRedColor();printf(" di-pickup ");resetColor();
            printf("di sini!\n");
        }
        if (gameState.gameMap._locationMatrix.contents[gameState.currentLocation.coordinate.x][gameState.currentLocation.coordinate.y].isDropOffPlace){
            printf("Ada pesanan yang dapat");
            changeToBlueColor();printf(" di-dropoff ");resetColor();
            printf("di sini!\n");
        }
        if (gameState.currentLocation.symbol == '8'){
            printf("Anda sedang berada di");
            changeToOrangeColor();printf(" Headquarters.\n");resetColor();
        }
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
        else if (isStringEquals(cmd, "EXIT"))
        {
            printf("EXIT selected.\n\n");
            playing = false;
        }
        else
        {
            printf("Command tidak dikenali!\n");
            printf("Ketik 'HELP' untuk bantuan.\n");
        }
        if ((isItemListEmpty(gameState.todoList) && isItemListEmpty(gameState.inProgressList) && gameState.time > 0))
        {
            playing = false;
        }
    }
    if ((isItemListEmpty(gameState.todoList) && isItemListEmpty(gameState.inProgressList)))
    {
        printf("\n\nSelamat! Kamu berhasil membantu Mobilita mengantarkan semua pesanan!");
        printf("\nWaktu: %d - Uang: %d Yen\n", gameState.time, gameState.cash);
        printf("now go sleep idontknow");
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
    printf("10. RETURN -> Untuk mengembalikan item ke to-do list (hanya saat efek aktif)\n");
    printf("11. EXIT -> Untuk keluar dari game\n");
}
