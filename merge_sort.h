#ifndef TASK3_MERGE_SORT_H
#define TASK3_MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "database.h"

void merge(Student_t *arr, Student_t *left, Student_t *right, int leftSize, int rightSize);

void merge_sort(Student_t *array, int number_of_students);

#endif
