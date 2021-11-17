#include <stdio.h>
#include "../../models/shared/macros.h"
#include "../globals.h"

void in_progress()
{
    ItemList loc = gameState.inProgressList;
    printf("Kapasitas tas: %d\n", gameState.bag.capacity);
    if (loc == NULL)
    {
        printf("Tidak ada item yang sedang diantarkan!\n");
    }
    else
    {
        printf("Ada %d pesanan yang sedang diantarkan : \n", itemListLength(gameState.inProgressList));
        int num = 1;
        while (loc != NULL)
        {
            if (isNormalItem(value(loc)))
            {
                printf("%d. Normal Item (Tujuan : %c)\n", num, value(loc).dropOffLocation.symbol);
            }
            else if (isHeavyItem(value(loc)))
            {
                printf("%d. Heavy Item (Tujuan : %c)\n", num, value(loc).dropOffLocation.symbol);
            }
            else if (isPerishableItem(value(loc)))
            {
                printf("%d. Perishable Item (Tujuan : %c, Waktu Sisa : %d)\n", num, value(loc).dropOffLocation.symbol, value(loc).perishTime);
            }
            else if (isVIPItem(value(loc)))
            {
                printf("%d. VIP Item (Tujuan : %c)\n", num, value(loc).dropOffLocation.symbol);
            }
            num++;
            loc = next(loc);
        }
        printf("\n");
    }
    printf("\n");
}