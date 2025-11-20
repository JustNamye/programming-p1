#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>

int main(void) {
    // formula is x^n/2n
    double x;
    long k;
    long double S = 0;

    if (scanf("%lf %ld", &x, &k) != 2) {
        puts("Invalid input");
        return 1;
    }
    
    long n = 1;

    do {
        long double temp = (long double) pow(x, n);
        temp /= 2 * n;
        S+=temp;
        n++;
    } while(n < k);

    printf("%Lf \n", S);
    return 0;
}