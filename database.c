#include "database.h"

int id_uniqueness_check(int id, Student_t *p_database, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        printf("%d", i);
        if (p_database[i].id == id)
            return 0;
    }
    return 1;
}

int id_index(int id, Student_t *p_database[50]) {
    for (int i = 0; i < 50; i++) {
        if (p_database[i]->id == id)
            return i;
    }
    return -1;
}

void add_student(Student_t *p_database, int number_of_students) {
    int id;
    char name[16], student_id[7];
    float average_grade;
    puts("Enter unique id of the student");
    scanf("%d", &id);
    puts("Enter student's name");
    scanf("%s", name);
    puts("Enter student id");
    scanf("%s", student_id);
    puts("Enter average grade");
    scanf("%f", &average_grade);
    if (id_uniqueness_check(id, p_database, number_of_students)) {
        p_database[number_of_students].id = id;
        p_database[number_of_students].name = name;
        p_database[number_of_students].student_id = student_id;
        p_database[number_of_students].average_grade = average_grade;
    } else
        puts("ID is not unique");                        // <---- Test in a while loop
}

void delete_student(Student_t *p_database[50], int number_of_students) {
    puts("Enter unique ID of the student");
    int id;
    scanf("%d", &id);
    int index = id_index(id, p_database);
    if (index != -1) {
        for (int i = index; i < number_of_students - 1; i++) {
            p_database[i] = p_database[i + 1];
        }
    } else {
        puts("ID not found in this database");
        exit(EXIT_FAILURE);                                 // <---- Maybe continue while loop
    }
}

void student_info(Student_t *p_database[50]) {
    int id;
    scanf("Enter student's id\n%d", &id);
    int index = id_index(id, p_database);
    if (index != -1) {                                          // <---- Change to just if (index == -1)
        char *name = p_database[index]->name;
        char *student_id = p_database[index]->student_id;
        float average_grade = p_database[index]->average_grade;
        printf("Student with id: %d\nName: %s\nStudent id:%s\nAverage grade%f\n",
               id, name, student_id, average_grade);
    } else {
        puts("ID not found in this database");
        exit(EXIT_FAILURE);                                 // <---- Maybe continue while loop
    }
}

void print_average_grades(Student_t *p_database[50], int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        char *name = p_database[i]->name;
        float average_grade = p_database[i]->average_grade;
        printf("%s: %f", name, average_grade);
    }
}