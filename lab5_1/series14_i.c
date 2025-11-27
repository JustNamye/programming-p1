#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>

int main(void)
{
    // formula is x^n/2n
    unsigned int x;
    unsigned int k;

    long long S = 0;

    if (scanf("%u %u", &x, &k) != 2)
    {
        puts("Invalid input");
        exit(EXIT_FAILURE);
    }

    for (unsigned int n = 1; n <= k; n++)
    {
        long long temp = (long long)pow(x, n);
        temp /= 2 * (long long) n;

        if (temp < 0 || (long long)S + temp > LLONG_MAX)
        {
            puts("Overflow!");
            exit(EXIT_FAILURE);
        }

        S += (long)temp;
    }
    printf("%lld"
           "\n",
           S);
    return EXIT_SUCCESS;
}