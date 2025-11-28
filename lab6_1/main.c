#include <stdio.h>
#include <stdlib.h>
#include <user_funcs.h>

int main(void)
{

    double a;
    double b;
    double c;

    printf("Enter 3 sides of triangle:");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        puts("Invalid input!");
        exit(EXIT_FAILURE);
    }
    if (a <= 0 || b <= 0 || c <= 0)
    {
        puts("Sides must be bigger than 0!");
        exit(EXIT_FAILURE);
    }

    double area = tri_area(a, b, c);

    if (area <= 0)
    {
        puts("Not a triangle!");
        exit(EXIT_FAILURE);
    }

    printf("S of given triangle is: %.3lf\n", area);

    switch (tri_type(a, b, c))
    {
    case 0:
        puts("Given triangle is acute.");
        break;
    case 1:
        puts("Given triangle is right.");
        break;
    case 2:
        puts("Given triangle is obtuse");
        break;
    default:
        puts("Something went wrong!");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}