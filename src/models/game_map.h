/**
 * @file game_map.h
 * @brief Header file untuk tipe data GameMap.
 */

#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "location.h"
#include "boolean_matrix.h"
#include "location_list.h"
#include "location_matrix.h"

/**
 * @struct GameMap
 * @brief Tipe data berisi ukuran map, matriks
 * adjacency, list lokasi, dan matriks lokasi.
 */
typedef struct
{
    int hSize;
    int vSize;
    BooleanMatrix _adjacency;
    LocationList _locations;
    LocationMatrix _locationMatrix;
} GameMap;

/**
 * @brief Constructor untuk membuat GameMap baru.
 * 
 * @param hSize Panjang map (horizontal).
 * @param vSize Lebar map (vertikal).
 * @param adjMatrix Matriks adjacency dari lokasi-lokasi yang ada.
 * @param locations List lokasi yang ada.
 * @return GameMap baru yang terdefinisi.
 */
GameMap newGameMap(int hSize, int vSize, BooleanMatrix adjMatrix, Location *locations);

/**
 * @brief Mengembalikan panjang GameMap \c m.
 * @param m GameMap instance.
 */
#define mapLength(m) (m).hSize
/**
 * @brief Mengembalikan lebar GameMap \c m.
 * @param m GameMap instance.
 */
#define mapWidth(m) (m).vSize
/**
 * @private
 * @brief Mengembalikan matriks adjacency dari map \c m.
 * @see BooleanMatrix
 * @param m GameMap instance
 */
#define adjMatrix(m) (m)._adjacency
/**
 * @private
 * @brief Mengembalikan list lokasi yang ada pada \c m.
 * @see LocationList
 * @param m GameMap instance
 */
#define locList(m) (m)._locations
/**
 * @private
 * @brief Mengembalikan matriks lokasi dari map \c m.
 * ! Hanya digunakan untuk menampilkan output map.
 * @see LocationMatrix
 * @param m GameMap instance
 */
#define locMatrix(m) (m)._locationMatrix

/**
 * @brief Menampilkan map game ke console output.
 * 
 * @param m GameMap instance yang akan ditampilkan.
 */
void displayGameMap(GameMap m);

/**
 * @brief Menampilkan lokasi-lokasi yang adjacent terurut berdasarkan
 *        koordinat.
 * 
 * @param m GameMap instance.
 * @param currentLocation Lokasi saat ini.
 */
void displayAdjacentLocation(GameMap m, Location currentLocation);

/**
 * @brief Mengecek apakah suatu lokasi adjacent dengan lokasi lain.
 * 
 * @param a Location pertama.
 * @param b Location kedua.
 * @return true jika a dan b sama, false selainnya.
 */
boolean isAdjacentTo(GameMap m, Location a, Location b);

/**
 * @brief Mengambil Location instance berdasarkan id.
 * 
 * @param m GameMap instance.
 * @param id Id Location.
 * @return Location dengan id 'id'.
 */
Location getLocationById(GameMap m, int id);

/**
 * @brief Mengambil Location instance berdasarkan simbol.
 * 
 * @param m GameMap instance
 * @param symbol Simbol Location.
 * @return Location dengan simbol 'symbol'.
 */
Location getLocationBySymbol(GameMap m, char symbol);

/**
 * @brief Mengambil Location instance berdasarkan koordinat.
 * 
 * @param m GameMap instance.
 * @param p Koordinat Location.
 * @return Location dengan koordinat p.
 */
Location getLocationByCoord(GameMap m, Point p);

#endif