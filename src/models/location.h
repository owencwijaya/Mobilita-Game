/**
 * @file location.h
 * @brief Header file untuk tipe data Location.
 */

#ifndef LOCATION_H
#define LOCATION_H

#include "boolean.h"
#include "point.h"

/**
 * @struct Location
 * @brief Struktur tipe data lokasi yang memuat
 * koordinat, simbol, dan id.
 */
typedef struct
{
    /**
     * @brief Identifier lokasi.
     * ! id harus unik untuk lokasi yang berbeda.
     */
    int id;
    /**
     * @brief Simbol lokasi yang dapat ditampilkan.
     */
    char symbol;
    /**
     * @brief Koordinat lokasi.
     */
    Point coordinate;
    /**
     * @brief Flag yang menandakan apakah lokasi
     * ini sedang ditempati player.
     */
    boolean isPlayerPlace;
    /**
     * @brief Flag yang menandakan apakah lokasi
     * ini adalah lokasi pick up item.
     */
    boolean isPickUpPlace;
    /**
     * @brief Flag yang menandakan apakah lokasi
     * ini adalah lokasi drop off item.
     */
    boolean isDropOffPlace;
    /**
     * @brief Flag yang menandakan apakah lokasi
     * ini dapat dituju relatif dari lokasi player.
     */
    boolean isReachable;
} Location;

/**
 * @brief Location yang tidak terdefinisi.
 */
extern const Location NULL_LOCATION;

/**
 * @brief Constructor untuk membuat Location baru.
 * 
 * @param id Identifier lokasi.
 * @param symbol Simbol lokasi.
 * @param coordinate Koordinat lokasi.
 * @return Location instance baru.
 */
Location newLocation(int id, char symbol, Point coordinate);

/**
 * @brief Mengecek apakah suatu lokasi berada pada
 * koordinat (titik) tertentu.
 * 
 * @param l Location instance.
 * @param p Koordinat yang akan dicek (Point instance).
 * @return true jika l berada di p, false selainnya.
 */
boolean isAt(Location l, Point p);

/**
 * @brief Mengecek apakah dua lokasi adalah sama
 * atau tidak.
 * 
 * @param l1 Location instance.
 * @param l2 Location instance.
 * @return true jika kedua lokasi sama, false selainnya.
 */
boolean isLocationIdentical(Location l1, Location l2);

/**
 * @brief Mengecek apakah suatu lokasi terdefinisi
 * atau tidak.
 * 
 * @param l Location instance.
 * @return true jika l terdefinisi, false selainnya.
 */
boolean isLocationDefined(Location l);

/**
 * @brief Menuliskan simbol lokasi ke console output
 * dengan formatting (warna) yang sesuai.
 * 
 * @param l Location instance.
 */
void writeLocationSymbol(Location l);

/**
 * @brief Set lokasi sebagai tempat pick up Item.
 * 
 * @param l Location instance.
 */
void setAsPickUpPlace(Location *l);

/**
 * @brief Unset lokasi sebagai tempat pick up Item.
 * 
 * @param l Location instance.
 */
void unsetAsPickUpPlace(Location *l);

/**
 * @brief Set lokasi sebagai tempat drop off Item.
 * 
 * @param l Location instance.
 */
void setAsDropOffPlace(Location *l);

/**
 * @brief Unset lokasi sebagai tempat drop off Item.
 * 
 * @param l Location instance.
 */
void unsetAsDropOffPlace(Location *l);

/**
 * @brief Set lokasi sebagai tempat yang dapat
 * dituju relatif dengan lokasi player saat ini.
 * 
 * @param l Location instance.
 */
void setAsReachable(Location *l);

/**
 * @brief Unset lokasi sebagai tempat yang dapat
 * dituju relatif dengan lokasi player saat ini.
 * 
 * @param l Location instance.
 */
void unsetAsReachable(Location *l);
/**
 * @brief Set lokasi sebagai lokasi pickup
 * untuk item di atas bag
 */
void setAsMarkedPickUp(Location *l);
/**
 * @brief Set lokasi sebagai lokasi dropoff
 * untuk item di atas bag
 */
void setAsMarkedDropOff(Location *l);
/**
 * @brief Unset lokasi pickup
 * di atas bag
 */
void unsetAsMarkedPickUp(Location *l);
/**
 * @brief Unset lokasi dropoff
 * di atas bag
 */
void unsetAsMarkedDropOff(Location *l);
/**
 * @brief Set lokasi sebagai lokasi player.
 * 
 * @param l Location instance.
 */
void setAsPlayerPlace(Location *l);

/**
 * @brief Unset lokasi sebagai lokasi player.
 * 
 * @param l Location instance.
 */
void unsetAsPlayerPlace(Location *l);

/**
 * @brief Toggle lokasi sebagai lokasi player.
 * 
 * @param l Location instance.
 */
void toggleAsPlayerPlace(Location *l);

/**
 * @private 
 * @brief Print isi data location ke console.
 * ! Private! Jangan digunakan di main program.
 * ! Hanya digunakan untuk driver.
 * @param l Location instance.
 */
void _dumpLocation(Location l);

#endif