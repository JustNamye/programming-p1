# Lab XX — Lab Work Report Template
 
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
lab03/
├── lab03_1.c   # Main file
└── Report.md   # Report
```
 
## Report
 
The goal of this lab is: 
- To learn to use standart C expressions, create breakpoints and debug programm.
- Find DOD of given expression.
- Calculate expression.

DOD of the expression is:
- x != 3
- x != -3
 
---
### Runtime Output

```
Input x: 2
E(2.000) = 0.20000000
```
```
Input x: 2.99
E(2.990) = 1.48749583
```
```
Input x: 3
E(3.000) = -nan
```
```
Input x: -3
E(-3.000) = -inf
```

---
### Debug session
 
```
Breakpoint 1, main () at task3_1.c:4
4       int main(void) {
(gdb) print x
$1 = 0
(gdb) print E
$2 = 6.953355807397855e-310
(gdb) next
5           double x = 0.0;
(gdb) next
8           printf("Input x: ");
(gdb) next
9           scanf("%lf", &x);
(gdb) next
Input x: -3   
11          a = x*x - 6*x + 9;
(gdb) print a
$3 = 0
(gdb) print b
$4 = 0
(gdb) print c
$5 = 0
(gdb) print d
$6 = 6.9533491712725251e-310
(gdb) next
12          b = x - 3;
(gdb) next
13          c = 3*x;
(gdb) next
14          d = x + 3;
(gdb) print E
$7 = 6.953355807397855e-310
(gdb) print a
$8 = 36
(gdb) print c
$9 = -9
(gdb) print b
$10 = -6
(gdb) print d
$11 = 6.9533491712725251e-310
(gdb) next
16          E=a/b+c/d;
(gdb) next
18          printf("E(%.3f) = %.8f\n", x, E);
(gdb) print a
$12 = 36
(gdb) print c
$13 = -9
(gdb) print b
$14 = -6
(gdb) print e
No symbol "e" in current context.
(gdb) print E
$15 = -inf
```
 
---