#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/lib.h"

int main(void)
{
    srand(time(NULL));

    float x = (float)(rand()%1000)/10;
    float y = (float)(rand()%1000)/10;
    float z = (float)(rand()%1000)/10;
    float w = (float)(rand()%1000)/10;
    float v = (float)(rand()%1000)/10;

    double res1 = func14(x, y, z, w);
    double res2 = func18(x, y, z, w);
    double res3 = func3(x, y, z, w, v);
    double res4 = func8(x, y, z, w, v);

    printf("%.1f %.1f %.1f %.1f %.1f\n", x, y, z, w, v);
    printf("func14: %.2lf\nfunc18: %.2lf\nfunc3: %.2lf\nfunc8: %.2lf\n", res1, res2, res3, res4);

    return EXIT_SUCCESS;
}