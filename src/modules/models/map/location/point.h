/**
 * @file point.h
 * @brief Header file untuk tipe data Point.
 */

#ifndef POINT_H
#define POINT_H

#include "../../shared/boolean.h"

/**
 * @struct Point
 * @brief Struktur tipe data titik.
 */
typedef struct
{
    /**
     * @brief Absis suatu titik.
     */
    int x;
    /**
     * @brief Ordinat suatu titik.
     */
    int y;
} Point;

/**
 * @brief Constructor untuk membuat Point baru.
 * 
 * @param x Absis.
 * @param y Ordinat.
 * @return Point instance baru dengan koordinat (x, y).
 */
Point newPoint(int x, int y);

/**
 * @brief Mengecek apakah dua titik sama atau tidak.
 * 
 * @param p1 Point instance.
 * @param p2 Point instance.
 * @return true jika kedua titik sama, false selainnya.
 */
boolean isPointIdentical(Point p1, Point p2);

/**
 * @brief Mengecek apakah suatu titik berada pada
 * koordinat "sebelum" titik lainnya, yaitu x1 < x2
 * atau x1 = x2 & y1 < y2.
 * 
 * @param p1 Point instance.
 * @param p2 Point instance.
 * @return true jika titik pertama berada pada
 * koordinat "sebelum" titik kedua, false selainnya.
 */
boolean isPointBefore(Point p1, Point p2);

/**
 * @brief Menuliskan titik p ke console output.
 * 
 * @param p Point instance.
 */
void displayPoint(Point p);

#endif
