/**
 * @file colorizer.h
 * @brief Module colorizer.
 */

#include <stdio.h>
#include "colorizer.h"

/**
 * @brief Mengubah warna console output
 *        menjadi merah.
 */
void changeToRedColor()
{
    printf("%s", RED_PREFIX);
}

/**
 * @brief Mengubah warna console output
 *        menjadi oranye.
 */
void changeToOrangeColor()
{
    printf("%s", ORANGE_PREFIX);
}

/**
 * @brief Mengubah warna console output
 *        menjadi biru.
 */
void changeToBlueColor()
{
    printf("%s", BLUE_PREFIX);
}

/**
 * @brief Mengubah warna console output
 *        menjadi hijau.
 */
void changeToGreenColor()
{
    printf("%s", GREEN_PREFIX);
}

/**
 * @brief Mengembalikan warna console
 *        output ke warna semula.
 */
void resetColor()
{
    printf("%s", POSTFIX);
}