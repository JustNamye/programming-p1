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
18041763254625513787
```
```
20 30
15080147870543527785
```
```
13 3
414
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
warning: Source file is more recent than executable.
10      {
(gdb) next
15          long long S = 0;
(gdb) next
17          if (scanf("%d %u", &x, &k) != 2)
(gdb) next
100 1000
23          long double n = 1;
(gdb) next
27              long long temp = (long long)pow(x, n);
(gdb) next
28              temp /= 2 * n;
(gdb) next
30              S += temp;
(gdb) next
32              n++;
(gdb) next
33          } while (n <= k);
(gdb) next
27              long long temp = (long long)pow(x, n);
(gdb) print n
$1 = 2
(gdb) print k
$2 = 1000
(gdb) print temp
$3 = 50
(gdb) print S
$4 = 50
(gdb) next
28              temp /= 2 * n;
(gdb) print temp
$5 = 10000
(gdb) next next
No symbol "next" in current context.
(gdb) next
30              S += temp;
(gdb) next
32              n++;
(gdb) next
33          } while (n <= k);
(gdb) next
27              long long temp = (long long)pow(x, n);
(gdb) next
28              temp /= 2 * n;
(gdb) next
30              S += temp;
(gdb) next
32              n++;
(gdb) next
33          } while (n <= k);
(gdb) next
27              long long temp = (long long)pow(x, n);
(gdb) next
28              temp /= 2 * n;
(gdb) print S
$6 = 169216
(gdb) print temp
$7 = 100000000
(gdb) next
30              S += temp;
(gdb) next
32              n++;
(gdb) print n
$8 = 4
(gdb) print S
$9 = 12669216
(gdb) print temp
$10 = 12500000
```
 
---