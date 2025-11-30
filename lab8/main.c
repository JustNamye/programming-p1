#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/user_funcs.h"

int main(void)
{
    int lenth1 = 10;
    int array1[lenth1];

    for (int i = 0; i < 10; i++)
    {
        if (scanf("%d", &array1[i]) != 1)
        {
            exit(EXIT_FAILURE);
        }
    }

    even_count(array1, lenth1);
    first_negative(array1, lenth1);
    rotate(array1, lenth1);
    range(array1, lenth1);

    int lenth2 = 100;
    char array2[lenth2];

    printf("\n");
    scanf("%s", array2);
    ascii_sort(array2, strlen(array2));

    return EXIT_SUCCESS;
}