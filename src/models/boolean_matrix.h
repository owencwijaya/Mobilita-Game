/**
 * @file boolean_matrix.h
 * @brief Header file untuk tipe data BooleanMatrix.
 */

#ifndef BOOLEAN_MATRIX_H
#define BOOLEAN_MATRIX_H

#include "boolean.h"

/**
 * @struct BooleanMatrix
 * @brief Matriks bernilai boolean.
 */
typedef struct
{
    /**
     * @brief 2D array untuk menyimpan elemen matriks.
     */
    boolean contents[20][30];
    /**
     * @brief Banyak baris matriks.
     */
    int rowEff;
    /**
     * @brief Banyak kolom matriks.
     */
    int colEff;
} BooleanMatrix;

/**
 * @brief Constructor untuk membuat BooleanMatrix baru.
 * 
 * @param rows Banyak baris efektif (rowEff).
 * @param cols Banyak kolom efektif (colEff).
 * @return BooleanMatrix instance.
 */
BooleanMatrix newBooleanMatrix(int rows, int cols);

#endif