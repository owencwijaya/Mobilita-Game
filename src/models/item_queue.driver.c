#include <stdio.h>
#include "item_queue.h"
#include "item.h"
#include "macros.h"

int main()
{
    Location a = newLocation(0, 'A', newPoint(0, 0));
    Location b = newLocation(1, 'B', newPoint(1, 1));
    Location c = newLocation(2, 'C', newPoint(1, 3));
    Item x = newItem(3, a, b, NORMAL, UNTIMED, UNTIMED);
    Item y = newItem(1, b, c, HEAVY, UNTIMED, UNTIMED);
    ItemQueue queue = newItemQueue();

    printf("x = Item(orderTime = %d)\n", orderTime(x));
    printf("y = Item(orderTime = %d)\n", orderTime(y));

    printf("queue = ItemQueue[0]\n");
    printf("enqueue x ...\n");
    enqueue(&queue, x);
    printf("head order time : %d\n", peekHeadTime(queue));
    printf("enqueue y ...\n");
    enqueue(&queue, y);
    printf("head order time : %d\n", peekHeadTime(queue));
    printf("queue = ItemQueue[y, x]\n");

    Item z;
    dequeue(&queue, &z);
    printf("dequeue queue\n");
    printf("Item == x ? %s\n", isItemIdentical(z, x) ? "TRUE" : "FALSE");
    printf("Item == y ? %s\n", isItemIdentical(z, y) ? "TRUE" : "FALSE");
    dequeue(&queue, &z);
    printf("dequeue queue\n");
    printf("Item == x ? %s\n", isItemIdentical(z, x) ? "TRUE" : "FALSE");
    printf("Item == y ? %s\n", isItemIdentical(z, y) ? "TRUE" : "FALSE");
}