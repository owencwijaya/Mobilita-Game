/**
 * @file gadget.c
 * @brief Implementasi tipe data Gadget.
 */

#include <stdio.h>
#include "boolean.h"
#include "gadget.h"
#include "macros.h"

/**
 * @brief Instance Gadget "Kain Pembungkus Waktu".
 */
const Gadget KAIN_PEMBUNGKUS_WAKTU = {0, 800, "Kain Pembungkus Waktu"};
/**
 * @brief Instance Gadget "Senter Pembesar".
 */
const Gadget SENTER_PEMBESAR = {1, 1200, "Senter Pembesar"};
/**
 * @brief Instance Gadget "Pintu Kemana Saja".
 */
const Gadget PINTU_KEMANA_SAJA = {2, 1500, "Pintu Kemana Saja"};
/**
 * @brief Instance Gadget "Mesin Waktu".
 */
const Gadget MESIN_WAKTU = {3, 3000, "Mesin Waktu"};
/**
 * @brief Instance Gadget "Senter Pengecil".
 */
const Gadget SENTER_PENGECIL = {4, 800, "Senter Pengecil"};
/**
 * @brief Instance Gadget yang tidak terdefinisi.
 */
const Gadget NULL_GADGET = {-1, -1, "-"};

/**
 * @brief Mengecek apakah dua gadget adalah sama.
 * Pengecekan dilakukan berdasarkan id.
 * 
 * @param gadget1 Gadget instance.
 * @param gadget2 Gadget isntance.
 * @return true jika kedua Gadget adalah sama, false selainnya.
 */
boolean isGadgetIdentical(Gadget gadget1, Gadget gadget2)
{
    return id(gadget1) == id(gadget2);
}

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
    printf("  id : %d\n", id(g));
    printf("  price : %d\n", price(g));
    printf("  name : %s\n", name(g));
    printf("}\n");
}