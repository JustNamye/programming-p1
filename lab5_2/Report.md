# Lab 05_02 —  Function Tabulation (C)
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Korotkiy Ivan  
**Date:** 20.11
 
---
 
## Task Description
 
> Compute series sums or products using loops. Variant 14.
 
## Structure
 
```
lab5_2/
├── main.c         # Task
└── Report.md      # Report
```
 
## Report
 
The goal of this lab is: 
- Learn using loops
- Avoid overflow durin program running
- Chose proper data types

Given formula: $e^{-x^2/2}tan\sqrt{1+x^2}$
DOD of given formula:\
$x\neq\pi/2+\pi n$\
$x\neq \sqrt{2.467}$

---
### Runtime Output

```
         x            d
   0.00000,      1.55741
   0.50000,      1.81410
   1.00000,      3.84184
   1.50000,     -1.37429
   2.00000,     -0.17249
```
```
         x            d
   0.00000,      1.55741
   0.28571,      1.63554
   0.57143,      1.90685
   0.85714,      2.67085
   1.14286,      9.96047
   1.42857,     -2.06272
   1.71429,     -0.52383
   2.00000,     -0.17249
```

---
### Debug session

```
Breakpoint 1, main () at lab5_2/main.c:6
6       int main(void) {
(gdb) next
7           double a = 0.0;
(gdb) next
8           double b = 2.0;
(gdb) next
12          if (scanf("%d", &count) != 1 || count <= 0) {
(gdb) print count
$1 = 0
(gdb) print a
$2 = 0
(gdb) print b
$3 = 2
(gdb) next
5
17          double step = (b - a) / (count - 1);
(gdb) print count
$4 = 5
(gdb) next
18          double x = a;
(gdb) next
20          int i = 0;
(gdb) next
22          printf("%10c %12c\n", 'x', 'd');
(gdb) next
         x            d
24          while (i<count)
(gdb) next
27              isDefined = cos(1 + x*x) != 0;
(gdb) print i
$5 = 0
(gdb) print x
$6 = 0
(gdb) print step
$7 = 0.5
(gdb) next
28              if (isDefined)
(gdb) next
30                  double tg = tan(sqrt(1+x*x));
(gdb) next
31                  if (tg==0)
(gdb) next
35                      double d = exp(-x*x/2)*tg;
(gdb) next
36                      printf("%10.5f, %12.5f\n", x, d);
(gdb) next
   0.00000,      1.55741
43              i++;
(gdb) print d
$8 = {i = {0, 1076887552}, x = 16, d = 16}
(gdb) print tg
No symbol "tg" in current context.
(gdb) print isDefined
$9 = true
(gdb) next
44              x = a + i * step;
(gdb) next
24          while (i<count)
(gdb) next
27              isDefined = cos(1 + x*x) != 0;
(gdb) set isDefined = false
No symbol "false" in current context.
(gdb) set isDefined = 0
(gdb) next
28              if (isDefined)
(gdb) set isDefined = 0
(gdb) next
40                  printf("%10.5f, %10s", x, "NaN");
(gdb) next
43              i++;
(gdb) next
44              x = a + i * step;
(gdb) next
24          while (i<count)
(gdb) next
27              isDefined = cos(1 + x*x) != 0;
(gdb) next
28              if (isDefined)
(gdb) next
30                  double tg = tan(sqrt(1+x*x));
(gdb) next
31                  if (tg==0)
(gdb) set tg = 0
(gdb) next
33                      printf("%10.5f, %10s", x, "NaN");
(gdb) exit
```
 
---