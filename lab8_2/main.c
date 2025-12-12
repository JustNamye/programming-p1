#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/user_funcs.h"

int main(void)
{
    srand(time(NULL));

    int size = 5;

    int matrix[size][size];
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            matrix[x][y] = rand()%10;
        }
    }
    
    printf("Matrix:\n");
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            printf("%d ", matrix[x][y]);
        }
        printf("\n");
    }

    int upperTri = sum_up_tri(size, matrix);
    int* sumColumns = sum_col(size, matrix);
    int moreAverage = count_more_average(size, matrix);
    int interquartileRange = interquartile_range(size, matrix);

    printf("Sum of upper triangle: %d\n", upperTri);
    printf("Sum of columns: ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", sumColumns[i]);
    }
    printf("\nAmount of more then avrg nums: %d\n", moreAverage);
    printf("Interquartile range: %d", interquartileRange);

    free(sumColumns);

    return EXIT_SUCCESS;
}