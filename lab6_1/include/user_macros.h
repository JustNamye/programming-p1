#ifndef USER_MACROS_H
#define USER_MACROS_H
#include <math.h>

#define HERON_AREA(out, a, b, c)                               \
    do                                                         \
    {                                                          \
        double _s = ((a) + (b) + (c)) / 2;                     \
        double _S = _s * (_s - (a)) * (_s - (b)) * (_s - (c)); \
        (out) = _S > 0 ? sqrt(_S) : 0;                         \
    } while (0)

#define IS_RIGHT(a, b, c)                                                                   \
    do                                                                                      \
    {                                                                                       \
        double _maxSide = fmax(a, fmax(b, c));                                                     \
        if (_maxSide * _maxSide == (a) * (a) + (b) * (b) + (c) * (c) - _maxSide * _maxSide) \
        {                                                                                   \
            puts("Triangle is right!");                                                     \
        }                                                                                   \
        else                                                                                \
        {                                                                                   \
            puts("Triangle is not right!");                                                 \
        }                                                                                   \
    } while (0);

#endif /* USER_MACROS_H */