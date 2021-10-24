/**
 * @file boolean_matrix.h
 * @author your name (you@domain.com)
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
 * @brief Mengembalikan banyak baris efektif BooleanMatrix \c b.
 * @param b BooleanMatrix instance.
 */
#define rows(b) (b).rowEff
/**
 * @brief Mengembalikan banyak kolom efektif BooleanMatrix \c b.
 * @param b BooleanMatrix instance.
 */
#define cols(b) (b).colEff
/**
 * @brief Mengembalikan elemen BooleanMatrix \c b pada index (i, j).
 * @param b BooleanMatrix instance.
 * @param i Index baris elemen yang akan diambil.
 * @param j Index kolom elemen yang akan diambil.
 */
#define elem(b, i, j) (b).contents[i][j]

/**
 * @brief Constructor untuk membuat BooleanMatrix baru.
 * 
 * @param rows Banyak baris efektif (rowEff).
 * @param cols Banyak kolom efektif (colEff).
 * @return BooleanMatrix instance.
 */
BooleanMatrix newBooleanMatrix(int rows, int cols);

#endif