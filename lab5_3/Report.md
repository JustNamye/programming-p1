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
lab5_3/
├── main.c         # Task
└── Report.md      # Report
```
 
## Report
 
The goal of this lab is: 
- Learn using loops
- Avoid overflow durin program running
- Chose proper data types

Given values:
a=7;
b=10;

---
### Runtime Output

```
7:265
10:145
10:2845
7:11203
```
```
7:100
10:49
10:49
7:100
```
```
7:66
10:48
10:100
7:202
```
```
7:42
10:30
10:505
7:1321
```

---
### Debug session

```
7       {
(gdb) next
11          printf("7:");
(gdb) next
12          if (scanf("%d", &seven_in) != 1)
(gdb) next
7:164
18          int i = 0;
(gdb) next
19          int dec_out = 0;
(gdb) next
21          while (seven_in > 0)
(gdb) next
23              short currentDigit = seven_in%10;
(gdb) next
25              if (currentDigit>=7)
(gdb) next
30              int temp = pow(7, i);
(gdb) next
32              temp*=currentDigit;
(gdb) next
33              seven_in/=10;
(gdb) next
34              dec_out+=temp;
(gdb) next
36              i++;
(gdb) print dec_out
$4 = 4
(gdb) next
21          while (seven_in > 0)
(gdb) next
23              short currentDigit = seven_in%10;
(gdb) next
25              if (currentDigit>=7)
(gdb) next
30              int temp = pow(7, i);
(gdb) next
32              temp*=currentDigit;
(gdb) next
33              seven_in/=10;
(gdb) next
34              dec_out+=temp;
(gdb) next
36              i++;
(gdb) next
21          while (seven_in > 0)
(gdb) print dec_out
$5 = 46
(gdb) next
23              short currentDigit = seven_in%10;
(gdb) next
25              if (currentDigit>=7)
(gdb) next
30              int temp = pow(7, i);
(gdb) next
32              temp*=currentDigit;
(gdb) next
33              seven_in/=10;
(gdb) next
34              dec_out+=temp;
(gdb) next
36              i++;
(gdb) next
21          while (seven_in > 0)
(gdb) print dec_out
$6 = 95
(gdb) next
39          printf("10:%d\n",dec_out);
(gdb) next
10:95
50          printf("10:");
(gdb) next
51          if (scanf("%d", &dec_in) != 1)
(gdb) next
10:49 
57          int j = 1;
(gdb) next
58          int rem = 0;
(gdb) next
60          int seven_out = 0;
(gdb) next
62          while (dec_in>0)
(gdb) next
64              seven_out *= 10;
(gdb) next
66              int temp = pow(7, j)-pow(7,j-1);
(gdb) next
67              dec_in-=temp;
(gdb) next
68              seven_out+=6;
(gdb) next
70              if (dec_in<0)
(gdb) next
74              j++;
(gdb) next
62          while (dec_in>0)
(gdb) print seven_out
$7 = 6
(gdb) next
64              seven_out *= 10;
(gdb) next
66              int temp = pow(7, j)-pow(7,j-1);
(gdb) 
67              dec_in-=temp;
(gdb) next
68              seven_out+=6;
(gdb) next
70              if (dec_in<0)
(gdb) 
74              j++;
(gdb) next
62          while (dec_in>0)
(gdb) next
64              seven_out *= 10;
(gdb) print seven_out
$8 = 66
(gdb) next
66              int temp = pow(7, j)-pow(7,j-1);
(gdb) next
67              dec_in-=temp;
(gdb) 
68              seven_out+=6;
(gdb) next
70              if (dec_in<0)
(gdb) next
72                  rem=-dec_in;
(gdb) next
74              j++;
(gdb) next
62          while (dec_in>0)
(gdb) next
81          int seven_changed = 0;
(gdb) print seven_out
$9 = 666
(gdb) next
84          while (seven_out>0)
(gdb) next
86              seven_changed*=10;
(gdb) next
88              short temp = seven_out%10;
(gdb) next
89              seven_out/=10;
(gdb) next
90              seven_changed+=temp;
(gdb) next
84          while (seven_out>0)
(gdb) next
86              seven_changed*=10;
(gdb) next
88              short temp = seven_out%10;
(gdb) next
89              seven_out/=10;
(gdb) print seven_changed
$10 = 60
(gdb) next
90              seven_changed+=temp;
(gdb) next
84          while (seven_out>0)
(gdb) next
86              seven_changed*=10;
(gdb) print seven_changed
$11 = 66
(gdb) next
88              short temp = seven_out%10;
(gdb) next
89              seven_out/=10;
(gdb) next
90              seven_changed+=temp;
(gdb) next
84          while (seven_out>0)
(gdb) next
93          while (rem>0)
(gdb) next
95              bool isAlive = true;
(gdb) next
96              int num = 1;
(gdb) next
97              int temp = 1;
(gdb) next
98              while (isAlive)
(gdb) next
100                 if (rem - temp*7 <= 0)
(gdb) next
108                 temp*=7;
(gdb) next
109                 num*=10;
(gdb) next
98              while (isAlive)
(gdb) next
100                 if (rem - temp*7 <= 0)
(gdb) print seven_changed
$12 = 666
(gdb) next
108                 temp*=7;
(gdb) next
109                 num*=10;
(gdb) next
98              while (isAlive)
(gdb) print seven_changed
$13 = 666
(gdb) print seven_changed
$14 = 666
(gdb) NEXT
Undefined command: "NEXT".  Try "help".
(gdb) next
100                 if (rem - temp*7 <= 0)
(gdb) next
102                     int sub = rem/temp;
(gdb) next
103                     seven_changed-= sub*num;
(gdb) next
104                     rem-= temp>1 ? temp * sub : rem;
(gdb) next
106                     isAlive = false;
(gdb) print seven_changed
$15 = 166
(gdb) next
108                 temp*=7;
(gdb) next
109                 num*=10;
(gdb) next
98              while (isAlive)
(gdb) next
93          while (rem>0)
(gdb) next
95              bool isAlive = true;
(gdb) next
96              int num = 1;
(gdb) next
97              int temp = 1;
(gdb) next
98              while (isAlive)
(gdb) next
100                 if (rem - temp*7 <= 0)
(gdb) next
108                 temp*=7;
(gdb) next
109                 num*=10;
(gdb) next
98              while (isAlive)
(gdb) next
100                 if (rem - temp*7 <= 0)
(gdb) next
102                     int sub = rem/temp;
(gdb) next
103                     seven_changed-= sub*num;
(gdb) next
104                     rem-= temp>1 ? temp * sub : rem;
(gdb) print seven_changed
$16 = 106
(gdb) next
106                     isAlive = false;
(gdb) next
108                 temp*=7;
(gdb) next
109                 num*=10;
(gdb) next
98              while (isAlive)
(gdb) next
93          while (rem>0)
(gdb) next
95              bool isAlive = true;
(gdb) next
96              int num = 1;
(gdb) next
97              int temp = 1;
(gdb) next
98              while (isAlive)
(gdb) next
100                 if (rem - temp*7 <= 0)
(gdb) next
102                     int sub = rem/temp;
(gdb) next
103                     seven_changed-= sub*num;
(gdb) next
104                     rem-= temp>1 ? temp * sub : rem;
(gdb) print seven_changed
$17 = 100
(gdb) next
106                     isAlive = false;
(gdb) next
108                 temp*=7;
(gdb) next
109                 num*=10;
(gdb) next
98              while (isAlive)
(gdb) next
93          while (rem>0)
(gdb) next
115         printf("7:%d\n", seven_changed);
(gdb) next
7:100
118         return EXIT_SUCCESS;
(gdb) next
119     }
```
 
---