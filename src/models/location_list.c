/**
 * @file location_list.c
 * @brief Implementasi tipe data LocationList.
 * Digunakan menyimpan daftar lokasi yang ada,
 * dan daftar lokasi yang adjacent dengan suatu
 * lokasi.
 */

#include <stdlib.h>
#include "boolean.h"
#include "location.h"
#include "point.h"
#include "location_list.h"

/**
 * @brief Constructor untuk membuat LocationList baru.
 * 
 * @param capacity Kapasitas list.
 * @return LocationList instance baru yang kosong.
 */
LocationList newLocationList(int capacity)
{
    LocationList l;
    capacity(l) = capacity;
    buffer(l) = (Location *)malloc(capacity * sizeof(Location));
    neff(l) = 0;
    return l;
}

/**
 * @brief Menghapus memory list dari heap memory.
 * 
 * @param l LocationList instance.
 */
void dealocateLocationList(LocationList *l)
{
    free(buffer(*l));
    neff(*l) = 0;
    capacity(*l) = 0;
}

/**
 * @brief Mengembalikan panjang list l.
 * 
 * @param l LocationList instance.
 * @return Panjang list l.
 */
int length(LocationList l)
{
    return neff(l);
}

/**
 * @brief Mengecek apakah suatu indeks i adalah
 * indeks yang valid untuk list l.
 * 
 * @param l LocationList instance.
 * @param i Indeks yang akan dicek.
 * @return true jika indeks valid, false selainnya.
 */
boolean isIndexValid(LocationList l, int i)
{
    return i < capacity(l);
}

/**
 * @brief Mengecek apakah suatu indeks i adalah
 * indeks yang efektif untuk list l.
 * 
 * @param l LocationList instance.
 * @param i Indeks yang akan dicek.
 * @return true jika indeks efektif, false selainnya.
 */
boolean isIndexEff(LocationList l, int i)
{
    return i < length(l);
}

/**
 * @brief Mengecek apakah list l kosong atau tidak.
 * 
 * @param l LocationList instance.
 * @return true jika list l kosong, false selainnya.
 */
boolean isLocationListEmpty(LocationList l)
{
    return length(l) == 0;
}

/**
 * @brief Mengecek apakah list l penuh atau tidak.
 * 
 * @param l LocationList instance.
 * @return true jika list l penuh, false selainnya.
 */
boolean isLocationListFull(LocationList l)
{
    return length(l) == capacity(l);
}

/**
 * @brief Memasukkan Location ke akhir list.
 * 
 * @param l LocationList instance.
 * @param location Location instance.
 */
void insertLast(LocationList *l, Location location)
{
    lElem(*l, length(*l)) = location;
    neff(*l)++;
}

/**
 * @brief Menghapus & mengambil Location terakhir
 * di dalam list.
 * 
 * @param l LocaitonList instance.
 * @param[out] location Location instance. 
 */
void deleteLast(LocationList *l, Location *val)
{
    neff(*l)--;
    *val = lElem(*l, length(*l));
}

/**
 * @brief Menambah kapasitas list l sebanyak num.
 * 
 * @param l LocationList instance.
 * @param num Banyak kapasitas yang akan ditambah.
 */
void growList(LocationList *l, int num)
{
    capacity(*l) += num;
    buffer(*l) = (Location *)realloc(buffer(*l), capacity(*l) * sizeof(Location));
}

/**
 * @brief Mengurangi kapasitas list l sebanyak num.
 * 
 * @param l LocationList instance.
 * @param num Banyak kapasitas yang akan dikurangi.
 */
void shrinkList(LocationList *l, int num)
{
    capacity(*l) -= num;
    if (neff(*l) > capacity(*l))
    {
        neff(*l) = capacity(*l);
    }
    buffer(*l) = (Location *)realloc(buffer(*l), capacity(*l) * sizeof(Location));
}

/**
 * @brief Merapatkan list l.
 * 
 * @param l LocationList instance.
 */
void compactList(LocationList *l)
{
    const int diff = capacity(*l) - neff(*l);
    shrinkList(l, diff);
}

/**
 * @brief Mengurutkan Location dalam l berdasarkan
 * koordinat.
 * @see Location
 * @param l LocationList instance.
 */
void sortLocationListByCoord(LocationList *l)
{
    for (int i = 0; i < length(*l) - 1; i++)
    {
        int priorityIndex = i;
        for (int j = i + 1; j < length(*l); j++)
        {
            if (isPointBefore(coord(lElem(*l, j)), coord(lElem(*l, priorityIndex))))
            {
                priorityIndex = j;
            }
        }
        Location temp = lElem(*l, i);
        lElem(*l, i) = lElem(*l, priorityIndex);
        lElem(*l, priorityIndex) = temp;
    }
}

/**
 * @brief Mengambil lokasi dalam list l berdasarkan
 * id lokasi.
 * 
 * @param l LocationList instance.
 * @param id Id lokasi yang akan diambil.
 * @return Lokasi dengan id 'id', atau NULL_LOCATION
 * jika lokasi dengan id 'id' tidak ditemukan dalam l.
 */
Location _getLocationById(LocationList l, int id)
{
    Location loc;
    int i = 0;
    while (i < length(l))
    {
        loc = lElem(l, i);
        if (id(loc) == id)
        {
            return loc;
        }
    }
    return NULL_LOCATION;
}

/**
 * @brief Mengambil lokasi dalam list l berdasarkan
 * simbol lokasi.
 * 
 * @param l LocationList instance.
 * @param symbol Simbol lokasi yang akan diambil.
 * @return Lokasi dengan simbol symbol, atau NULL_LOCATION
 * jika lokasi dengan simbol symbol tidak ditemukan dalam l.
 */
Location _getLocationBySymbol(LocationList l, char symbol)
{
    Location loc;
    int i = 0;
    while (i < length(l))
    {
        loc = lElem(l, i);
        if (symbol(loc) == symbol)
        {
            return loc;
        }
    }
    return NULL_LOCATION;
}

/**
 * @brief Mengambil lokasi dalam list l berdasarkan
 * koordinat lokasi.
 * 
 * @param l LocationList instance.
 * @param p Koordinat lokasi yang akan diambil.
 * @return Lokasi dengan koordinat p, atau NULL_LOCATION
 * jika lokasi dengan koordinat p tidak ditemukan dalam l.
 */
Location _getLocationByCoord(LocationList l, Point p)
{
    Location loc;
    int i = 0;
    while (i < length(l))
    {
        loc = lElem(l, i);
        if (isPointIdentical(coord(loc), p))
        {
            return loc;
        }
    }
    return NULL_LOCATION;
}
