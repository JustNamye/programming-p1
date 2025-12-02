# Lab 12 — Working with C-Strings and File Operation

**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Korotkiy Ivan  
**Date:** 01.12
 
---
 
## Task Description
 
>   To learn how to work with text and binary files in the C programming language
 
## Structure
 
```
lab12/
├── attachments/
├── include/
├── src/
├── main.c
├── Makefile
└── Report.md
```
 
## Report

Given task:
![alt text](attachments/image.png)

---
### Runtime output
```
Enter some text: hello world!, some text\ bla bla bla- text
Enter deviders without space: !\
Token: hello world
Token: , some text
Token:  bla bla bla- text
```
```
ter some text: hello world!, some text\ bla bla bla- text
Enter deviders without space: , 
Token: hello world!
Token:  some text\ bla bla bla- text
```
**with space**
```
Enter some text: hello world!, some text\ bla bla bla- text
Enter deviders without space:  
Token: hello
Token: world!,
Token: some
Token: text\
Token: bla
Token: bla
Token: bla-
Token: text
```
---