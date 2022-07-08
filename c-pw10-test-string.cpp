
// Ввести с клавиатуры текст, состоящий из строк. Строк не менее 3.
// В строке не менее 5 слов.
// Словом считать набор алфавитно-цифровых символов не менее одного.
// Слова разделены одним пробелом. Все слова палиндромы заменить словом “палиндром”.
// Программа должна выполнять ввод текста, вывод его исходного варианта, выполнять
// необходимые действия и выводить требуемый результат.

#include <windows.h>
#include <iostream>
#include <conio.h>   // getch()
#include <stdbool.h> // true и false

#define SIZE 81 /* предельная длина строки, включая \0*/
#define LIM 10  /* максимальное количество вводимых строк */
#define STOP "" /* нулевая строка для прекращения ввода */

using namespace std;
int main(void);

//////////////////////////////// функции работы со строками //////////////////////

int isPalindrom(char *);
// bool isPalindrom(char*);

//////////////////////////////// функции дополнительные //////////////////////////

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

    int work_or_test = 0;

    system("cls");
    equal(75);
    cout << endl;
    cout << " ***| Программа обработки текста |***" << endl
         << endl;
    cout << "  Сделайте выбор:" << endl;
    cout << " 1:ПУСК программы." << endl; // работа в программе согласно условия
    cout << " 2:ТЕСТ программы." << endl; // тест программы вывод на экран всех условий
    cout << " 3: __| ВЫХОД |__" << endl;
    do
    {
        cout << endl
             << " Выбор > ";
        cin >> work_or_test;

        if (work_or_test != 1 && work_or_test != 2 && work_or_test != 3)
        {
            cout << endl
                 << " Некорректный ввод (Выбор = 3 -выход).";
            cout << endl
                 << " Пожалуйста сделайте выбор.";
        }

    } while (work_or_test != 1 && work_or_test != 2 && work_or_test != 3);

    // ============================== пуск программы ====================================================

    if (work_or_test == 1)
    {
        system("cls");
        equal(75);
        cout << endl;
        cout << " ***| Программа обработки текста |***" << endl
             << endl;

        char str[SIZE];       // строка для обработки вводимая пользователем
        char buf[SIZE];       // строку в буфер до обработки
        char tmp[SIZE];       // рабочая строка для палиндромов
        char text[LIM][SIZE]; // строки в двумерный массив если прошли обработку

        int word = 0; // кол-во слов
        int cst = 0;  // счетчик строк
        int min;      // min длина слова
        int q;        // на начало строки для копирования

        char *pch; // для strtok
        char *w;   // выделяемое слово
        char *p;   // указатель на начало слова

        bool exit; // проверка хватает кол-во слов

        cout << " Условие: строк не менее 3, слов не менее 5," << endl
             << "          слово набор алфавитно-цифровых символов не менее одного." << endl
             << endl;
        cout << " Вводите строки и они будут обработаны." << endl;
        cout << " По завершению ввода строк нажмите <ENTER> в пустой строке." << endl
             << endl;
        eatline();
        do
        {
            exit = false;
            cout << " " << cst << " строка:";
            while (gets_s(str, SIZE) != NULL && strcmp(str, STOP) != 0 && cst != LIM)
            {
                buf[0] = '\0';    // помечаем буфер как пустую строку, либо char buf[81] = "";
                strcpy(buf, str); // копируем сразу введенную строку

                pch = &str[0]; // на начало строки
                min = 81;      // min есть вся строка

                // спец знаки (оставить алфавитно цифровые) корректируем
                pch = strtok(str, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/");
                while (pch != NULL) // пока есть лексемы
                {
                    word++; //добавляем слова

                    if (strlen(pch) < min) // минимальная длина слова
                    {
                        min = strlen(pch);
                        if (min == 1)
                            min++;
                    }

                    if (strlen(pch) <= 1) // не менее одного алфавитно цифрового
                    {
                        word--; // удаление не слов
                    }

                    pch = strtok(NULL, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/");
                }

                if (min == 81)
                    min = strlen(str);
                if (word == 0)
                    min = 0;

                cout << " В " << cst << " строке: " << word << " слов, min длина слова равна " << min << "." << endl;

                dot(15);
                if (word >= 5)
                    cout << "|ok|";
                cout << endl
                     << endl;

                if (word < 5)
                {
                    exit = false;
                    cout << " СЛОВ не достаточно для выполнения условия." << endl;

                    dash(10);
                    cout << endl
                         << endl;

                    cout << " " << cst << " строка:";
                }
                else
                {
                    // если все ok копируем буферную строку в двумерный массив
                    q = 0; // старт копирования
                    strcpy(&text[cst][q], buf);

                    exit = true; // разрешаем выход по пустой строке
                    cst++;       // увеличить счетчик строк
                    cout << " " << cst << " строка:";
                }

                word = 0; // сброс слов
                min = 0;  // сброс min слова
            }

            if (cst < 3)
            {
                cout << " СТРОК не достаточно для выполнения условия." << endl;
                dash(10);
                cout << endl
                     << endl;
            }

            if (cst >= 3 && exit == false)
            {
                cout << " СТРОК достаточно |ok|." << endl;
                cout << " Чтобы завершить ввод строк:" << endl;
                cout << " В строке введите не менее 5 слов." << endl;
                cout << " И нажмите <ENTER> в пустой строке." << endl;
                dash(10);
                cout << endl
                     << endl;
            }

        } while (cst < 3 || exit == false);

        cout << endl;
        dash(75);
        cout << endl;

        cout << endl
             << " Исходный текст:" << endl
             << endl;
        for (int i = 0; i < cst; i++)
        {
            cout << " " << text[i] << endl;
        }

        cout << endl;
        dot(25);
        cout << endl;

        cout << endl
             << " Заменяем все слова палиндромы на 'П'" << endl
             << endl;
        for (int i = 0; i < cst; i++)
        {
            p = 0;
            w = 0;
            tmp[0] = '\0'; // помечаем буфер как пустую строку, либо char tmp[81] = "";

            cout << " [" << i << " ст] ";
            strcpy(tmp, text[i]);                               // копируем строку в рабочий массив
            w = strtok(tmp, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/"); // выделяем первое слово в рабочей строке

            // цикл обработки слов в рабочей строке
            while (w)
            {
                if (isPalindrom(w)) // если слово - палиндром
                {
                    p = strstr(text[i], w);   // находим его в исходной строке
                    strcpy(p, p + strlen(w)); // удаляем палиндром и вернем строку
                    cout << " 'П' ";
                }
                else
                {
                    cout << w;
                }

                // выделяем следующее слово в рабочей строке
                w = strtok(NULL, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/");
            }
            cout << endl;
        }
        cout << endl;
        dot(25);
        cout << endl;

        cout << endl
             << " Удаляем все палиндромы в тексте" << endl
             << endl;
        for (int i = 0; i < cst; i++)
        {
            cout << " [" << i << " ст] " << text[i] << endl;
        }
    }

    // ============================== тест программы ====================================================

    if (work_or_test == 2)
    {
        system("cls");
        equal(75);
        cout << endl;
        cout << "____________________________| ТЕСТ программы |_____________________________" << endl;
        dash(75);

        int cst = 5;    // количество строк
        char *w;        // выделяемое слово
        char *p;        // указатель на начало слова
        char tmp[SIZE]; // временная рабочая строка (буфер)
        char text[LIM][SIZE] = {
            {"44 Numbers - 11, 42, 000, 111, 4242, 4224, 55, 5555, (55 15), 020 [28 88]."},
            {"zz Letters - level, nope, eye, civic, moon, wow, radar, gray, stats, ok."},
            {"aa Буквы - дед, он, как, кабак, там, шалаш"},
            {"TT Микс - exe Срт TexxeT ABBA mix soLos 11ТссТ11 tuu44uut fin."},
            {"gg ЯЯ world! ага Впереди, мадам земля! оно YES мир"},
        };

        cout << endl
             << " Исходный текст:" << endl
             << endl;
        for (int i = 0; i < cst; i++)
        {
            cout << " " << text[i] << endl;
        }

        cout << endl;
        dot(25);
        cout << endl;

        cout << endl
             << " Заменяем все слова палиндромы на 'П'" << endl
             << endl;
        for (int i = 0; i < cst; i++)
        {
            p = 0;
            w = 0;
            tmp[0] = '\0'; // помечаем буфер как пустую строку, либо char tmp[81] = "";

            cout << " [" << i << " ст] ";
            strcpy(tmp, text[i]);                               // копируем строку в рабочий массив
            w = strtok(tmp, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/"); // выделяем первое слово в рабочей строке

            // цикл обработки слов в рабочей строке
            while (w)
            {
                if (isPalindrom(w)) // если слово - палиндром
                {
                    p = strstr(text[i], w);   // находим его в исходной строке
                    strcpy(p, p + strlen(w)); // удаляем палиндром и вернем строку
                    cout << " 'П' ";
                }
                else
                {
                    cout << w;
                }

                // выделяем следующее слово в рабочей строке
                w = strtok(NULL, " .,;|`~!@#$%^&*()_-+={}[]:'<>?/");
            }
            cout << endl;
        }
        cout << endl;
        dot(25);
        cout << endl;

        cout << endl
             << " Удаляем все палиндромы в тексте" << endl
             << endl;
        for (int i = 0; i < cst; i++)
        {
            cout << " [" << i << " ст] " << text[i] << endl;
        }
    }

    cout << endl;
    dash(75);
    cout << endl
         << endl;
    cout << "   ...................." << endl;
    cout << "   |  sum summus mus  |" << endl;
    cout << "   |      (^-^)/      |" << endl;
    cout << "   |  всего хорошего  |" << endl;
    cout << "   ````````````````````" << endl
         << endl;

    equal(75);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

//============================= функции вспомогательные =========================================
//
void dash(int count)
{
    for (int i = 0; i < count; i++)
        cout << "-";
}
void dot(int count)
{
    for (int i = 0; i < count; i++)
        cout << " . ";
}
void equal(int count)
{
    for (int i = 0; i < count; i++)
        cout << "=";
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

//============================= функции работы со строками =========================================
//
// определение палиндрома
int isPalindrom(char *w)
{
    int beg = 0;             // начало слова
    int end = strlen(w) - 1; // конец  слова
    if (end == 0)
        end = 1; // не равен 1 символу
    while (beg < end)
        if (w[beg++] != w[end--])
            return 0; // не палиндром

    return 1; // палиндром
}

/*
bool isPalindrom(char* w)
{
    char* p = strdup(w);
    int   cmp = strcmp(w, strrev(p));
    free(p);
    return (cmp ? false : true);
}
*/
