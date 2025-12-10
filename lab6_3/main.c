#include <stdio.h>
#include <stdlib.h>
#include "include/user_funcs.h"
#include "include/callbacks.h"

int main(void)
{
    int from;
    int to;

    if (scanf("%d %d", &from, &to) != 2)
    {
        puts("error.");
        exit(EXIT_FAILURE);
    }

    printf("Square roots: ");
    for_positive(from, to, print_sqrt);
    printf("\nSquares: ");
    for_positive(from, to, print_square);
    printf("\nFactorials: ");
    for_positive(from, to, print_fact);

    return EXIT_SUCCESS;
}