#include <stdio.h>
#include "../modules/io/word_utils.h"
#include "../modules/core/globals.h"
#include "../models/macros.h"
void save_file()
{
    printf("Masukkan nama file untuk di-save: \n");
    printf("(pastikan file berakhiran .txt) >>> ");
    readConsoleInput();
    readWord();
    char *saveName = stringify(currentWord);

    FILE *file = NULL;
    file = fopen(saveName, "w");
    //ukuran map
    fprintf(file, "%d ", gameState.gameMap.hSize);
    fprintf(file, "%d\n", gameState.gameMap.vSize);

    //lokasi HQ
    fprintf(file, "%d ", _getLocationBySymbol(gameState.gameMap._locations, '8').coordinate.x);
    fprintf(file, "%d\n", _getLocationBySymbol(gameState.gameMap._locations, '8').coordinate.y);

    //lokasi gedung
    fprintf(file, "%d\n", length(gameState.gameMap._locations) - 1);
    int i = 0;
    for (i = 1; i < length(gameState.gameMap._locations); i++)
    {
        Location l = getLocationById(gameState.gameMap, i);
        char symbol = symbol(l);
        int x = x(coord(l));
        int y = y(coord(l));
        fprintf(file, "%c %d %d\n", symbol, x, y);
    }

    //adjacency matrix
    int j = 0;
    for (i = 0; i < rows(gameState.gameMap._adjacency); i++)
    {
        for (j = 0; j < cols(gameState.gameMap._adjacency); j++)
        {
            fprintf(file, "%d", gameState.gameMap._adjacency.contents[i][j]);
            if (j + 1 != cols(gameState.gameMap._adjacency))
            {
                fprintf(file, " ");
            }
        }
        fprintf(file, "\n");
    }
    Item item;
    char itemTypeChar;

    //todolist
    fprintf(file, "%d\n", itemListLength(gameState.todoList));
    for (i = 0; i < itemListLength(gameState.todoList); i++)
    {
        item = getItem(gameState.todoList, i);
        if (item.type == NORMAL)
        {
            itemTypeChar = 'N';
        }
        else if (item.type == HEAVY)
        {
            itemTypeChar = 'H';
        }
        else if (item.type == PERISHABLE)
        {
            itemTypeChar = 'P';
        }
        else if (item.type == VIP)
        {
            itemTypeChar = 'V';
        }
        if (item.type == PERISHABLE)
        {
            fprintf(file, "%d %c %c %c %d %d\n", item.orderTime, item.pickUpLocation.symbol, item.dropOffLocation.symbol, itemTypeChar, item.perishTime, item.perishTimeReference);
        }
        else
        {
            fprintf(file, "%d %c %c %c\n", item.orderTime, item.pickUpLocation.symbol, item.dropOffLocation.symbol, itemTypeChar);
        }
    }
    //inprogress list
    fprintf(file, "%d\n", itemListLength(gameState.inProgressList));
    for (i = 0; i < itemListLength(gameState.inProgressList); i++)
    {
        item = getItem(gameState.inProgressList, i);
        if (item.type == NORMAL)
        {
            itemTypeChar = 'N';
        }
        else if (item.type == HEAVY)
        {
            itemTypeChar = 'H';
        }
        else if (item.type == PERISHABLE)
        {
            itemTypeChar = 'P';
        }
        else if (item.type == VIP)
        {
            itemTypeChar = 'V';
        }
        if (item.type == PERISHABLE)
        {
            fprintf(file, "%d %c %c %c %d %d\n", item.orderTime, item.pickUpLocation.symbol, item.dropOffLocation.symbol, itemTypeChar, item.perishTime, item.perishTimeReference);
        }
        else
        {
            fprintf(file, "%d %c %c %c\n", item.orderTime, item.pickUpLocation.symbol, item.dropOffLocation.symbol, itemTypeChar);
        }
    }

    //bag
    ItemStack tempBag = newItemStack(capacity(gameState.bag));
    int bagcap = 0;
    if (!isStackEmpty(gameState.bag))
    {
        bagcap = topIndex(gameState.bag) + 1;
    }
    fprintf(file, "%d %d\n", capacity(gameState.bag), bagcap);
    while (!isStackEmpty(gameState.bag))
    {
        pop(&gameState.bag, &item);
        if (item.type == NORMAL)
        {
            itemTypeChar = 'N';
        }
        else if (item.type == HEAVY)
        {
            itemTypeChar = 'H';
        }
        else if (item.type == PERISHABLE)
        {
            itemTypeChar = 'P';
        }
        else if (item.type == VIP)
        {
            itemTypeChar = 'V';
        }
        if (item.type == PERISHABLE)
        {
            fprintf(file, "%d %c %c %c %d %d\n", item.orderTime, item.pickUpLocation.symbol, item.dropOffLocation.symbol, itemTypeChar, item.perishTime, item.perishTimeReference);
        }
        else
        {
            fprintf(file, "%d %c %c %c\n", item.orderTime, item.pickUpLocation.symbol, item.dropOffLocation.symbol, itemTypeChar);
        }
        push(&tempBag, item);
    }
    //balikin lagi isi bag
    while (!isStackEmpty(tempBag))
    {
        pop(&tempBag, &item);
        push(&gameState.bag, item);
    }

    //order
    ItemQueue tempOrder = newItemQueue();
    int qLength = 0;
    if (!isEmpty(gameState.order))
    {
        qLength = gameState.order.tailIndex - gameState.order.headIndex + 1;
    }
    fprintf(file, "%d\n", qLength);
    while (!isEmpty(gameState.order))
    {
        dequeue(&gameState.order, &item);
        if (item.type == NORMAL)
        {
            itemTypeChar = 'N';
        }
        else if (item.type == HEAVY)
        {
            itemTypeChar = 'H';
        }
        else if (item.type == PERISHABLE)
        {
            itemTypeChar = 'P';
        }
        else if (item.type == VIP)
        {
            itemTypeChar = 'V';
        }
        if (item.type == PERISHABLE)
        {
            fprintf(file, "%d %c %c %c %d %d\n", item.orderTime, item.pickUpLocation.symbol, item.dropOffLocation.symbol, itemTypeChar, item.perishTime, item.perishTimeReference);
        }
        else
        {
            fprintf(file, "%d %c %c %c\n", item.orderTime, item.pickUpLocation.symbol, item.dropOffLocation.symbol, itemTypeChar);
        }
        enqueue(&tempOrder, item);
    }

    //balikin lagi isi order
    while (!isEmpty(tempOrder))
    {
        dequeue(&tempOrder, &item);
        enqueue(&gameState.order, item);
    }

    //time + cash
    fprintf(file, "%d %d\n", gameState.time, gameState.cash);
    //gadgetList
    for (i = 0; i < 5; i++)
    {
        Gadget tempGadget = getGadget(gameState.inventory, i);
        fprintf(file, "%d\n", tempGadget.id);
    }
    //currentLocation
    fprintf(file, "%c %d %d\n", gameState.currentLocation.symbol, gameState.currentLocation.coordinate.x, gameState.currentLocation.coordinate.y);

    //speedBoost
    fprintf(file, "%d %d %d\n", gameState.abs.SpeedBoost, gameState.abs.SpeedBoostCount, gameState.abs.SpeedBoostStack);
    fprintf(file, "%d %d\n", gameState.abs.IsSenterPengecilOn, gameState.abs.PintuKemanaSaja);
    fprintf(file, "%d %d\n", gameState.abs.IsHeavyItemOn, gameState.abs.HeavyItemStack);
    fprintf(file, "%d %d %d %d %d\n", gameState.abs.IsVIPItemOn, gameState.abs.VIPItemStack, gameState.abs.TodoVIP, gameState.abs.IsReturnOn, gameState.abs.ReturnStack);
    fclose(file);
    printf("File berhasil disimpan!");
}