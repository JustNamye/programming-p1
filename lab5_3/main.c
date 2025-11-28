#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    // 7 -> 10
    int sevenIn;

    printf("7:");
    if (scanf("%d", &sevenIn) != 1)
    {
        puts("Invalid input");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int decOut = 0;

    while (sevenIn > 0)
    {
        short currentDigit = sevenIn % 10;

        if (currentDigit >= 7)
        {
            puts("Invalid input");
            exit(EXIT_FAILURE);
        }
        int temp = pow(7, i);

        temp *= currentDigit;
        sevenIn /= 10;
        decOut += temp;

        i++;
    }

    printf("10:%d\n", decOut);

    // 10 -> 7
    int decIn;

    printf("10:");
    if (scanf("%d", &decIn) != 1)
    {
        puts("Invalid input");
        exit(EXIT_FAILURE);
    }

    int j = 1;
    int rem = 0;

    int sevenOut = 0;

    while (decIn > 0)
    {
        sevenOut *= 10;

        int temp = pow(7, j) - pow(7, j - 1);
        decIn -= temp;
        sevenOut += 6;

        if (decIn < 0)
        {
            rem = -decIn;
        }
        j++;
    }

    int sevenChanged = 0;

    // shift number
    while (sevenOut > 0)
    {
        sevenChanged *= 10;

        short temp = sevenOut % 10;
        sevenOut /= 10;
        sevenChanged += temp;
    }

    while (rem > 0)
    {
        bool isAlive = true;
        int num = 1;
        int temp = 1;
        while (isAlive)
        {
            if (rem - temp * 7 <= 0)
            {
                int sub = rem / temp;
                sevenChanged -= sub * num;
                rem -= temp > 1 ? temp * sub : rem;

                isAlive = false;
            }
            temp *= 7;
            num *= 10;
        }
    }

    printf("7:%d\n", sevenChanged);

    return EXIT_SUCCESS;
}