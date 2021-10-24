/**
 * @file location_list.h
 * @brief Header file untuk tipe data LocationList.
 */

#ifndef LOCATION_LIST_H
#define LOCATION_LIST_H

#include "boolean.h"
#include "location.h"
#include "point.h"

/**
 * @struct LocationList
 * @brief List dinamis berisi data Location.
 */
typedef struct
{
    /**
     * @brief Memory tempat menyimpan elemen list.
     */
    Location *buffer;
    /**
     * @brief Banyak elemen list.
     */
    int nEff;
    /**
     * @brief Kapasitas list.
     */
    int capacity;
} LocationList;

/**
 * @brief Mengambil banyak elemen list.
 * @param l LocationList instance.
 */
#define neff(l) (l).nEff
/**
 * @brief Mengambil kapasitas elemen list.
 * @param l LocationList instance.
 */
#define capacity(l) (l).capacity
/**
 * @brief Mengambil memory list.
 * @param l LocationList instance.
 */
#define buffer(l) (l).buffer
/**
 * @brief Mengambil elemen list pada indeks tertentu.
 * @param l LocationList instance.
 * @param i Indeks elemen yang akan diambil.
 */
#define lElem(l, i) (l).buffer[i]

/**
 * @brief Constructor untuk membuat LocationList baru.
 * 
 * @param capacity Kapasitas list.
 * @return LocationList instance baru yang kosong.
 */
LocationList newLocationList(int capacity);

/**
 * @brief Menghapus memory list dari heap memory.
 * 
 * @param l LocationList instance.
 */
void dealocateLocationList(LocationList *l);

/**
 * @brief Mengembalikan panjang list l.
 * 
 * @param l LocationList instance.
 * @return Panjang list l.
 */
int length(LocationList l);

/**
 * @brief Mengecek apakah suatu indeks i adalah
 * indeks yang valid untuk list l.
 * 
 * @param l LocationList instance.
 * @param i Indeks yang akan dicek.
 * @return true jika indeks valid, false selainnya.
 */
boolean isIndexValid(LocationList l, int i);

/**
 * @brief Mengecek apakah suatu indeks i adalah
 * indeks yang efektif untuk list l.
 * 
 * @param l LocationList instance.
 * @param i Indeks yang akan dicek.
 * @return true jika indeks efektif, false selainnya.
 */
boolean isIndexEff(LocationList l, int i);

/**
 * @brief Mengecek apakah list l kosong atau tidak.
 * 
 * @param l LocationList instance.
 * @return true jika list l kosong, false selainnya.
 */
boolean isLocationListEmpty(LocationList l);

/**
 * @brief Mengecek apakah list l penuh atau tidak.
 * 
 * @param l LocationList instance.
 * @return true jika list l penuh, false selainnya.
 */
boolean isLocationListFull(LocationList l);

/**
 * @brief Memasukkan Location ke akhir list.
 * 
 * @param l LocationList instance.
 * @param location Location instance.
 */
void insertLast(LocationList *l, Location location);

/**
 * @brief Menghapus & mengambil Location terakhir
 * di dalam list.
 * 
 * @param l LocaitonList instance.
 * @param[out] location Location instance. 
 */
void deleteLast(LocationList *l, Location *location);

/**
 * @brief Menambah kapasitas list l sebanyak num.
 * 
 * @param l LocationList instance.
 * @param num Banyak kapasitas yang akan ditambah.
 */
void growList(LocationList *l, int num);

/**
 * @brief Mengurangi kapasitas list l sebanyak num.
 * 
 * @param l LocationList instance.
 * @param num Banyak kapasitas yang akan dikurangi.
 */
void shrinkList(LocationList *l, int num);

/**
 * @brief Merapatkan list l.
 * 
 * @param l LocationList instance.
 */
void compactList(LocationList *l);

/**
 * @brief Mengurutkan Location dalam l berdasarkan
 * koordinat.
 * @see Location
 * @param l LocationList instance.
 */
void sortLocationListByCoord(LocationList *l);

/**
 * @brief Mengambil lokasi dalam list l berdasarkan
 * id lokasi.
 * 
 * @param l LocationList instance.
 * @param id Id lokasi yang akan diambil.
 * @return Lokasi dengan id 'id', atau NULL_LOCATION
 * jika lokasi dengan id 'id' tidak ditemukan dalam l.
 */
Location _getLocationById(LocationList l, int id);

/**
 * @brief Mengambil lokasi dalam list l berdasarkan
 * simbol lokasi.
 * 
 * @param l LocationList instance.
 * @param symbol Simbol lokasi yang akan diambil.
 * @return Lokasi dengan simbol symbol, atau NULL_LOCATION
 * jika lokasi dengan simbol symbol tidak ditemukan dalam l.
 */
Location _getLocationBySymbol(LocationList l, char symbol);

/**
 * @brief Mengambil lokasi dalam list l berdasarkan
 * koordinat lokasi.
 * 
 * @param l LocationList instance.
 * @param p Koordinat lokasi yang akan diambil.
 * @return Lokasi dengan koordinat p, atau NULL_LOCATION
 * jika lokasi dengan koordinat p tidak ditemukan dalam l.
 */
Location _getLocationByCoord(LocationList l, Point p);

#endif