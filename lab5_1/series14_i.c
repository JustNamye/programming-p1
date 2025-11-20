#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>

int main(void) {
    // formula is x^n/2n
    unsigned int x;
    unsigned long long k;
    unsigned long long S = 0;

    if (scanf("%d %llu", &x, &k) != 2) {
        puts("Invalid input");
        return 1;
    }

    for (unsigned long long n = 1; n <= k; n++)
    {
        __int128_t temp = (__int128_t) pow(x, n);
        temp /= 2 * n;

        if (temp < 0 || (__int128_t) S + temp > (__int128_t) ULLONG_MAX) {
            puts("Overflow!");
            return 2;
        }
        S+=(long long) temp;        
    }
    printf("%llu" "\n", S);
    return 0;
}