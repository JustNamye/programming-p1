#include <stdio.h>
#include <stdlib.h>
#include <user_macros.h>

int main(void)
{

    double a;
    double b;
    double c;

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        puts("Error");
        exit(EXIT_FAILURE);
    }
    else if (a <= 0 || b <= 0 || c <= 0)
    {
        puts("Values must be > 0");
        exit(EXIT_FAILURE);
    }

    double S;
    HERON_AREA(S, a, b, c);

    if (S<=0)
    {
        puts("Not a triangle");
        exit(EXIT_FAILURE);
    }
    printf("S of triangle: %lf\n", S);

    IS_RIGHT(a, b, c);

    return EXIT_SUCCESS;
}