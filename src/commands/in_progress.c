#include <stdio.h>
#include "../modules/core/globals.h"

void in_progress()
{
    ItemList inProgressList = gameState.inProgressList;
    if (isItemListEmpty(inProgressList))
    {
        printf("Tidak ada item yang sedang diantarkan!\n");
    }
    else
    {
        printf("Pesanan yang sedang diantarkan : \n");
        int num = 1;
        ItemListNode node = *inProgressList;
        while (node != NULL)
        {
            Item item = value(node);
            char symbol = symbol(dropOffLoc(item));
            if (isNormalItem(item))
            {
                printf("%d. Normal Item (Tujuan : %c)\n", num, symbol);
            }
            else if (isHeavyItem(item))
            {
                printf("%d. Heavy Item (Tujuan : %c)\n", num, symbol);
            }
            else if (isPerishableItem(item))
            {
                printf("%d. Perishable Item (Tujuan : %c, Waktu Sisa : %d)\n", num, symbol, perishTime(item));
            }
            else if (isVIPItem(item))
            {
                printf("%d. VIP Item (Tujuan : %c)\n", num, symbol);
            }
            num++;
            node = next(node);
        }
        printf("\n");
    }
}