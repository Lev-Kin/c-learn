/*
// Задание 1:
// Описать структуру Student
//  - фамилия;
//  - группа;
//  - успеваемость (массив из 5 int)).
//  Создать массив студентов и написать программу, позволяющую:
// - динамически изменять размер массива;
// - выводить список отличников (>75% отличных оценок);
// - выводить список двоечников (>50% оценок 2 и 3).

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>   // getch()
#include <stdbool.h> // true и false
#include <stdlib.h>  // rand() и srand()
#include <time.h>    // time()

#define A 11   // количесво оценок (amount) - для задания поставить значения 5 !!!
#define W 42   // ширина строки    (width)  - ширина таблицы для фамилии (11ch)
#define N 3    // количество всех студентов (default)
#define LIM 10 // корректировка списка оценок по студентам

#if A > 11
#define A 11
#endif

#if W < 42
#define W 42
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void);

///////////////////////// функции вывода таблиц по категориям ////////////////////////////////////////////

void printAllStudent(struct StudyAll *, int);
void printStudentPosNegMid(struct StudyAll *, struct StudyGood *, struct StudyMid *, struct StudyBad *, int);

//////////////////////////////// функции вспомогательные  ///////////////////////////////////////////////

void dash(int);
void dot(int);
void dotdot(int);
void equal(int);
void tabs(int);
void apostrophe(int);
void underscore(int);
void eatline(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////

struct StudyAll // структура всех студентов
{
    int group;        // группа
    char surname[W];  // массив фамилий студентов
    int mark[LIM][A]; // массив оценок студентов
};
struct StudyGood // структура хорошистов
{
    int group;
    char surname[W];
    int mark[LIM][A];
};
struct StudyMid // структура среднячков
{
    int group;
    char surname[W];
    int mark[LIM][A];
};
struct StudyBad // структура двоечников
{
    int group;
    char surname[W];
    int mark[LIM][A];
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char repeat;
    char input;
    int work_or_test = 0;

    system("cls");
    equal(80);
    printf("\n");
    tabs(9);
    printf("\n");
    apostrophe(80);
    printf("\n");
    printf("\t     ***| Задание 1 (Модуль 10 Структуры и объединения) |***\n\n");
    printf("\tСделайте выбор:\n");
    printf("\t1:ПУСК программы.\n"); // работа в программе согласно условия
    printf("\t2:ТЕСТ программы.\n"); // тест программы вывод на экран всех условий
    printf("\t3: __| ВЫХОД |__\n");
    do
    {
        printf("     |  \n     '->");
        scanf_s("%d", &work_or_test);
        eatline();

        if (work_or_test != 1 && work_or_test != 2 && work_or_test != 3)
        {
            printf("\n\tНекорректный ввод (Выбор = 3 -выход).");
            printf("\n\tПожалуйста сделайте выбор.\n");
        }

    } while (work_or_test != 1 && work_or_test != 2 && work_or_test != 3);

    // ============================== пуск программы ====================================================

    if (work_or_test == 1)
    {
        do
        {
            system("cls");
            equal(80);
            printf("\n");
            tabs(9);
            printf("\n");
            apostrophe(80);
            printf("\n");
            printf("\t     ***| Задание 1 (Модуль 10 Структуры и объединения) |***\n");

            char surname[W] = {'\0'};

            int checkrec = 0; // проверка на добавление памяти
            int records = 0;  // запись переопределение (количество студентов)

            bool memory1 = false; // проверка памяти стандарт   (по умолчанию)
            bool memory2 = false; // проверка памяти превышение (перераспределение)

            StudyAll *students = nullptr;
            StudyGood *studentG = nullptr;
            StudyMid *studentM = nullptr;
            StudyBad *studentB = nullptr;

            StudyAll *tmp1 = nullptr;
            StudyGood *tmp2 = nullptr;
            StudyMid *tmp3 = nullptr;
            StudyBad *tmp4 = nullptr;

            students = (StudyAll *)malloc((N + 1) * sizeof(StudyAll));
            studentG = (StudyGood *)malloc((N + 1) * sizeof(StudyGood));
            studentM = (StudyMid *)malloc((N + 1) * sizeof(StudyMid));
            studentB = (StudyBad *)malloc((N + 1) * sizeof(StudyBad));
            do
            {
                if (N < checkrec)
                    memory1 = false; // переключатели

                if ((checkrec == LIM) && (memory1))
                {
                    printf("\n\n\tПревышен лимит студентов для формирования корректных списков.\n");
                    printf("\tДанные отправлены на обработку.\n");
                    memory1 = true;
                    break;
                }

                if (students && studentG && studentM && studentB)
                {
                    if (N > checkrec)
                        memory1 = true; // переключатели

                    if (memory1)
                    {
                        printf("\n");
                        dot(26);
                        printf("\n");

                        // защита ввода фамилии (вернуть если длиная фамилия >11ch) или без фамилии)
                        do
                        {
                            printf("\n\tВведите фамилию %d-го студента: ", records + 1);
                            gets_s((students + records)->surname, 41);

                        } while (students[records].surname[0] == '\0' ||
                                 (int)strlen((students + records)->surname) > 11);

                        // защита ввода группа
                        do
                        {
                            while (1)
                            {
                                char ch = 0;
                                printf("\n\tВведите группу студента: ");

                                if (!scanf_s("%d", &(students + records)->group) || getchar() != '\n')
                                {
                                    while ((ch = getchar()) != '\n' && ch != EOF)
                                        ;
                                }
                                else
                                    break;
                            }

                        } while ((students + records)->group > 9 || (students + records)->group <= 0);

                        // защита оценок ввод только от 1 до 5
                        printf("\n\tВведите оценки студента: \n");
                        for (int j = 0; j < A; j++)
                        {
                            do
                            {
                                while (1)
                                {
                                    char ch = 0;
                                    printf("\tВведите %d-yю оценку: ", j + 1);

                                    if (!scanf_s("%d", &(students + records)->mark[records][j]) || getchar() != '\n')
                                    {
                                        while ((ch = getchar()) != '\n' && ch != EOF)
                                            ;
                                    }
                                    else
                                        break;
                                }

                            } while ((students + records)->mark[records][j] > 5 ||
                                     (students + records)->mark[records][j] <= 0);
                        }

                        records++;
                        checkrec = records; // регистрируем перевыделение
                    }

                    // идем по расширению
                    if (memory1 == false)
                    {
                        // перевыделение памяти если больше значения (default)
                        tmp1 = (StudyAll *)realloc(students, (checkrec + 1) * sizeof(StudyAll));
                        tmp2 = (StudyGood *)realloc(studentG, (checkrec + 1) * sizeof(StudyGood));
                        tmp3 = (StudyMid *)realloc(studentM, (checkrec + 1) * sizeof(StudyMid));
                        tmp4 = (StudyBad *)realloc(studentB, (checkrec + 1) * sizeof(StudyBad));

                        if (tmp1 && tmp2 && tmp3 && tmp4)
                        {
                            students = tmp1;
                            studentG = tmp2;
                            studentM = tmp3;
                            studentB = tmp4;

                            if (checkrec == LIM)
                            {
                                printf("\n\n\tПревышен лимит студентов для формирования корректных списков.\n");
                                printf("\tДанные отправлены на обработку.\n");
                                memory2 = true;
                                break;
                            }

                            records = checkrec; // регистрируем перевыделение
                            memory2 = true;
                        }
                        else
                        {
                            printf("\tНет возможности выделить память под %d элементов массивов структур\n", checkrec);
                            memory2 = false;

                            // если не будет памяти на перевыделение новой, очистим и дефолтную
                            free(students);
                            free(studentG);
                            free(studentM);
                            free(studentB);
                        }

                        if (memory2)
                        {
                            printf("\n");
                            dot(26);
                            printf("\n");

                            // защита ввода фамилии (вернуть если длиная фамилия или без фамилии)
                            do
                            {
                                printf("\n\tВведите фамилию %d-го студента: ", records + 1);
                                gets_s((students + records)->surname, 41);

                            } while (students[records].surname[0] == '\0' ||
                                     (int)strlen((students + records)->surname) > 11);

                            // защита ввода группа
                            do
                            {
                                while (1)
                                {
                                    char ch = 0;
                                    printf("\n\tВведите группу студента: ");

                                    if (!scanf_s("%d", &(students + records)->group) || getchar() != '\n')
                                    {
                                        while ((ch = getchar()) != '\n' && ch != EOF)
                                            ;
                                    }
                                    else
                                        break;
                                }

                            } while ((students + records)->group > 9 ||
                                     (students + records)->group <= 0);

                            // защита оценок ввод только от 1 до 5
                            printf("\n\tВведите оценки студента: \n");
                            for (int j = 0; j < A; j++)
                            {
                                do
                                {
                                    while (1)
                                    {
                                        char ch = 0;
                                        printf("\tВведите %d-yю оценку: ", j + 1);

                                        if (!scanf_s("%d", &(students + records)->mark[records][j]) || getchar() != '\n')
                                        {
                                            while ((ch = getchar()) != '\n' && ch != EOF)
                                                ;
                                        }
                                        else
                                            break;
                                    }

                                } while ((students + records)->mark[records][j] > 5 ||
                                         (students + records)->mark[records][j] <= 0);
                            }

                            records++;
                            checkrec = records; // регистрируем перевыделение
                        }
                    }
                    else // идем по дефолту
                    {
                        memory1 = true;
                    }
                }
                else
                {
                    printf("\tНет возможности выделить память под %d элементов массивов структур\n", N);
                    memory1 = false;
                }

                printf("\t");
                dotdot(35);
                printf("\n\tY - Продолжить ввод данных.");
                printf("\n     |  Q - Отмена (обработать данные).\n     '->");
                input = getche();
            } while (input == 'y' || input == 'Y');

            printf("\n");
            dash(80);
            printf("\n\n");

            printAllStudent(students, records);

            dot(26);
            printf("\n\n\n");

            printStudentPosNegMid(students, studentG, studentM, studentB, records);

            if (memory1)
            {
                // освобождаем память дефолта
                free(students);
                free(studentG);
                free(studentM);
                free(studentB);

                memory1 = false;
            }

            if (memory2)
            {
                // освобождаем память перевыделения
                free(tmp1);
                free(tmp2);
                free(tmp3);
                free(tmp4);

                tmp1 = nullptr;
                tmp2 = nullptr;
                tmp3 = nullptr;
                tmp4 = nullptr;

                memory2 = false;
            }

            students = nullptr;
            studentG = nullptr;
            studentM = nullptr;
            studentB = nullptr;

            dash(80);
            printf("\n\tY - Переделать таблицы.");
            printf("\n     |  Q - ВыхоД из программы.\n     '->");
            repeat = getche();
        } while (repeat == 'y' || repeat == 'Y');
    }

    // ============================== тест программы ====================================================

    if (work_or_test == 2)
    {
        do
        {
            system("cls");
            equal(80);
            printf("\n");
            tabs(9);
            printf("\n");
            apostrophe(80);
            printf("\n");
            printf("\t     ***| Задание 1 (Модуль 10 Структуры и объединения) |***\n\n");
            printf("_______________________________| ТЕСТ  программы |______________________________\n\n\n");

            srand((unsigned int)time(nullptr));

            char surname[][W] = {{"Смирнов"}, {"Иванов"}, {"Васильев"}, {"Волкова"}, {"Соколова"}, {"Лебедева"}};

            int checkrec = 0; // проверка на добавление памяти
            int records = 0;  // запись переопределение (количество студентов)

            bool memory1 = false; // проверка памяти стандарт   (по умолчанию)
            bool memory2 = false; // проверка памяти превышение (перераспределение)

            StudyAll *students = nullptr;
            StudyGood *studentG = nullptr;
            StudyMid *studentM = nullptr;
            StudyBad *studentB = nullptr;

            students = (StudyAll *)malloc(N * sizeof(StudyAll));
            studentG = (StudyGood *)malloc(N * sizeof(StudyGood));
            studentM = (StudyMid *)malloc(N * sizeof(StudyMid));
            studentB = (StudyBad *)malloc(N * sizeof(StudyBad));

            if (students && studentG && studentM && studentB)
            {
                checkrec = sizeof(surname) / sizeof(*surname);

                // идем по расширению
                if (N < checkrec)
                {
                    StudyAll *tmp1 = nullptr;
                    StudyGood *tmp2 = nullptr;
                    StudyMid *tmp3 = nullptr;
                    StudyBad *tmp4 = nullptr;

                    // перевыделение памяти если больше значения (default)
                    tmp1 = (StudyAll *)realloc(students, checkrec * sizeof(StudyAll));
                    tmp2 = (StudyGood *)realloc(studentG, checkrec * sizeof(StudyGood));
                    tmp3 = (StudyMid *)realloc(studentM, checkrec * sizeof(StudyMid));
                    tmp4 = (StudyBad *)realloc(studentB, checkrec * sizeof(StudyBad));

                    if (checkrec > LIM)
                    {
                        printf("\n\tПревышен лимит студентов для формирования корректных списков.\n");

                        // освобождаем память перевыделения LIM
                        free(tmp1);
                        free(tmp2);
                        free(tmp3);
                        free(tmp4);

                        tmp1 = nullptr;
                        tmp2 = nullptr;
                        tmp3 = nullptr;
                        tmp4 = nullptr;

                        memory2 = false;
                    }
                    else
                    {
                        if (tmp1 && tmp2 && tmp3 && tmp4)
                        {
                            students = tmp1;
                            studentG = tmp2;
                            studentM = tmp3;
                            studentB = tmp4;

                            records = checkrec; // регистрируем перевыделение

                            memory2 = true;
                        }
                        else
                        {
                            printf("\tНет возможности выделить память под %d элементов массивов структур\n", checkrec);
                            memory2 = false;

                            // если не будет памяти на перевыделение новой, очистим и дефолтную
                            free(students);
                            free(studentG);
                            free(studentM);
                            free(studentB);
                        }

                        if (memory2)
                        {
                            // инсталляция фамилии в структуру поля фамилии
                            for (int i = 0; i < records; i++)
                            {
                                strcpy((students + i)->surname, surname[i]);
                            }

                            // инсталляция группы в структуру поля группы
                            for (int i = 0; i < records; i++)
                            {
                                (students + i)->group = (rand() % 3) + 1;
                            }

                            // инсталляция оценок в структуру поля оценки
                            for (int i = 0; i < records; i++)
                            {
                                for (int j = 0; j < A; j++)
                                {
                                    (students + i)->mark[i][j] = (rand() % 5) + 1;
                                }
                            }

                            printAllStudent(students, records);

                            dot(26);
                            printf("\n\n\n");

                            printStudentPosNegMid(students, studentG, studentM, studentB, records);
                        }

                        if (memory2)
                        {
                            // освобождаем память перевыделения
                            free(tmp1);
                            free(tmp2);
                            free(tmp3);
                            free(tmp4);

                            tmp1 = nullptr;
                            tmp2 = nullptr;
                            tmp3 = nullptr;
                            tmp4 = nullptr;

                            memory2 = false;
                        }
                    }
                }
                else // идем по дефолту
                {
                    memory1 = true;
                    records = N;
                }

                if (memory1)
                {
                    for (int i = 0; i < records; i++)
                    {
                        strcpy((students + i)->surname, surname[i]);
                    }

                    for (int i = 0; i < records; i++)
                    {
                        (students + i)->group = (rand() % 3) + 1;
                    }

                    for (int i = 0; i < records; i++)
                    {
                        for (int t = 0; t < A; t++)
                        {
                            (students + i)->mark[i][t] = (rand() % 5) + 1;
                        }
                    }

                    printAllStudent(students, records);

                    dot(26);
                    printf("\n\n\n");

                    printStudentPosNegMid(students, studentG, studentM, studentB, records);
                }
            }
            else
            {
                printf("\tНет возможности выделить память под %d элементов массивов структур\n", N);
                memory1 = false;
            }

            if (memory1)
            {
                // освобождаем память дефолта
                free(students);
                free(studentG);
                free(studentM);
                free(studentB);

                memory1 = false;
            }

            students = nullptr;
            studentG = nullptr;
            studentM = nullptr;
            studentB = nullptr;

            dash(80);
            printf("\n\tY - Повторить ТЕСТ.");
            printf("\n     |  Q - ВыхоД из ТЕСТА.\n     '->");
            repeat = getche();
        } while (repeat == 'y' || repeat == 'Y');
    }

    printf("\n\t\t\t    ..........................");
    printf("\n\t\t\t    |     Всего хорошего     |");
    printf("\n\t\t\t    |         (^-^)/         |");
    printf("\n\t\t\t    ''''''''''''''''''''''''''\n");

    printf("\n");
    dotdot(80);
    printf("\n");
    tabs(9);
    printf("\n");
    equal(80);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

//============================= функции вывода таблиц по категориям =========================================
//
// вывод на экран таблицы всех студентов и их данные
void printAllStudent(StudyAll *students, int records)
{
    printf("\tТаблица - Всех учащихся студентов\n");
    printf("\t.__________________________________________________________________.\n");
    printf("\t| № |   Фамилия   | Гр |                  Оценки                   |\n");
    printf("\t|---|-------------|----|-------------------------------------------|\n");

    for (int i = 0; i < records; i++)
    {
        printf("\t| %d | %11s |  %d |", i + 1, (students + i)->surname, (students + i)->group);

        for (int j = 0; j < A; j++)
        {
            printf(" %d |", (students + i)->mark[i][j]);
        }

        if (i != records - 1)
            printf("\n");
    }

    printf("\n");
    printf("\t|___|_____________|____|___________________________________________|\n\n\n");
}

// вывод на экран таблиц студентов по категориям и их данные
void printStudentPosNegMid(StudyAll *students, struct StudyGood *studentG, struct StudyMid *studentM, struct StudyBad *studentB, int records)
{
    double q = 100 / (double)A; // коэффициент на одну оценку процентов

    double check_pst; // проверка положительных
    double check_neg; // проверка отрицательных

    int positive; // накопление положительных оценок
    int negative; // накопление отрицательных оценок

    // accuracy
    // переменные для точности положительных оценок (процентов)
    double acypst_tmp1, acypst_fin1;
    int transfer1 = 1;
    int acypst_tmp2, pstn_end;

    // переменные для точности отрицательных оценок (процентов)
    double acyneg_tmp1, acyneg_fin1;
    int transfer2 = 1;
    int acyneg_tmp2, negn_end;

    int st_good = 0; // кол-во хороших студентов
    int st_mid = 0;  // кол-во средних студентов
    int st_bad = 0;  // кол-во  плохих студентов

    printf("\tТаблица - Успеваемости всех учащихся студентов\n");
    printf("\t.__________________________________________________________________.\n");
    printf("\t|   |             |    |       Количество оценок       |           |\n");
    printf("\t| № |   Фамилия   | Гр | Положительных | Отрицательных |     %%     |\n");
    printf("\t|---|-------------|----|-------------------------------------------|\n");

    for (int i = 0; i < records; i++)
    {
        positive = 0;
        negative = 0;
        check_pst = 0;
        check_neg = 0;

        for (int j = 0; j < A; j++)
        {
            // планка отрицательных и положительных оценок
            if ((students + i)->mark[i][j] > 3)
                positive++;
            else
                negative++;
        }

        check_pst = q * (double)positive;
        check_neg = q * (double)negative;

        ////////////////////////////////////////////////////////////////////////////////////
        // приведем к точности проценты положительных и отрицательных оценок
        // проценты положительных оценок
        acypst_tmp2 = check_pst * transfer1 * 10; // берем число на порядок больше
        pstn_end = acypst_tmp2 % 10;              // определяем последнюю цифру
        acypst_tmp1 = acypst_tmp2 / 10;           // приводим число к указанной точности
        acypst_tmp1 = int(acypst_tmp1);           // отбрасываем ненужные цифры

        if (pstn_end >= 5)
            acypst_tmp1++;                     // проверяем по правилам округления
        acypst_fin1 = acypst_tmp1 / transfer1; // возвращаем на место запятую
        check_pst = acypst_fin1;

        // проценты  отрицательных оценок
        acyneg_tmp2 = check_neg * transfer2 * 10;
        negn_end = acyneg_tmp2 % 10;
        acyneg_tmp1 = acyneg_tmp2 / 10;
        acyneg_tmp1 = int(acyneg_tmp1);

        if (negn_end >= 5)
            acyneg_tmp1++;
        acyneg_fin1 = acyneg_tmp1 / transfer2;
        check_neg = acyneg_fin1;
        //////////////////////////////////////////////////////////////////////////////////////

        // Сортируем студентов отличников, средняков, двоечников
        if ((int)check_pst > 75)
        {
            printf("\t| %d | %11s |  %d |     %3d       |     %3d       | %3d /%3d  |",
                   (i + 1), (students + i)->surname, (students + i)->group,
                   positive, negative, (int)check_pst, (int)check_neg);

            strcpy((studentG + st_good)->surname, (students + i)->surname);
            (studentG + st_good)->group = (students + i)->group;

            for (int j = 0; j < A; j++)
            {
                (studentG + st_good)->mark[st_good][j] = (students + i)->mark[i][j];
            }
            st_good++;

            if (i != records - 1)
                printf("\n");
        }
        else if ((int)check_neg > 50)
        {
            printf("\t| %d | %11s |  %d |     %3d       |     %3d       | %3d /%3d  |",
                   (i + 1), (students + i)->surname, (students + i)->group,
                   positive, negative, (int)check_pst, (int)check_neg);

            strcpy((studentB + st_bad)->surname, (students + i)->surname);
            (studentB + st_bad)->group = (students + i)->group;

            for (int j = 0; j < A; j++)
            {
                (studentB + st_bad)->mark[st_bad][j] = (students + i)->mark[i][j];
            }
            st_bad++;

            if (i != records - 1)
                printf("\n");
        }
        else
        {
            printf("\t| %d | %11s |  %d |     %3d       |     %3d       | %3d /%3d  |",
                   (i + 1), (students + i)->surname, (students + i)->group,
                   positive, negative, (int)check_pst, (int)check_neg);

            strcpy((studentM + st_mid)->surname, (students + i)->surname);
            (studentM + st_mid)->group = (students + i)->group;

            for (int j = 0; j < A; j++)
            {
                (studentM + st_mid)->mark[st_mid][j] = (students + i)->mark[i][j];
            }
            st_mid++;

            if (i != records - 1)
                printf("\n");
        }
    }
    printf("\n");
    printf("\t|___|_____________|____|_______________|_______________|___________|\n\n\n");
    dot(26);
    printf("\n\n\n");

    // Выводим таблицы той категории к которой относятся учащейся студенты
    if (st_good != 0)
    {
        printf("\tТаблица - Студентов отличников\n");
        printf("\t.__________________________________________________________________.\n");
        printf("\t| № |   Фамилия   | Гр |                  Оценки                   |\n");
        printf("\t|---|-------------|----|-------------------------------------------|\n");

        for (int i = 0; i < st_good; i++)
        {
            printf("\t| %d | %11s |  %d |", i + 1, (studentG + i)->surname, (studentG + i)->group);

            for (int t = 0; t < A; t++)
            {
                printf(" %d |", (studentG + i)->mark[i][t]);
            }

            if (i != i - 1)
                printf("\n");
        }

        printf("\t|___|_____________|____|___________________________________________|\n\n\n");
    }

    if (st_mid != 0)
    {
        printf("\tТаблица - Студентов среднячков\n");
        printf("\t.__________________________________________________________________.\n");
        printf("\t| № |   Фамилия   | Гр |                  Оценки                   |\n");
        printf("\t|---|-------------|----|-------------------------------------------|\n");

        for (int i = 0; i < st_mid; i++)
        {
            printf("\t| %d | %11s |  %d |", i + 1, (studentM + i)->surname, (studentM + i)->group);

            for (int t = 0; t < A; t++)
            {
                printf(" %d |", (studentM + i)->mark[i][t]);
            }

            if (i != i - 1)
                printf("\n");
        }

        printf("\t|___|_____________|____|___________________________________________|\n\n\n");
    }

    if (st_bad != 0)
    {
        printf("\tТаблица - Студентов двоечников\n");
        printf("\t.__________________________________________________________________.\n");
        printf("\t| № |   Фамилия   | Гр |                  Оценки                   |\n");
        printf("\t|---|-------------|----|-------------------------------------------|\n");

        for (int i = 0; i < st_bad; i++)
        {
            printf("\t| %d | %11s |  %d |", (i + 1), (studentB + i)->surname, (studentB + i)->group);

            for (int j = 0; j < A; j++)
            {
                printf(" %d |", (studentB + i)->mark[i][j]);
            }

            if (i != i - 1)
                printf("\n");
        }
        printf("\t|___|_____________|____|___________________________________________|\n\n\n");
    }
}

//============================= функции вспомогательные =========================================
//
void dash(int count)
{
    for (int i = 0; i < count; i++)
        printf("-");
}
void dot(int count)
{
    for (int i = 0; i < count; i++)
        printf("  .");
}
void dotdot(int count)
{
    for (int i = 0; i < count; i++)
        printf(".");
}
void equal(int count)
{
    for (int i = 0; i < count; i++)
        printf("=");
}
void tabs(int count)
{
    for (int i = 0; i < count; i++)
        printf("\t|");
}
void apostrophe(int count)
{
    for (int i = 0; i < count; i++)
        printf("`");
}
void underscore(int count)
{
    for (int i = 0; i < count; i++)
        printf("_");
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
*/

