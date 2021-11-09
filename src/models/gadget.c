/**
 * @file gadget.c
 * @brief Implementasi tipe data Gadget.
 */

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "gadget.h"

/**
 * @brief Instance Gadget "Kain Pembungkus Waktu".
 */
Gadget KAIN_PEMBUNGKUS_WAKTU;
/**
 * @brief Instance Gadget "Senter Pembesar".
 */
Gadget SENTER_PEMBESAR;
/**
 * @brief Instance Gadget "Pintu Kemana Saja".
 */
Gadget PINTU_KEMANA_SAJA;
/**
 * @brief Instance Gadget "Mesin Waktu".
 */
Gadget MESIN_WAKTU;
/**
 * @brief Instance Gadget "Senter Pengecil".
 */
Gadget SENTER_PENGECIL;

/**
 * @brief List semua gadget yang ada dalam game.
 */
Gadget GADGETS[5];

void initGadget()
{
    KAIN_PEMBUNGKUS_WAKTU = (Gadget)malloc(sizeof(struct gadget));
    SENTER_PEMBESAR = (Gadget)malloc(sizeof(struct gadget));
    PINTU_KEMANA_SAJA = (Gadget)malloc(sizeof(struct gadget));
    MESIN_WAKTU = (Gadget)malloc(sizeof(struct gadget));
    SENTER_PENGECIL = (Gadget)malloc(sizeof(struct gadget));
    price(KAIN_PEMBUNGKUS_WAKTU) = 800;
    name(KAIN_PEMBUNGKUS_WAKTU) = "Kain Pembungkus Waktu";
    price(SENTER_PEMBESAR) = 1200;
    name(SENTER_PEMBESAR) = "Senter Pembesar";
    price(PINTU_KEMANA_SAJA) = 1500;
    name(PINTU_KEMANA_SAJA) = "Pintu Kemana Saja";
    price(MESIN_WAKTU) = 3000;
    name(MESIN_WAKTU) = "Mesin Waktu";
    price(SENTER_PENGECIL) = 800;
    name(SENTER_PENGECIL) = "Senter Pengecil";
    GADGETS[0] = KAIN_PEMBUNGKUS_WAKTU;
    GADGETS[1] = SENTER_PEMBESAR;
    GADGETS[2] = PINTU_KEMANA_SAJA;
    GADGETS[3] = MESIN_WAKTU;
    GADGETS[4] = SENTER_PENGECIL;
}

// /**
//  * @brief Mengecek apakah dua gadget adalah sama.
//  * Pengecekan dilakukan berdasarkan id.
//  *
//  * @param gadget1 Gadget instance.
//  * @param gadget2 Gadget isntance.
//  * @return true jika kedua Gadget adalah sama, false selainnya.
//  */
// boolean isGadgetIdentical(Gadget gadget1, Gadget gadget2)
// {
//     return id(gadget1) == id(gadget2);
// }

/**
 * @private 
 * @brief Print isi data gadget ke console.
 * ! Private! Jangan digunakan di main program.
 * ! Hanya digunakan untuk driver.
 * @param g GadgetList instance.
 */
void _dumpGadget(Gadget g)
{
    printf("Gadget {\n");
    // printf("  id : %d\n", id(g));
    printf("  price : %d\n", price(g));
    printf("  name : %s\n", name(g));
    printf("}\n");
}