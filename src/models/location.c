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
        else if (l.isDropOffPlace && l.isMarkedDropOff)
        {
            changeToBlueColor();
        }
        else if (l.isPickUpPlace && l.isMarkedPickUp)
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
    unsetAsMarkedPickUp(l);
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
 * @brief Set lokasi sebagai lokasi pickup
 * untuk item di atas bag
 */
void setAsMarkedPickUp(Location *l){
    l->isMarkedPickUp = true;
}
/**
 * @brief Set lokasi sebagai lokasi dropoff
 * untuk item di atas bag
 */
void setAsMarkedDropOff(Location *l){
    l->isMarkedDropOff = true;
}
/**
 * @brief Unset lokasi pickup
 * di atas bag
 */
void unsetAsMarkedPickUp(Location *l){
    l->isMarkedPickUp = false;
}
/**
 * @brief Unset lokasi dropoff
 * di atas bag
 */
void unsetAsMarkedDropOff(Location *l){
    l->isMarkedDropOff = false;
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

/**
 * @private 
 * @brief Print isi data location ke console.
 * ! Private! Jangan digunakan di main program.
 * ! Hanya digunakan untuk driver.
 * @param l Location instance.
 */
void _dumpLocation(Location l)
{
    printf("Location {\n");
    printf("  id : %d\n", id(l));
    printf("  symbol : %c\n", symbol(l));
    printf("  coordinate : ");
    displayPoint(coord(l));
    printf("\n");
    printf("  isPlayerPlace : %s\n", l.isPlayerPlace ? "TRUE" : "FALSE");
    printf("  isPickUpPlace : %s\n", l.isPickUpPlace ? "TRUE" : "FALSE");
    printf("  isDropOffPlace : %s\n", l.isDropOffPlace ? "TRUE" : "FALSE");
    printf("  isReachable : %s\n", l.isReachable ? "TRUE" : "FALSE");
    printf("}\n");
}