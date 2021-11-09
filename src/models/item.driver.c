#include <stdio.h>
#include "item.h"
#include "location.h"
#include "point.h"
#include "../modules/colorizer/colorizer.h"

int main()
{
    Location l1, l2;
    l1 = newLocation(0, 'A', newPoint(1, 1));
    l2 = newLocation(1, 'B', newPoint(1, 3));
    Item a, b, c, d;
    a = newItem(1, l1, l2, NORMAL, UNTIMED, UNTIMED);
    b = newItem(3, l2, l1, HEAVY, UNTIMED, UNTIMED);
    c = newItem(10, l2, l1, PERISHABLE, 10, 10);
    d = newItem(200, l1, l2, VIP, UNTIMED, UNTIMED);

    printf("a = ");
    _dumpItem(a);
    printf("\n");
    printf("b = ");
    _dumpItem(b);
    printf("\n");
    printf("c = ");
    _dumpItem(c);
    printf("\n");
    printf("d = ");
    _dumpItem(d);
    printf("\n\n");

    printf("a == a ? %s\n", a == a ? "TRUE" : "FALSE");
    printf("a == b ? %s\n", a == b ? "TRUE" : "FALSE");
    printf("a == c ? %s\n", a == c ? "TRUE" : "FALSE");
    printf("a == d ? %s\n", a == d ? "TRUE" : "FALSE");
    printf("\n\n");

    printf("is a normal item ? %s\n", isNormalItem(a) ? "TRUE" : "FALSE");
    printf("is a heavy item ? %s\n", isHeavyItem(a) ? "TRUE" : "FALSE");
    printf("is a perishable item ? %s\n", isPerishableItem(a) ? "TRUE" : "FALSE");
    printf("is a VIP item ? %s\n", isVIPItem(a) ? "TRUE" : "FALSE");
    printf("\n");

    printf("is b normal item ? %s\n", isNormalItem(b) ? "TRUE" : "FALSE");
    printf("is b heavy item ? %s\n", isHeavyItem(b) ? "TRUE" : "FALSE");
    printf("is b perishable item ? %s\n", isPerishableItem(b) ? "TRUE" : "FALSE");
    printf("is b VIP item ? %s\n", isVIPItem(b) ? "TRUE" : "FALSE");
    printf("\n");

    printf("is c normal item ? %s\n", isNormalItem(c) ? "TRUE" : "FALSE");
    printf("is c heavy item ? %s\n", isHeavyItem(c) ? "TRUE" : "FALSE");
    printf("is c perishable item ? %s\n", isPerishableItem(c) ? "TRUE" : "FALSE");
    printf("is c VIP item ? %s\n", isVIPItem(c) ? "TRUE" : "FALSE");
    printf("\n");

    printf("is d normal item ? %s\n", isNormalItem(d) ? "TRUE" : "FALSE");
    printf("is d heavy item ? %s\n", isHeavyItem(d) ? "TRUE" : "FALSE");
    printf("is d perishable item ? %s\n", isPerishableItem(d) ? "TRUE" : "FALSE");
    printf("is d VIP item ? %s\n", isVIPItem(d) ? "TRUE" : "FALSE");
    printf("\n");
    return 0;
}