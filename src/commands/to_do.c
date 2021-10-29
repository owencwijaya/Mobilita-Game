#include "../modules/core/globals.h"
#include "../models/macros.h"


void to_do(){
    ItemList loc = gameState.todoList;
    if (loc == NULL){
        printf("Tidak ada pesanan pada To Do List\n");

    } else {
        printf("Pesanan pada To Do List: \n");
        int num = 1;

        while (loc != NULL){
            if (isNormalItem(value(loc))){
                printf("%d. %c -> %c (Normal Item)\n", num, value(loc).pickUpLocation, value(loc).dropOffLocation);
            } else if (isHeavyItem(value(loc))){
                printf("%d. %c -> %c (Heavy Item)\n", num, value(loc).pickUpLocation, value(loc).dropOffLocation);
            } else if (isPerishableItem(value(loc))){
                printf("%d. %c -> %c (Perishable Item)\n", num, value(loc).pickUpLocation, value(loc).dropOffLocation);
            } else if (isVIPItem(value(loc))){
                printf("%d. %c -> %c (VIP Item)\n", num, value(loc).pickUpLocation, value(loc).dropOffLocation);
            }
            num++;
            loc = next(loc);

        }
        printf("\n");

    }
}