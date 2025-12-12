#ifndef EXAM_H_
#define EXAM_H_

#define STRING_LEN 50
#define SUBJECT_MAX 20
#define STUDENTS_MAX 100
#define BIN_FILE "exam.bin"

typedef struct
{
    char studentName[STRING_LEN];
    int grade;
} Result;

typedef struct
{
    int day;
    int mounth;
    int year;
} Date;

typedef struct
{
    char subjectName[STRING_LEN];
    Result result[STUDENTS_MAX];
    Date date;
    int resultCount;
} Subject;

typedef struct
{
    Subject subject[SUBJECT_MAX];
    int subjectCount;
} Exam;

int getInt(const char *prompt);
void examInit(Exam *exam);
void createFile(Exam *exam);
void printAll(Exam *exam);
void deleteOld(Exam *exam);
void append(Exam *exam);
Subject *search(Exam *exam);

#endif
