# Lab 06_01 — User Functions (C)
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Korotkiy Ivan  
**Date:** 20.11
 
---
 
## Task Description
 
> Write small, single-purpose functions and demonstrate them from main. Variant 14.
 
## Structure
 
```
lab6_1/
├── build/
├── include/
├── src /
├── main.c
├── Makefile
└── Report.md
```
 
## Report

Triangle area - tri_area():
- Calculates triangle area with Herons formula
- $s=\frac{a+b+c}{2}$
- $S=\sqrt{s(s-a)()(s-b)(s-c)}$

Triangle type - tri_type():
- Gets max side
- Сompares the sum of the squares of the shorter sides with the longer one.
- If max size is bigger - triangle is acute
- If max size equals - its right
- If max size is smaller - its obtuse

Given values:
a=7;
b=10;

---
### Runtime Output

```
Enter 3 sides of triangle:3 4 5
S of given triangle is: 6.000
Given triangle is right.
```
```
Enter 3 sides of triangle:0 0 0
Sides must be bigger than 0!
```
```
Enter 3 sides of triangle:100 1 1
Not a triangle!
```
```
Enter 3 sides of triangle:10 10 10
S of given triangle is: 43.301
Given triangle is acute.
```
```
Enter 3 sides of triangle:6 6 11
S of given triangle is: 13.189
Given triangle is obtuse
```
---
### Debug session

```
Breakpoint 1, main () at main.c:6
6       {
(gdb) next
12          printf("Enter 3 sides of triangle:");
(gdb) next
13          if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
(gdb) next
Enter 3 sides of triangle:3 4 5
18          if (a <= 0 || b <= 0 || c <= 0)
(gdb) next
24          double area = tri_area(a, b, c);
(gdb) next
26          if (area <= 0)
(gdb) print area
$1 = 6
(gdb) print a
$2 = 3
(gdb) print b
$3 = 4
(gdb) print c
$4 = 5
(gdb) next
32          printf("S of given triangle is: %.3lf\n", area);
(gdb) next
S of given triangle is: 6.000
34          switch (tri_type(a, b, c))
(gdb) next
40              puts("Given triangle is right.");
(gdb) exit
```
 
---