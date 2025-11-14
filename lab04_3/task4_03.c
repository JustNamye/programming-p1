#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    const float radius = 0.75f;

    double x,y;
    
    if (scanf("%lf %lf", &x, &y) != 2) {
        puts("Input error");
        return 1;
    }

    double distance = sqrt(x*x + y*y);
    bool inCircle = distance<=radius;

    double funcY = sqrt(x);
    bool belowUpperFunc = y<=funcY;
    bool aboveLowerFunc = -y>=-funcY;

    bool isShaded = belowUpperFunc && aboveLowerFunc;

    if (!inCircle) {
        puts("OUTSIDE");
    } 
    else if (isShaded) {
        puts("SHADED");
    }
    else {
        puts("NOT SHADED");
    }
    
    
    
    
return 0;
}