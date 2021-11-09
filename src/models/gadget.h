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
struct gadget
{
    /**
     * @brief Harga gadget.
     */
    int price;
    /**
     * @brief Nama gadget.
     */
    char *name;
};

/**
 * @brief Tipe data referensi gadget.
 * 
 */
typedef struct gadget *Gadget;

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
 * @brief List semua gadget yang ada dalam game.
 */
extern Gadget GADGETS[5];

/**
 * @brief Mengambil property price dari sebuah Gadget.
 * @param g Gadget instance.
 */
#define price(g) (g)->price
/**
 * @brief Mengambil property name dari sebuah Gadget.
 * @param g Gadget instance.
 */
#define name(g) (g)->name

/**
 * @brief Menginisialisasi nilai semua gadget yang ada.
 * 
 */
void initGadget();

/**
 * @brief Mengecek apakah dua gadget adalah sama.
 * Pengecekan dilakukan berdasarkan id.
 * 
 * @param gadget1 Gadget instance.
 * @param gadget2 Gadget isntance.
 * @return true jika kedua Gadget adalah sama, false selainnya.
 */
boolean isGadgetIdentical(Gadget gadget1, Gadget gadget2);

/**
 * @private 
 * @brief Print isi data gadget ke console.
 * ! Private! Jangan digunakan di main program.
 * ! Hanya digunakan untuk driver.
 * @param g GadgetList instance.
 */
void _dumpGadget(Gadget g);

#endif