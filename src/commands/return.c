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
                deleteItemLast(&gameState.inProgressList, &temp2);
                
                unsetAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[temp.dropOffLocation.coordinate.x][temp.dropOffLocation.coordinate.y]);
                if (!isStackEmpty(gameState.bag)){
                    setAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).dropOffLocation.coordinate.x][top(gameState.bag).dropOffLocation.coordinate.y]);
                }
                
                if (temp.type == PERISHABLE){
                    temp.perishTime = temp.perishTimeReference;
                }
                if (temp.type == HEAVY && gameState.abs.IsSenterPengecilOn){
                    gameState.abs.IsSenterPengecilOn = false;
                } else {
                    gameState.abs.HeavyItemStack--;
                }
            
                insertItemLast(&gameState.todoList, temp);
                printf("Efek 'Return to Sender' digunakan!\n");
                printf("Item teratas pada bag telah dikembalikan ke pengirim!\n");
                if (isNormalItem(temp)){
                    printf("(Normal Item (%c -> %c))\n\n", temp.pickUpLocation.symbol, temp.dropOffLocation.symbol);
                } else if (isHeavyItem(temp)){
                    printf("(Heavy Item (%c -> %c))\n\n", temp.pickUpLocation.symbol, temp.dropOffLocation.symbol);
                } else if (isPerishableItem(temp)){
                    printf("(Perishable Item (%c -> %c))\n\n", temp.pickUpLocation.symbol, temp.dropOffLocation.symbol);
                }
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


