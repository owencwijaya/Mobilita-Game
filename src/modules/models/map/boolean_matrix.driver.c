#include <stdio.h>
#include "../shared/boolean.h"
#include "../shared/macros.h"
#include "boolean_matrix.h"

int main()
{
    BooleanMatrix b = newBooleanMatrix(3, 4);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", elem(b, i, j));
        }
        printf("\n");
    }

    printf("\n");

    elem(b, 1, 1) = true;
    elem(b, 2, 3) = true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", elem(b, i, j));
        }
        printf("\n");
    }

    printf("\n");

    printf("%d\n", elem(b, 0, 0));
    printf("%d\n", elem(b, 1, 1));
}