// Задание 2:
// Описать структуру Man
// - фамилия;
// - имя;
// - возраст;
// - дата рождения.
// Создать массив людей и написать программу, позволяющую:
// - вывод информации с сортировкой по фамилии или имени;
// - вывод списка людей, родившихся в данном месяце с указанием даты рождения;
// - изменение размеров массива при добавлении и удалении записей;
// - редактирование записи.

#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define LIM 30

//////////////////////////////// функции ввода вывода /////////////////////////////////////////////////

void outputTablе1(struct Man *, int);
void outputTablе2(struct Man *, int);

//////////////////////////////// функции сортировки ///////////////////////////////////////////////////

void sortSurname(struct Man *, int);
void sortName(struct Man *, int);

//////////////////////////////// функции вспомогательные ///////////////////////////////////////////////

void dash(int);
void dot(int);
void dotdot(int);
void equal(int);
void tabs(int);
void apostrophe(int);
void underscore(int);
void eatline(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Man
{
    char surname[LIM];
    char name[LIM];
    int age;
    int day;
    int month;
    int year;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Man *ptrman = nullptr;

    int count = 0;
    int menu;
    int option;

    char enter; // для подтверждения
    char repeat;

    bool find;            // для 7 пункта
    bool memory1 = false; // проверка памяти
    bool memory2 = false; // проверка перевыделение памяти
    bool work = false;
    bool goback = true;
    do
    {
        system("cls");
        equal(80);
        printf("\n");
        tabs(9);
        printf("\n");
        apostrophe(80);
        printf("\n");
        printf("\t     ***| Задание 2 (Модуль 10 Структуры и объединения) |***\n\n");
        printf("\t________________________| Главное меню |________________________________\n");
        printf("\t  Выберите ПУНКТ меню:\n");
        printf("\t1:Добавление записи.\n");
        printf("\t2:Просмотреть записи.\n");
        printf("\t3:Редактирование записей.\n");
        printf("\t4:Удаление записи.\n");
        printf("\t5:Сортировка записи по фамилии.\n");
        printf("\t6:Сортировка записи по имени.\n");
        printf("\t7:Вывод людей, родившихся в определенном месяце.\n");
        printf("\t8: | ВыхоД |\n     |\n     '->");
        menu = 0;
        scanf_s("%d", &menu);
        eatline();
        switch (menu)
        {
        case 1:
            printf("\n");
            dash(80);
            printf("\n\t\t      _______| Выбран 1 пункт меню |_______\n\n");
            printf("\t1:Ввести записи (добавить).\n");
            printf("\t2: | Отмена |"); // оставить как есть

            do
            {
                option = 0;
                printf("\n     |\n     '->");
                scanf_s("%d", &option);
                eatline();
                if (option != 1 && option != 2)
                {
                    printf("\n\tНекорректный ввод (Действие = 2 -отмена).");
                    printf("\n\tПожалуйста сделайте выбор.");
                }

            } while (option != 1 && option != 2);

            if (option == 1)
            {
                if (work == false)
                {
                    ptrman = (Man *)calloc(1, sizeof(Man));
                    if (ptrman)
                    {
                        work = true;
                    }
                    else
                        printf("\tНет возможности выделить память под первый элемент массива структур\n");
                }

                if (work)
                {
                    do
                    {
                        ptrman = (Man *)realloc(ptrman, (count + 1) * sizeof(Man));
                        if (ptrman)
                        {
                            memory1 = true;
                            memory2 = true;
                        }
                        else
                        {
                            printf("\tНе удалось выделить память под %d указатель на структуру!\n", count);
                            memory2 = false;
                        }

                        if (memory1 && memory2)
                        {
                            printf("\n");
                            dot(26);
                            printf("\n");
                            printf("\n\t===  Вводим %2d  запись  ===\n\n", count + 1);

                            // защита ввода фамилия
                            do
                            {
                                printf("\tФамилия: ");
                                gets_s((ptrman + count)->surname, 41);

                            } while (ptrman[count].surname[0] == '\0' || (int)strlen((ptrman + count)->surname) > 11);

                            // защита ввода имя
                            do
                            {
                                printf("\tИмя:     ");
                                gets_s((ptrman + count)->name, 41);

                            } while (ptrman[count].name[0] == '\0' || (int)strlen((ptrman + count)->name) > 11);

                            // защита ввода возраст
                            do
                            {
                                while (1)
                                {
                                    char ch = 0;
                                    printf("\tВозраст: ");

                                    if (!scanf_s("%d", &(ptrman + count)->age) || getchar() != '\n')
                                    {
                                        while ((ch = getchar()) != '\n' && ch != EOF)
                                            ;
                                    }
                                    else
                                        break;
                                }

                            } while ((ptrman + count)->age > 99 || (ptrman + count)->age <= 0);

                            // защита ввода дата
                            while (true)
                            {
                                printf("\n\tДата рождения:");
                                printf("\n\t____формат____");
                                printf("\n\t (дд.мм.гггг) \n\t  ");

                                if (scanf("%2d.%2d.%5d",
                                          &(ptrman + count)->day, &(ptrman + count)->month, &(ptrman + count)->year) == 3 &&
                                    (ptrman + count)->day > 0 && (ptrman + count)->day < 32 && (ptrman + count)->month > 0 && (ptrman + count)->month < 13 && (ptrman + count)->year > 0 && (ptrman + count)->year < 2021)
                                    break;
                                //&& (2020 - (ptrman + count)->year) == (ptrman + count)->age) break;

                                printf("\n\tВведена неверная дата рождения.");
                                printf("\n\tБудте внимательны!!!\n");

                                eatline();
                            }
                            eatline();

                            count++;
                        }

                        printf("\t");
                        dotdot(30);
                        printf("\n\tY - Ввести еще одну запись.");
                        printf("\n     |  Q - Выход в Главное меню.\n     '->");
                        repeat = getche();
                    } while (repeat == 'y' || repeat == 'Y');
                }
            }
            break;

        case 2:
            printf("\n");
            dash(80);
            if (memory1)
            {
                printf("\n\t\t      _______| Выбран 2 пункт меню |_______\n\n\n");

                if (count != 0)
                {
                    outputTablе1(ptrman, count);
                }
                else
                {
                    printf("\tСписок пуст.");
                }
            }
            else
                printf("\n\tПамять для записей не выделена.");

            printf("\n");
            dotdot(80);
            printf("\n");
            tabs(9);
            printf("\n");
            equal(80);
            printf("\n\tВернутся в главное меню нажмите-<ENTER>");
            enter = getche();
            break;

        case 3:
            printf("\n");
            dash(80);
            if (memory1)
            {
                int record;
                printf("\n\t\t      _______| Выбран 3 пункт меню |_______\n\n");
                printf("\t1:Редактировать запись в таблице.\n");
                printf("\t2: | Отмена |"); // оставить как есть

                do
                {
                    option = 0;
                    printf("\n     |\n     '->");
                    scanf_s("%d", &option);
                    eatline();
                    if (option != 1 && option != 2)
                    {
                        printf("\n\tНекорректный ввод (Действие = 2 -отмена).");
                        printf("\n\tПожалуйста сделайте выбор.");
                    }

                } while (option != 1 && option != 2);

                if (option == 1)
                {
                    do
                    {
                        if (count != 0)
                        {
                            printf("\n");
                            dot(26);
                            printf("\n\n");
                            outputTablе1(ptrman, count);
                        }
                        else
                        {
                            printf("\n\n\tСписок пуст.");
                            break;
                        }

                        do
                        {
                            while (1)
                            {
                                char ch = 0;
                                printf("\n\tВведите номер записи для редактирования:");
                                printf("\n     |\n     '->");

                                if (!scanf_s("%d", &record) || getchar() != '\n')
                                {
                                    while ((ch = getchar()) != '\n' && ch != EOF)
                                        ;
                                }
                                else
                                    break;
                            }

                            if (record > count || record <= 0)
                            {
                                printf("\n\tЗапись под таким номером отсутствует.");
                                printf("\n\tПовторите ввод.\n");
                            }

                        } while (record > count || record <= 0);

                        printf("\n");
                        dot(26);
                        printf("\n");

                        outputTablе2(ptrman, record - 1);

                        printf("\n\t===  Редактируем %2d  запись  ===\n\n", record);

                        // защита ввода фамилия
                        do
                        {
                            printf("\tФамилия: ");
                            gets_s((ptrman + (record - 1))->surname, 41);

                        } while (ptrman[(record - 1)].surname[0] == '\0' || (int)strlen((ptrman + (record - 1))->surname) > 11);

                        // защита ввода имя
                        do
                        {
                            printf("\tИмя:     ");
                            gets_s((ptrman + (record - 1))->name, 41);

                        } while (ptrman[(record - 1)].name[0] == '\0' || (int)strlen((ptrman + (record - 1))->name) > 11);

                        // защита ввода возраст
                        do
                        {
                            while (1)
                            {
                                char ch = 0;
                                printf("\tВозраст: ");

                                if (!scanf_s("%d", &(ptrman + (record - 1))->age) || getchar() != '\n')
                                {
                                    while ((ch = getchar()) != '\n' && ch != EOF)
                                        ;
                                }
                                else
                                    break;
                            }

                        } while ((ptrman + (record - 1))->age > 99 || (ptrman + (record - 1))->age <= 0);

                        // защита ввода дата
                        while (true)
                        {
                            printf("\n\tДата рождения:");
                            printf("\n\t____формат____");
                            printf("\n\t (дд.мм.гггг) \n\t  ");

                            if (scanf("%2d.%2d.%5d",
                                      &(ptrman + (record - 1))->day, &(ptrman + (record - 1))->month, &(ptrman + (record - 1))->year) == 3 &&
                                (ptrman + (record - 1))->day > 0 && (ptrman + (record - 1))->day < 32 && (ptrman + (record - 1))->month > 0 && (ptrman + (record - 1))->month < 13 && (ptrman + (record - 1))->year > 0 && (ptrman + (record - 1))->year < 2021)
                                break;
                            //&& (2020 - (ptrman + count)->year) == (ptrman + count)->age) break;

                            printf("\n\tВведена неверная дата рождения.");
                            printf("\n\tБудте внимательны!!!\n");

                            eatline();
                        }
                        eatline();

                        printf("\n\tЗапись под номером %d отредактирована.\n", record);

                        printf("\t");
                        dotdot(40);
                        printf("\n\tY - Редактировать еще одну запись.");
                        printf("\n     |  Q - Отмена.\n     '->");
                        repeat = getche();
                    } while (repeat == 'y' || repeat == 'Y');
                }
            }
            else
                printf("\n\tПамять для записей не выделена.");

            printf("\n");
            dotdot(80);
            printf("\n");
            tabs(9);
            printf("\n");
            equal(80);
            printf("\n\tВернутся в главное меню нажмите-<ENTER>");
            enter = getche();
            break;

        case 4:
            printf("\n");
            dash(80);
            if (memory1)
            {
                int id;
                printf("\n\t\t      _______| Выбран 4 пункт меню |_______\n\n");
                printf("\t1:Удалить запись из таблицы.\n");
                printf("\t2: | Отмена |"); // оставить как есть

                do
                {
                    option = 0;
                    printf("\n     |\n     '->");
                    scanf_s("%d", &option);
                    eatline();
                    if (option != 1 && option != 2)
                    {
                        printf("\n\tНекорректный ввод (Действие = 2 -отмена).");
                        printf("\n\tПожалуйста сделайте выбор.");
                    }

                } while (option != 1 && option != 2);

                if (option == 1)
                {
                    do
                    {
                        if (count != 0)
                        {
                            printf("\n");
                            dot(26);
                            printf("\n\n");
                            outputTablе1(ptrman, count);
                        }
                        else
                        {
                            printf("\n\n\tСписок пуст.");
                            break;
                        }

                        do
                        {
                            while (1)
                            {
                                char ch = 0;
                                printf("\n\tВведите номер записи для удаления:");
                                printf("\n     |\n     '->");

                                if (!scanf_s("%d", &id) || getchar() != '\n')
                                {
                                    while ((ch = getchar()) != '\n' && ch != EOF)
                                        ;
                                }
                                else
                                    break;
                            }

                            if (id > count || id <= 0)
                            {
                                printf("\n\tЗапись под таким номером отсутствует.");
                                printf("\n\tПовторите ввод.\n");
                            }

                        } while (id > count || id <= 0);

                        // удаляем запись
                        for (int i = id - 1; i < count; i++)
                            ptrman[i] = ptrman[i + 1];

                        count--;

                        ptrman = (Man *)realloc(ptrman, (count + 1) * sizeof(Man));

                        printf("\n\tЗапись под номером %d удалена.\n", id);

                        printf("\t");
                        dotdot(40);
                        printf("\n\tY - Удалить еще одну запись.");
                        printf("\n     |  Q - Отмена.\n     '->");
                        repeat = getche();
                    } while (repeat == 'y' || repeat == 'Y');
                }
            }
            else
                printf("\n\tПамять для записей не выделена.");

            printf("\n");
            dotdot(80);
            printf("\n");
            tabs(9);
            printf("\n");
            equal(80);
            printf("\n\tВернутся в главное меню нажмите-<ENTER>");
            enter = getche();
            break;

        case 5:
            printf("\n");
            dash(80);
            if (memory1)
            {
                printf("\n\t\t      _______| Выбран 5 пункт меню |_______\n\n\n");

                if (count != 0)
                {
                    sortSurname(ptrman, count);
                    outputTablе1(ptrman, count);
                }
                else
                {
                    printf("\tСписок пуст.");
                }
            }
            else
                printf("\n\tПамять для записей не выделена.");

            printf("\n");
            dotdot(80);
            printf("\n");
            tabs(9);
            printf("\n");
            equal(80);
            printf("\n\tВернутся в главное меню нажмите-<ENTER>");
            enter = getche();
            break;

        case 6:
            printf("\n");
            dash(80);
            if (memory1)
            {
                printf("\n\t\t      _______| Выбран 6 пункт меню |_______\n\n\n");

                if (count != 0)
                {
                    sortName(ptrman, count);
                    outputTablе1(ptrman, count);
                }
                else
                {
                    printf("\tСписок пуст.");
                }
            }
            else
                printf("\n\tПамять для записей не выделена.");

            printf("\n");
            dotdot(80);
            printf("\n");
            tabs(9);
            printf("\n");
            equal(80);
            printf("\n\tВернутся в главное меню нажмите-<ENTER>");
            enter = getche();
            break;

        case 7:
            printf("\n");
            dash(80);
            if (memory1)
            {
                printf("\n\t\t      _______| Выбран 7 пункт меню |_______\n\n");
                printf("\t1:Найти людей по месяцу в веденной таблице.\n");
                printf("\t2: | Отмена |"); // оставить как есть

                do
                {
                    option = 0;
                    printf("\n     |\n     '->");
                    scanf_s("%d", &option);
                    eatline();
                    if (option != 1 && option != 2)
                    {
                        printf("\n\tНекорректный ввод (Действие = 2 -отмена).");
                        printf("\n\tПожалуйста сделайте выбор.");
                    }

                } while (option != 1 && option != 2);

                if (option == 1)
                {
                    do
                    {
                        if (count != 0)
                        {
                            int search;
                            find = false;

                            printf("\n");
                            dot(26);
                            printf("\n");

                            do
                            {
                                while (1)
                                {
                                    char ch = 0;
                                    printf("\n\tВведите месяц (1-12) даты рождения для поиска :");
                                    printf("\n     |\n     '->");

                                    if (!scanf_s("%d", &search) || getchar() != '\n')
                                    {
                                        while ((ch = getchar()) != '\n' && ch != EOF)
                                            ;
                                    }
                                    else
                                        break;
                                }

                                if (search > 12 || search <= 0)
                                {
                                    printf("\n\tОшибка ввода искомого месяца.");
                                    printf("\n\tПовторите ввод.\n");
                                }

                            } while (search > 12 || search <= 0);

                            for (int i = 0; i < count; i++)
                            {
                                if (ptrman[i].month == search)
                                {
                                    find = true;
                                    outputTablе2(ptrman, i);
                                }
                            }

                            if (!find)
                            {
                                printf("\n\tВ списке нет людей, родившихся в искомом месяце.\n");
                            }
                        }
                        else
                        {
                            printf("\n\n\tСписок пуст.");
                            break;
                        }

                        printf("\t");
                        dotdot(25);
                        printf("\n\tY - Повторить поиск.");
                        printf("\n     |  Q - Отмена.\n     '->");
                        repeat = getche();
                    } while (repeat == 'y' || repeat == 'Y');
                }
            }
            else
                printf("\n\tПамять для записей не выделена.");

            printf("\n");
            dotdot(80);
            printf("\n");
            tabs(9);
            printf("\n");
            equal(80);
            printf("\n\tВернутся в главное меню нажмите-<ENTER>");
            enter = getche();
            break;

        case 8:
            goback = false;
            break;

        default:
            printf("\n\tНеверный пункт меню.\n");
            printf("\tБудьте внимательны!!!\n");
            printf("\tДля продолжения-<ENTER>");
            enter = getch();
            break;
        }

    } while (goback);

    if (ptrman)
    {
        free(ptrman);
    }

    ptrman = nullptr;

    printf("\n\t\t\t    ..........................");
    printf("\n\t\t\t    |     Всего хорошего     |");
    printf("\n\t\t\t    |         (^-^)/         |");
    printf("\n\t\t\t    ''''''''''''''''''''''''''\n");

    printf("\n");
    dotdot(80);
    printf("\n");
    tabs(9);
    printf("\n");
    equal(80);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}

// вывод таблицы с введенными записями
void outputTablе1(struct Man *point, int n)
{
    printf("\tТаблица - Всех записей\n");
    printf("\t.____________________________________________________________.\n");
    printf("\t|  №  |   Фамилия   |     Имя     | Возраст | Дата  рождения |\n");
    printf("\t|-----|-------------|-------------|---------|----------------|\n");

    for (int i = 0; i < n; i++)
    {
        printf("\t| %2d  | %11s | %11s |   %2d    |   %2d.%2d.%4d   |", i + 1,
               (point + i)->surname, (point + i)->name, (point + i)->age,
               (point + i)->day, (point + i)->month, (point + i)->year);

        if (i != n - 1)
            printf("\n");
    }

    printf("\n");
    printf("\t|_____|_____________|_____________|_________|________________|\n\n");
}

// вывод таблицы запись которой редактируем
void outputTablе2(struct Man *point, int n)
{
    printf("\n");
    printf("\tТаблица - Обработки данных.\n");
    printf("\t.____________________________________________________________.\n");
    printf("\t|  №  |   Фамилия   |     Имя     | Возраст | Дата  рождения |\n");
    printf("\t|-----|-------------|-------------|---------|----------------|\n");
    printf("\t| %2d  | %11s | %11s |   %2d    |   %2d.%2d.%4d   |", n + 1,
           (point + n)->surname, (point + n)->name, (point + n)->age,
           (point + n)->day, (point + n)->month, (point + n)->year);
    printf("\n");
    printf("\t|_____|_____________|_____________|_________|________________|\n\n");
}

// сортировка по имени
void sortName(struct Man *point, int n)
{
    Man temp;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(point[i].name, point[j].name) > 0)
            {
                temp = point[i];
                point[i] = point[j];
                point[j] = temp;
            }
}

// сортировка по фамилии
void sortSurname(struct Man *point, int n)
{
    Man temp;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(point[i].surname, point[j].surname) > 0)
            {
                temp = point[i];
                point[i] = point[j];
                point[j] = temp;
            }
}

//============================= функции вспомогательные =========================================
//
void dash(int count)
{
    for (int i = 0; i < count; i++)
        printf("-");
}
void dot(int count)
{
    for (int i = 0; i < count; i++)
        printf("  .");
}
void dotdot(int count)
{
    for (int i = 0; i < count; i++)
        printf(".");
}
void equal(int count)
{
    for (int i = 0; i < count; i++)
        printf("=");
}
void tabs(int count)
{
    for (int i = 0; i < count; i++)
        printf("\t|");
}
void apostrophe(int count)
{
    for (int i = 0; i < count; i++)
        printf("`");
}
void underscore(int count)
{
    for (int i = 0; i < count; i++)
        printf("_");
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
