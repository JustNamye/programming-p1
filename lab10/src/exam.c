// exam.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exam.h"

#define FILE_NAME "exam.txt"

static void loadExamFromFile(Exam *exam);

int getInt(const char *prompt)
{
    char line[128];
    int value;
    while (1)
    {
        printf("%s", prompt);
        if (!fgets(line, sizeof(line), stdin))
        {
            puts("Input error!");
            continue;
        }
        line[strcspn(line, "\n")] = '\0';
        if (sscanf(line, "%d", &value) == 1)
        {
            return value;
        }
        puts("Wrong input! Please enter a number.");
    }
}

void getString(const char *prompt, char *buf, int size)
{
    while (1)
    {
        printf("%s", prompt);
        if (!fgets(buf, size, stdin))
        {
            puts("Input error!");
            continue;
        }
        buf[strcspn(buf, "\n")] = '\0';
        if (buf[0] == '\0')
        {
            puts("Input cannot be empty, try again.");
            continue;
        }
        break;
    }
}

void examInit(Exam *exam)
{
    exam->subjectCount = 0;
}

static void loadExamFromFile(Exam *exam)
{
    FILE *f = fopen(FILE_NAME, "r");
    exam->subjectCount = 0;
    if (!f)
    {
        return;
    }

    char line[STRING_LEN];
    while (fgets(line, sizeof(line), f))
    {
        line[strcspn(line, "\n")] = '\0';
        if (line[0] == '\0')
            continue;

        Subject subj;
        memset(&subj, 0, sizeof(Subject));
        strncpy(subj.subjectName, line, STRING_LEN - 1);
        subj.subjectName[STRING_LEN - 1] = '\0';
        subj.resultCount = 0;

        int d = 0, m = 0, y = 0;
        if (fgets(line, sizeof(line), f) == NULL)
            break;
        if (sscanf(line, "%d %d %d", &d, &m, &y) != 3)
        {
            break;
        }
        subj.date.day = d;
        subj.date.mounth = m;
        subj.date.year = y;

        while (fgets(line, sizeof(line), f))
        {
            line[strcspn(line, "\n")] = '\0';
            if (strcmp(line, "END") == 0)
                break;

            char name[STRING_LEN];
            int grade;
            if (sscanf(line, "%49s %d", name, &grade) == 2)
            {
                if (subj.resultCount < STUDENTS_MAX)
                {
                    strncpy(subj.result[subj.resultCount].studentName, name, STRING_LEN - 1);
                    subj.result[subj.resultCount].studentName[STRING_LEN - 1] = '\0';
                    subj.result[subj.resultCount].grade = grade;
                    subj.resultCount++;
                }
            }
        }

        if (exam->subjectCount < SUBJECT_MAX)
        {
            exam->subject[exam->subjectCount] = subj;
            exam->subjectCount++;
        }
        else
        {
            break;
        }
    }

    fclose(f);
}

void createFile(Exam *exam)
{
    FILE *f = fopen(FILE_NAME, "w");
    if (!f)
    {
        puts("Cannot create file!");
        return;
    }

    for (int i = 0; i < exam->subjectCount; i++)
    {
        Subject *s = &exam->subject[i];
        fprintf(f, "%s\n", s->subjectName);
        fprintf(f, "%d %d %d\n", s->date.day, s->date.mounth, s->date.year);
        for (int j = 0; j < s->resultCount; j++)
        {
            Result *r = &s->result[j];
            fprintf(f, "%s %d\n", r->studentName, r->grade);
        }
        fprintf(f, "END\n");
    }

    fclose(f);
    puts("File created.\n");
}

Subject *byDate(Exam *exam, int day, int mounth, int year)
{
    for (int i = 0; i < exam->subjectCount; i++)
    {
        Subject *s = &exam->subject[i];
        if (s->date.day == day && s->date.mounth == mounth && s->date.year == year)
            return s;
    }
    return NULL;
}

Subject *byName(Exam *exam, const char *name)
{
    for (int i = 0; i < exam->subjectCount; i++)
    {
        Subject *s = &exam->subject[i];
        if (strcmp(s->subjectName, name) == 0)
            return s;
    }
    return NULL;
}

Subject *search(Exam *exam)
{
    loadExamFromFile(exam);

    puts("Search by:");
    puts("1 - subject");
    puts("2 - date");

    int answer = getInt("Enter choice: ");

    switch (answer)
    {
    case 1:
    {
        char name[STRING_LEN];
        getString("Enter subject name: ", name, STRING_LEN);
        return byName(exam, name);
    }
    case 2:
    {
        int day = getInt("Enter day: ");
        int mounth = getInt("Enter mounth: ");
        int year = getInt("Enter year: ");
        return byDate(exam, day, mounth, year);
    }
    default:
        puts("Wrong key!");
        return NULL;
    }
}

