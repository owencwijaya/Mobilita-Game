/**
 * @file location_matrix.h
 * @brief Header file untuk tipe data LocationMatrix.
 */

#ifndef LOCATION_MATRIX_H
#define LOCATION_MATRIX_H

#include "../../shared/boolean.h"
#include "location.h"

/**
 * @struct LocationMatrix
 * @brief Matriks berisi data Location.
 */
typedef struct
{
    /**
     * @brief 2D array untuk menyimpan elemen matriks.
     */
    Location contents[20][30];
    /**
     * @brief Banyak baris matriks yang terdefinisi.
     */
    int rowEff;
    /**
     * @brief Banyak kolom matriks yang terdefinisi.
     */
    int colEff;
} LocationMatrix;

/**
 * @brief Constructor untuk membuat LocationMatrix baru.
 * 
 * @param rows Banyak baris matriks.
 * @param cols Banyak kolom matriks.
 * @return LocationMatrix instance baru yang kosong.
 */
LocationMatrix newLocationMatrix(int rows, int cols);

/**
 * @brief Set elemen LocationMatrix l pada indeks
 * tertentu.
 * 
 * @param l LocationMatrix instance.
 * @param rowIndex Indeks baris yang akan di-set.
 * @param colIndex Indeks kolom yang akan di-set.
 * @param value Location instance.
 */
void lSetElem(LocationMatrix *l, int rowIndex, int colIndex, Location value);

#endif