# Lab 04 — Conditional Statements
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Korotkiy Ivan  
**Date:** 06.11
 
---
 
## Task Description
 
> Practice writing branching logic using conditional statements. Variant 14.
 
## Structure
 
```text
lab04_3/
├── task4_03.c   # Main file
└── Report.md   # Report
```
 
## Report
 
The goal of this lab is: 
- Implement decisions with if/else and the ternary operator ?:.
- Extract and compare digits of an integer using / and %.
- Combine simple conditions with logical operators (&&, ||, !).
- Validate inputs and print clear diagnostic messages.
 
Logical condition:
```
√(x*x+y*y)<=R
y<=√x
-y>=√x
```

---
### Runtime Output

```
0 0
SHADED
```
```
-1 0
OUTSIDE
```
```
2 0
OUTSIDE
```
```
0.75 0
SHADED
```
```
0 0
SHADED
```
```
0.6 0.3
SHADED
```
```
0.3 0.7
OUTSIDE
```

---
### Debug session
 
```
Breakpoint 1, main () at lab04_3/task4_03.c:5
5       int main(void){
(gdb) next
6           const float radius = 0.75f;
(gdb) next
10          if (scanf("%lf %lf", &x, &y) != 2) {
(gdb) 3 3
Undefined command: "3".  Try "help".
(gdb) next
3 3
15          double distance = sqrt(x*x + y*y);
(gdb) next
16          bool inCircle = distance<=radius;
(gdb) print radius
$1 = 0.75
(gdb) print x
$2 = 3
(gdb) print y
$3 = 3
(gdb) print distance
$4 = 4.2426406871192848
(gdb) print inCircle
$5 = false
(gdb) print aboveLowerFunc
$6 = false
(gdb) print isShaded
$7 = false
(gdb) next
18          double funcY = sqrt(x);
(gdb) next
19          bool belowUpperFunc = y<=funcY;
(gdb) next
20          bool aboveLowerFunc = -y>=-funcY;
(gdb) next
22          bool isShaded = belowUpperFunc && aboveLowerFunc;
(gdb) ntext
Undefined command: "ntext".  Try "help".
(gdb) next
24          if (!inCircle) {
(gdb) print isShaded
$8 = false
(gdb) next
25              puts("OUTSIDE");
(gdb) next
OUTSIDE
37      return 0;
```
 
---