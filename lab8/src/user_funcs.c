#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void even_count(int array[], int lenth)
{
    int count = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (array[i] % 2 == 0)
        {
            count++;
        }
    }
    printf("\nEven nums amount: %d", count);
}

void first_negative(int array[], int lenth)
{
    for (int i = 0; i < lenth; i++)
    {
        if (array[i] < 0)
        {
            printf("\nFirst nagative number: %d", array[i]);
            return;
        }
    }
    printf("\nNo negative values");
}

void rotate(int array[], int lenth)
{
    printf("\nRotated array: ");
    for (int i = lenth - 1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
}

int cmp_char(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

void ascii_sort(char array[], int lenth)
{
    qsort(array, lenth, sizeof(char), cmp_char);
    printf("\nSorted array by ascii:");
    for (int i = 0; i < lenth; i++) {
        printf("%c", array[i]);
    }
}

void range(int array[], int lenth)
{
    int min = 0;
    int max = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
        else if (array[i] > max)
        {
            max = array[i];
        }
    }
    printf("\nRange between min and max nums: %d", max - min);
}