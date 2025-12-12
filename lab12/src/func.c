#include <stdio.h>
#include <stdlib.h>

char *my_strtok(char *str, const char *delim)
{
    static char *next = NULL;

    if (str != NULL)
    {
        next = str;
    }
    if (next == NULL)
    {
        return NULL;
    }

    char *start = next;
    while (*start)
    {
        const char *d = delim;
        int is_delim = 0;
        while (*d)
        {
            if (*start == *d)
            {
                is_delim = 1;
                break;
            }
            d++;
        }
        if (!is_delim)
            break;
        start++;
    }

    if (*start == '\0')
    {
        next = NULL;
        return NULL;
    }

    char *end = start;
    while (*end)
    {
        const char *d = delim;
        int is_delim = 0;
        while (*d)
        {
            if (*end == *d)
            {
                is_delim = 1;
                break;
            }
            d++;
        }
        if (is_delim)
            break;
        end++;
    }

    if (*end)
    {
        *end = '\0';
        next = end + 1;
    }
    else
    {
        next = NULL;
    }

    return start;
}
