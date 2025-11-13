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
lab04/
├── task4_01.c   # Main file
└── Report.md   # Report
```
 
## Report
 
The goal of this lab is: 
- Implement decisions with if/else and the ternary operator ?:.
- Extract and compare digits of an integer using / and %.
- Combine simple conditions with logical operators (&&, ||, !).
- Validate inputs and print clear diagnostic messages.
 
---
### Runtime Output

```
Enter a three-digit number: 457
Enter a one-digit positive number: 9
Number 457 doesn't contain 6
Number 457 doesn't contain 9
```
```
Enter a three-digit number: 963
Enter a one-digit positive number: 8
Number 963 contains 6
Number 963 doesn't contain 8
```
```
Enter a three-digit number: 609
Enter a one-digit positive number: 9
Number 609 contains 6
Number 609 contains 9
```

---
### Debug session
 
```
Breakpoint 1, main () at task4_01.c:3
3       int main(void){
(gdb) next
5           printf("Enter a three-digit number: ");
(gdb) next
6           if (scanf("%d", &n)!=1 || n>999 || n<100){
(gdb) next
Enter a three-digit number: 993
11              printf("Enter a one-digit positive number: ");
(gdb) next
12              if (scanf("%d", &k)!=1 || k>9 || k<0){
(gdb) next
Enter a one-digit positive number: 0  
18                  int e = 6;
(gdb) print n
$1 = 993
(gdb) print k
$2 = 0
(gdb) next
20                  int d1 = n/100%10;
(gdb) next
21                  int d2 = n/10%10;
(gdb) next
22                  int d3 = n%10;
(gdb) next
24                  printf((d1 == e || d2 == e || d3 == e) ? 
(gdb) print d1, d2, d3
$3 = 3
(gdb) print d2
$4 = 9
(gdb) print d3
$5 = 3
(gdb) print d1
$6 = 9
(gdb) next
Number 993 doesn't contain 6
28                  printf((d1 == k || d2 == k || d3 == k) ? 
(gdb) next
Number 993 doesn't contain 0
32              return 0;
```
 
---