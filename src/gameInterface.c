#include <stdio.h>
#include "commandMatching.c"
#include "modules/core/globals.h"
#include "commands/buy.c"
#include "commands/inventory.c"
#include "commands/to_do.c"
#include "commands/in_progress.c"
#include "commands/pick_up.c"
#include "commands/drop_off.c"
#include "commands/move.c"


void help();

void gameMenu()
{
    boolean playing = true;
    while (playing)
    {   

        printf("\n\nLokasi Mobita: %c ", symbol(gameState.currentLocation));
        displayPoint(coord(gameState.currentLocation));printf("\n");
        printf("Waktu: %d\n", gameState.time);
        printf("Uang: %d\n", gameState.cash);
        printf("ENTER COMMAND: ");
        readConsoleInput();
        readWord();
        if (checkWord(currentWord, "MOVE."))
        {
            printf("MOVE selected.\n");
            move(gameState);
        }
        else if (checkWord(currentWord, "PICK_UP."))
        {
            printf("PICK_UP selected.\n");
            pick_up();
        }
        else if (checkWord(currentWord, "DROP_OFF."))
        {
            printf("DROP_OFF selected.\n");
            drop_off();
        }
        else if (checkWord(currentWord, "MAP."))
        {
            printf("MAP selected.\n");
            displayGameMap(gameState.gameMap);
        }
        else if (checkWord(currentWord, "TO_DO."))
        {
            printf("TO_DO selected.\n");
            to_do();
        }
        else if (checkWord(currentWord, "IN_PROGRESS."))
        {
            printf("IN_PROGRESS selected.\n");
            in_progress();
        }
        else if (checkWord(currentWord, "BUY."))
        {
            printf("BUY selected.\n");
            buy();
        }
        else if (checkWord(currentWord, "INVENTORY."))
        {
            printf("INVENTORY selected.\n");
            inventory();
        }
        else if (checkWord(currentWord, "HELP."))
        {
            printf("HELP selected.\n");
            help();
        }
        else if (checkWord(currentWord, "EXIT."))
        {
            printf("EXIT selected.\n");
            playing = false;
        }
        else
        {
            printf("Command tidak dikenali!\n");
            printf("Ketik 'HELP.' untuk bantuan.\n");
        }
        if ((isItemListEmpty(gameState.todoList) && isItemListEmpty(gameState.inProgressList) && gameState.time > 0)){
            playing = false;
        }    
        
    }
    if ((isItemListEmpty(gameState.todoList) && isItemListEmpty(gameState.inProgressList))){
        printf("\n\nSelamat! Kamu berhasil membantu Mobilita mengantarkan semua pesanan!");
        printf("\nWaktu: %d - Uang: %d Yen\n", gameState.cash, gameState.time);
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
    printf("10. EXIT -> Untuk keluar dari game\n");
}
