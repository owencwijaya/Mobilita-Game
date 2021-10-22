#include <stdio.h>
#include "listpos.c"
#define enter printf("\n")
int main(){
    ListPos l;
    readList(&l);
    displayList(l);
    printf("\n%d\n", length(l));
    isFull(l) ? printf("yes") : printf("no");
    enter;
    isEmpty(l) ? printf("yes") : printf("no");
    ListPos l2;
    readList(&l2);
    displayList(l2);
    printf("\n%d\n", length(l2));
    displayList(plusMinusTab(l, l2, true)); enter;
    displayList(plusMinusTab(l, l2, false));
    printf("\n%d", indexOf(l, 7));
    int max, min = 0;
    isListEqual(l, l2) ? printf("yes") : printf("no");
    displayList(l); displayList(l2);
    extremes(l, &max, &min);
    printf("\n%d %d", max, min);
    enter;
    isAllEven(l) ? printf("Yes") : printf("No");
    sort(&l, false); enter;
    displayList(l);
    sort(&l, true); enter;
    displayList(l);
    insertLast(&l, 6); enter;
    displayList(l);
    int val;
    deleteLast(&l, &val);
    enter; displayList(l); enter;
    printf("%d", val);
    

}


