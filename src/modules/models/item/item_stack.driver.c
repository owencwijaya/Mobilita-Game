#include <stdio.h>
#include "../shared/macros.h"
#include "item_stack.h"
#include "item.h"

int main()
{
    Location a = newLocation(0, 'A', newPoint(0, 0));
    Location b = newLocation(1, 'B', newPoint(1, 1));
    Location c = newLocation(2, 'C', newPoint(1, 3));
    Item x = newItem(3, a, b, NORMAL, UNTIMED, UNTIMED);
    Item y = newItem(1, b, c, HEAVY, UNTIMED, UNTIMED);
    ItemStack stack = newItemStack(2);
    printf("capacity(stack) = %d\n", capacity(stack));
    printf("stack is empty ? %s\n", isStackEmpty(stack) ? "TRUE" : "FALSE");
    printf("stack is full ? %s\n", isStackFull(stack) ? "TRUE" : "FALSE");
    printf("\n");

    printf("Insert 1 item ...\n");
    push(&stack, x);
    printf("capacity(stack) = %d\n", capacity(stack));
    printf("stack is empty ? %s\n", isStackEmpty(stack) ? "TRUE" : "FALSE");
    printf("stack is full ? %s\n", isStackFull(stack) ? "TRUE" : "FALSE");
    printf("\n");

    printf("Insert 1 item ...\n");
    push(&stack, y);
    printf("capacity(stack) = %d\n", capacity(stack));
    printf("stack is empty ? %s\n", isStackEmpty(stack) ? "TRUE" : "FALSE");
    printf("stack is full ? %s\n", isStackFull(stack) ? "TRUE" : "FALSE");
    printf("\n");

    printf("Increment stack capacity ...\n");
    incrementCapacity(&stack);
    printf("capacity(stack) = %d\n", capacity(stack));
    printf("stack is empty ? %s\n", isStackEmpty(stack) ? "TRUE" : "FALSE");
    printf("stack is full ? %s\n", isStackFull(stack) ? "TRUE" : "FALSE");

    printf("Double stack capacity ...\n");
    doubleCapacity(&stack);
    printf("capacity(stack) = %d\n", capacity(stack));
    printf("stack is empty ? %s\n", isStackEmpty(stack) ? "TRUE" : "FALSE");
    printf("stack is full ? %s\n", isStackFull(stack) ? "TRUE" : "FALSE");
    printf("\n");

    printf("Double stack capacity ...\n");
    doubleCapacity(&stack);
    printf("Double stack capacity ...\n");
    doubleCapacity(&stack);
    printf("Double stack capacity ...\n");
    doubleCapacity(&stack);
    printf("Double stack capacity ...\n");
    doubleCapacity(&stack);
    printf("capacity(stack) = %d\n", capacity(stack));
    printf("Double stack capacity ...\n");
    doubleCapacity(&stack);
    printf("capacity(stack) = %d\n", capacity(stack));
    printf("Increment stack capacity ...\n");
    incrementCapacity(&stack);
    printf("capacity(stack) = %d\n", capacity(stack));

    return 0;
}