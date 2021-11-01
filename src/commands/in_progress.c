#include <stdio.h>
#include "../modules/core/globals.h"
#include "../models/macros.h"


void in_progress(){
    ItemList loc = gameState.inProgressList;
    if(loc == NULL){
        printf("Tidak ada item di yang diantarkan\n");
    }else{
        printf("Pesanan yang sedang diantarkan : \n");
        int num = 1;
        while(loc != NULL){
            if(isNormalItem(value(loc))){
                printf("%d. Normal Item (Tujuan : %c)\n", num, value(loc).dropOffLocation.symbol);
            }else if (isHeavyItem(value(loc))){
                printf("%d. Heavy Item (Tujuan : %c)\n", num, value(loc).dropOffLocation.symbol);
            }else if (isPerishableItem(value(loc))){
                printf("%d. Perishable Item (Tujuan : %c)\n", num, value(loc).dropOffLocation.symbol);
            }else if(isVIPItem(value(loc))){
                printf("%d. VIP Item (Tujuan : %c)\n", num, value(loc).dropOffLocation.symbol);
            }
        num++;
        loc = next(loc);
        }
        printf("\n");
    }
}