// Дана строка символов. Заменить в ней все пробелы на табуляции.
// Дана строка символов. Определить количество букв, цифр и остальных символов, присутствующих в строке.
// Подсчитать количество слов во введенном предложении.
// Дана строка символов. Необходимо проверить  является ли эта строка палиндромом.
// Пользователь вводит отдельно строку и символ, необходимо показать
// на экран номер только последнего совпадения (нумерация с единицы).

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>   // getch()
#include <stdbool.h> // true и false

#define S 81 // room for 80 chars + '\0'

int main(void);

//////////////////////////////// функции задания ////////////////////////////////

char *changeCh(char *);
void search(char *);
void findWStrSet(char *);
int strPalindrome(char *);
int endChStr(char *, char);

//////////////////////////////// функции вспомогательные  ////////////////////////

void dash(int);
void dot(int);
void dotdot(int);
void equal(int);
void tabs(int);
void apostrophe(int);
void underscore(int);
void eatline(void);

//////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Есть строка символов (согласно условию)
    char strBase[S] = {"Imagination rules the W — Воображение МИРОМ. 157790 :!)-+]"};
    char strPLat[S] = {"Was it a car or a cat I saw?"};
    char strPCyr[S] = {"А роза упала на лапу Азора."};
    char strSets[S * 2] = {"Приятный запах доносился с кухни...\n\tА вот и пироги!!! Today we have great meal? Yes."};

    char *strWork = NULL; // для рабочей строки

    char repeat;
    char enter;
    int menu;
    bool goback = true;
    do
    {
        system("cls");
        equal(81);
        printf("\n");
        tabs(11);
        printf("\n");
        apostrophe(81);
        printf("\n");
        printf("\t\t      ***| Задание 2 (Модуль 8 Строки) |***\n\n");
        printf("\t________________________| Главное меню |_________________________________\n");
        printf("\t  Выберите ФУНКЦИЮ:\n");
        printf("\t1:Заменены пробелов на табуляции.\n");
        printf("\t2:Определяет количество букв, цифр и остальных символов, \n");
        printf("\t  присутствующих в строке.\n");
        printf("\t3:Определяет количество слов в введенном предложении.\n");
        printf("\t4:Определяет является ли строка палиндромом.\n");
        printf("\t5:Определение позиции введенного символа который встречается последним\n");
        printf("\t  в введенной строке (нумерация строки с единицы).\n");
        printf("\t6: | ВыхоД |\n     |\n     '->");
        menu = 0;
        scanf_s("%d", &menu);
        eatline();
        switch (menu)
        {
        case 1:
            do
            {
                printf("\n");
                dash(81);
                printf("\n\t\t      _______| Выбран 1 пункт меню |_______\n\n");

                printf("\tИсходная строка:\n\n");
                printf(" [str]  ");
                puts(strBase);

                strWork = (char *)malloc(S * sizeof(char));
                if (strWork)
                {
                    printf("\n");
                    dot(27);
                    printf("\n\n\t\t\t__| Результат 1 пункта меню |__\n\n");

                    strcpy(strWork, strBase);
                    changeCh(strWork);

                    /* Представьте себе линейку с табуляторами каждые 8 ​​пробелов.
                       Символ табуляции выравнивает текст до следующей остановки табуляции.
                       Часть / 8 * 8 эффективно усекает результат до ближайшего кратного 8.*/

                    printf("\tСимвол ' ' был заменен на '\\t' - табуляцию в строке.\n\n");

                    printf(" [str]  ");
                    puts(strWork);

                    free(strWork);
                }
                else
                    printf("\n\tНет возможности выделить память под строку.\n");

                printf("\n");
                dotdot(81);
                printf("\n");
                tabs(11);
                printf("\n");
                equal(81);
                printf("\n\tY - Повторить пункт 1.");
                printf("\n     |  Q - Выход в Главное меню.\n     '->");
                repeat = getche();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 2:
            do
            {
                printf("\n");
                dash(81);
                printf("\n\t\t      _______| Выбран 2 пункт меню |_______\n\n");

                printf("\tИсходная строка:\n\n");
                printf(" [str]  ");
                puts(strBase);

                strWork = (char *)malloc(S * sizeof(char));
                if (strWork)
                {
                    printf("\n");
                    dot(27);
                    printf("\n\n\t\t\t__| Результат 2 пункта меню |__\n");

                    strcpy(strWork, strBase);
                    search(strWork);

                    free(strWork);
                }
                else
                    printf("\n\tНет возможности выделить память под строку.\n");

                printf("\n");
                dotdot(81);
                printf("\n");
                tabs(11);
                printf("\n");
                equal(81);
                printf("\n\tY - Повторить пункт 2.");
                printf("\n     |  Q - Выход в Главное меню.\n     '->");
                repeat = getche();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 3:
            do
            {
                printf("\n");
                dash(81);
                printf("\n\t\t      _______| Выбран 3 пункт меню |_______\n\n");

                printf("\tИсходная строка:\n\n");
                printf(" [str]  ");
                puts(strSets);

                strWork = (char *)malloc((S * 2) * sizeof(char));
                if (strWork)
                {
                    printf("\n");
                    dot(27);
                    printf("\n\n\t\t\t__| Результат 3 пункта меню |__\n\n");
                    printf("\tВ строке:");

                    strcpy(strWork, strSets);
                    findWStrSet(strSets);

                    free(strWork);
                }
                else
                    printf("\n\tНет возможности выделить память под строку.\n");

                printf("\n");
                dotdot(81);
                printf("\n");
                tabs(11);
                printf("\n");
                equal(81);
                printf("\n\tY - Повторить пункт 3.");
                printf("\n     |  Q - Выход в Главное меню.\n     '->");
                repeat = getche();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 4:
            do
            {
                printf("\n");
                dash(81);
                printf("\n\t\t      _______| Выбран 4 пункт меню |_______\n\n");

                printf("\tИсходные строки:\n\n");
                printf(" [str1] ");
                puts(strBase);
                printf(" [str2] ");
                puts(strPLat);
                printf(" [str3] ");
                puts(strPCyr);

                strWork = (char *)malloc(S * sizeof(char));
                if (strWork)
                {
                    printf("\n");
                    dot(27);
                    printf("\n\n\t\t\t__| Результат 4 пункта меню |__\n\n");

                    strcpy(strWork, strBase);
                    if (strPalindrome(strWork) == 1)
                    {
                        printf(" [str1] ");
                        puts(strBase);
                        printf("\tСтрока является палиндромом.\n\n");
                    }
                    else
                    {
                        printf(" [str1] ");
                        puts(strBase);
                        printf("\tСтрока НЕ является палиндромом.\n\n");
                    }

                    strcpy(strWork, strPLat);
                    if (strPalindrome(strWork) == 1)
                    {
                        printf(" [str2] ");
                        puts(strPLat);
                        printf("\tСтрока является палиндромом.\n\n");
                    }
                    else
                    {
                        printf(" [str2] ");
                        puts(strPLat);
                        printf("\tСтрока НЕ является палиндромом.\n\n");
                    }

                    strcpy(strWork, strPCyr);
                    if (strPalindrome(strWork) == 1)
                    {
                        printf(" [str3] ");
                        puts(strPCyr);
                        printf("\tСтрока является палиндромом.\n\n");
                    }
                    else
                    {
                        printf(" [str3] ");
                        puts(strPCyr);
                        printf("\tСтрока НЕ является палиндромом.\n\n");
                    }

                    free(strWork);
                }
                else
                    printf("\n\tНет возможности выделить память под строку.\n");

                dotdot(81);
                printf("\n");
                tabs(11);
                printf("\n");
                equal(81);
                printf("\n\tY - Повторить пункт 4.");
                printf("\n     |  Q - Выход в Главное меню.\n     '->");
                repeat = getche();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 5:
            do
            {
                char str[S] = {'\0'}; // строка для ввода пользователем
                char ch;              // символ в строке

                printf("\n");
                dash(81);
                printf("\n\t\t      _______| Выбран 5 пункт меню |_______\n\n");

                do
                {
                    printf("\tВведите строку:\n");
                    printf(" [str]  ");
                    gets_s(str, S);

                    if (str[0] == '\0')
                        printf("\n");

                } while (str[0] == '\0');

                do
                {
                    printf("\n     |  Введите символ, для которого следует найти последнюю позицию в строке:");
                    printf("\n     '->");
                    ch = getchar();

                } while (ch == '\n');
                eatline();

                strWork = (char *)malloc(S * sizeof(char));
                if (strWork)
                {
                    printf("\n");
                    dot(27);
                    printf("\n\n\t\t\t__| Результат 5 пункта меню |__\n\n");

                    strcpy(strWork, str);

                    printf("\tВ строке:\n");
                    printf(" [str]  ");
                    puts(strWork);

                    if (endChStr(str, ch) != 0)
                    {
                        printf("\n\tПоследний искомый символ '%c' в строке,\n", ch);
                        printf("\tнаходится на позиции - %d (нумерация с единицы).\n", endChStr(str, ch));
                    }
                    else
                    {
                        printf("\n\tИскомый символ '%c' отсутствует в строке, для определения позиции.\n", ch);
                    }

                    free(strWork);
                }
                else
                    printf("\n\tНет возможности выделить память под строку.\n");

                printf("\n");
                dotdot(81);
                printf("\n");
                tabs(11);
                printf("\n");
                equal(81);
                printf("\n\tY - Повторить пункт 5.");
                printf("\n     |  Q - Выход в Главное меню.\n     '->");
                repeat = getche();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 6:
            printf("\n\t\t\t    ..........................");
            printf("\n\t\t\t    |     Всего хорошего     |");
            printf("\n\t\t\t    |         (^-^)/         |");
            printf("\n\t\t\t    ''''''''''''''''''''''''''\n");
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

    strWork = NULL;

    printf("\n");
    dotdot(81);
    printf("\n");
    tabs(11);
    printf("\n");
    equal(81);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

//============================= функции задания ================================================
//
// 1. Функция заменяет все символы точки " " в строке, на символы табуляции "\t".
char *changeCh(char *str)
{
    char *ph;
    while (true)
    {
        // поиск вхождения символа строку char * strchr( const char * string, int symbol);
        ph = strchr(str, ' ');
        if (ph != NULL)
        {
            *ph = '\t';
            str++;
        }
        else
            break;
    }

    return str;
}

// 2. Подсчет, количества букв, цифр и остальных символов в строке.
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

    printf("\n\tВ строке обнаружено следующие количество:");
    printf("\n\tЦифр   =  %d", digit);
    printf("\n\tЗнаков =  %d", sign);
    printf("\n\tЛатиницы  БОЛЬШЫX букв = %d", latBig);
    printf("\n\tЛатиницы    малых букв = %d", latSmall);
    printf("\n\tКириллицы БОЛЬШЫХ букв = %d", cyrBig);
    printf("\n\tКириллицы   малых букв = %d", cyrSmall);
    printf("\n");
}

// 3. Функция, определяет количество слов в введенном предложении.
void findWStrSet(char *str)
{
    char check[S * 2] = {'\0'}; //строка проверки для пропуска работы
    char cut[S * 2] = {'\0'};   //строка хранения резаных кусков рабочей строки
    char *pch;

    int sentences = 0; // количество предложений
    int cw = 0;        // количество слов в предложении
    int k = 0;         // позиция конца начала следующего реза строки
    int j = 0;         // позиция с которой начинать резать строки

    // Перебираем в цикле каждый символ рабочей строки
    for (int i = 0; i <= (int)strlen(str); i++)
    {
        // Ищем конец предложения (основные знаки конца предложения) включаем работу
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            k = i; // присваиваем позицию остановки

            //Если в конце предложения многоточие или !!! или ?? двигаем дальше (проброс)
            while (str[k] == ' ' || str[k] == '.' || str[k] == '!' ||
                   str[k] == '?' || str[k] == '\t' || str[k] == '\n')
                k++;

            strncpy(cut, &str[j], k - j);
            cut[k - j] = '\0';
            strcpy(check, cut);
            check[k - j] = '\0';

            if ((int)strlen(check) != 0)
            {
                sentences++;
                pch = strtok(cut, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/\t\n");
                while (pch != NULL)
                {
                    if (strlen(pch) > 1)
                        cw++;
                    pch = strtok(NULL, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/\t\n");
                }
                printf("\n\tВ %d предложении количество слов = %d\n", sentences, cw);
                printf("\t");
                puts(check);
            }

            j = k;  // получаем начала следующего копирования для str
            cw = 0; // сбрасываем подсчет слов

            cut[0] = '\0';   // передвинем в начало очистим строку и (можно убрать но...)
            check[0] = '\0'; // передвинем в начало очистим строку
        }
    }
}

// 4. Функция, определяет является ли строка палиндромом.
int strPalindrome(char *s)
{
    char *pch;
    char tmp[S] = {'\0'};
    char stick[S] = {'\0'}; //для склейки лексем формируем строку
    bool palindrome = true;

    strcpy(tmp, s);

    pch = strtok(tmp, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/\t\n");
    while (pch != NULL)
    {
        strcat(stick, pch);
        pch = strtok(NULL, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/\t\n");
    }

    // приведем все к одному регистру (верхнему)
    for (int i = 0; stick[i] != '\0'; i++)
    {
        if (stick[i] >= 'a' && stick[i] <= 'z')
            (stick[i] -= 'a' - 'A');
        if (stick[i] >= 'а' && stick[i] <= 'я')
            (stick[i] -= 'а' - 'А');
        if (stick[i] == 'ё')
            (stick[i] -= 'ё' - 'Ё');
    }

    // Перебираем в цикле символы и проверим равны или нет всей строки
    for (int i = 0, j = (int)strlen(stick) - 1; i < (int)strlen(stick); i++, j--)
        if (stick[i] != stick[j])
            palindrome = false;

    if (palindrome)
        return 1;
    else
        return 0;
}

// 5. Функция, определяет последний символ в строке (искомый пользователем).
int endChStr(char *str, char ch)
{
    // strrchr – поиск последнего вхождения символа в строку.
    // char *strrchr (char *str, int ch);
    char *pch;
    pch = strrchr(str, ch);
    if (pch != NULL)
        return pch - str + 1;
    else
        return 0;
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
        printf("|\t");
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
