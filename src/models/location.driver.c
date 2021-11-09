#include <stdio.h>
#include "location.h"

int main()
{
    Location a, b, c, d;
    Point p = newPoint(1, 2);
    a = newLocation(0, 'A', p);
    b = newLocation(1, 'B', newPoint(5, 1));
    c = newLocation(2, 'C', newPoint(4, 3));
    d = newLocation(3, 'D', newPoint(2, 7));

    printf("\033[38;5;14mSECTION 1 : isAt, isLocationIdentical, isLocationDefined\033[0m\n");
    printf("a = ");
    _dumpLocation(a);
    printf("\n");
    printf("b = ");
    _dumpLocation(b);
    printf("\n");
    printf("c = ");
    _dumpLocation(c);
    printf("\n");
    printf("d = ");
    _dumpLocation(d);
    printf("\n");

    printf("a is at (1, 2) ? %s\n", isAt(a, p) ? "TRUE" : "FALSE");
    printf("b is at (1, 2) ? %s\n", isAt(b, p) ? "TRUE" : "FALSE");
    printf("c is at (1, 2) ? %s\n", isAt(c, p) ? "TRUE" : "FALSE");
    printf("d is at (1, 2) ? %s\n", isAt(d, p) ? "TRUE" : "FALSE");
    printf("a == A ? %s\n", isLocationIdentical(a, a) ? "TRUE" : "FALSE");
    printf("b == A ? %s\n", isLocationIdentical(b, a) ? "TRUE" : "FALSE");
    printf("c == A ? %s\n", isLocationIdentical(c, a) ? "TRUE" : "FALSE");
    printf("d == A ? %s\n", isLocationIdentical(d, a) ? "TRUE" : "FALSE");
    // printf("a is defined ? %s\n", isLocationDefined(a) ? "TRUE" : "FALSE");
    // printf("b is defined ? %s\n", isLocationDefined(b) ? "TRUE" : "FALSE");
    // printf("c is defined ? %s\n", isLocationDefined(c) ? "TRUE" : "FALSE");
    // printf("d is defined ? %s\n", isLocationDefined(d) ? "TRUE" : "FALSE");

    printf("\033[38;5;14mSECTION 2 : set/unset\033[0m\n");
    setAsPlayerPlace(a);
    setAsPickUpPlace(a);
    setAsDropOffPlace(a);
    setAsReachable(a);
    _dumpLocation(a);
    printf("\n");
    unsetAsPlayerPlace(a);
    unsetAsPickUpPlace(a);
    unsetAsDropOffPlace(a);
    unsetAsReachable(a);
    _dumpLocation(a);
    printf("\n\n");

    printf("\033[38;5;14mSECTION 3 : writeLocationSymbol\033[0m\n");
    setAsPlayerPlace(a);
    setAsPickUpPlace(a);
    setAsDropOffPlace(a);
    setAsReachable(a);

    setAsPickUpPlace(b);
    setAsDropOffPlace(b);
    setAsReachable(b);

    setAsPickUpPlace(c);
    setAsReachable(c);

    setAsReachable(d);

    _dumpLocation(a);
    writeLocationSymbol(a);
    printf("\n");
    printf("\n");
    _dumpLocation(b);
    writeLocationSymbol(b);
    printf("\n");
    printf("\n");
    _dumpLocation(c);
    writeLocationSymbol(c);
    printf("\n");
    printf("\n");
    _dumpLocation(d);
    writeLocationSymbol(d);
    printf("\n");
    printf("\n");

    unsetAsReachable(d);
    _dumpLocation(d);
    writeLocationSymbol(d);
    printf("\n");
    printf("\n");
}