void printAll(Exam *exam)
{
    loadExamFromFile(exam);

    if (exam->subjectCount == 0)
    {
        puts("No records found. Create file or append records first.\n");
        return;
    }

    for (int i = 0; i < exam->subjectCount; i++)
    {
        Subject *s = &exam->subject[i];
        printf("\n(%02d.%02d.%04d) %s:\n", s->date.day, s->date.mounth, s->date.year, s->subjectName);
        for (int j = 0; j < s->resultCount; j++)
        {
            Result *r = &s->result[j];
            printf("  %s - %d\n", r->studentName, r->grade);
        }
    }
    puts("");
}

void deleteOld(Exam *exam)
{
    loadExamFromFile(exam);

    int yearLimit = getInt("Enter filter year: ");

    int writeIndex = 0;
    for (int readIndex = 0; readIndex < exam->subjectCount; readIndex++)
    {
        if (exam->subject[readIndex].date.year >= yearLimit)
        {
            if (writeIndex != readIndex)
                exam->subject[writeIndex] = exam->subject[readIndex];
            writeIndex++;
        }
    }
    exam->subjectCount = writeIndex;

    createFile(exam);
    puts("Old records deleted.\n");
}


void addSubject(Exam *exam, Subject subject)
{
    subject.subjectName[STRING_LEN - 1] = '\0';

    for (int i = 0; i < exam->subjectCount; i++)
    {
        if (strcmp(exam->subject[i].subjectName, subject.subjectName) == 0)
            return;
    }

    if (exam->subjectCount < SUBJECT_MAX)
    {
        exam->subject[exam->subjectCount] = subject;
        exam->subject[exam->subjectCount].resultCount = subject.resultCount;
        exam->subjectCount++;
    }
}

int hasSubject(Exam *exam, Subject subject)
{
    subject.subjectName[STRING_LEN - 1] = '\0';
    for (int i = 0; i < exam->subjectCount; i++)
    {
        if (strcmp(exam->subject[i].subjectName, subject.subjectName) == 0)
            return 1;
    }
    return 0;
}

void addResult(Subject *subject, Result result)
{
    result.studentName[STRING_LEN - 1] = '\0';
    for (int i = 0; i < subject->resultCount; i++)
    {
        if (strcmp(subject->result[i].studentName, result.studentName) == 0)
        {
            subject->result[i].grade = result.grade;
            return;
        }
    }
    if (subject->resultCount < STUDENTS_MAX)
    {
        subject->result[subject->resultCount] = result;
        subject->resultCount++;
    }
}

Subject *getSubject(Exam *exam, Subject subject)
{
    subject.subjectName[STRING_LEN - 1] = '\0';
    for (int i = 0; i < exam->subjectCount; i++)
    {
        if (strcmp(exam->subject[i].subjectName, subject.subjectName) == 0)
            return &exam->subject[i];
    }
    return NULL;
}

void append(Exam *exam)
{
    loadExamFromFile(exam);

    char subjectName[STRING_LEN];
    getString("Enter subject name: ", subjectName, STRING_LEN);

    Subject subject;
    memset(&subject, 0, sizeof(subject));
    strncpy(subject.subjectName, subjectName, STRING_LEN - 1);
    subject.subjectName[STRING_LEN - 1] = '\0';
    subject.resultCount = 0;

    Subject *existing = getSubject(exam, subject);
    if (!existing)
    {
        subject.date.day = getInt("Enter day: ");
        subject.date.mounth = getInt("Enter mounth: ");
        subject.date.year = getInt("Enter year: ");
        addSubject(exam, subject);
        existing = getSubject(exam, subject);
    }

    while (1)
    {
        char studentName[STRING_LEN];
        getString("Enter students name (0 to stop): ", studentName, STRING_LEN);
        if (strcmp(studentName, "0") == 0)
            break;
        int grade = getInt("Enter grade: ");

        Result res;
        memset(&res, 0, sizeof(res));
        strncpy(res.studentName, studentName, STRING_LEN - 1);
        res.studentName[STRING_LEN - 1] = '\0';
        res.grade = grade;

        addResult(existing, res);
    }

    createFile(exam);
    puts("Record appended.\n");
}
