#include <stdio.h>

int main(void){
    int type;
    printf("Enter shape ID (1–4): ");
    if (scanf("%d", &type) != 1) {
        puts("Invalid input");
        return 1;
    }
    switch (type)
    {
    case 1:
        puts("line");
        break;
    case 2:
        puts("triangle");
        break;
    case 3:
        puts("square");
        break;
    case 4:
        puts("circle");
        break;
    default:
        puts("Error: ID must be between 1 and 4");
        return 2;
    }
return 0;
}