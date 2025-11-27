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
    int x;
    unsigned int k;

    long long S = 0;

    if (scanf("%d %u", &x, &k) != 2)
    {
        puts("Invalid input");
        exit(EXIT_FAILURE);
    }

    long double n = 1;

    do
    {
        long long temp = (long long)pow(x, n);
        temp /= 2 * n;

        S += temp;

        n++;
    } while (n <= k);

    printf("%llu"
           "\n",
           S);
    return EXIT_SUCCESS;
}