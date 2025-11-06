#include <stdio.h>

int main(void){
    int n, k;
    printf("Enter a three-digit number: ");
    if (scanf("%d", &n)!=1 || n>999 || n<100){
        printf("Incorrect value. Must be a three-digit number.\n");
        return 1;
    }
    else {
        printf("Enter a one-digit positive number: ");
        if (scanf("%d", &k)!=1 || k>9 || k<0){
            printf("Incorrect value. Must be a one-digit positive number.\n");
            return 1;
        }
        else {

            int e = 6;

            int d1 = n/100%10;
            int d2 = n/10%10;
            int d3 = n%10;

            printf((d1 == e || d2 == e || d3 == e) ? 
            "Number %d contains %d\n" : 
            "Number %d doesn't contain %d\n", n, e);

            printf((d1 == k || d2 == k || d3 == k) ? 
            "Number %d contains %d\n" : 
            "Number %d doesn't contain %d\n", n, k);

        return 0;
        }
    }
}