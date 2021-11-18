/**
 * @file colorizer.h
 * @brief Header module colorizer.
 */

#ifndef COLORIZER_H
#define COLORIZER_H

#define RED_PREFIX "\x1b[38;5;196m"
#define ORANGE_PREFIX "\x1b[38;5;202m"
#define BLUE_PREFIX "\x1b[38;5;21m"
#define GREEN_PREFIX "\x1b[38;5;40m"
#define POSTFIX "\033[0m"


/**
 * @brief Mengubah warna console output
 *        menjadi merah.
 */
void changeToRedColor();
/**
 * @brief Mengubah warna console output
 *        menjadi oranye.
 */
void changeToOrangeColor();
/**
 * @brief Mengubah warna console output
 *        menjadi biru.
 */
void changeToBlueColor();
/**
 * @brief Mengubah warna console output
 *        menjadi hijau.
 */
void changeToGreenColor();
/**
 * @brief Mengembalikan warna console
 *        output ke warna semula.
 */
void resetColor();

#endif