#include <stdio.h>

// #include "../../models/location.h"
// #include "../../models/location_list.h"
// #include "../../models/point.h"
// #include "../../models/boolean_matrix.h"
// #include "../../models/item_queue.h"
// #include "../../models/item.h"
// #include "../../models/game_map.h"
// #include "../../models/macros.h"
// #include "../core/globals.h"
// #include "./machines/wordmachine.h"
// #include "word_utils.h"

#include "../../models/gadget.c"
#include "../../models/gadget_list.c"
#include "../../models/location.c"
#include "../../models/location_list.c"
#include "../../models/location_matrix.c"
#include "../../models/point.c"
#include "../../models/state.c"
#include "../../models/boolean_matrix.c"
#include "../../models/item_queue.c"
#include "../../models/item.c"
#include "../../models/item_list.c"
#include "../../models/item_stack.c"
#include "../../models/game_map.c"
#include "../../models/macros.h"
#include "../core/globals.h"
#include "./machines/wordmachine.c"
#include "./machines/charmachine.c"
#include "../colorizer/colorizer.c"
#include "word_utils.c"

void parseConfig(char *path)
{
    readFile(path);
    int mapLength, mapWidth;
    readWord();
    mapLength = parseInt(stringify(currentWord));
    readNextWord();
    mapWidth = parseInt(stringify(currentWord));

    Location hq;
    Point hqCoord;
    int hq_abs, hq_ord;
    readNextWord();
    hq_abs = parseInt(stringify(currentWord));
    readNextWord();
    hq_ord = parseInt(stringify(currentWord));
    hqCoord = newPoint(hq_abs, hq_ord);
    hq = newLocation(0, '8', hqCoord);

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
    readNextWord();
    itemCount = parseInt(stringify(currentWord));
    int orderTime, perishTime, itemType, perishTimeReference;
    char pickUpLocSymbol, dropOffLocSymbol, type;
    Location pickUpLocation, dropOffLocation;
    ItemQueue order = newItemQueue();
    Item item;
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

        setAsPickUpPlace(&pickUpLocation);
        setAsDropOffPlace(&dropOffLocation);

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
    gameState = newState(g, newItemList(), newItemList(), newItemStack(3), order);
}

void _dumpConfig()
{
}