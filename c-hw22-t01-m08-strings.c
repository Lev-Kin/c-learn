/*
// 1.1
// Задание 1:
// Написать функцию, которая удаляет из строки символ с заданным номером.
// Задание 2:
// Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.
// Задание 3:
// Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
// Задание 4:
// Написать программу, которая заменяет все символы точки "." в строке, введенной
// пользователем, на символы восклицательного знака "!".
// Задание 5:
// Пользователь вводит строку символов и искомый символ, посчитать сколько раз
// он встречается в строке.
// Задание 6:
// Пользователь вводит строку. Определить количество букв, количество цифр и
// количество остальных символов, присутствующих в строке.
// Рекомендации:
// 1. Для проверки, что символ является числом, не обязательно сравнивать его
// со всеми 10-ю цифрами, достаточно сравнить код символа с диапазоном кодов цифр.
// Код символа 0 – 48, 1 – 49, 2 – 50 …. 9 – 57.
// 2. Должна быть программа, проверяющая работу функции.

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>   // getch()
#include <stdbool.h> // true и false

#define SIZE 81 // room for 80 chars + '\0'

int main(void);

//////////////////////////////// функции задания ////////////////////////////////

char *eraseId(char *, int);
char *eraseCh(char *, char);
char *addChInIdStr(char *, char, int);
char *changeCh(char *);
int countCh(char *, char);
void search(char *);

//////////////////////////////// функции вспомогательные  ////////////////////////

void dash(int);
void dot(int);
void equal(int);
void eatline(void);

//////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char str[SIZE]; // строка
    char ch;        // символ в строке
    int id;         // индекс в строке (позиция)

    char repeat;
    char enter;
    int option;
    int menu;
    bool goback = true;
    do
    {
        system("cls");
        equal(75);
        printf("\n");
        printf(" ***| Задание 1.1 (Модуль 8 Строки) |***\n\n");
        printf(" ___________| Главное меню |_______________________________________________\n");
        printf("   Выберите ФУНКЦИЮ:\n");
        printf(" 1:Удаления из строки символа с заданной позиции.\n");
        printf(" 2:Удаления из строки заданного символа и всех его дубликатов.\n");
        printf(" 3:Добавления символа в строку в указанную позицию.\n");
        printf(" 4:Замены в строке символа точка '.' на символ восклицательный знак '!'.\n");
        printf(" 5:Подсчета количества в строке заданного символа.\n");
        printf(" 6:Подсчета количества цифр, букв и иных символов, присутствующих в строке.\n");
        printf(" 7: | ВыхоД |\n\n>");
        menu = 0;
        scanf_s("%d", &menu);
        eatline();
        switch (menu)
        {
        case 1:
            do
            {
                id = 0;
                str[0] = '\0';

                dash(75);
                printf("\n _______| Выбран 1 пункт меню |_______\n\n");

                do
                {
                    printf(" Введите строку: \n");
                    printf(" [строка] ");
                    gets_s(str, SIZE);

                    if (str[0] == '\0')
                        printf("\n");

                } while (str[0] == '\0');

                printf("\n Отсчет строки начинается с нулевой позиции! \n");
                printf(" Позиция может быть задана от 0 до %d.\n", strlen(str) - 1);
                printf(" Введите позицию символа в строке, который следует удалить:\n");
                do
                {
                    printf(" > ");
                    scanf_s("%d", &id);
                    eatline();
                    if (id > ((int)strlen(str) - 1) || id < 0)
                    {
                        printf("\n Некорректный ввод позиции.");
                        printf("\n Позиция выходит за пределы строки.");
                        printf("\n Позиция может быть от 0 до %d.\n", (int)strlen(str) - 1);
                    }

                } while (id > ((int)strlen(str) - 1) || id < 0);

                printf("\n");
                dot(25);
                printf("\n\n __| Результат 1 пункта меню |__\n\n");

                printf(" Символ '%c' стоящий на %d позиции был удален.\n\n", str[id], id);
                printf(" [строка] ");
                puts(eraseId(str, id));

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 1.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 2:
            do
            {
                ch = '0';
                str[0] = '\0';

                dash(75);
                printf("\n _______| Выбран 2 пункт меню |_______\n\n");

                do
                {
                    printf(" Введите строку: \n");
                    printf(" [строка] ");
                    gets_s(str, SIZE);

                    if (str[0] == '\0')
                        printf("\n");

                } while (str[0] == '\0');

                do
                {
                    printf("\n Введите символ, который следует удалить из строки:\n");
                    printf(" > ");
                    ch = getchar();

                } while (ch == '\n');
                eatline();

                printf("\n");
                dot(25);
                printf("\n\n __| Результат 2 пункта меню |__\n\n");

                if (eraseCh(str, ch) != NULL)
                {
                    printf(" Символ '%c' и все его дубликаты были удалены.\n\n", ch);
                    printf(" [строка] ");
                    puts(str);
                }
                else
                {
                    printf(" Символ '%c' в строке не найден.\n\n", ch);
                    printf(" [строка] ");
                    puts(str);
                }

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 2.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 3:
            do
            {
                id = 0;
                ch = '0';
                str[0] = '\0';

                dash(75);
                printf("\n _______| Выбран 3 пункт меню |_______\n\n");

                do
                {
                    printf(" Введите строку: \n");
                    printf(" [строка] ");
                    gets_s(str, SIZE);

                    if (str[0] == '\0')
                        printf("\n");

                } while (str[0] == '\0');

                do
                {
                    printf("\n Введите символ, который следует добавить в строку:\n");
                    printf(" > ");
                    ch = getchar();

                } while (ch == '\n');
                eatline();

                printf("\n Отсчет строки начинается с нулевой позиции! \n");
                printf(" Позиция может быть от 0 до %d.\n", (int)strlen(str) - 1);
                printf(" Введите позицию, куда следует вставить символ '%c':\n", ch);
                do
                {
                    printf(" > ");
                    scanf_s("%d", &id);
                    eatline();
                    if (id > ((int)strlen(str) - 1) || id < 0)
                    {
                        printf("\n Некорректный ввод позиции для вставки.");
                        printf("\n Позиция выходит за пределы строки.");
                        printf("\n Позиция может быть от 0 до %d.\n", (int)strlen(str) - 1);
                    }

                } while (id > ((int)strlen(str) - 1) || id < 0);

                printf("\n");
                dot(25);
                printf("\n\n __| Результат 3 пункта меню |__\n\n");

                printf(" Символ '%c' был добавлен на %d позицию в строке.\n\n", ch, id);

                printf(" [строка] ");
                puts(addChInIdStr(str, ch, id));

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 3.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 4:
            do
            {
                str[0] = '\0';

                dash(75);
                printf("\n _______| Выбран 4 пункт меню |_______\n\n");

                do
                {
                    printf(" Введите строку: \n");
                    printf(" [строка] ");
                    gets_s(str, SIZE);

                    if (str[0] == '\0')
                        printf("\n");

                } while (str[0] == '\0');

                printf("\n");
                dot(25);
                printf("\n\n __| Результат 4 пункта меню |__\n\n");

                if (changeCh(str) != NULL)
                {
                    printf(" Символ '.' был заменен на '!' в строке.\n\n");
                    printf(" [строка] ");
                    puts(str);
                }
                else
                {
                    printf(" Символ '.' для замены на '!' в строке не найден.\n\n");
                    printf(" [строка] ");
                    puts(str);
                }

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 4.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 5:
            do
            {
                id = 0;
                ch = '0';
                str[0] = '\0';

                dash(75);
                printf("\n _______| Выбран 5 пункт меню |_______\n\n");

                do
                {
                    printf(" Введите строку: \n");
                    printf(" [строка] ");
                    gets_s(str, SIZE);

                    if (str[0] == '\0')
                        printf("\n");

                } while (str[0] == '\0');

                do
                {
                    printf("\n Введите символ, который следует посчитать в строке:\n");
                    printf(" > ");
                    ch = getchar();

                } while (ch == '\n');
                eatline();

                printf("\n");
                dot(25);
                printf("\n\n __| Результат 5 пункта меню |__\n\n");

                if (countCh(str, ch) != 0)
                {
                    printf(" Символ '%c' в строке встречается %d раз.\n\n", ch, countCh(str, ch));
                    printf(" [строка] ");
                    puts(str);
                }
                else
                {
                    printf(" Символ '%c' в строке не найден.\n\n", ch);
                    printf(" [строка] ");
                    puts(str);
                }

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 5.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 6:
            do
            {
                id = 0;
                ch = '0';
                str[0] = '\0';
                option = 0;

                dash(75);
                printf("\n _______| Выбран 6 пункт меню |_______\n\n");
                printf("   Выберите действие:\n");
                printf(" 1:Ввести текст для работы с функцией.\n");
                printf(" 2:ТЕСТ работы функции c заданной строкой.\n");
                printf(" 3: | Отмена |\n");

                do
                {
                    printf("\n Действие > ");
                    scanf_s("%d", &option);
                    eatline();
                    if (option != 1 && option != 2 && option != 3)
                    {
                        printf("\n Некорректный ввод (Действие = 3 -отмена).");
                        printf("\n Пожалуйста сделайте выбор.");
                    }

                } while (option != 1 && option != 2 && option != 3);

                if (option == 1)
                {
                    do
                    {
                        printf(" Введите строку: \n");
                        printf(" [строка] ");
                        gets_s(str, SIZE);

                        if (str[0] == '\0')
                            printf("\n");

                    } while (str[0] == '\0');

                    printf("\n");
                    dot(25);
                    printf("\n\n __| Результат 6 пункта меню |__\n");

                    search(str);
                }

                if (option == 2)
                {
                    char strtest[SIZE] = {"DIgit - 123890. LaiN - ZVQ. КрилЛица - ЁЙёЫгЮУФД. Signs - !?."};

                    printf("\n");
                    puts(strtest);

                    search(strtest);
                }

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 6.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 7:
            printf("\n\t..................");
            printf("\n\t|   До свидание  |");
            printf("\n\t|     (^-^)/     |");
            printf("\n\t''''''''''''''''''\n\n");
            goback = false;
            break;

        default:
            printf("\n Неверный пункт меню.\n");
            printf(" Будьте внимательны!!!\n");
            printf(" Для продолжения-<ENTER>");
            enter = getch();
            break;
        }

    } while (goback);

    equal(75);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

//============================= функции задания =============================================
//
// 1. Функция удаляет из строки символ с заданным номером.
char *eraseId(char *str, int id)
{
    while (id < (int)strlen(str))
        str[id++] = str[id + 1];

    return str;
}

// 2. Функция удаляет из строки заданный символ и все его дубликаты.
char *eraseCh(char *str, char ch)
{
    bool symbol = false;
    for (int i = 0; i < (int)strlen(str); i++)
    {
        if (str[i] == ch)
        {
            for (int j = i; j < (int)strlen(str); j++)
                str[j] = str[j + 1];
            i--;
            symbol = true;
        }
    }

    if (symbol)
        return str;
    else
        return NULL;
}

// 3. Функция вставляет заданный символ в указанную позицию в строке.
char *addChInIdStr(char *str, char ch, int id)
{
    // while (id > strlen(str)) str[id--] = str[id]; str[id] = ch;
    int wstr = strlen(str); // длина строки для счетчика
    str[wstr + 1] = '\0';   // переопределяем конец строки
    while (id < wstr)
        str[wstr--] = str[wstr - 1];
    str[id] = ch;

    return str;
}

// 4. Функция заменяет все символы точки "."
//    в строке, введенной пользователем, на символы восклицательного знака "!".
char *changeCh(char *str)
{
    char *ph;
    bool symbol = false;
    while (true)
    {
        // поиск вхождения символа строку char * strchr( const char * string, int symbol);
        ph = strchr(str, '.');
        if (ph != NULL)
        {
            *ph = '!';
            str++;
            symbol = true;
        }
        else
            break;
    }

    if (symbol)
        return str;
    else
        return NULL;
}

// 5. Функция подсчета искомого символа.
int countCh(char *str, char ch)
{
    int count = 0;
    bool symbol = false;
    for (int i = 0; i < (int)strlen(str); i++)
    {
        if (str[i] == ch)
        {
            count++;
            symbol = true;
        }
    }

    if (symbol)
        return count;
    else
        return 0;
}

// 6. Подсчет, количества букв, цифр и остальных символов в строке.
void search(char *str)
{
    int digit = 0;    // цифры
    int latBig = 0;   // латинская большая буква
    int latSmall = 0; // латинская малая буква
    int cyrBig = 0;   // кириллица большая буква
    int cyrSmall = 0; // кириллица малая буква
    int sign = 0;     // знак

    for (int i = 0; i < (int)strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            digit++;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            latBig++;
        else if (str[i] >= 'a' && str[i] <= 'z')
            latSmall++;
        else if (str[i] >= 'А' && str[i] <= 'Я' || str[i] == 'Ё')
            cyrBig++;
        else if (str[i] >= 'а' && str[i] <= 'я' || str[i] == 'ё')
            cyrSmall++;
        else if (str[i] != ' ')
            sign++;
    }

    printf("\n В строке обнаружено следующие количество:");
    printf("\n Цифр   =  %d", digit);
    printf("\n Знаков =  %d", sign);
    printf("\n Латиницы  БОЛЬШЫX букв = %d", latBig);
    printf("\n Латиницы    малых букв = %d", latSmall);
    printf("\n Кириллицы БОЛЬШЫХ букв = %d", cyrBig);
    printf("\n Кириллицы   малых букв = %d", cyrSmall);
    printf("\n");
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
        printf(" . ");
}
void equal(int count)
{
    for (int i = 0; i < count; i++)
        printf("=");
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

// 1.2
// Задание 1:
// Дополните свою библиотеку функций реализациями нижеследующих функций
// int mystrcmp (const char* str1, const char* str2);
// - функция сравнивает две строки, и , если строки равны возвращает 0, если первая
//    строка больше второй, то возвращает 1, иначе -1.
// int StringToNumber( char* str);
// - функция конвертирует строку в число и возвращает это число.
// char* NumberToString (int number);
// - функция конвертирует число в строку и возвращает указатель на эту строку.
// char* Uppercase (char* str1);
// - функция преобразует строку в верхний регистр.
// char* Lowercase (char* str1);
// - функция преобразует строку в нижний регистр.
// char* mystrrev (char* str);
// - функция реверсирует строку и возвращает указатель на новую строку.
// Символы кириллицы также рассмотреть.

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>   // getch()
#include <stdbool.h> // true и false

#define SIZE 81 // предельная длина строки, включая \0 // room for 80 chars + '\0'

int main(void);

//////////////////////////////// функции задания ////////////////////////////////

int mystrcmp(const char *, const char *);
int StringToNumber(char *);
char *NumberToString(int);
char *Uppercase(char *);
char *Lowercase(char *);
char *mystrrev(char *);

//////////////////////////////// функции вспомогательные  ////////////////////////

void dash(int);
void dot(int);
void equal(int);
void eatline(void);

//////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char *str = nullptr;  // указатель на элемент строки str
    char *str1 = nullptr; // указатель на элемент строки str1
    char *str2 = nullptr; // указатель на элемент строки str2
    char *strn = nullptr; // указатель на элемент строки strn

    char repeat;
    char enter;
    int menu;
    bool back = true;
    do
    {
        system("cls");
        equal(75);
        printf("\n");
        printf(" ***| Задание 1.2 (Модуль 8 Строки) |***\n\n");
        printf(" ___________| Главное меню |_______________________________________________\n");
        printf("   Выберите ФУНКЦИЮ для работы:\n");
        printf(" 1:Определяющая какая из двух строк меньше, больше или равна.\n");
        printf(" 2:Конвертирования стрку в  число и возвращающая это число.\n");
        printf(" 3:Конвертирования числа в строку и возвращающая указатель на эту строку.\n");
        printf(" 4:Преобразования строки в верхний регистр.\n");
        printf(" 5:Преобразования строки в нижний  регистр.\n");
        printf(" 6:Реверса строки и возврата указателя на новую строку.\n");
        printf(" 7: | ВыхоД |\n\n>");
        menu = 0;
        scanf_s("%d", &menu);
        eatline();
        switch (menu)
        {
        case 1:
            do
            {
                dash(75);
                printf("\n _______| Выбран 1 пункт меню |_______\n\n");

                str1 = (char *)malloc(SIZE * sizeof(char));
                str2 = (char *)malloc(SIZE * sizeof(char));
                if (str1 && str2)
                {
                    printf(" Введите строки: \n");
                    printf(" [1 ст] ");
                    gets_s(str1, SIZE);

                    printf(" [2 ст] ");
                    gets_s(str2, SIZE);

                    printf("\n");
                    dot(25);
                    printf("\n\n __| Результат 1 пункта меню |__\n\n");

                    if (mystrcmp(str1, str2) == -1)
                        printf(" [1 ст] меньше [2 ст]\n");
                    if (mystrcmp(str1, str2) == 0)
                        printf(" [1 ст] и [2 ст] равны\n");
                    if (mystrcmp(str1, str2) == 1)
                        printf(" [1 ст] больше [2 ст]\n");

                    free(str1);
                    free(str2);
                }
                else
                    printf("\n Нет возможности выделить память под строки.\n");

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 1.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 2:
            do
            {
                dash(75);
                printf("\n _______| Выбран 2 пункт меню |_______\n\n");

                int result;
                str = (char *)malloc(SIZE * sizeof(char));
                if (str)
                {
                    printf(" Введите строку: \n");
                    printf(" [строка] ");
                    gets_s(str, SIZE);

                    printf("\n");
                    dot(25);
                    printf("\n\n __| Результат 2 пункта меню |__\n\n");

                    result = StringToNumber(str);
                    printf("\n\n Числовое значение строки = %d\n", result);

                    free(str);
                }
                else
                    printf("\n Нет возможности выделить память под строку.\n");

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 2.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 3:
            do
            {
                dash(75);
                printf("\n _______| Выбран 3 пункт меню |_______\n\n");

                int number;
                char test[777] = " Введенное число (";
                char *result;
                char ch;

                while (1)
                {
                    printf(" Введите целое число: \n ");
                    // Чтение символа символа из стандартного вывода, заканчивающегося символом новой строки.
                    if (!scanf_s("%d", &number) || getchar() != '\n')
                    {
                        // Очищаем стандартный вывод перед чтением следующего символа.
                        while ((ch = getchar()) != '\n' && ch != EOF)
                            ;
                    }
                    else
                        break;

                    printf("\n !!!Ошибка ввода.");
                    printf("\n Введите целое число.");
                    printf("\n Повторите ввод:\n\n");
                }

                printf("\n");
                dot(25);
                printf("\n\n __| Результат 3 пункта меню |__\n\n");

                result = NumberToString(number);

                printf(" [строка] ");
                puts(result);

                printf("\n Проверка:\n");
                strcat(test, result); // склейка строк
                strcat(test, ") - находится в строке.");
                puts(test);

                // if (number == 0) eatline(); // на ошибочный ввод (уже не надо)
                number = 0;

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 3.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 4:
            do
            {
                dash(75);
                printf("\n _______| Выбран 4 пункт меню |_______\n\n");

                str = (char *)malloc(SIZE * sizeof(char));
                if (str)
                {
                    printf(" Введите строку: \n");
                    printf(" [строка] ");
                    gets_s(str, SIZE);

                    printf("\n");
                    dot(25);
                    printf("\n\n __| Результат 4 пункта меню |__\n\n");

                    Uppercase(str);

                    printf(" [строка] ");
                    puts(str);

                    free(str);
                }
                else
                    printf("\n Нет возможности выделить память под строку.\n");

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 4.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 5:
            do
            {
                dash(75);
                printf("\n _______| Выбран 5 пункт меню |_______\n\n");

                str = (char *)malloc(SIZE * sizeof(char));
                if (str)
                {
                    printf(" Введите строку: \n");
                    printf(" [строка] ");
                    gets_s(str, SIZE);

                    printf("\n");
                    dot(25);
                    printf("\n\n __| Результат 5 пункта меню |__\n\n");

                    Lowercase(str);

                    printf(" [строка] ");
                    puts(str);

                    free(str);
                }
                else
                    printf("\n Нет возможности выделить память под строку.\n");

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 5.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 6:
            do
            {
                dash(75);
                printf("\n _______| Выбран 2 пункт меню |_______\n\n");

                str = (char *)malloc(SIZE * sizeof(char));
                strn = (char *)malloc(SIZE * sizeof(char));
                if (str && strn)
                {
                    printf(" Введите строку: \n");
                    printf(" [строка] ");
                    gets_s(str, SIZE);

                    printf("\n");
                    dot(25);
                    printf("\n\n __| Результат 6 пункта меню |__\n\n");

                    strcpy(strn, mystrrev(str)); //новая реверс строка (все забрали (указатель перехвачен))

                    printf(" Новая реверс\n");
                    printf(" [строка] ");
                    puts(strn);

                    printf("\n Исходная не реверс\n");
                    printf(" [строка] ");
                    puts(str); // проверка изменений в исходной строке

                    free(str);
                    free(strn);
                }
                else
                    printf("\n Нет возможности выделить память под строки.\n");

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 6.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 7:
            printf("\n\t..................");
            printf("\n\t|   До свидание  |");
            printf("\n\t|     (^-^)/     |");
            printf("\n\t''''''''''''''''''\n\n");
            back = false;
            break;

        default:
            printf("\n Неверный пункт меню.\n");
            printf(" Будьте внимательны!!!\n");
            printf(" Для продолжения-<ENTER>");
            enter = getch();
            break;
        }

    } while (back);

    str = nullptr;
    str1 = nullptr;
    str2 = nullptr;
    strn = nullptr;

    equal(75);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

//============================= функции задания =============================================
//
// 1. Функция сравнивает две строки, и , если строки равны возвращает 0,
//    если первая строка больше второй, то возвращает 1, иначе - 1.
int mystrcmp(const char *str1, const char *str2)
{
    if (strlen(str1) < strlen(str2))
        return -1;
    else if (strlen(str1) > strlen(str2))
        return 1;
    else
        return 0;
}

// 2. Функция конвертирует строку в число и возвращает это число.
int StringToNumber(char *str)
{
    int digit;          // перевод строки в цифры
    int number = 0;     // число которое получаем
    int ascii;          // значения ascii
    bool minus = false; // на случай отрицательного значения

    printf(" Значение символов в строке согласно таблице ASCII \n");
    for (int i = 0; i < (int)strlen(str); i++)
    {
        if (str[i] == '-')
        {
            printf(" '%d'", str[i]);
            minus = true;
        }
        else
        {
            // переводим значения в цифры
            digit = (int)str[i] - (int)'0'; // 48 = '0'
            number = number * 10 + digit;   // накапливаем число

            ascii = (int)str[i];
            printf(" '%d'", ascii);
        }
    }

    if (minus)
        return -number;
    else
        return number;
}

// 3. Функция конвертирует число в строку и возвращает указатель на эту строку.
char *NumberToString(int number)
{
    bool negative = false; //  число положительное или отрицательное

    int digit; // цифры
    int k = 1; // количество цифр в числе

    char ch = 0;                    // значение получаемое от цифр
    char tmp;                       // для переворота числа
    char str[SIZE] = {'\0'};        // строка та строка
    char minus[SIZE] = {'-', '\0'}; // вставка минуса

    if (number < 0)
    {
        negative = true;
        number = -number;
    }

    int bufn = number;
    while ((bufn /= 10) > 0)
        k++;

    for (int i = 0; i < k; i++)
    {
        digit = number % 10;
        number = number / 10;
        ch = (char)(digit + 48);

        str[i] = ch; // заполняем строку
    }
    str[k] = '\0';

    // перевернем полученную строку от цифр
    for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    if (negative)
    {
        strcat(minus, str);
        strcpy(str, minus);
    }

    char *ptr = str; // указатель на строку созданную (эту строку)

    return ptr;
}

// 4. Функция преобразует строку в верхний регистр.
char *Uppercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            (str[i] -= 'a' - 'A');
        if (str[i] >= 'а' && str[i] <= 'я')
            (str[i] -= 'а' - 'А');
        if (str[i] == 'ё')
            (str[i] -= 'ё' - 'Ё');
    }

    return str;
}

// 5. Функция преобразует строку в нижний регистр.
char *Lowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            (str[i] += 'a' - 'A');
        if (str[i] >= 'А' && str[i] <= 'Я')
            (str[i] += 'а' - 'А');
        if (str[i] == 'Ё')
            (str[i] += 'ё' - 'Ё');
    }

    return str;
}

// 6. Функция реверсирует строку и возвращает указатель на новую строку.
char *mystrrev(char *str)
{
    char tmp;
    char buf[SIZE];
    buf[0] = '\0';

    strcpy(buf, str); // заполняем рабочую строку
    for (int i = 0, j = strlen(buf) - 1; i < j; i++, j--)
    {
        tmp = buf[i];
        buf[i] = buf[j];
        buf[j] = tmp;
    }

    char *ptr = buf; // указатель на временную рабочую строку

    return ptr; // возвращаем указатель на новую строку
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
        printf(" . ");
}
void equal(int count)
{
    for (int i = 0; i < count; i++)
        printf("=");
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
*/

