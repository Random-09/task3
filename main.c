#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "database.h"
#include "merge_sort.h"

int main() {
    int running = true;
    int number_of_students = 0;
    Student_t *database;
    database = (Student_t *) malloc(50 * (sizeof(Student_t)));
    char input;
    int choice;
    while (running) {
        printf("1. Add student\n2. Delete student\n3. Student info\n4. Print average grades\n5. Exit\n");
        printf("^%d^\n", database[0].id);
        scanf("%s", &input);
        choice = strtol(&input, NULL, 10);
        switch (choice) {
            case ADD_STUDENT:
                add_student(database, number_of_students);
                printf("^%d^\n", database[0].id);
                number_of_students++;
                break;
            case DELETE_STUDENT:
                delete_student(database, number_of_students);
                number_of_students--;
                break;
            case STUDENT_INFO:
                for (int i = 0; i < 50; i++) {
                    printf("%s\n", database[i].student_id);
                }
                student_info(database);
                printf("^^^^%d^^^^\n", database[0].id);
                break;
            case PRINT_AVERAGE_GRADES:
                merge_sort(database, number_of_students);
                print_average_grades(database, number_of_students);
                break;
            case EXIT:
                running = false;
                break;
            default:
                puts("Incorrect input");
                break;
        }
    }
}


// TODO
// Разобраться с поинтерами
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