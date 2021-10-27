#include <stdio.h>
#include "item_list.h"
#include "item.h"
#include "point.h"
#include "location.h"
#include "../modules/colorizer/colorizer.h"

int main()
{
    ItemList iList = newItemList();
    printf("iList = []\n");
    printf("iList is empty ? %s\n", isItemListEmpty(iList) ? "TRUE" : "FALSE");
    printf("is 0 a valid index for iList ? %s\n", isItemListIndexValid(iList, 0) ? "TRUE" : "FALSE");
    printf("\n");

    Location a = newLocation(0, 'A', newPoint(0, 0));
    Location b = newLocation(1, 'B', newPoint(1, 1));
    Location c = newLocation(2, 'C', newPoint(1, 3));
    Item w = newItem(0, a, b, NORMAL, UNTIMED, UNTIMED);
    Item x = newItem(1, b, a, HEAVY, UNTIMED, UNTIMED);
    Item y = newItem(5, b, c, PERISHABLE, 10, 10);
    Item z = newItem(10, c, a, VIP, UNTIMED, UNTIMED);
    insertItemLast(&iList, w);
    insertItemFirst(&iList, x);
    insertItemAt(&iList, 1, y);
    printf("iList = [w, x, y]\n");
    printf("iList[0] = ");
    _dumpItem(getItem(iList, 0));
    printf("\n");
    printf("iList[1] = ");
    _dumpItem(getItem(iList, 1));
    printf("\n");
    printf("iList[2] = ");
    _dumpItem(getItem(iList, 2));
    printf("\n");

    printf("Set iList[1] ke z...\n");
    setItem(&iList, 1, z);
    printf("iList[0] == z ? %s\n", isItemIdentical(getItem(iList, 0), z) ? "TRUE" : "FALSE");
    printf("iList[1] == z ? %s\n", isItemIdentical(getItem(iList, 1), z) ? "TRUE" : "FALSE");
    printf("iList[2] == z ? %s\n", isItemIdentical(getItem(iList, 2), z) ? "TRUE" : "FALSE");
    printf("indexOf z = %d\n", indexOfItem(iList, z));
    printf("iList is empty ? %s\n", isItemListEmpty(iList) ? "TRUE" : "FALSE");
    printf("is 1 a valid index for iList ? %s\n", isItemListIndexValid(iList, 1) ? "TRUE" : "FALSE");
    printf("is 3 a valid index for iList ? %s\n", isItemListIndexValid(iList, 3) ? "TRUE" : "FALSE");
    printf("length = %d\n", itemListLength(iList));
    printf("\n");

    printf("iList = []\n");
    deleteItemAt(&iList, 1, &w);
    deleteItemFirst(&iList, &w);
    deleteItemLast(&iList, &w);
    printf("iList is empty ? %s\n", isItemListEmpty(iList) ? "TRUE" : "FALSE");
    printf("is 1 a valid index for iList ? %s\n", isItemListIndexValid(iList, 1) ? "TRUE" : "FALSE");
    printf("length = %d\n", itemListLength(iList));
    printf("\n");
    return 0;
}