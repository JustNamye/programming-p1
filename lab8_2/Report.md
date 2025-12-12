# Lab 8 —  Implementing a Function Library with Unit Testing

**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Korotkiy Ivan  
**Date:** 29.11
 
---
 
## Task Description
 
>  The objective of this lab is to process 2D arrays in C, focusing on index based operations,matrix manipulation, aggregate functions and 1D representation of matrices. Variant 14.
 
## Structure
 
```
lab8_2/
├── attachments/
├── test/
├── include/
├── src/
├── main.c
├── Makefile
└── Report.md
```
 
## Report

Given task list:

![alt text](attachments/list.png)

![alt text](attachments/1.png)
![alt text](attachments/2.png)
![alt text](attachments/3.png)
![alt text](attachments/4.png)

---
### Unity tests screenshot
![alt text](attachments/unityresult.png)

 
---
### Runtime output:
```
Matrix:
2 9 8 6 6 
5 1 7 3 5 
2 4 8 5 7 
2 8 3 9 5 
8 4 2 7 8 
Sum of upper triangle: 89
Sum of columns:  19 26 28 30 31
Amount of more then avrg nums: 17
Interquartile range: 5
```
```
Matrix:
6 8 9 2 0 
6 9 3 2 7 
4 3 0 3 2 
5 9 2 7 1 
0 6 6 5 3 
Sum of upper triangle: 62
Sum of columns:  21 35 20 19 13
Amount of more then avrg nums: 17
Interquartile range: 4
```
```
Matrix:
0 4 6 2 6 
9 7 7 7 4 
3 6 7 8 2 
5 0 8 8 7 
7 1 1 7 8 
Sum of upper triangle: 83
Sum of columns:  24 18 29 32 27
Amount of more then avrg nums: 20
Interquartile range: 4
```

---