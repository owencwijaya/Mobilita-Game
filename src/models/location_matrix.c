/**
 * @file location_matrix.c
 * @brief Implementasi tipe data LocationMatrix.
 */

#include "boolean.h"
#include "location.h"
#include "location_matrix.h"

/**
 * @brief Constructor untuk membuat LocationMatrix baru.
 * 
 * @param rows Banyak baris matriks.
 * @param cols Banyak kolom matriks.
 * @return LocationMatrix instance baru yang kosong.
 */
LocationMatrix newLocationMatrix(int rows, int cols)
{
    LocationMatrix locationMatrix;
    rows(locationMatrix) = rows;
    cols(locationMatrix) = cols;

    for (int i = 0; i < rows(locationMatrix); i++)
    {
        for (int j = 0; j < cols(locationMatrix); j++)
        {
            elem(locationMatrix, i, j) = NULL_LOCATION;
        }
    }
}

/**
 * @brief Set elemen LocationMatrix l pada indeks
 * tertentu.
 * 
 * @param l LocationMatrix instance.
 * @param rowIndex Indeks baris yang akan di-set.
 * @param colIndex Indeks kolom yang akan di-set.
 * @param value Location instance.
 */
void lSetElem(LocationMatrix *locationMatrix, int rowIndex, int colIndex, Location location)
{
    elem(*locationMatrix, rowIndex, colIndex) = location;
}
