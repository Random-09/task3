#include "merge_sort.h"

void merge(Student_t *array, Student_t *left, Student_t *right, int left_size, int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i].average_grade <= right[j].average_grade) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }
    while (j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(Student_t *array, int number_of_students) {
    if (number_of_students < 2) {
        puts("Cant sort array");
        exit(EXIT_FAILURE);
    }
    int middle = number_of_students / 2;
    Student_t left[middle];
    Student_t right[number_of_students - middle];
    for (int i = 0; i < middle; i++)
        left[i] = array[i];
    for (int i = middle; i < number_of_students; i++)
        right[i - middle] = array[i];
    merge_sort(left, middle);
    merge_sort(right, number_of_students - middle);
    merge(array, left, right, middle, number_of_students - middle);
}