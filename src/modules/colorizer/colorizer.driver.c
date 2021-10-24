#include <stdio.h>
#include "colorizer.h"

int main()
{
    changeToRedColor();
    printf("RED\n");
    changeToOrangeColor();
    printf("ORANGE\n");
    changeToBlueColor();
    printf("BLUE\n");
    changeToGreenColor();
    printf("GREEN\n");
    resetColor();
    printf("NORMAL\n");
    return 0;
}