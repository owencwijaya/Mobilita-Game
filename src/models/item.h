/**
 * @file item.h
 * @brief Header file untuk tipe data Item.
 */

#ifndef ITEM_H
#define ITEM_H

#include "location.h"

/**
 * @brief Alias untuk tipe ItemType.
 */
typedef int ItemType;
/**
 * @brief Tipe item Normal.
 */
#define NORMAL 0
/**
 * @brief Tipe item Heavy.
 */
#define HEAVY 1
/**
 * @brief Tipe item Perishable.
 */
#define PERISHABLE 2
/**
 * @brief Tipe item VIP.
 */
#define VIP 3

/**
 * @brief Perish time untuk item
 * yang non-perishable.
 */
#define UNTIMED -1

/**
 * @struct Item
 * @brief Struktur tipe data Item dan pesanan.
 */
typedef struct
{
    /**
     * @brief Waktu pesanan item.
     */
    int orderTime;
    /**
     * @brief Tempat pick up item.
     */
    Location pickUpLocation;
    /**
     * @brief Tempat drop off item.
     */
    Location dropOffLocation;
    /**
     * @brief Tipe item.
     */
    ItemType type;
    /**
     * @brief Waktu hangus item.
     */
    int perishTime;
    /**
     * @brief Referensi waktu hangus item.
     */
    int perishTimeReference;
} Item;

/**
 * @brief Constructor untuk membuat Item baru.
 * 
 * @param orderTime Waktu order item.
 * @param pickUpLocation Lokasi pick up item.
 * @param dropOffLocation Lokasi drop off item.
 * @param type Tipe item.
 * @param perishTime Waktu hangus item.
 * @param perishTimeReference referensi waktu hangus item.
 * @return Item instance baru.
 */
Item newItem(int orderTime, Location pickUpLocation, Location dropOffLocation, ItemType type, int perishTime, int perishTimeReference);

/**
 * @brief Mengecek apakah dua item sama atau tidak.
 * 
 * @param item1 Item instance.
 * @param item2 Item instance.
 * @return true jika kedua item sama, false selainnya.
 */
boolean isItemIdentical(Item item1, Item item2);

/**
 * @brief Mengecek apakah tipe suatu item adalah 
 * Normal atau bukan.
 * 
 * @param item Item instance. 
 * @return true jika tipe item Normal, false selainnya.
 */
boolean isNormalItem(Item item);

/**
 * @brief Mengecek apakah tipe suatu item adalah 
 * Heavy atau bukan.
 * 
 * @param item Item instance. 
 * @return true jika tipe item Heavy, false selainnya.
 */
boolean isHeavyItem(Item item);

/**
 * @brief Mengecek apakah tipe suatu item adalah 
 * Perishable atau bukan.
 * 
 * @param item Item instance. 
 * @return true jika tipe item Perishable, false selainnya.
 */
boolean isPerishableItem(Item item);

/**
 * @brief Mengecek apakah tipe suatu item adalah 
 * VIP atau bukan.
 * 
 * @param item Item instance. 
 * @return true jika tipe item VIP, false selainnya.
 */
boolean isVIPItem(Item item);

/**
 * @private 
 * @brief Print isi data item ke console.
 * ! Private! Jangan digunakan di main program.
 * ! Hanya digunakan untuk driver.
 * @param item Item instance.
 */
void _dumpItem(Item item);

#endif