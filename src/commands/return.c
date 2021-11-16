#include <stdio.h>
#include "../modules/core/globals.h"
#include "../models/macros.h"

void returnToSender(){
    if (gameState.abs.IsReturnOn){
        if (top(gameState.bag).type != VIP){
            if (!isItemListEmpty(gameState.inProgressList)){
                Item temp;
                Item temp2;
                pop(&gameState.bag, &temp);
                deleteItemFirst(&gameState.inProgressList, &temp2);
                if (temp.type == PERISHABLE){
                    temp.perishTime = temp.perishTimeReference;
                }

            
                insertItemLast(&gameState.todoList, temp);
                printf("Efek 'Return to Sender' digunakan!\n");
                printf("Item teratas pada bag telah dikembalikan ke pengirim\n");
                gameState.abs.ReturnStack--;
                if (gameState.abs.ReturnStack == 0){
                    gameState.abs.IsReturnOn = false;
                }
                setAsPickUpPlace(&gameState.gameMap._locationMatrix.contents[temp.pickUpLocation.coordinate.x][temp.pickUpLocation.coordinate.y]);
                printf("Sisa penggunaan: %d kali\n", gameState.abs.ReturnStack);
                } else {
                printf("Tidak ada item yang sedang diantarkan!\n\n");
            }
        } else {
            printf("Efek 'Return to Sender' tidak dapat digunakan pada item VIP!\n\n");
        }
        
    } else {
        printf("Efek 'Return to Sender' sedang tidak aktif!\n\n");
    }
}


