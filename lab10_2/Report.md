# Lab 10 —  Files in C

**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Korotkiy Ivan  
**Date:** 01.12
 
---
 
## Task Description
 
>   To learn how to work with text and binary files in the C programming language
 
## Structure
 
```
lab10/
├── attachments/
├── include/
├── src/
├── main.c
├── Makefile
├── exam.bin
└── Report.md
```
 
## Report

Given task:
![alt text](attachments/image.png)

---
### Runtime output

```
Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 2
No records found. Create file or append records first.

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 1
File created.

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 2
No records found. Create file or append records first.

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 5
Enter subject name: Math
Enter day: 22
Enter mounth: 11
Enter year: 2025
Enter students name (0 to stop): Kate
Enter grade: 98
Enter students name (0 to stop): Alex
Enter grade: 85
Enter students name (0 to stop): Max
Enter grade: 78
Enter students name (0 to stop): 0
File created.

Record appended.

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 2

(22.11.2025) Math:
  Kate - 98
  Alex - 85
  Max - 78

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 0
Exiting.
```
```
Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 2

(22.11.2025) Math:
  Kate - 98
  Alex - 85
  Max - 78

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 5
Enter subject name: Math
Enter students name (0 to stop): Bob 
Enter grade: 57
Enter students name (0 to stop): 0
File created.

Record appended.

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 2

(22.11.2025) Math:
  Kate - 98
  Alex - 85
  Max - 78
  Bob - 57

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 5
Enter subject name: IT
Enter day: 25
Enter mounth: 05
Enter year: 2020
Enter students name (0 to stop): Ivan
Enter grade: 99
Enter students name (0 to stop): Max
Enter grade: 100
Enter students name (0 to stop): Mark
Enter grade: 85
Enter students name (0 to stop): 0
File created.

Record appended.

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 2

(22.11.2025) Math:
  Kate - 98
  Alex - 85
  Max - 78
  Bob - 57

(25.05.2020) IT:
  Ivan - 99
  Max - 100
  Mark - 85

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 3
Search by:
1 - subject
2 - date
Enter choice: 1
Enter subject name: IT

(25.05.2020) IT:
Ivan - 99
Max - 100
Mark - 85

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 3
Search by:
1 - subject
2 - date
Enter choice: 2
Enter day: 22 
Enter mounth: 11
Enter year: 2025

(22.11.2025) Math:
Kate - 98
Alex - 85
Max - 78
Bob - 57

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 0
Exiting.
```
```
Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 4
Enter filter year: 2022
File created.

Old records deleted.

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 3
Search by:
1 - subject
2 - date
Enter choice: 1
Enter subject name: IT

Couldnt find any matching record!

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 2

(22.11.2025) Math:
  Kate - 98
  Alex - 85
  Max - 78
  Bob - 57

Choose an action:
1 - create file
2 - print
3 - search
4 - delete
5 - append
0 - exit
Enter choice: 0
Exiting.
```
---