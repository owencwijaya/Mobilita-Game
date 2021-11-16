/**
 * @file colorizer.h
 * @brief Module colorizer.
 */

#include <stdio.h>
#include "colorizer.h"

/**
 * Uncomment the line below to enable ANSI escape
 * sequence rendering in windows console
 * @see https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
 * @see https://stackoverflow.com/questions/16755142/how-to-make-win32-console-recognize-ansi-vt100-escape-sequences
 */

#ifdef _WIN32
#include <windows.h>

void enableAnsiRendering()
{
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(outputHandle, &mode);
    mode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(outputHandle, mode))
      {
     exit(1);
  }
}
 

#else

void enableAnsiRendering()
{
}

#endif

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