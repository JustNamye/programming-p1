#include <math.h>

double tri_area(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    double S = s * (s - a) * (s - b) * (s - c);
    return S > 0 ? sqrt(S) : 0;
}

int tri_type(double a, double b, double c)
{
    // let be IDs 0-2
    // 0 - acute
    // 1 - right
    // 2 - obtuse

    double sideMax;
    double side1;
    double side2;

    if (a > c && a > b)
    {
        sideMax = a;
        side1 = b;
        side2 = c;
    }
    else if (c > a && c > b)
    {
        sideMax = c;
        side1 = a;
        side2 = b;
    }
    else if (b > a && b > a)
    {
        sideMax = b;
        side1 = a;
        side2 = c;
    }
    else if (a == c && a == b)
    {
        return 0;
    }
    else
    {
        return -1;
    }

    double dif = sideMax * sideMax - side1 * side1 - side2 * side2;

    if (dif < 0)
    {
        return 0;
    }
    if (dif == 0)
    {
        return 1;
    }
    if (dif > 0)
    {
        return 2;
    }

    return -1;
}