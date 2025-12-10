#include <stdio.h>
#include <math.h>

int main(void)
{
    double a; 
    double b; 
    double c; 
    double d; 
    double e;
    double x;
    double E;

    printf("Enter x: ");
    scanf("%lf", &x);

    a = cos(x);
    b = sin(2 * x);
    c = exp(x);
    d = tan(x);
    e = log(x + 9);

    E = a / b + c * d / e;

    printf("E(%.3f) = %.8f\n", x, E);

    return 0;
}