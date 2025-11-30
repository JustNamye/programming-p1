#include <stdio.h>
#include <stdlib.h>
#include "include/user_funcs.h"

int main(void)
{
    int size;
    if (scanf("%d", &size) != 1)
    {
        exit(EXIT_FAILURE);
    }

    int matrix[size][size];
    for (int wi = 0; wi < size; wi++)
    {
        for (int hi = 0; hi < size; hi++)
        {
            if (scanf("%d", &matrix[wi][hi]) != 1)
            {
                exit(EXIT_FAILURE);
            }
        }
    }
    

    return EXIT_SUCCESS;
}