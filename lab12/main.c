#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/func.h"

int main(void)
{
    char str[256];
    char delim[50];

    printf("Enter some text: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter deviders without space: ");
    fgets(delim, sizeof(delim), stdin);
    delim[strcspn(delim, "\n")] = '\0';

    char *token = my_strtok(str, delim);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = my_strtok(NULL, delim);
    }

    return EXIT_SUCCESS;
}