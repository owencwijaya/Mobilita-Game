/**
 * @file gadget_list.h
 * @brief Header file untuk tipe data GadgetList.
 */

#ifndef GADGET_LIST_H
#define GADGET_LIST_H

#include "../shared/boolean.h"
#include "gadget.h"

/**
 * @struct GadgetList
 * @brief List statik berisi tepat 5 Gadget.
 */
typedef struct
{
    /**
     * @brief Array statik dengan panjang 5 berisi Gadget. 
     */
    Gadget contents[5];
} GadgetList;

/**
 * @brief Constructor untuk membuat GadgetList baru.
 * 
 * @return Instance GadgetList berisi 5 Gadget yang tidak terdefinisi. 
 */
GadgetList newGadgetList();

/**
 * @brief Mengecek apakah suatu GadgetList kosong atau tidak.
 * 
 * @param gList GadgetList instance.
 * @return true jika semua elemen gList adalah gadget yang tidak
 *         terdefinsi, false selainnya. 
 */
boolean isGadgetListEmpty(GadgetList gList);

/**
 * @brief Mengecek apakah gadget gList penuh atau tidak.
 * 
 * @param gList GadgetList instance.
 * @return true jika semua elemen gList bukanlah gadget yang tidak
 *         terdefinsi, false selainnya.
 */
boolean isGadgetListFull(GadgetList gList);

/**
 * @brief Mengecek apakah indeks valid untuk sebuah GagdetList.
 * 
 * @param index Indeks yang akan dicek.
 * @return true jika indeks valid untuk GadgetList, false
 *         selainnya.
 */
boolean isGagetListIndexValid(int index);

/**
 * @brief Mengambil Gadget instance dari gList pada indeks index.
 * 
 * @param gList GadgetList instance.
 * @param index Indeks dari Gadget pada gList yang akan diambil.
 * @return Gadget instance pada indeks index di GadgetList gList.
 */
Gadget getGadget(GadgetList gList, int index);

/**
 * @brief Set elemen gList pada indeks index menjadi Gadget g.
 * 
 * @param gList GadgetList instance.
 * @param index Indeks gList yang akan di-set.
 * @param g Gadget instance.
 */
void setGadget(GadgetList *gList, int index, Gadget g);

/**
 * @brief Menambahkan gadget pada slot yang kosong.
 * 
 * @param gList GadgetList instance.
 * @param g Gadget yang ingin ditambahkan
 */
void insertGadget(GadgetList *gList, Gadget g);

/**
 * @brief Mengambil dan menghapus gadget dari GadgetList.
 * 
 * @param gList GadgetList instance.
 * @param index Indeks gadget yang akan diambil & dihapus.
 * @param g Gadget yang dihapus.
 */
void deleteGadget(GadgetList *gList, int index, Gadget *g);

/**
 * @brief Menuliskan list Gadget (inventory) ke console output.
 * ! Hanya digunakan untuk command INVENTORY.
 * 
 * @param gList GadgetList instance.
 */
void displayGadget(GadgetList gList);

/**
 * @brief Menghitung panjang gadget list
 * !
 * 
 * @param gList GadgetList instance.
 */
int gListLength(GadgetList gList);

#endif