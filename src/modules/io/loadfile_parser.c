#include <stdio.h>

#include "../models/map/location/location.h"
#include "../models/map/location/location_list.h"
#include "../models/map/location/point.h"
#include "../models/map/boolean_matrix.h"
#include "../models/item/item_queue.h"
#include "../models/item/item.h"
#include "../models/map/game_map.h"
#include "../models/shared/macros.h"
#include "../core/globals.h"
#include "./machines/wordmachine.h"
#include "word_utils.h"

void parseLoad(char *path)
{
    // * Read config file path
    readFile(path);
    // * Set map size
    int mapLength, mapWidth;
    readWord();
    readNextWord();
    mapLength = parseInt(stringify(currentWord));
    readNextWord();
    mapWidth = parseInt(stringify(currentWord));

    // * Parse HQ location
    Location hq;
    Point hqCoord;
    int hq_abs, hq_ord;
    readNextWord();
    hq_abs = parseInt(stringify(currentWord));
    readNextWord();
    hq_ord = parseInt(stringify(currentWord));
    hqCoord = newPoint(hq_abs, hq_ord);
    hq = newLocation(0, '8', hqCoord);

    // * Locations list
    int locationCount;
    readNextWord();
    locationCount = parseInt(stringify(currentWord)) + 1;

    LocationList lList = newLocationList(locationCount);
    insertLast(&lList, hq);
    Location loc;
    Point coord;
    int location_abs, location_ord;
    char symbol;

    for (int i = 1; i < locationCount; i++)
    {
        readNextWord();
        symbol = stringify(currentWord)[0];
        readNextWord();
        location_abs = parseInt(stringify(currentWord));
        readNextWord();
        location_ord = parseInt(stringify(currentWord));
        coord = newPoint(location_abs, location_ord);
        loc = newLocation(i, symbol, coord);

        insertLast(&lList, loc);
    }

    // * Adjacency matrix
    BooleanMatrix adjMatrix;
    adjMatrix = newBooleanMatrix(locationCount, locationCount);

    for (int i = 0; i < locationCount; i++)
    {
        for (int j = 0; j < locationCount; j++)
        {
            readNextWord();
            elem(adjMatrix, i, j) = parseInt(stringify(currentWord));
        }
    }

    int itemCount;
    int orderTime, perishTime, itemType, perishTimeReference;
    char pickUpLocSymbol, dropOffLocSymbol, type;
    Location pickUpLocation, dropOffLocation;
    Item item;

    //todoList
    readNextWord();
    ItemList todoList = newItemList();
    itemCount = parseInt(stringify(currentWord));

    for (int i = 0; i < itemCount; i++)
    {
        readNextWord();
        orderTime = parseInt(stringify(currentWord));
        readNextWord();
        pickUpLocSymbol = stringify(currentWord)[0];
        pickUpLocation = _getLocationBySymbol(lList, pickUpLocSymbol);
        readNextWord();
        dropOffLocSymbol = stringify(currentWord)[0];
        dropOffLocation = _getLocationBySymbol(lList, dropOffLocSymbol);
        readNextWord();
        type = stringify(currentWord)[0];
        switch (type)
        {
        case 'N':
            itemType = NORMAL;
            break;
        case 'H':
            itemType = HEAVY;
            break;
        case 'P':
            itemType = PERISHABLE;
            break;
        case 'V':
            itemType = VIP;
            break;
        }

        if (itemType == PERISHABLE)
        {
            readNextWord();
            perishTime = parseInt(stringify(currentWord));
            readNextWord();
            perishTimeReference = parseInt(stringify(currentWord));
        }
        else
        {
            perishTime = UNTIMED;
            perishTimeReference = UNTIMED;
        }
        item = newItem(orderTime, pickUpLocation, dropOffLocation, itemType, perishTime, perishTimeReference);
        insertItemLast(&todoList, item);
    }

    //inprogress
    readNextWord();
    ItemList inProgressList = newItemList();
    itemCount = parseInt(stringify(currentWord));

    for (int i = 0; i < itemCount; i++)
    {
        readNextWord();
        orderTime = parseInt(stringify(currentWord));
        readNextWord();
        pickUpLocSymbol = stringify(currentWord)[0];
        pickUpLocation = _getLocationBySymbol(lList, pickUpLocSymbol);
        readNextWord();
        dropOffLocSymbol = stringify(currentWord)[0];
        dropOffLocation = _getLocationBySymbol(lList, dropOffLocSymbol);
        readNextWord();
        type = stringify(currentWord)[0];
        switch (type)
        {
        case 'N':
            itemType = NORMAL;
            break;
        case 'H':
            itemType = HEAVY;
            break;
        case 'P':
            itemType = PERISHABLE;
            break;
        case 'V':
            itemType = VIP;
            break;
        }

        if (itemType == PERISHABLE)
        {
            readNextWord();
            perishTime = parseInt(stringify(currentWord));
            readNextWord();
            perishTimeReference = parseInt(stringify(currentWord));
        }
        else
        {
            perishTime = UNTIMED;
            perishTimeReference = UNTIMED;
        }
        item = newItem(orderTime, pickUpLocation, dropOffLocation, itemType, perishTime, perishTimeReference);
        insertItemLast(&inProgressList, item);
    }

    //bag
    readNextWord();
    int bagCapacity = parseInt(stringify(currentWord));

    ItemStack bag = newItemStack(bagCapacity);
    ItemStack tempBag;
    readNextWord();
    itemCount = parseInt(stringify(currentWord));
    for (int i = 0; i < itemCount; i++)
    {
        readNextWord();
        orderTime = parseInt(stringify(currentWord));
        readNextWord();
        pickUpLocSymbol = stringify(currentWord)[0];
        pickUpLocation = _getLocationBySymbol(lList, pickUpLocSymbol);
        readNextWord();
        dropOffLocSymbol = stringify(currentWord)[0];
        dropOffLocation = _getLocationBySymbol(lList, dropOffLocSymbol);
        readNextWord();
        type = stringify(currentWord)[0];
        switch (type)
        {
        case 'N':
            itemType = NORMAL;
            break;
        case 'H':
            itemType = HEAVY;
            break;
        case 'P':
            itemType = PERISHABLE;
            break;
        case 'V':
            itemType = VIP;
            break;
        }

        if (itemType == PERISHABLE)
        {
            readNextWord();
            perishTime = parseInt(stringify(currentWord));
            readNextWord();
            perishTimeReference = parseInt(stringify(currentWord));
        }
        else
        {
            perishTime = UNTIMED;
            perishTimeReference = UNTIMED;
        }
        item = newItem(orderTime, pickUpLocation, dropOffLocation, itemType, perishTime, perishTimeReference);
        push(&bag, item);
    }

    Item tempItem;
    tempBag = newItemStack(capacity(bag));
    while (!isStackEmpty(bag))
    {
        pop(&bag, &tempItem);
        push(&tempBag, tempItem);
    }

    //order
    readNextWord();
    itemCount = parseInt(stringify(currentWord));

    ItemQueue order = newItemQueue();

    for (int i = 0; i < itemCount; i++)
    {
        readNextWord();
        orderTime = parseInt(stringify(currentWord));
        readNextWord();
        pickUpLocSymbol = stringify(currentWord)[0];
        pickUpLocation = _getLocationBySymbol(lList, pickUpLocSymbol);
        readNextWord();
        dropOffLocSymbol = stringify(currentWord)[0];
        dropOffLocation = _getLocationBySymbol(lList, dropOffLocSymbol);
        readNextWord();
        type = stringify(currentWord)[0];
        switch (type)
        {
        case 'N':
            itemType = NORMAL;
            break;
        case 'H':
            itemType = HEAVY;
            break;
        case 'P':
            itemType = PERISHABLE;
            break;
        case 'V':
            itemType = VIP;
            break;
        }

        if (itemType == PERISHABLE)
        {
            readNextWord();
            perishTime = parseInt(stringify(currentWord));
            readNextWord();
            perishTimeReference = parseInt(stringify(currentWord));
        }
        else
        {
            perishTime = UNTIMED;
            perishTimeReference = UNTIMED;
        }
        item = newItem(orderTime, pickUpLocation, dropOffLocation, itemType, perishTime, perishTimeReference);
        enqueue(&order, item);
    }

    GameMap g = newGameMap(mapLength, mapWidth, adjMatrix, lList);
    gameState = newState(g, todoList, inProgressList, tempBag, order);
    readNextWord();
    gameState.time = parseInt(stringify(currentWord));
    readNextWord();
    gameState.cash = parseInt(stringify(currentWord));
    int gadgetID;

    GadgetList tempGList = newGadgetList();
    for (int i = 0; i < 5; i++)
    {
        readNextWord();
        gadgetID = parseInt(stringify(currentWord));
        if (gadgetID == 0)
        {
            insertGadget(&tempGList, KAIN_PEMBUNGKUS_WAKTU);
        }
        else if (gadgetID == 1)
        {
            insertGadget(&tempGList, SENTER_PEMBESAR);
        }
        else if (gadgetID == 2)
        {
            insertGadget(&tempGList, PINTU_KEMANA_SAJA);
        }
        else if (gadgetID == 3)
        {
            insertGadget(&tempGList, MESIN_WAKTU);
        }
        else if (gadgetID == 4)
        {
            insertGadget(&tempGList, SENTER_PENGECIL);
        }
        else if (gadgetID == -1)
        {
            insertGadget(&tempGList, SENTER_PENGECIL);
        }
    }

    gameState.inventory = tempGList;

    readNextWord();
    char *playerLocSymbol = stringify(currentWord);
    readNextWord();
    int playerAbs = parseInt(stringify(currentWord));
    readNextWord();
    int playerOrd = parseInt(stringify(currentWord));
    setPlayerLocation(&gameState.gameMap, playerAbs, playerOrd);
    setAsPlayerPlace(&gameState.gameMap._locationMatrix.contents[playerAbs][playerOrd]);
    gameState.currentLocation = gameState.gameMap._locationMatrix.contents[playerAbs][playerOrd];
    readNextWord();

    int sbFlag = parseInt(stringify(currentWord));
    if (sbFlag)
    {
        gameState.abs.SpeedBoost = true;
    }
    readNextWord();
    int sbCount = parseInt(stringify(currentWord));
    gameState.abs.SpeedBoostCount = sbCount;
    readNextWord();
    int sbStack = parseInt(stringify(currentWord));
    gameState.abs.SpeedBoostStack = sbStack;

    readNextWord();
    int spOn = parseInt(stringify(currentWord));
    if (spOn)
    {
        gameState.abs.IsSenterPengecilOn = true;
    }

    readNextWord();
    int pintu = parseInt(stringify(currentWord));
    if (pintu)
    {
        gameState.abs.PintuKemanaSaja = true;
    }

    readNextWord();
    int heavyFlag = parseInt(stringify(currentWord));
    if (heavyFlag)
    {
        gameState.abs.IsHeavyItemOn = true;
    }

    readNextWord();
    int heavyStack = parseInt(stringify(currentWord));
    if (heavyFlag)
    {
        gameState.abs.HeavyItemStack = heavyStack;
    }

    readNextWord();
    int vipFlag = parseInt(stringify(currentWord));
    if (vipFlag)
    {
        gameState.abs.IsVIPItemOn = true;
    }

    readNextWord();
    int vipStack = parseInt(stringify(currentWord));
    if (vipFlag)
    {
        gameState.abs.VIPItemStack = vipStack;
    }

    readNextWord();
    int todoVIP = parseInt(stringify(currentWord));
    gameState.abs.TodoVIP = todoVIP;

    readNextWord();
    int returnFlag = parseInt(stringify(currentWord));
    if (returnFlag)
    {
        gameState.abs.IsReturnOn = true;
    }

    readNextWord();
    int returnStack = parseInt(stringify(currentWord));
    if (returnFlag)
    {
        gameState.abs.ReturnStack = returnStack;
    }

    printf("File save berhasil diload!\n");

    setAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).dropOffLocation.coordinate.x][top(gameState.bag).dropOffLocation.coordinate.y]);
    for (int i = 0; i < itemListLength(gameState.todoList); i++)
    {
        Item temp = getItem(gameState.todoList, i);
        setAsPickUpPlace(&gameState.gameMap._locationMatrix.contents[temp.pickUpLocation.coordinate.x][temp.pickUpLocation.coordinate.y]);
    }
}