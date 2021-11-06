#include <stdlib.h>
#include <stdio.h>
#include "../modules/core/globals.h"
#include "../models/macros.h"

void to_do()
{
    ItemList loc = gameState.todoList;
    if (loc == NULL)
    {
        printf("Tidak ada pesanan pada To Do List!\n");
    }
    else
    {
        printf("Pesanan pada To Do List: \n");
        int num = 1;

        while (loc != NULL)
        {
            if (isNormalItem(value(loc)))
            {
                printf("%d. %c -> %c (Normal Item)\n", num, value(loc).pickUpLocation.symbol, value(loc).dropOffLocation.symbol);
            }
            else if (isHeavyItem(value(loc)))
            {
                printf("%d. %c -> %c (Heavy Item)\n", num, value(loc).pickUpLocation.symbol, value(loc).dropOffLocation.symbol);
            }
            else if (isPerishableItem(value(loc)))
            {
                printf("%d. %c -> %c (Perishable Item, sisa waktu %d)\n", num, value(loc).pickUpLocation.symbol, value(loc).dropOffLocation.symbol, value(loc).perishTime);
            }
            else if (isVIPItem(value(loc)))
            {
                printf("%d. %c -> %c (VIP Item)\n", num, value(loc).pickUpLocation.symbol, value(loc).dropOffLocation.symbol);
            }
            num++;
            loc = next(loc);
        }
        printf("\n");
    }
}
