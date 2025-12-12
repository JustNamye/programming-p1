#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define IN_FILE_NAME "input.txt"
#define OUT_FILE_NAME "output.txt"

void replace_error_with_warning(char *line)
{
    const char *target = "error";
    const char *replacement = "warning";
    char buffer[2048];
    char *pos = line;
    buffer[0] = '\0';

    while (*pos)
    {
        int match = 1;
        for (int i = 0; target[i] != '\0'; i++)
        {
            if (tolower((unsigned char)pos[i]) != target[i])
            {
                match = 0;
                break;
            }
        }
        if (match)
        {
            strcat(buffer, replacement);
            pos += strlen(target);
        }
        else
        {
            size_t len = strlen(buffer);
            buffer[len] = *pos;
            buffer[len + 1] = '\0';
            pos++;
        }
    }
    strcpy(line, buffer);
}

void capitalize_sentences(char *line)
{
    int capitalize_next = 1;
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (capitalize_next && isalpha((unsigned char)line[i]))
        {
            line[i] = toupper((unsigned char)line[i]);
            capitalize_next = 0;
        }
        if (line[i] == '.' || line[i] == '!' || line[i] == '?')
        {
            capitalize_next = 1;
        }
    }
}