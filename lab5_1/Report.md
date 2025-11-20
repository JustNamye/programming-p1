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

**series14_i.c:**
```
5 10
628501
```
```
3 6
101
```
**series14_fp.c:**
```
3 5
18.375000
```
```
2.5 11
868.138912 
```
```
19.351 42
732255531196396302493352899026909327776619897552896.000000
```

---
### Debug session
 
**series14_i.c:**
```
Breakpoint 1, main () at lab5_1/series14_i.c:8
8       int main(void) {
(gdb) next
14          if (scanf("%d %llu", &x, &k) != 2) {
(gdb) next
3 6 
19          for (unsigned long long n = 1; n <= k; n++)
(gdb) print k
$1 = 6
(gdb) print x
$2 = 3
(gdb) print n
$3 = 0
(gdb) print S
$4 = 0
(gdb) next
21              __int128_t temp = (__int128_t) pow(x, n);
(gdb) next
22              temp /= 2 * n;
(gdb) next
24              if (temp < 0 || (__int128_t) S + temp > (__int128_t) ULLONG_MAX) {
(gdb) next
28              S+=(long long) temp;        
(gdb) next
19          for (unsigned long long n = 1; n <= k; n++)
(gdb) print temp
No symbol "temp" in current context.
(gdb) next
21              __int128_t temp = (__int128_t) pow(x, n);
(gdb) next
22              temp /= 2 * n;
(gdb) print temp
$5 = 9
(gdb) print S
$6 = 1
```
**series14_fp.c:**
```
8       int main(void) {
(gdb) print x
$1 = 0
(gdb) prin k
Ambiguous command "prin k": print, print-object, printf.
(gdb) print k
$2 = 0
(gdb) next
12          long double S = 0;
(gdb) next
14          if (scanf("%lf %ld", &x, &k) != 2) {
(gdb) next
5 1
19          long n = 1;
(gdb) print x
$3 = 5
(gdb) print k
$4 = 1
(gdb) print n
$5 = 0
(gdb) print S
$6 = 0
(gdb) next
22              long double temp = (long double) pow(x, n);
(gdb) next
23              temp /= 2 * n;
(gdb) next
24              S+=temp;        
(gdb) print temp
$7 = 2.5
(gdb) print S
$8 = 0
(gdb) next
25          } while(n < k);
(gdb) print S
$9 = 2.5
(gdb) next
27          printf("%Lf \n", S);
```
 
---