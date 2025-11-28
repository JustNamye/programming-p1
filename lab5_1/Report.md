# Lab 05_01 — Series Sums and Products
 
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
lab05_1/
├── series14_i.c   # Int task
├── series14_i.c   # Float task
└── Report.md      # Report
```
 
## Report
 
The goal of this lab is: 
- Learn using loops
- Avoid overflow durin program running
- Chose proper data types
---
### Runtime Output

**series14_i.c:**
```
13 3
414
```
```
100 10      
Overflow!
```
**series14_fp.c:**
```
100 10
5056187782758700962.500000
```
```
20 30
18871893121615047329559440154769227776.000000
```
```
13 3
414.916667
```

---
### Debug session
 
**series14_i.c:**
```
Breakpoint 1, main () at lab5_1/series14_i.c:10
warning: Source file is more recent than executable.
10      {
(gdb) next
15          long long S = 0;
(gdb) next
17          if (scanf("%u %u", &x, &k) != 2)
(gdb) next
100 10
23          for (unsigned int n = 1; n <= k; n++)
(gdb) next
25              long long temp = (long long)pow(x, n);
(gdb) next
26              temp /= 2 * (long long) n;
(gdb) next
28              if (temp < 0 || (long long)S + temp > LLONG_MAX)
(gdb) next
34              S += (long)temp;
(gdb) next
23          for (unsigned int n = 1; n <= k; n++)
(gdb) next
25              long long temp = (long long)pow(x, n);
(gdb) print S
$1 = 50
(gdb) print temp
$2 = 50
(gdb) next
26              temp /= 2 * (long long) n;
(gdb) print temp
$3 = 10000
(gdb) next
28              if (temp < 0 || (long long)S + temp > LLONG_MAX)
(gdb) next
34              S += (long)temp;
(gdb) print n
$4 = 2
(gdb) next
23          for (unsigned int n = 1; n <= k; n++)
(gdb) next
25              long long temp = (long long)pow(x, n);
(gdb) next
26              temp /= 2 * (long long) n;
(gdb) next
28              if (temp < 0 || (long long)S + temp > LLONG_MAX)
(gdb) next
34              S += (long)temp;
(gdb) next
23          for (unsigned int n = 1; n <= k; n++)
(gdb) print S
$5 = 169216
(gdb) pritn temp
Undefined command: "pritn".  Try "help".
(gdb) print temp
No symbol "temp" in current context.
(gdb) next
25              long long temp = (long long)pow(x, n);
(gdb) next
26              temp /= 2 * (long long) n;
(gdb) print n
$6 = 4
(gdb) print S
$7 = 169216
(gdb) print temp
$8 = 100000000
(gdb) next
28              if (temp < 0 || (long long)S + temp > LLONG_MAX)
(gdb) next
34              S += (long)temp;
(gdb) next
23          for (unsigned int n = 1; n <= k; n++)
(gdb) print S
$9 = 12669216
```
**series14_fp.c:**
```
Breakpoint 1, main () at lab5_1/series14_fp.c:10
10      {
(gdb) next
15          long double S = 0;
(gdb) next
17          if (scanf("%d %u", &x, &k) != 2)
(gdb) next
100 1000
23          long n = 1;
(gdb) next
27              long double temp = (long double)pow(x, n);
(gdb) next
28              temp /= 2 * n;
(gdb) next
30              S += temp;
(gdb) print temp
$1 = 50
(gdb) print S
$2 = 0
(gdb) print n
$3 = 1
(gdb) next
32              n++;
(gdb) next
33          } while (n <= k);
(gdb) next
27              long double temp = (long double)pow(x, n);
(gdb) next
28              temp /= 2 * n;
(gdb) print n
$4 = 2
(gdb) print S
$5 = 50
(gdb) next
30              S += temp;
(gdb) print n
$6 = 2
(gdb) print temp
$7 = 2500
(gdb) print S
$8 = 50
(gdb) next
32              n++;
(gdb) next
33          } while (n <= k);
(gdb) next
27              long double temp = (long double)pow(x, n);
(gdb) next
28              temp /= 2 * n;
(gdb) next
30              S += temp;
(gdb) print temp
$9 = 166666.666666666666671
(gdb) print n
$10 = 3
(gdb) print s
No symbol "s" in current context.
(gdb) print S
$11 = 2550
(gdb) nex
Ambiguous command "nex": next, nexti.
(gdb) next
32              n++;
(gdb) print S
$12 = 169216.666666666666671
```
 
---