#include <stdlib.h>
#include <stdio.h>
#include "../models/location.h"
#include "../models/item.h"
#include "../modules/core/globals.h"

void to_do()
{
    ItemList todoList = gameState.todoList;
    if (isItemListEmpty(todoList))
    {
        printf("Tidak ada pesanan pada To Do List!\n");
    }
    else
    {
        printf("Pesanan pada To Do List: \n");
        int num = 1;
        ItemListNode node = *todoList;
        while (node != NULL)
        {
            Item item = value(node);
            char pickLocation = symbol(pickUpLoc(item));
            char dropLocation = symbol(dropOffLoc(item));
            if (isNormalItem(item))
            {
                printf("%d. %c -> %c (Normal Item)\n", num, pickLocation, dropLocation);
            }
            else if (isHeavyItem(item))
            {
                printf("%d. %c -> %c (Heavy Item)\n", num, pickLocation, dropLocation);
            }
            else if (isPerishableItem(item))
            {
                printf("%d. %c -> %c (Perishable Item, sisa waktu %d)\n", num, pickLocation, dropLocation,
                       perishTime(item));
            }
            else if (isVIPItem(item))
            {
                printf("%d. %c -> %c (VIP Item)\n", num, pickLocation, dropLocation);
            }
            num++;
            node = next(node);
        }
        printf("\n");
    }
}
