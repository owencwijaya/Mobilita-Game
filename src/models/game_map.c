/**
 * @file game_map.c
 * @brief Implementasi tipe data GameMap.
 */

#include <stdio.h>
#include "location.h"
#include "boolean_matrix.h"
#include "location_list.h"
#include "location_matrix.h"
#include "game_map.h"
#include "macros.h"

/**
 * @brief Constructor untuk membuat GameMap baru.
 * 
 * @param hSize Panjang map (horizontal).
 * @param vSize Lebar map (vertikal).
 * @param adjMatrix Matriks adjacency dari lokasi-lokasi yang ada.
 * @param locations List lokasi yang ada.
 * @return GameMap baru yang terdefinisi.
 */
GameMap newGameMap(int hSize, int vSize, BooleanMatrix adjMatrix, LocationList locations)
{
    GameMap m;
    mapLength(m) = hSize;
    mapWidth(m) = vSize;
    adjMatrix(m) = adjMatrix;
    locList(m) = locations;
    LocationMatrix locMatrix = newLocationMatrix(hSize + 1, vSize + 1);
    for (int i = 0; i < rows(locMatrix); i++)
    {
        for (int j = 0; j < cols(locMatrix); j++)
        {
            elem(locMatrix, i, j) = _getLocationByCoord(locations, newPoint(i, j));
        }
    }
    locMatrix(m) = locMatrix;
    return m;
}

/**
 * @brief Menampilkan map game ke console output.
 * 
 * @param m GameMap instance yang akan ditampilkan.
 */
void displayGameMap(GameMap m)
{
    for (int i = 0; i < rows(locMatrix(m)) + 1; i++)
    {
        if (i == 0 || i == rows(locMatrix(m)))
        {
            for (int j = 0; j < cols(locMatrix(m)) + 1; j++)
            {
                printf("*");
            }
        }
        else
        {
            printf("*");
            for (int j = 1; j < cols(locMatrix(m)); j++)
            {
                writeLocationSymbol(elem(locMatrix(m), i, j));
            }

            printf("*");
        }
        printf("\n");
    }
}

/**
 * @brief Menampilkan lokasi-lokasi yang adjacent terurut berdasarkan
 *        koordinat.
 * 
 * @param m GameMap instance.
 * @param currentLocation Lokasi saat ini.
 */
void displayAdjacentLocation(GameMap m, Location currentLocation)
{
    LocationList adjLocs = getAdjacentLocations(locList(m), currentLocation, adjMatrix(m));
    for (int i = 0; i < length(adjLocs); i++)
    {
        printf("%d. %c ", i + 1, symbol(lElem(adjLocs, i)));
        displayPoint(coord(lElem(adjLocs, i)));
        printf("\n");
    }
}

LocationList getAdjacentLocations(LocationList lList, Location currentLocation, BooleanMatrix adjMatrix)
{
    LocationList adjLocs = newLocationList(26);
    int i = id(currentLocation);
    adjLocs = newLocationList(26);
    for (int j = 0; j < cols(adjMatrix); j++)
    {
        if (elem(adjMatrix, i, j))
        {
            insertLast(&adjLocs, _getLocationById(lList, j));
        }
    }
    return adjLocs;
}

/**
 * @brief Mengecek apakah suatu lokasi adjacent dengan lokasi lain.
 * 
 * @param a Location pertama.
 * @param b Location kedua.
 * @return true jika a dan b sama, false selainnya.
 */
boolean isAdjacentTo(GameMap m, Location a, Location b)
{
    int idA = id(a);
    int idB = id(b);
    return elem(adjMatrix(m), idA, idB);
}

/**
 * @brief Mengambil Location instance berdasarkan id.
 * 
 * @param m GameMap instance.
 * @param id Id Location.
 * @return Location dengan id 'id'.
 */
Location getLocationById(GameMap m, int id)
{
    return _getLocationById(locList(m), id);
}

/**
 * @brief Mengambil Location instance berdasarkan simbol.
 * 
 * @param m GameMap instance
 * @param symbol Simbol Location.
 * @return Location dengan simbol 'symbol'.
 */
Location getLocationBySymbol(GameMap m, char symbol)
{
    return _getLocationBySymbol(locList(m), symbol);
}

/**
 * @brief Mengambil Location instance berdasarkan koordinat.
 * 
 * @param m GameMap instance.
 * @param p Koordinat Location.
 * @return Location dengan koordinat p.
 */
Location getLocationByCoord(GameMap m, Point p)
{
    return _getLocationByCoord(locList(m), p);
}