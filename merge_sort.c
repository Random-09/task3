#include "merge_sort.h"


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


//void merge(Student_t *array, Student_t *left, Student_t *right, int left_size, int right_size) {
//    int i = 0, j = 0, k = 0;
//    while (i < left_size && j < right_size) {
//        if (left[i].average_grade <= right[j].average_grade) {
//            array[k] = left[i];
//            i++;
//        } else {
//            array[k] = right[j];
//            j++;
//        }
//        k++;
//    }
//    while (i < left_size) {
//        array[k] = left[i];
//        i++;
//        k++;
//    }
//    while (j < right_size) {
//        array[k] = right[j];
//        j++;
//        k++;
//    }
//}
//
//void merge_sort(Student_t *array, int number_of_students) {
//    if (number_of_students < 2) {
//        puts("Cant sort array");
//        printf("%d", number_of_students);
//        exit(EXIT_FAILURE);
//    }
//    int middle = number_of_students / 2;
//    Student_t left[middle];
//    Student_t right[number_of_students - middle];
//    for (int i = 0; i < middle; i++)
//        left[i] = array[i];
//    for (int i = middle; i < number_of_students; i++)
//        right[i - middle] = array[i];
//    merge_sort(left, middle);
//    merge_sort(right, number_of_students - middle);
//    merge(array, left, right, middle, number_of_students - middle);
//}