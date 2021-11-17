#include <stdio.h>
#include "gadget.h"
#include "../shared/boolean.h"

int main()
{
    printf("\033[38;5;14mSECTION 1 : Dump data Gadget\033[0m\n");
    printf("KAIN_PEMBUNGKUS_WAKTU = ");
    _dumpGadget(KAIN_PEMBUNGKUS_WAKTU);
    printf("\n");
    printf("SENTER_PEMBESAR = ");
    _dumpGadget(SENTER_PEMBESAR);
    printf("\n");
    printf("PINTU_KEMANA_SAJA = ");
    _dumpGadget(PINTU_KEMANA_SAJA);
    printf("\n");
    printf("MESIN_WAKTU = ");
    _dumpGadget(MESIN_WAKTU);
    printf("\n");
    printf("SENTER_PENGECIL = ");
    _dumpGadget(SENTER_PENGECIL);
    printf("\n\n");

    printf("\033[38;5;14mSECTION 2 : isGadgetIdentical\033[0m\n");
    printf("KAIN_PEMBUNGKUS_WAKTU == KAIN_PEMBUNGKUS_WAKTU ? %s\n", isGadgetIdentical(KAIN_PEMBUNGKUS_WAKTU, KAIN_PEMBUNGKUS_WAKTU) ? "TRUE" : "FALSE");
    printf("KAIN_PEMBUNGKUS_WAKTU == SENTER_PEMBESAR ? %s\n", isGadgetIdentical(KAIN_PEMBUNGKUS_WAKTU, SENTER_PEMBESAR) ? "TRUE" : "FALSE");
    printf("KAIN_PEMBUNGKUS_WAKTU == PINTU_KEMANA_SAJA ? %s\n", isGadgetIdentical(KAIN_PEMBUNGKUS_WAKTU, PINTU_KEMANA_SAJA) ? "TRUE" : "FALSE");
    printf("KAIN_PEMBUNGKUS_WAKTU == MESIN_WAKTU ? %s\n", isGadgetIdentical(KAIN_PEMBUNGKUS_WAKTU, MESIN_WAKTU) ? "TRUE" : "FALSE");
    printf("KAIN_PEMBUNGKUS_WAKTU == SENTER_PENGECIL ? %s\n", isGadgetIdentical(KAIN_PEMBUNGKUS_WAKTU, SENTER_PENGECIL) ? "TRUE" : "FALSE");
    printf("KAIN_PEMBUNGKUS_WAKTU == NULL_GADGET ? %s\n", isGadgetIdentical(KAIN_PEMBUNGKUS_WAKTU, NULL_GADGET) ? "TRUE" : "FALSE");

    return 0;
}