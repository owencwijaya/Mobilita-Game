/**
 * @file gadget_list.c
 * @brief Implementasi tipe data GadgetList.
 * Tipe data ini digunakan untuk inventory pada game.
 */

#include <stdio.h>
#include "boolean.h"
#include "gadget.h"
#include "gadget_list.h"

/**
 * @brief Constructor untuk membuat GadgetList baru.
 * 
 * @return Instance GadgetList berisi 5 Gadget yang tidak terdefinisi. 
 */
GadgetList newGadgetList()
{
    GadgetList gList;
    for (int i = 0; i < 5; i++)
    {
        setGadget(&gList, i, NULL_GADGET);
    }
    return gList;
}

/**
 * @brief Mengecek apakah suatu GadgetList kosong atau tidak.
 * 
 * @param gList GadgetList instance.
 * @return true jika semua elemen gList adalah gadget yang tidak
 *         terdefinsi, false selainnya. 
 */
boolean isGadgetListEmpty(GadgetList gList)
{
    for (int i = 0; i < 5; i++)
    {
        if (!isGadgetIdentical(getGadget(gList, i), NULL_GADGET))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Mengecek apakah gadget gList penuh atau tidak.
 * 
 * @param gList GadgetList instance.
 * @return true jika semua elemen gList bukanlah gadget yang tidak
 *         terdefinsi, false selainnya.
 */
boolean isGadgetListFull(GadgetList gList)
{
    for (int i = 0; i < 5; i++)
    {
        if (isGadgetIdentical(getGadget(gList, i), NULL_GADGET))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Mengambil Gadget instance dari gList pada indeks index.
 * Mengembalikan NULL_GADGET jika index berada di luar range
 * yang berlaku (0..4).
 * 
 * @param gList GadgetList instance.
 * @param index Indeks dari Gadget pada gList yang akan diambil.
 * @return Gadget instance pada indeks index di GadgetList gList.
 */
Gadget getGadget(GadgetList gList, int index)
{
    return (index >= 0 && index < 5) ? gList.contents[index] : NULL_GADGET;
}

/**
 * @brief Set elemen gList pada indeks index menjadi Gadget g.
 * 
 * @param gList GadgetList instance.
 * @param index Indeks gList yang akan di-set.
 * @param g Gadget instance.
 */
void setGadget(GadgetList *gList, int index, Gadget g)
{
    gList->contents[index] = g;
}

/**
 * @brief Menuliskan list Gadget (inventory) ke console output.
 * ! Hanya digunakan untuk command INVENTORY.
 * 
 * @param gList GadgetList instance.
 */
void displayGadget(GadgetList gList)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d. %s\n", i + 1, name(getGadget(gList, i)));
    }
}