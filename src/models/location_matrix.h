/**
 * @file location_matrix.h
 * @brief Header file untuk tipe data LocationMatrix.
 */

#ifndef LOCATION_MATRIX_H
#define LOCATION_MATRIX_H

#include "boolean.h"
#include "location.h"

/**
 * @struct LocationMatrix
 * @brief Matriks berisi data Location.
 */
struct locationmatrix
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
};

/**
 * @brief Tipe data referensi location matrix.
 * 
 */
typedef struct locationmatrix *LocationMatrix;

#ifndef MATRIX_MACRO
#define MATRIX_MACRO

/**
 * @brief Mengembalikan banyak baris efektif location matrix.
 * @param l LocationMatrix instance.
 */
#define rows(l) (l)->rowEff
/**
 * @brief Mengembalikan banyak kolom efektif location matrix.
 * @param l LocationMatrix instance.
 */
#define cols(l) (l)->colEff
/**
 * @brief Mengembalikan elemen matriks pada index (i, j).
 * @param l LocationMatrix instance.
 * @param i Index baris elemen yang akan diambil.
 * @param j Index kolom elemen yang akan diambil.
 */
#define elem(l, i, j) (l)->contents[i][j]

#endif

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
void lSetElem(LocationMatrix l, int rowIndex, int colIndex, Location value);

#endif