// 1.3
// Задание 1:
// Есть некоторый текст.
// 1. Найдите и замените вхождение некоторого слова на заданное пользователем
//     слово.
// 2. Изменить текст таким образом, чтобы каждое предложение начиналось с большой
//     буквы.
// 3. Посчитайте, сколько раз каждая буква встречается в тексте.
// 4. Посчитайте, сколько раз цифры встречаются в тексте.

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>   // getch()
#include <stdbool.h> // true и false

#define SIZE 81 // room for 80 chars + '\0'
#define LIM 10  /* максимальное количество вводимых строк */

int main(void);

//////////////////////////////// функции задания ////////////////////////////////

char *replaceWord(char *, char *, char *);
char *upLetterFW(char *);
void countLetterSt(char *, int *, int *, int *, int *, int *, int *);
void countDigitSt(char *, int *);

//////////////////////////////// функции вспомогательные  ////////////////////////

void dash(int);
void dot(int);
void equal(int);
void eatline(void);
int findWord(char *, char *);
char *Uppercase(char *, int);
char *Lowercase(char *, int);

//////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Есть некоторый текст (согласно условию)
    char textBase[LIM][SIZE] = {{" 1. numbers - 11, 42, 000, 123, 55, 2525, (55 15), 020 [28 88]."},
                                {" 2. letters - level, nope, A1, friends, gray, Yes, stats, zz."},
                                {" 3. юрий Гагарин первый в космосе 12 АПР 1961г !"},
                                {" 4. компилятор - для перевода в машинный код."},
                                {" 5. now or never! life is a journey? life is beautiful.    ёЁ."}};

    int qstr = 5; // количество строк

    char fw[SIZE];  // введенное искомое слово в тексте
    char nw[SIZE];  // введенное слово для замены искомого слова в тексте
    char str[SIZE]; // рабочая строка

    char textFinish[LIM][SIZE * 2]; // формирование обработанного текста

    char repeat;
    char enter;
    int menu;
    bool goback = true;
    do
    {
        system("cls");
        equal(75);
        printf("\n");
        printf(" ***| Задание 1.3 (Модуль 8 Строки) |***\n\n");
        printf(" ___________| Главное меню |_______________________________________________\n");
        printf("   Выберите ФУНКЦИЮ:\n");
        printf(" 1:Находит и заменяет введенное слова на заданное слово.\n");
        printf(" 2:Изменяет текст где каждое предложение начинается с большой буквы.\n");
        printf(" 3:Подсчета, сколько раз каждая буква встречается в тексте.\n");
        printf(" 4:Подсчета, сколько раз цифры встречаются в тексте.\n");
        printf(" 5: | ВыхоД |\n\n>");
        menu = 0;
        scanf_s("%d", &menu);
        eatline();
        switch (menu)
        {
        case 1:
            do
            {
                char tmp[SIZE];
                char *pch;
                int cw = 0;     // количество найденных слов в строке
                int word = 0;   // реальное слово
                int search = 0; // количество слов в тексте для замены
                bool justDoIt = false;

                dash(75);
                printf("\n _______| Выбран 1 пункт меню |_______\n\n");

                printf(" Исходный текст:\n\n");
                for (int i = 0; i < qstr; i++)
                    puts(textBase[i]);

                do
                {
                    printf("\n Выберите слово в тексте для заменены:\n");
                    printf(" Слово --> ");
                    gets_s(fw, 80);

                    if (strlen(fw) <= 1)
                    {
                        printf("\n Некорректный ввод искомого слова.\n Повторите ввод.\n");
                    }

                } while (strlen(fw) <= 1);

                for (int i = 0; i < qstr; i++)
                {
                    strcpy(str, textBase[i]); // копируем строки из текста
                    // проверяем есть ли слова в строках текста для дальнейшей работы
                    if (findWord(str, fw) != 0)
                        justDoIt = true;
                }

                if (justDoIt == true)
                {
                    do
                    {
                        printf("\n Задайте слово на какое следует заменить слово в тексте:\n");
                        printf(" Слово --> ");

                        gets_s(nw, 80);
                        strcpy(tmp, nw);

                        pch = strtok(tmp, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/");
                        while (pch != NULL)
                        {
                            if (strcmp(pch, nw) == 0)
                                word++;
                            pch = strtok(NULL, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/");
                        }

                        if (word == 0)
                        {
                            printf("\n Некорректный ввод слова.\n Повторите ввод.\n");
                        }

                    } while (word == 0);

                    printf("\n");
                    dot(25);
                    printf("\n\n __| Результат 1 пункта меню |__\n\n");

                    for (int i = 0; i < qstr; i++)
                    {
                        strcpy(str, textBase[i]);   // копируем строки из текста
                        cw = findWord(str, fw);     // считаем количество замененных слов в тексте
                        if (findWord(str, fw) != 0) // проверяем есть ли слова для замены в строке
                        {
                            search += cw;
                            replaceWord(str, fw, nw);   // заменяем найденное слово в тексте на заданное новое
                            strcpy(textFinish[i], str); // формируем измененный текст
                        }
                        else
                        {
                            strcpy(textFinish[i], str); // пропуск строки без замены формируем измененный текст
                        }
                    }

                    printf(" В тексте было изменено %d слов.\n", search);
                    printf(" Измененный текст с измененными словами.\n\n");
                    for (int i = 0; i < qstr; i++)
                        puts(textFinish[i]);
                    textFinish[0][0] = '\0';
                }
                else
                {
                    printf("\n");
                    dot(25);
                    printf("\n\n __| Результат 1 пункта меню |__\n\n");

                    printf(" Введенного слово в тексте не найдено.\n");
                    printf(" Текст остался без изменений.\n\n");
                    for (int i = 0; i < qstr; i++)
                        puts(textBase[i]);
                }

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 1.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 2:
            do
            {
                dash(75);
                printf("\n _______| Выбран 2 пункт меню |_______\n\n");

                printf(" Исходный текст:\n\n");
                for (int i = 0; i < qstr; i++)
                    puts(textBase[i]);

                printf("\n");
                dot(25);
                printf("\n\n __| Результат 2 пункта меню |__\n\n");

                for (int i = 0; i < qstr; i++)
                {
                    strcpy(str, textBase[i]);   // копируем строки из текста
                    upLetterFW(str);            // начинаем предложение с БОЛЬШОЙ буквы
                    strcpy(textFinish[i], str); // формируем измененный текст
                }

                printf(" Измененный текст. Предложения начинаются с большой буквы.\n\n");
                for (int i = 0; i < qstr; i++)
                    puts(textFinish[i]);
                textFinish[0][0] = '\0';

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 2.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 3:
            do
            {
                int latBig[SIZE] = {0};   // массив для хранения количества больших букв латиницы
                int latSmall[SIZE] = {0}; // массив для хранения количества малых   букв латиницы
                int cyrBig[SIZE] = {0};   // массив для хранения количества больших букв кириллицы
                int cyrSmall[SIZE] = {0}; // массив для хранения количества малых   букв кириллицы
                int countE[SIZE] = {0};   // отдельно счетчик Ё
                int counte[SIZE] = {0};   // отдельно счетчик ё

                dash(75);
                printf("\n _______| Выбран 3 пункт меню |_______\n\n");

                printf(" Исходный текст:\n\n");
                for (int i = 0; i < qstr; i++)
                    puts(textBase[i]);

                printf("\n");
                dot(25);
                printf("\n\n __| Результат 3 пункта меню |__\n\n");

                printf(" Если буква в тексте не встречается то она не выводится (Z = 0).");

                for (int i = 0; i < qstr; i++)
                {
                    strcpy(str, textBase[i]); // копируем строки из текста
                    countLetterSt(str, latBig, latSmall, cyrBig, cyrSmall, countE, counte);
                }

                //-------- латиница ---------------------------------------------------------------

                printf("\n\n Латиница БОЛЬШИЕ буквы:\n");
                printf(" --------------------------\n");
                // задаем счётчик 26 букв если если 0 то это А и так далее по алфавиту если было значение иначе пропускаем
                for (int i = 0; i < 26; i++)
                    if (latBig[i] != 0)
                    {
                        // С 'А' начала старта (база) берем соответствующее ей значение latBig[0] в массиве
                        // приводим к char чтоб определялся буква, i просто служит как направляющая
                        // если в int то 0 + 65 приведем в char это буква А
                        // и так далее int 1 + 65 = char B двигаемся по таблице ascii
                        printf(" Буква '%c' количество = %d\n", (char)(i + 'A'), latBig[i]);
                    }

                printf("\n\n Латиница малые буквы:\n");
                printf(" --------------------------\n");
                for (int i = 0; i < 26; i++)
                    if (latSmall[i] != 0)
                        printf(" Буква '%c' количество = %d\n", (char)(i + 'a'), latSmall[i]);

                printf("\n");
                dot(25);

                //-------- кирилица ---------------------------------------------------------------
                printf("\n\n Кириллица БОЛЬШИЕ буквы:\n");
                printf(" --------------------------\n");

                for (int i = 0; i < 32; i++)
                    if (cyrBig[i] != 0)
                        printf(" Буква '%c' количество = %d\n", (char)(i + 'А'), cyrBig[i]);

                if (countE[0] != 0)
                {
                    printf(" . . . . . . . . . . . . .\n");
                    printf(" Буква 'Ё' количество = %d\n", countE[0]);
                }

                printf("\n\n Кириллица малые буквы:\n");
                printf(" --------------------------\n");
                for (int i = 0; i < 32; i++)
                    if (cyrSmall[i] != 0)
                        printf(" Буква '%c' количество = %d\n", (char)(i + 'а'), cyrSmall[i]);

                if (counte[0] != 0)
                {
                    printf(" . . . . . . . . . . . . .\n");
                    printf(" Буква 'ё' количество = %d\n", counte[0]);
                }

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 3.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 4:
            do
            {
                int digit[SIZE] = {0}; // массив для хранения количества цифр

                dash(75);
                printf("\n _______| Выбран 4 пункт меню |_______\n\n");

                printf(" Исходный текст:\n\n");
                for (int i = 0; i < qstr; i++)
                    puts(textBase[i]);

                printf("\n");
                dot(25);
                printf("\n\n __| Результат 4 пункта меню |__\n\n");

                printf(" Если цифра в тексте не встречается то она не выводится (7 = 0).\n\n");

                for (int i = 0; i < qstr; i++)
                {
                    strcpy(str, textBase[i]);
                    countDigitSt(str, digit);
                }

                printf(" Цифры в тексте:\n");
                printf(" --------------------------\n");
                for (int i = 0; i < 10; i++)
                    if (digit[i] != 0)
                    {
                        printf(" Цифра '%c' количество = %d\n", (char)(i + '0'), digit[i]);
                    }

                printf("\n");
                equal(75);
                printf("\n Y - Повторить пункт 4.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 5:
            printf("\n\t..................");
            printf("\n\t|   До свидание  |");
            printf("\n\t|     (^-^)/     |");
            printf("\n\t''''''''''''''''''\n\n");
            goback = false;
            break;

        default:
            printf("\n Неверный пункт меню.\n");
            printf(" Будьте внимательны!!!\n");
            printf(" Для продолжения-<ENTER>");
            enter = getch();
            break;
        }

    } while (goback);

    equal(75);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

//============================= функции задания =============================================
//
// 1. Функция находит и заменяет введенное слова на заданное слово.
char *replaceWord(char *str, char *fword, char *rword)
{
    char buffer[SIZE * 2]; //буфер рабочей строки
    buffer[0] = '\0';
    int i, j, pos = 0;
    for (i = 0; str[i]; i++)
    {
        for (j = 0; str[i + j] && fword[j]; j++) //начинается ли с i-ой позиции строка fword
            if (str[i + j] != fword[j])
                break;
        if (!fword[j]) //если fword[j]=0, то мы дошли до конца строки fword
        {
            //в j у нас длина строки fword, которую мы перепрыгиваем
            i += j - 1;
            //на место стоки fword ставим строку rword
            for (j = 0; rword[j]; j++)
                buffer[pos++] = rword[j];
        }
        else
        {
            buffer[pos++] = str[i]; //просто копируем символ
        }
        buffer[pos] = NULL; //ставим конец строки
    }
    strcpy(str, buffer); //копируем в первоначальную строку

    /*
        char* pch;
        char* r = (char*)calloc(SIZE, sizeof(char));
        pch = strstr(str, fword);
        do
        {
            pch[0] = '\0';
            pch--;
            r = strcpy(r, str);
            r = strcat(r, rword);
            r[strlen(r)] = '\0';
            r = strcat(r, pch + strlen(fword) + 1);
            strcpy(str, r);
            pch = strstr(str, fword);
        } while (pch != NULL);
        free(r);
    */
    return str;
}

// 2. Функция изменяет текст где каждое предложение начинается с большой буквы.
char *upLetterFW(char *str)
{
    // Предложения не начинаются с пробелов (задаются табуляторы)
    // Отступ в тексте сделан ' ' для наглядности в учебных целях
    // Для начала текста проверяем если малая буква то меняем регистр
    if (Lowercase(str, 0))
        str = Uppercase(str, 0);

    // Перебираем в цикле каждый символ строки из текста
    for (int i = 0; i <= (int)strlen(str); i++)
    {
        // Ищем конец предложения (основные знаки конца предложения)
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            int k = i + 1; // Переменная для значения символа, которому будем менять регистр

            // Выполняем цикл до тех пор пока не найдем начало нового предложения,
            // так как пробле может быть не один, а несколько.
            while (str[k] == ' ')
                k++;

            // Если символ строчный, то меняем его на заглавный.
            if (Lowercase(str, k))
                str = Uppercase(str, k);
        }
    }

    return str;
}

// 3. Подсчет, сколько раз каждая буква встречается в тексте.
void countLetterSt(char *str, int *latBig, int *latSmall, int *cyrBig, int *cyrSmall, int *countE, int *counte)
{
    for (int i = 0; i < strlen(str); i++)
    {
        // проверяем диапазон если буква попалась то заполним массив
        // на то место под номером какая была определена, увеличиваем счетчик
        // пример если А то => А = cyrBig[0] и заносим 1 далее если еще А то еще суммируем

        //-------- латиница ---------------------------------------------------------------
        if (str[i] >= 'A' && str[i] <= 'Z')
            latBig[str[i] - 'A']++;
        if (str[i] >= 'a' && str[i] <= 'z')
            latSmall[str[i] - 'a']++;
        //-------- кирилица ---------------------------------------------------------------
        if (str[i] >= 'А' && str[i] <= 'Я')
            cyrBig[str[i] - 'А']++;
        if (str[i] >= 'а' && str[i] <= 'я')
            cyrSmall[str[i] - 'а']++;
        if (str[i] == 'Ё')
            countE[str[i] - 'Ё']++; // !Ё отдельно
        if (str[i] == 'ё')
            counte[str[i] - 'ё']++; // !ё отдельно
    }
}

// 4. Подсчет, сколько раз цифры встречаются в тексте.
void countDigitSt(char *str, int *digit)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            digit[str[i] - '0']++;
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
        printf(" . ");
}
void equal(int count)
{
    for (int i = 0; i < count; i++)
        printf("=");
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

// Ищем есть ли слова в строке которые написал пользователь (целое слово)
int findWord(char *str, char *word)
{
    char tmp[SIZE];
    char *pch;
    int cw = 0;

    strcpy(tmp, str);
    pch = strtok(tmp, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/");
    while (pch != NULL)
    {
        if (strcmp(pch, word) == 0)
            cw++;
        pch = strtok(NULL, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/");
    }

    return cw;
}

// Функция преобразует букву в верхний регистр.
char *Uppercase(char *str, int k)
{
    if (str[k] >= 'a' && str[k] <= 'z')
        (str[k] -= 'a' - 'A');
    if (str[k] >= 'а' && str[k] <= 'я')
        (str[k] -= 'а' - 'А');
    if (str[k] == 'ё')
        (str[k] -= 'ё' - 'Ё');

    return str;
}

// Функция преобразует букву в нижний регистр.
char *Lowercase(char *str, int k)
{
    if (str[k] >= 'A' && str[k] <= 'Z')
        (str[k] += 'a' - 'A');
    if (str[k] >= 'А' && str[k] <= 'Я')
        (str[k] += 'а' - 'А');
    if (str[k] == 'Ё')
        (str[k] += 'ё' - 'Ё');

    return str;
}
