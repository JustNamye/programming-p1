#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    double a = 0.0;
    double b = 2.0;

    int count;

    if (scanf("%d", &count) != 1 || count <= 0)
    {
        puts("Invalid input");
        exit(EXIT_FAILURE);
    }

    double step = (b - a) / (count - 1);
    double x = a;

    int i = 0;

    printf("%10c %12c\n", 'x', 'd');

    while (i < count)
    {
        bool isDefined;
        isDefined = cos(1 + x * x) != 0;
        if (isDefined)
        {
            double tg = tan(sqrt(1 + x * x));
            double d = exp(-x * x / 2) * tg;
            printf("%10.5f, %12.5f\n", x, d);
        }
        else
        {
            printf("%10.5f, %10s", x, "NaN");
        }

        i++;
        x = a + i * step;
    }
    return EXIT_SUCCESS;
}