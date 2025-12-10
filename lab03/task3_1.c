#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 0.0;
    double a; 
    double b; 
    double c; 
    double d;
    double E;

    printf("Input x: ");
    scanf("%lf", &x);

    a = x * x - 6 * x + 9;
    b = x - 3;
    c = 3 * x;
    d = x + 3;

    E = a / b + c / d;

    printf("E(%.3f) = %.8f\n", x, E);

    return 0;
}