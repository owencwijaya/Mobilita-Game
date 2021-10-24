/**
 * @file point.c
 * @brief Implementasi tipe data Point.
 * Digunakan untuk merepresentasikan
 * sebuah koordinat lokasi.
 * @see Location
 */

#include <stdio.h>
#include "boolean.h"
#include "point.h"

/**
 * @brief Constructor untuk membuat Point baru.
 * 
 * @param x Absis.
 * @param y Ordinat.
 * @return Point instance baru dengan koordinat (x, y).
 */
Point newPoint(int x, int y)
{
    Point p;
    abs(p) = x;
    ord(p) = y;
}

/**
 * @brief Mengecek apakah dua titik sama atau tidak.
 * 
 * @param p1 Point instance.
 * @param p2 Point instance.
 * @return true jika kedua titik sama, false selainnya.
 */
boolean isPointIdentical(Point p1, Point p2)
{
    return abs(p1) == abs(p2) && ord(p1) == ord(p2);
}

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
boolean isPointBefore(Point p1, Point p2)
{
    return abs(p1) < abs(p2) || (abs(p1) == abs(p2) && ord(p1) < ord(p2));
}

/**
 * @brief Menuliskan titik p ke console output.
 * 
 * @param p Point instance.
 */
void displayPoint(Point p)
{
    printf("(%d, %d)", abs(p), ord(p));
}