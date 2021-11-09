#include <stdlib.h>
#include <stdio.h>
#include "gadget_list.h"
#include "gadget.h"

int main()
{
    GadgetList gList = newGadgetList();
    initGadget();

    printf("\033[38;5;14mSECTION 1 : displayGadget, isGadgetListEmpty\033[0m\n");
    displayGadget(gList);
    printf("Empty : %s\n", isGadgetListEmpty(gList) ? "TRUE" : "FALSE");
    printf("\n");

    printf("\033[38;5;14mSECTION 2 : setGadget\033[0m\n");
    setGadget(gList, 0, SENTER_PEMBESAR);
    displayGadget(gList);
    printf("\n");

    printf("\033[38;5;14mSECTION 3 : insertGadget, isGadgetFull\033[0m\n");
    insertGadget(gList, KAIN_PEMBUNGKUS_WAKTU);
    insertGadget(gList, PINTU_KEMANA_SAJA);
    insertGadget(gList, SENTER_PENGECIL);
    insertGadget(gList, MESIN_WAKTU);
    displayGadget(gList);
    printf("Full : %s\n", isGadgetListFull(gList) ? "TRUE" : "FALSE");
    printf("Empty : %s\n\n", isGadgetListEmpty(gList) ? "TRUE" : "FALSE");

    printf("\033[38;5;14mSECTION 4 : deleteGadget, gListLength\033[0m\n");
    Gadget g;
    g = deleteGadget(gList, 2);
    displayGadget(gList);
    printf("Full : %s\n", isGadgetListFull(gList) ? "TRUE" : "FALSE");
    printf("Empty : %s\n", isGadgetListEmpty(gList) ? "TRUE" : "FALSE");
    printf("Gadget : %s\n", name(g));
    printf("Length : %d\n", gListLength(gList));
    printf("\n");

    printf("\033[38;5;14mSECTION 5 : mixed cases\033[0m\n");
    g = deleteGadget(gList, 4);
    displayGadget(gList);
    printf("\n\n");
    insertGadget(gList, PINTU_KEMANA_SAJA);
    displayGadget(gList);
    printf("\n\n");
    g = deleteGadget(gList, 3);
    g = deleteGadget(gList, 2);
    g = deleteGadget(gList, 1);
    g = deleteGadget(gList, 0);
    displayGadget(gList);
    printf("Full : %s\n", isGadgetListFull(gList) ? "TRUE" : "FALSE");
    printf("Empty : %s\n", isGadgetListEmpty(gList) ? "TRUE" : "FALSE");
    printf("Length : %d\n", gListLength(gList));
    printf("\n");

    return 0;
}