#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/func.h"

int main(void)
{
    int n;

    printf("Enter a number: ");
    if(scanf("%d", &n) != 1){
        exit(EXIT_FAILURE);
    }

    int divisors = countDivisorsRecursive(n, 1);
    printf("Divisor count: %d\n", divisors);
    printf("\nTriangle:\n");
    drawDigitTriangleRecursive(n, 1);

    // int divisors = countDivisorsIterative(n);
    // printf("Divisor count: %d\n", divisors);
    // printf("\nTriangle:\n");
    // drawDigitTriangleIterative(n);

    return EXIT_SUCCESS;
}