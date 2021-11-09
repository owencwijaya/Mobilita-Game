#include <stdio.h>
#include "../modules/core/globals.h"

void returnToSender(){
    if (gameState.abs.IsReturnOn){
        if (!isItemListEmpty(gameState.inProgressList)){
            Item temp;
            Item temp2;
            pop(&gameState.bag, &temp);
            deleteItemFirst(&gameState.inProgressList, &temp2);
            if (temp.type == PERISHABLE){
                temp.perishTime = temp.perishTimeReference;
            }

            if (temp.type != VIP){
                insertItemLast(&gameState.todoList, temp);
                printf("Efek 'Return to Sender' digunakan!\n");
                printf("Item teratas pada bag telah dikembalikan ke pengirim\n");
                gameState.abs.ReturnStack--;
                if (gameState.abs.ReturnStack == 0){
                    gameState.abs.IsReturnOn = false;
                }
                printf("Sisa penggunaan: %d kali\n", gameState.abs.ReturnStack);
            } else {
                printf("Efek 'Return to Sender' tidak dapat digunakan pada item VIP!\n");
            }
        } else {
            printf("Tidak ada item yang sedang diantarkan!");
        }
    } else {
        printf("Efek 'Return to Sender' sedang tidak aktif!\n");
    }
}


