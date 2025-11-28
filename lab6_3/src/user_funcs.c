#include <math.h>
#include <stdio.h>

void print_sqrt(int value)
{
    printf("%.2lf ", sqrt(value));
}

void print_square(int value)
{
    printf("%d ", value * value);
}

void print_fact(int value)
{
    int res = 1;
    for (int i = 1; i <= value; i++)
    {
        res *= i;
    }
    printf("%d ", res);
}