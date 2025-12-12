#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/func.h"

int main(void)
{
    FILE *input_file = fopen(IN_FILE_NAME, "r");
    if (!input_file)
    {
        perror("Cannot open input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(OUT_FILE_NAME, "w");
    if (!output_file)
    {
        perror("Cannot open output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    char line[1024];

    while (fgets(line, sizeof(line), input_file))
    {
        replace_error_with_warning(line);
        capitalize_sentences(line);
        fputs(line, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File processing complete. Output saved to %s\n", OUT_FILE_NAME);

    return EXIT_SUCCESS;
}