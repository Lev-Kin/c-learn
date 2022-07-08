
// Ввести строку с клавиатуры. В строке не менее 5 слов.
// Под словом следует понимать последовательность из любых символов кроме
// пробела, точки и точки с запятой. Слова разделены 1 пробелом.
// Из заданной строки удалить все цифры, подсчитать количество и
// сумму удаленных цифр, заменить все заглавные латинские буквы на строчные.

#include <windows.h>
#include <stdio.h>
#include <conio.h>  // в этом файле содержится функция getch()
#include <string.h> // strlen() - кол-во посимвольно, strtok() - разбиение на лексемы
#include <ctype.h>  // функция преобразования регистра toupper

int main(void);
void dash(int);

int words(char[]);
int words_min(char[]);
void operation_digit(char[]);
void toUPper(char *);
void delete_digit(char[]);

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char str[81];
    char repeat;
    char replay;
    do
    {
        system("cls");
        printf(" ***| Программа работы над строками |***\n");

        dash(70);
        do
        {
            printf("\n Введите строку не менее 5 слов.\n\n>");
            gets_s(str, 81);

            // В строке не меньше 5 слов.
            // Слово - не ( .,)(последовательность из любых символов) более 2x символов.(Ac. Ум. Юг)
            if (words(str) < 5)
            {
                printf("\n Условие не выполнено. Вы вели менее 5 слов  | !!! |");
                printf("\n Слово - не ( .,) и более 2x символов (Юг Ёж)| !!! |");
                printf("\n Повторите - ENTER >");
                replay = getchar();
            }
            else
            {
                printf("\n Вы вели %d слов, условие выполнено | OK |", words(str));
                printf("\n Минимальная длина из %d слов состоит из %d символов | OK |", words(str), words_min(str));
                printf("\n\n");
            }
        } while (words(str) < 5);

        dash(70);

        printf("\n Исходная строка:\n");
        printf(" %s\n\n", str);

        operation_digit(str);
        toUPper(str);

        printf("\n Обработанная строка:\n ");
        delete_digit(str);

        printf("\n Y - Продолжить.");
        printf("\n Q - Выход.\n\n");
        repeat = getch();
    } while (repeat == 'y' || repeat == 'Y');

    printf("\n ___|  Всего хорошего  |___");
    printf("\n ___|      (^-^)/      |___\n\n\a");

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void dash(int count)
{
    int i;
    for (i = 0; i < count; i++)
        printf("-");
}

// Подсчет количества слов
int words(char str[])
{
    int word = 0;
    for (int i = 0; str[i] != 0; i++)
    { // Посимвольный просмотр строки

        if ((str[i] != ' ' && str[i] != '.' && str[i] != ';') && ((i == 0 || str[i - 1] == ' ' || str[i - 1] == '.' || str[i - 1] == ';')))
            word++;

        /* начало слова - не пробел, не точка, не точка с запятой  начало строки или впереди( .;)
        if ((str[i] != ' ' && str[i] != '.' && str[i] != ';')
            && ((str[i+1] == 0 || str[i + 1] == ' ' || str[i + 1] == '.' || str[i + 1] == ';'))) word++;
           конец  слова - не пробел, не точка, не точка с запятой, далее - конец строки или ( .;)*/

        /*if (str[i] != ' ') k = k + 1;
       else
       {
           // отнимаем слова если меньше 2х символов
           if (k < min) min = k;
           if (min <= 1) word--;
           k = 0;*/
    }
    return word;
}

int words_min(char str[]) // Минимальная длина слова = 2 (последовательность из символов)
{
    int min = 81;
    int k = 0;

    for (int i = 0; i < strlen(str) && str[i] != 0; i++)
    {
        if (str[i] != ' ')
            k = k + 1;
        else
        {
            if (k < min)
                min = k;
            k = 0;
        }

        if (min == 1)
            min++;
    }
    return min;
}

void operation_digit(char str[])
{
    unsigned int i, k = 0, sum = 0;
    {
        for (i = 0; i < strlen(str); i++)
        {
            if (((str[i] >= '0' && str[i] <= '9')) != '\0')
            {
                k++;
                sum += (str[i] - '0');
            }
        }
    }
    printf(" Кол-во цифр в строке = %d.\n", k);
    printf(" Сумма  цифр в строке = %d.\n", sum);
}

void toUPper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void delete_digit(char str[])
{
    char *pch = strtok(str, "0123456789.;"); // во втором параметре указаны разделители
    while (pch != NULL)                      // пока есть лексемы
    {
        printf("%s", pch);
        pch = strtok(NULL, "0123456789.;");
    }
    printf("\n");
}
