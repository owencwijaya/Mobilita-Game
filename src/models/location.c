/**
 * @file location.c
 * @brief Implementasi tipe data Location.
 * Digunakan untuk merepresentasikan lokasi
 * pada GameMap.
 * @see GameMap
 */

#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include "location.h"
#include "../modules/colorizer/colorizer.h"
#include "macros.h"

/**
 * @brief Location yang tidak terdefinisi.
 */
const Location NULL_LOCATION = {-1, '\0', {-1, -1}, false, false, false};

/**
 * @brief Constructor untuk membuat Location baru.
 * 
 * @param id Identifier lokasi.
 * @param symbol Simbol lokasi.
 * @param coordinate Koordinat lokasi.
 * @return Location instance baru.
 */
Location newLocation(int id, char symbol, Point coordinate)
{
    Location l;
    id(l) = id;
    symbol(l) = symbol;
    coord(l) = coordinate;
    unsetAsDropOffPlace(&l);
    unsetAsPickUpPlace(&l);
    unsetAsPlayerPlace(&l);
    unsetAsReachable(&l);
    return l;
}

/**
 * @brief Mengecek apakah suatu lokasi berada pada
 * koordinat (titik) tertentu.
 * 
 * @param l Location instance.
 * @param p Koordinat yang akan dicek (Point instance).
 * @return true jika l berada di p, false selainnya.
 */
boolean isAt(Location l, Point p)
{
    return isPointIdentical(coord(l), p);
}

/**
 * @brief Mengecek apakah dua lokasi adalah sama
 * atau tidak.
 * 
 * @param l1 Location instance.
 * @param l2 Location instance.
 * @return true jika kedua lokasi sama, false selainnya.
 */
boolean isLocationIdentical(Location l1, Location l2)
{
    return symbol(l1) == symbol(l2) && isPointIdentical(coord(l1), coord(l2)) && id(l1) == id(l2);
}

/**
 * @brief Mengecek apakah suatu lokasi terdefinisi
 * atau tidak.
 * 
 * @param l Location instance.
 * @return true jika l terdefinisi, false selainnya.
 */
boolean isLocationDefined(Location l)
{
    return !isLocationIdentical(l, NULL_LOCATION);
}

/**
 * @brief Menuliskan simbol lokasi ke console output
 * dengan formatting (warna) yang sesuai.
 * 
 * @param l Location instance.
 */
void writeLocationSymbol(Location l)
{
    if (isLocationDefined(l))
    {
        if (l.isPlayerPlace)
        {
            changeToOrangeColor();
        }
        else if (l.isDropOffPlace)
        {
            changeToBlueColor();
        }
        else if (l.isPickUpPlace)
        {
            changeToRedColor();
        }
        else if (l.isReachable)
        {
            changeToGreenColor();
        }
        printf("%c", symbol(l));
        resetColor();
    }
    else
    {
        printf(" ");
    }
}

/**
 * @brief Set lokasi sebagai tempat pick up Item.
 * 
 * @param l Location instance.
 */
void setAsPickUpPlace(Location *l)
{
    l->isPickUpPlace = true;
}

/**
 * @brief Unset lokasi sebagai tempat pick up Item.
 * 
 * @param l Location instance.
 */
void unsetAsPickUpPlace(Location *l)
{
    l->isPickUpPlace = false;
}

/**
 * @brief Set lokasi sebagai tempat drop off Item.
 * 
 * @param l Location instance.
 */
void setAsDropOffPlace(Location *l)
{
    l->isDropOffPlace = true;
}

/**
 * @brief Unset lokasi sebagai tempat drop off Item.
 * 
 * @param l Location instance.
 */
void unsetAsDropOffPlace(Location *l)
{
    l->isDropOffPlace = false;
}

/**
 * @brief Set lokasi sebagai tempat yang dapat
 * dituju relatif dengan lokasi player saat ini.
 * 
 * @param l Location instance.
 */
void setAsReachable(Location *l)
{
    l->isReachable = true;
}

/**
 * @brief Unset lokasi sebagai tempat yang dapat
 * dituju relatif dengan lokasi player saat ini.
 * 
 * @param l Location instance.
 */
void unsetAsReachable(Location *l)
{
    l->isReachable = false;
}

/**
 * @brief Set lokasi sebagai lokasi player.
 * 
 * @param l Location instance.
 */
void setAsPlayerPlace(Location *l)
{
    l->isPlayerPlace = true;
}

/**
 * @brief Unset lokasi sebagai lokasi player.
 * 
 * @param l Location instance.
 */
void unsetAsPlayerPlace(Location *l)
{
    l->isPlayerPlace = false;
}

/**
 * @brief Toggle lokasi sebagai lokasi player.
 * 
 * @param l Location instance.
 */
void toggleAsPlayerPlace(Location *l)
{
    l->isPlayerPlace = !(l->isPlayerPlace);
}
