#include <stdio.h>
#include <string.h> //sementara string.h aja dulu sampe diconfirm
#include "ADT/gameMatrix.h"
#include "ADT/Point/point.c"
#include "ADT/MesinKata/charmachine.c"
#include "ADT/MesinKata/wordmachine.c"
//Buat Raden: semua yang udah dibikin gabungin di sini aja
void help();

void gameMenu(gameMatrix *GM){ //ganti tipe struct aja
    /*
    boolean playing = true;
    while (playing){
        printf("\nENTER COMMAND (beserta titik): ");
        startWord();
        char *command = currentWord.contents;
        //strcmp
        //strcat("foo", "bar") = foobar
        printf("%s", command);
        if (strcmp(command, "MOVE")){
            //move(); placeholder buat move
        } else if (command == "PICK_UP"){
            //pick_up();
        } else if (command == "DROP_OFF"){
            //drop_off();
        } else if (strcmp(command, "MAP") == 0){
            displayMap(GM -> map);
        } else if (command == "TO_DO"){
            //to_do()
        } else if (command == "IN_PROGRESS"){
            //in_progress();
        } else if (command == "BUY"){
            //buy();
        } else if (command == "INVENTORY"){
            //inventory();
        } else if (command == "HELP"){
            help();
        } else if (command == "EXIT"){
            playing = false;
        } else {
            printf("Command tidak dikenali!\n");
            printf("Ketik 'HELP.' untuk bantuan.\n");
        }
    }
    */
   printf("masih placeholder, nunggu string.h"); 
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
