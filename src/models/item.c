/**
 * @file item.c
 * @brief Implementasi tipe data Item.
 * Digunakan untuk mencatat order, termasuk
 * Todo list dan In Progress list.
 */

#include "boolean.h"
#include "location.h"
#include "item.h"

/**
 * @brief Constructor untuk membuat Item baru.
 * 
 * @param orderTime Waktu order item.
 * @param pickUpLocation Lokasi pick up item.
 * @param dropOffLocation Lokasi drop off item.
 * @param type Tipe item.
 * @param perishTime Waktu hangus item.
 * @return Item instance baru.
 */
Item newItem(int orderTime, Location pickUpLocation, Location dropOffLocation, ItemType type, int perishTime)
{
    Item item;
    orderTime(item) = orderTime;
    pickUpLoc(item) = pickUpLocation;
    dropOffLoc(item) = dropOffLocation;
    itemType(item) = type;
    perishTime(item) = perishTime;
    return item;
}

/**
 * @brief Mengecek apakah dua item sama atau tidak.
 * 
 * @param item1 Item instance.
 * @param item2 Item instance.
 * @return true jika kedua item sama, false selainnya.
 */
boolean isItemIdentical(Item item1, Item item2)
{
    return isLocationIdentical(pickUpLoc(item1), pickUpLoc(item2)) && isLocationIdentical(dropOffLoc(item1), dropOffLoc(item2)) && itemType(item1) == itemType(item2);
}

/**
 * @brief Mengecek apakah tipe suatu item adalah 
 * Normal atau bukan.
 * 
 * @param item Item instance. 
 * @return true jika tipe item Normal, false selainnya.
 */
boolean isNormalItem(Item item)
{
    return itemType(item) == NORMAL;
}

/**
 * @brief Mengecek apakah tipe suatu item adalah 
 * Heavy atau bukan.
 * 
 * @param item Item instance. 
 * @return true jika tipe item Heavy, false selainnya.
 */
boolean isHeavyItem(Item item)
{
    return itemType(item) == HEAVY;
}

/**
 * @brief Mengecek apakah tipe suatu item adalah 
 * Perishable atau bukan.
 * 
 * @param item Item instance. 
 * @return true jika tipe item Perishable, false selainnya.
 */
boolean isPerishableItem(Item item)
{
    return itemType(item) == PERISHABLE;
}

/**
 * @brief Mengecek apakah tipe suatu item adalah 
 * VIP atau bukan.
 * 
 * @param item Item instance. 
 * @return true jika tipe item VIP, false selainnya.
 */
boolean isVIPItem(Item item)
{
    return itemType(item) == VIP;
}