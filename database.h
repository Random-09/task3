#ifndef TASK3_DATABASE_H
#define TASK3_DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define DB_CAPACITY 50
#define DATA_LEN 10

typedef struct {
    int id;
    char *name;
    char *student_card_number;
    float average_grade;
} Student_t;

enum choice {
    ADD_STUDENT = 1,
    DELETE_STUDENT,
    STUDENT_INFO,
    PRINT_AVERAGE_GRADES,
    EXIT
};

int id_uniqueness_check(int id, Student_t *p_database, int number_of_students);

int id_index(int id, Student_t *p_database);

void add_student(Student_t *p_database, int *number_of_students);

void delete_student(Student_t *p_database, int *number_of_students);

void student_info(Student_t *p_database);

void print_average_grades(Student_t *p_database, const int *number_of_students);


#endif
