#include <stdio.h>
#include <string.h> //sementara string.h aja dulu sampe diconfirm
#include "commandMatching.c"
#include "modules/core/globals.h"
//Buat Raden: semua yang udah dibikin gabungin di sini aja

void help();
void buy();
void inventory();



void gameMenu(){ //ganti tipe struct aja
    boolean playing = true;
    while (playing){
        printf("\nENTER COMMAND: ");
        readConsoleInput();
        readWord();
        if (checkWord(currentWord, "MOVE.")){
            printf("MOVE selected.\n");
            //move(); placeholder buat move
        } else if (checkWord(currentWord, "PICK_UP.")){
            printf("PICK_UP selected.\n");
            //pick_up();
        } else if (checkWord(currentWord, "DROP_OFF.")){
            printf("DROP_OFF selected.\n");
            //drop_off();
        } else if (checkWord(currentWord, "MAP.")){
            printf("MAP selected.\n");
            displayGameMap(gameState.gameMap);
        } else if (checkWord(currentWord, "TO_DO.")){
            printf("TO_DO selected.\n");
            //to_do()
        } else if (checkWord(currentWord, "IN_PROGRESS.")){
            printf("IN_PROGRESS selected.\n");
            //in_progress();
        } else if (checkWord(currentWord, "BUY.")){
            printf("BUY selected.\n");
            buy();
        } else if (checkWord(currentWord, "INVENTORY.")){
            printf("INVENTORY selected.\n");
            inventory();
        } else if (checkWord(currentWord, "HELP.")){
            printf("HELP selected.\n");
            help();
        } else if (checkWord(currentWord, "EXIT.")){
            printf("EXIT selected.\n");
            playing = false;
        } else {
            printf("Command tidak dikenali!\n");
            printf("Ketik 'HELP.' untuk bantuan.\n");
        }
    }
}

void help(){
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


void buy(){
    gameState.cash = 99999999;
    if (gameState.cash == 0){
        printf("Anda tidak mempunyai uang!\n");
    } else if (isGadgetListFull(gameState.inventory)){
        printf("Inventory penuh!");
    } else {
        printf("Uang anda sekarang: %d Yen\n", gameState.cash);
        printf("Gadget yang tersedia: \n");
        printf("1. Kain Pembungkus Waktu (800 Yen) \n");
        printf("2. Senter Pembesar (1200 Yen) \n");
        printf("3. Pintu Kemana Saja (1500 Yen) \n");
        printf("4. Mesin Waktu (3000 Yen) \n");
        printf("5. Senter Pengecil (800 Yen) \n");
        printf("Gadget mana yang ingin kau beli? \n");
        printf("(Ketik 0 jika ingin kembali)\n\n");

        int option;
        if (isGadgetListFull(gameState.inventory)){
            printf("Inventory sudah penuh!\n");
            printf("Gunakan command 'INVENTORY' untuk mengecek");
        } else {
            printf("ENTER OPTION: ");
            readConsoleInput();
            option = currentChar;
            if (option == '1'){
                if (gameState.cash >= 800){
                    gameState.cash -= 800;
                    setGadget(&gameState.inventory, gListLength(gameState.inventory), KAIN_PEMBUNGKUS_WAKTU);
                    printf("Gadget 'Kain Pembungkus Waktu' berhasil dibeli!\n");
                } else {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            }else if (option == '2'){
                if (gameState.cash >= 1200){
                    gameState.cash -= 1200;
                    setGadget(&gameState.inventory, gListLength(gameState.inventory), SENTER_PEMBESAR);
                    printf("Gadget 'Senter Pembesar' berhasil dibeli!\n");
                } else {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            } else if (option == '3'){
                if (gameState.cash >= 1500){
                    gameState.cash -= 1500;
                    setGadget(&gameState.inventory, gListLength(gameState.inventory), PINTU_KEMANA_SAJA);
                    printf("Gadget 'Pintu Kemana Saja' berhasil dibeli!\n");
                } else {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            } else if (option == '4'){
                if (gameState.cash >= 3000){
                    gameState.cash -= 3000;
                    setGadget(&gameState.inventory, gListLength(gameState.inventory), MESIN_WAKTU);
                    printf("Gadget 'Mesin Waktu' berhasil dibeli!\n");
                } else {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            } else if (option == '5'){
                if (gameState.cash >= 800){
                    gameState.cash -= 800;
                    setGadget(&gameState.inventory, gListLength(gameState.inventory), SENTER_PENGECIL);
                    printf("Gadget 'Senter Pengecil' berhasil dibeli!\n");
                } else {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            } 
        }
    }
    gameState.cash = 0;
}


void inventory(){
    displayGadget(gameState.inventory);
    if (gListLength(gameState.inventory) == 0){
        printf("Inventory kosong!\n");
    } else {
        printf("Gadget mana yang ingin digunakan? \n");
        printf("(Ketik 0 jika ingin kembali)\n\n");
        int option;
        readConsoleInput();
        option = currentChar;

        Gadget tempGadget = getGadget(gameState.inventory, (int)(option - '0') - 1);
        setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
    }
}