# Lab 06_01 — User Functions (C)
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Korotkiy Ivan  
**Date:** 20.11
 
---
 
## Task Description
 
> Learn to write small, single-purpose function-like macros in C. Variant 14.
 
## Structure
 
```
lab6_2/
├── build/
├── include/
├── src/
├── main.c
├── Makefile
└── Report.md
```
 
## Report

HERON_AREA:
- Calculates triangle area with Herons formula
- $s=\frac{a+b+c}{2}$
- $S=\sqrt{s(s-a)(s-b)(s-c)}$

IS_RIGHT:
- Gets max side
- Сompares the sum of the squares of the shorter sides with the longer one.
- If max size equals - triangle's right, otherwise - not.

---
### Runtime Output

```
3 4 5
S of triangle: 6.000000
Triangle is right!
```
```
5 3 3
S of triangle: 4.145781
Triangle is not right!
```
```
0 0 0
Values must be > 0
```
```
50 100 1
Not a triangle
```
---
### .i file excerpt

```
# 5 "main.c"
int main(void)
{

    double a;
    double b;
    double c;

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        puts("Error");
        exit(
# 15 "main.c" 3 4
            1
# 15 "main.c"
                        );
    }
    else if (a <= 0 || b <= 0 || c <= 0)
    {
        puts("Values must be > 0");
        exit(
# 20 "main.c" 3 4
            1
# 20 "main.c"
                        );
    }

    double S;
    do { double _s = ((a) + (b) + (c)) / 2; double _S = _s * (_s - (a)) * (_s - (b)) * (_s - (c)); (S) = _S > 0 ? sqrt(_S) : 0; } while (0);

    if (S<=0)
    {
        puts("Not a triangle");
        exit(
# 29 "main.c" 3 4
            1
# 29 "main.c"
                        );
    }
    printf("S of triangle: %lf\n", S);

    do { double _maxSide = fmax(a, fmax(b, c)); if (_maxSide * _maxSide == (a) * (a) + (b) * (b) + (c) * (c) - _maxSide * _maxSide) { puts("Triangle is right!"); } else { puts("Triangle is not right!"); } } while (0);;

    return 
# 35 "main.c" 3 4
          0
# 35 "main.c"
                      ;
}
```
 
---