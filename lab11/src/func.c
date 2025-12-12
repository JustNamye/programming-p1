#include <stdio.h>

int countDivisorsRecursive(int n, int current)
{
    if (current > n)
        return 0;
    if (n % current == 0)
        return 1 + countDivisorsRecursive(n, current + 1);
    else
        return countDivisorsRecursive(n, current + 1);
}

int countDivisorsIterative(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            count++;
    }
    return count;
}

void drawDigitTriangleRecursive(int n, int current)
{
    if (current > n)
        return;
    for (int i = 0; i < current; i++)
    {
        printf("%d", current);
    }
    printf("\n");
    drawDigitTriangleRecursive(n, current + 1);
}

void drawDigitTriangleIterative(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 0; col < row; col++)
        {
            printf("%d", row);
        }
        printf("\n");
    }
}