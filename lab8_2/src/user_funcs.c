#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int sum_up_tri(int size, int matrix[size][size]) {
    int sum = 0;
    for (int wi = 0; wi < size; wi++)
    {
        for (int hi = wi; hi < size; hi++)
        {
            sum+=matrix[wi][hi];
        }
    }
    return sum;
}

int* sum_col(int size, int matrix[size][size]) {
    int* ml = malloc(size * sizeof(int));
    if (!ml) {
        return NULL;
    }

    for (int col = 0; col < size; col++)
    {
        for (int row = 0; row < size; row++) {
            ml[col]+=matrix[row][col];
        }
    }

    return ml;
}

int average(int size, int matrix[size][size]) {
    int res = 0;
    for (int w = 0; w < size; w++)
    {
        for (int h = 0; h < size; h++)
        {
            res+=matrix[w][h];
        }
    }
    res/=(size*size);
    return res;
}

int count_more_average(int size, int matrix[size][size]) {
    int count;
    for (int w = 0; w < size; w++)
    {
        for (int h = 0; h < size; h++)
        {
            if (matrix[w][h]>average(size, matrix))
            {
                count++;
            }
        }
    }
    return count;
}

int cmp_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

double interquartile_range(int size, int matrix[size][size]) {
    int total = size * size;
    int* flat = malloc(total * sizeof(int));
    if (!flat) return 0;

    int index = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            flat[index++] = matrix[i][j];

    qsort(flat, total, sizeof(int), cmp_int);

    double Q1, Q3;

    int mid = total / 2;
    
    if (mid % 2 == 0) {
        Q1 = (flat[mid/2 - 1] + flat[mid/2]) / 2.0;
    } else {
        Q1 = flat[mid/2];
    }

    int start = (total % 2 == 0) ? mid : mid + 1;
    int upper_len = total - start;
    if (upper_len % 2 == 0) {
        Q3 = (flat[start + upper_len/2 - 1] + flat[start + upper_len/2]) / 2.0;
    } else {
        Q3 = flat[start + upper_len/2];
    }

    free(flat);

    return Q3 - Q1;
}