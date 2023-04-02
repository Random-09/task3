#include "database.h"

int id_uniqueness_check(int id, Student_t *p_database, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        if (p_database[i].id == id)
            return 0;
    }
    return 1;
}

int id_index(int id, Student_t *p_database) {
    for (int i = 0; i < 50; i++) {
        if (p_database[i].id == id)
            return i;
    }
    return -1;
}

void add_student(Student_t *p_database, int number_of_students) {
    int id;
    char *name;
    char *student_card_number;
    name = (char *) malloc(10 * sizeof(char ));
    student_card_number = (char *) malloc(10 * sizeof(char ));
    float average_grade;
    puts("Enter unique id of the student");
    scanf("%d", &id);
    puts("Enter student's name");
    scanf("%s", name);
    puts("Enter student id");
    scanf("%s", student_card_number);
    puts("Enter average grade");
    scanf("%f", &average_grade);
    if (id_uniqueness_check(id, p_database, number_of_students)) {
        Student_t student = {id, name, student_card_number, average_grade};
        p_database[number_of_students] = student;
    } else
        puts("ID is not unique!\n");
}

void delete_student(Student_t *p_database) {
    puts("Enter unique ID of the student");
    int id;
    scanf("%d", &id);
    int index = id_index(id, p_database);
    free(p_database[index].name);
    free(p_database[index].student_card_number);
    if (index != -1) {
        for (int i = index; i < DB_CAPACITY - 1; i++) {
            p_database[i] = p_database[i + 1];
        }
    } else {
        puts("ID not found in this database!");
    }
}

void student_info(Student_t *p_database) {
    int id;
    puts("Enter student's ID");
    scanf("%d", &id);
    int index = id_index(id, p_database);
    if (index != -1) {
        char *name = p_database[index].name;
        char *student_card_number = p_database[index].student_card_number;
        float average_grade = p_database[index].average_grade;
        printf("Student with id: %d\nName: %s\nStudent id: %s\nAverage grade %f\n",
               id, name, student_card_number, average_grade);
    } else {
        printf("%d", index);
        puts("ID not found in this database!\n");
    }
}

void print_average_grades(Student_t *p_database, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        char *name = p_database[i].name;
        float average_grade = p_database[i].average_grade;
        printf("%s: %.1f\n", name, average_grade);
    }
}