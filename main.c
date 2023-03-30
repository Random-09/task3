#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *name;
    char *student_id;
    float average_grade;
} Student_t;

enum choice {
    ADD_STUDENT = 1,
    DELETE_STUDENT,
    STUDENT_INFO,
    PRINT_AVERAGE_GRADES,
    EXIT
};

int id_uniqueness_check(int id, Student_t *p_database[50]) {
    for (int i = 0; i < 50; i++) {
        if (p_database[i]->id == id)
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

void add_student(Student_t *p_database[50], int current_index) {
    int id;
    char name[16], student_id[7];
    float average_grade;
    printf("Enter unique id of the student.");
    scanf("%d", &id);
    printf("Enter student's name");
    gets(name);
    printf("Enter student id");
    gets(student_id);
    printf("Enter average grade");
    scanf("%f", &average_grade);
    if (id_uniqueness_check(id, p_database)) {
        p_database[current_index]->id = id;
        p_database[current_index]->name = name;
        p_database[current_index]->student_id = student_id;
        p_database[current_index]->average_grade = average_grade;
    } else
        printf("ID is not unique");                        // <---- Test in a while loop
}

void delete_student(Student_t *p_database[50], int number_of_students) {
    printf("Enter unique ID of the student");
    int id;
    scanf("%d", &id);
    int index = id_index(id, p_database);
    if (index != -1) {
        for (int i = index; i < number_of_students - 1; i++) {
            p_database[i] = p_database[i + 1];
        }
    } else {
        printf("ID not found in this database");
        exit(EXIT_FAILURE);                                 // <---- Maybe continue while loop
    }
}

void student_info(Student_t *p_database[50]) {
    printf("Enter student's id");
    int id;
    scanf("%d", &id);
    int index = id_index(id, p_database);
    if (index != -1) {
        char *name = p_database[index]->name;
        char *student_id = p_database[index]->student_id;
        float average_grade = p_database[index]->average_grade;
        printf("Student with id: %d\nName: %s\nStudent id:%s\nAverage grade%f\n",
               id, name, student_id, average_grade);
    } else {
        printf("ID not found in this database");
        exit(EXIT_FAILURE);                                 // <---- Maybe continue while loop
    }
}

void print_average_grades() {

}


int main() {
    int exit_flag = 0;
    int number_of_students = 0;
    Student_t *database[50];
    while (!exit_flag) {
        printf("1. Add student\n2. Delete student\n3. Student info\n4. Print average grades\n5. Exit");
        char input;
        scanf("%c", &input);
        int choice = strtol(&input, NULL, 10);
        switch (choice) {
            case ADD_STUDENT:
                add_student(database, number_of_students);
                number_of_students++;
            case DELETE_STUDENT:
                delete_student(database, number_of_students);
                number_of_students--;
            case STUDENT_INFO:
                student_info(database);
            case PRINT_AVERAGE_GRADES:
                print_average_grades();
            case EXIT:
                exit_flag = 1;
            default:
                printf("Incorrect input");
        }
    }
}


// TODO
// Проверка на дурака везде, как в main



// Необходимо реализовать простую базу данных студентов.
// Пользователю выпадает меню с действиями над базой.
// Необходимо реализовать возможность добавления студента,
// просмотра данных о студенте, удаления студента,
// а также вывод рейтинга студентов по среднему баллу.
// В базе должны хранится характеристики: уникальный ID,
// Имя, Номер студенческого, Средний балл (float).
// Все действия над студентом выполнять на основе уникального ID.
// Вывод рейтинга студентов осуществляется по среднему баллу.
// Сортировку студентов по рейтингу реализовать с помощью алгоритма Merge Sort.
// Для хранения данных о студенте использовать структуру.
// Максимальное число студентов в базе - 50 шт. Использовать scanf можно.