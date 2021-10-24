/**
 * @file gadget.h
 * @brief Header file untuk tipe data Gadget.
 */

#ifndef GADGET_H
#define GADGET_H

#include "boolean.h"

/**
 * @struct Gadget
 * @brief Tipe data yang merepresentasikan gadget yang dapat dibeli.
 * Tipe data ini tidak memiliki constructor karena Gadget yang ada
 * selalu sama (tidak ada konstruksi instance gadget pada runtime).
 */
typedef struct
{
    /**
     * @brief Identifier gadget yang unik untuk setiap gadget.
     */
    int id;
    /**
     * @brief Harga gadget.
     */
    int price;
    /**
     * @brief Nama gadget.
     */
    char *name;
} Gadget;

/**
 * @brief Mengambil property id dari sebuah Gadget.
 * @param g Gadget instance.
 */
#define id(g) (g).id
/**
 * @brief Mengambil property price dari sebuah Gadget.
 * @param g Gadget instance.
 */
#define price(g) (g).price
/**
 * @brief Mengambil property name dari sebuah Gadget.
 * @param g Gadget instance.
 */
#define name(g) (g).name

/**
 * @brief Instance Gadget "Kain Pembungkus Waktu".
 */
extern Gadget KAIN_PEMBUNGKUS_WAKTU;
/**
 * @brief Instance Gadget "Senter Pembesar".
 */
extern Gadget SENTER_PEMBESAR;
/**
 * @brief Instance Gadget "Pintu Kemana Saja".
 */
extern Gadget PINTU_KEMANA_SAJA;
/**
 * @brief Instance Gadget "Mesin Waktu".
 */
extern Gadget MESIN_WAKTU;
/**
 * @brief Instance Gadget "Senter Pengecil".
 */
extern Gadget SENTER_PENGECIL;
/**
 * @brief Instance Gadget yang tidak terdefinisi.
 */
extern Gadget NULL_GADGET;

/**
 * @brief Mengecek apakah dua gadget adalah sama.
 * Pengecekan dilakukan berdasarkan id.
 * 
 * @param gadget1 Gadget instance.
 * @param gadget2 Gadget isntance.
 * @return true jika kedua Gadget adalah sama, false selainnya.
 */
boolean isGadgetIdentical(Gadget gadget1, Gadget gadget2);

#endif