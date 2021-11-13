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
#include "../modules/colorizer/colorizer.h"
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
        if (m._locationMatrix.contents[lElem(adjLocs, i).coordinate.x][lElem(adjLocs, i).coordinate.y].isPickUpPlace){
            changeToRedColor();
        }
        if (m._locationMatrix.contents[lElem(adjLocs, i).coordinate.x][lElem(adjLocs, i).coordinate.y].isDropOffPlace){
            changeToBlueColor();
        }
        if (symbol(lElem(adjLocs, i)) == '8'){
            changeToOrangeColor();
        }
        printf("%d. %c ", i + 1, symbol(lElem(adjLocs, i)));
        displayPoint(coord(lElem(adjLocs, i)));
        printf("\n");
        resetColor();
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

/**
 * @brief Set lokasi player pada koordinat (x, y).
 * 
 * @param m GameMap instance.
 * @param x Absis lokasi player saat ini.
 * @param y Ordinat lokasi player saat ini.
 */
void setPlayerLocation(GameMap *m, int x, int y)
{
    setAsPlayerPlace(&elem(locMatrix(*m), x, y));
}

/**
 * @brief Set lokasi pada koordinat (x, y) sebagai lokasi
 *        pick up item.
 * 
 * @param m GameMap instance.
 * @param x Absis lokasi yang akan diset sebagai lokasi
 *          pick up.
 * @param y Ordinat lokasi yang akan diset sebagai lokasi
 *          pick up.
 */
void setPickUpLocation(GameMap *m, int x, int y)
{
    setAsPickUpPlace(&elem(locMatrix(*m), x, y));
}

/**
 * @brief Set lokasi pada koordinat (x, y) sebagai lokasi
 *        drop off item.
 * 
 * @param m GameMap instance.
 * @param x Absis lokasi yang akan diset sebagai lokasi
 *          drop off.
 * @param y Ordinat lokasi yang akan diset sebagai lokasi
 *          drop off.
 */
void setDropOffLocation(GameMap *m, int x, int y)
{
    setAsDropOffPlace(&elem(locMatrix(*m), x, y));
}