#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "merge_sort.h"

int main() {
    int exit_flag = 0;
    int number_of_students = 0;
    Student_t *database[50];
    while (!exit_flag) {
        printf("1. Add student\n2. Delete student\n3. Student info\n4. Print average grades\n5. Exit\n");
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
                merge_sort(database, number_of_students);
                print_average_grades(database, number_of_students);
            case EXIT:
                exit_flag = 1;
            default:
                printf("Incorrect input");
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