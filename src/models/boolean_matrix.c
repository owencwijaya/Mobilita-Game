/**
 * @file boolean_matrix.c
 * @brief Implementasi tipe data BooleanMatrix.
 * 
 * @par Digunakan untuk matriks adjacency pada instance GameMap.
 * @see GameMap
 */

#include "boolean.h"
#include "boolean_matrix.h"
#include "macros.h"

/**
 * @brief Constructor untuk membuat BooleanMatrix baru.
 * 
 * @param rows Banyak baris efektif.
 * @param cols Banyak kolom efektif.
 * @return \c BooleanMatrix instance.
 */
BooleanMatrix newBooleanMatrix(int rows, int cols)
{
    BooleanMatrix b;
    rows(b) = rows;
    cols(b) = cols;

    for (int i = 0; i < rows(b); i++)
    {
        for (int j = 0; j < cols(b); j++)
        {
            elem(b, i, j) = false;
        }
    }

    return b;
}
