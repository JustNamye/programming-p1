# Lab 03 — Expressions
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Korotkiy Ivan  
**Date:** 06.11
 
---
 
## Task Description
 
> Calculate the expression using standard C expressions. Variant 14.
 
## Structure
 
```text
lab03_2/
├── Report.md   # Report
└── task3_2.c   # Main file
```
 
## Report
 
The goal of this lab is: 
- To learn to use standart C expressions, create breakpoints and debug programm.
- Find DOD of given expression.
- Calculate expression.

DOD of the expression:
- $x \neq \frac{k*\pi}{2}$
- $x \neq \frac{\pi}{2} + k*\pi$
- $x > -9$

---
### Runtime Output

```
Enter x: 3
E(3.000) = 2.39087790
```
```
Enter x: -8.99
E(-8.990) = -1.18707164
```
violated $x > -9$
```
Enter x: -9.01
E(-9.010) = -nan
```
violated $x \neq \frac{\pi}{2} + k*\pi$
```
Enter x: 4.71
E(4.710) = 17754.60071091
```
violated $x \neq \frac{k*\pi}{2}$
```
Enter x: 1.57
E(1.570) = 2560.28487240
```

---
### Debug session
 
```
Breakpoint 1, main () at task3_2.c:4
4       int main(void) {
(gdb) next
7           printf("Enter x: ");
(gdb) next
8           scanf("%lf", &x);
(gdb) next
Enter x: -10
10          a = cos(x);
(gdb) print a
$1 = 0
(gdb) print b
$2 = 0
(gdb) print c
$3 = 0
(gdb) print d
$4 = 0
(gdb) print e
$5 = 6.9533491712725251e-310
(gdb) print E
$6 = 6.953355807396274e-310
(gdb) next
11          b = sin(2*x);
(gdb) next
12          c = exp(x);
(gdb) next
13          d = tan(x);
(gdb) print a
$7 = -0.83907152907645244
(gdb) print b
$8 = -0.91294525072762767
(gdb) print c
$9 = 4.5399929762484854e-05
(gdb) print d
$10 = 0
(gdb) print e
$11 = 6.9533491712725251e-310
(gdb) print E
$12 = 6.953355807396274e-310
(gdb) next
14          e = log(x+9);
(gdb) next
16          E = a/b + c*d/e;
(gdb) next
18          printf("E(%.3f) = %.8f\n", x, E);
(gdb) print a
$13 = -0.83907152907645244
(gdb) print b
$14 = -0.91294525072762767
(gdb) print c
$15 = 4.5399929762484854e-05
(gdb) print d
$16 = -0.64836082745908663
(gdb) print e
$17 = -nan(0x8000000000000)
(gdb) print E
$18 = -nan(0x8000000000000)
```
 
---