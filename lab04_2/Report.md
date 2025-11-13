# Lab 04 — Conditional Statements
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Korotkiy Ivan  
**Date:** 06.11
 
---
 
## Task Description
 
> Practice writing branching logic using conditional statements. Variant 14
 
## Structure
 
```text
lab04_2/
├── task4_02.c   # Main file
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
Enter shape ID (1–4): 2
triangle
```
```
Enter shape ID (1–4): 4
circle
```
```
Enter shape ID (1–4): 5
Error: ID must be between 1 and 4
```

---
### Debug session
 
```
Breakpoint 1, main () at task4_02.c:3
3       int main(void){
(gdb) next
5           printf("Enter shape ID (1–4): ");
(gdb) next
6           if (scanf("%d", &type) != 1) {
(gdb) next
Enter shape ID (1–4): 1
10          switch (type)
(gdb) next
13              puts("line");
(gdb) print type
$1 = 1
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/justn/programming-p1/lab04_2/task4_02 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at task4_02.c:3
3       int main(void){
(gdb) next
5           printf("Enter shape ID (1–4): ");
(gdb) next
6           if (scanf("%d", &type) != 1) {
(gdb) next
Enter shape ID (1–4): a 
7               puts("Invalid input");
(gdb) next
Invalid input
8               return 1;
```
 
---