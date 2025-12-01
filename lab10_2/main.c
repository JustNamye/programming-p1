#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/exam.h"

int main(void)
{
    Exam exam;
    examInit(&exam);

    while (1)
    {
        puts("Choose an action:");
        puts("1 - create file");
        puts("2 - print");
        puts("3 - search");
        puts("4 - delete");
        puts("5 - append");
        puts("0 - exit");

        int action = getInt("Enter choice: ");

        if (action == 0)
        {
            break;
        }

        switch (action)
        {
        case 1:
            createFile(&exam);
            break;
        case 2:
            printAll(&exam);
            break;
        case 3:
            Subject *subject = search(&exam);

            if (subject == NULL)
            {
                puts("\nCouldnt find any matching record!\n");
                continue;
            }
            printf("\n(%02d.%02d.%04d) %s:\n",
                   subject->date.day,
                   subject->date.mounth,
                   subject->date.year,
                   subject->subjectName);
            for (int i = 0; i < subject->resultCount; i++)
            {
                Result r = subject->result[i];
                printf("%s - %d\n", r.studentName, r.grade);
            }
            puts("");
            break;
        case 4:
            deleteOld(&exam);
            break;
        case 5:
            append(&exam);
            break;
        default:
            puts("Wrong input!\n");
            break;
        }
    }

    puts("Exiting.");

    return EXIT_SUCCESS;
}