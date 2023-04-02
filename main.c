#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "database.h"
#include "merge_sort.h"

int main() {
    int running = true;
    int number_of_students = 0;
    Student_t *database;
    database = (Student_t *) malloc(DB_CAPACITY * (sizeof(Student_t)));
    char input;
    int choice;
    while (running) {
        if (number_of_students == DB_CAPACITY)                  // <---- check for full capacity!
            printf("Database is full!");
        printf("1. Add student\n2. Delete student\n3. Student info\n4. Print average grades\n5. Exit\n");
        scanf("%s", &input);
        choice = strtol(&input, NULL, 10);
        switch (choice) {
            case ADD_STUDENT:
                add_student(database, number_of_students);
                number_of_students++;
                break;
            case DELETE_STUDENT:
                delete_student(database);
                number_of_students--;
                break;
            case STUDENT_INFO:
                student_info(database);
                break;
            case PRINT_AVERAGE_GRADES:
                merge_sort(database, 0, number_of_students - 1);
                print_average_grades(database, number_of_students);
                break;
            case EXIT:
                running = false;
                break;
            default:
                puts("Incorrect input!");
                break;
        }
    }
    free(database);
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