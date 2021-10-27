#include <stdio.h>
#include "point.h"
#include "boolean.h"

int main()
{
    Point a, b, c, d;
    a = newPoint(3, 2);
    b = newPoint(4, 5);
    c = newPoint(4, 4);
    d = newPoint(3, 2);

    printf("\033[38;5;14mSECTION 1 : displayPoint\033[0m\n");
    printf("a = ");
    displayPoint(a);
    printf("\nb = ");
    displayPoint(b);
    printf("\nc = ");
    displayPoint(c);
    printf("\nd = ");
    displayPoint(d);
    printf("\n\n");

    printf("\033[38;5;14mSECTION 2 : isPointIdentical\033[0m\n");
    printf("a == a ? %s\n", isPointIdentical(a, a) ? "TRUE" : "FALSE");
    printf("a == b ? %s\n", isPointIdentical(a, b) ? "TRUE" : "FALSE");
    printf("a == c ? %s\n", isPointIdentical(a, c) ? "TRUE" : "FALSE");
    printf("a == d ? %s\n", isPointIdentical(a, d) ? "TRUE" : "FALSE");
    printf("\n");

    printf("\033[38;5;14mSECTION 2 : isPointBefore\033[0m\n");
    printf("a < a ? %s\n", isPointBefore(a, a) ? "TRUE" : "FALSE");
    printf("a < b ? %s\n", isPointBefore(a, b) ? "TRUE" : "FALSE");
    printf("a < c ? %s\n", isPointBefore(a, c) ? "TRUE" : "FALSE");
    printf("a < d ? %s\n", isPointBefore(a, d) ? "TRUE" : "FALSE");
    printf("b < c ? %s\n", isPointBefore(b, c) ? "TRUE" : "FALSE");
    printf("c < b ? %s\n", isPointBefore(c, b) ? "TRUE" : "FALSE");
}