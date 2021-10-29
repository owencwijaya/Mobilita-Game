#include "../modules/core/globals.h"
#include "../modules/io/machines/charmachine.h"

void in_progress(){
    if (isItemListEmpty(gameState.inProgressList)){
        printf("Tidak ada pesan yang sedang diantarkan.\n");
    } else {
        printf("Pesanan yang sedang diantarkan:\n");

        ItemList tempL = gameState.inProgressList;

        for (int i = 1; i <= itemListLength(gameState.inProgressList); i++){
            printf("%d. ", i);
            if (tempL->value.type == NORMAL) printf("Normal Item ");
            if (tempL->value.type == HEAVY) printf("Heavy Item ");
            if (tempL->value.type == PERISHABLE) printf("Perishable Item ");
            if (tempL->value.type == VIP) printf("VIP Item ");
            printf("Tujuan: %c\n", symbol(tempL->value.dropOffLocation));
            tempL = tempL->next;
        }
    }
}