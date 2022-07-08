// Вывести на экран фигуры заполненные звёздочками. Диалог с пользователем реализовать при помощи меню.

#include <windows.h>
#include <stdio.h>
#include <conio.h> // в этом файле содержится функция getch()

void dash1(int);
void dash2(int);

void dash1(int count = 20)
{
    int i;
    for (i = 0; i < count; i++)
        printf("-");
    printf("\n");
}
void dash2(int count = 20)
{
    int i;
    for (i = 0; i < count; i++)
        printf("-");
}

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool prodolgenie = true;
    int chislo_menu = 0;
    int sposob_vvoda = 0;

    do
    {
        system("cls");
        printf(" ***| Программа с рисунками | ***\n\n"
               "  1:Рисунок--> a\n");
        printf("  2:Рисунок--> б\n");
        printf("  3:Рисунок--> в\n");
        printf("  4:Рисунок--> г\n");
        printf("  5:Рисунок--> д\n");
        printf("  6:Рисунок--> е\n");
        printf("  7:Рисунок--> ж\n");
        printf("  8:Рисунок--> з\n");
        printf("  9:Рисунок--> и\n");
        printf(" 10:Рисунок--> к\n");
        printf(" 11:| ВыхоД |\n\n>");
        scanf("%d", &chislo_menu);
        switch (chislo_menu)
        {

        case 1:
            dash1();
            for (int i = 20; i > 0; i--)
            {
                for (int j = 0; j < 20; j++)
                {
                    if (j < 20 - i)
                        printf(" ");
                    else
                        printf("*");
                }
                printf("\n");
            }
            dash1();

            printf(" \nДля продолжения-ENTER.");
            getch();
            break;

        case 2:
            dash2();
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (i == 0)
                    {
                        break;
                    }
                    printf("*");
                }
                printf("\n");
            }
            dash2();

            printf(" \nДля продолжения-ENTER.");
            getch();
            break;

        case 3:
            dash1();
            for (int a = 19, j = 0; j != 19; ++j, a -= 2)
            {
                for (int i = 0; i < j; ++i)
                {
                    printf(" ");
                }
                for (int i = 0; i < a; ++i)
                {
                    printf("*");
                }
                puts("");
            }
            dash1();

            printf(" \nДля продолжения-ENTER.");
            getch();
            break;

        case 4:
            dash1();
            for (int a = 2, j = 19; j != 0; --j, a += 2)
            {
                for (int i = 1; i < j; ++i)
                {
                    printf(" ");
                }
                for (int i = 19; i < a; ++i)
                {
                    printf("*");
                }
                puts("");
            }
            dash1();

            printf(" \nДля продолжения-ENTER.");
            getch();
            break;

        case 5:
            dash1();
            for (int a = 19, j = 1; j != 10; ++j, a -= 2)
            {
                for (int i = 1; i < j; ++i)
                {
                    printf(" ");
                }
                for (int i = 0; i < a; ++i)
                {
                    printf("*");
                }
                puts("");
            }
            for (int a = 1, j = 10; j != 0; --j, a += 2)
            {
                for (int i = 1; i < j; ++i)
                {
                    printf(" ");
                }
                for (int i = 0; i < a; ++i)
                {
                    printf("*");
                }
                puts("");
            }
            dash1();

            printf(" \nДля продолжения-ENTER.");
            getch();
            break;

        case 6:
            printf("---------------------");
            for (int y = 0; y <= 19; y++)
            {

                for (int x = 0; x <= 20; x++)
                {
                    if (y <= x && (y <= 20 - x) || (y >= 20 - x) && y >= x)
                    {
                        printf(" ");
                    }
                    else
                    {
                        printf("*");
                    }
                }
                printf("\n");
            }
            printf("---------------------");

            printf(" \nДля продолжения-ENTER.");
            getch();
            break;

        case 7:
            dash2();
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (i == 0)
                    {
                        break;
                    }
                    printf("*");
                }
                printf("\n");
            }
            for (int y = 1; y <= 10; y++)
            {
                for (int x = 1; x <= 10; x++)
                {
                    if (x >= y)
                        printf("*");
                }
                puts("");
            }
            dash1();

            printf(" \nДля продолжения-ENTER.");
            getch();
            break;

        case 8:
            dash1();
            for (int i = 0; i < 10; i++)
            {
                for (int j = 1; j < 21; j++)
                {
                    if (j < 20 - i)
                        printf(" ");
                    else
                        printf("*");
                }
                printf("\n");
            }
            for (int i = 9; i > 0; i--)
            {
                for (int j = 1; j < 21; j++)
                {
                    if (j < 21 - i)
                        printf(" ");
                    else
                        printf("*");
                }
                printf("\n");
            }
            dash1();

            printf(" \nДля продолжения-ENTER.");
            getch();
            break;

        case 9:
            dash1();
            for (int y = 1; y <= 19; y++)
            {
                for (int x = 1; x <= 19; x++)
                {
                    if (x >= y)
                        printf("*");
                }
                puts("");
            }
            dash1();

            printf(" \nДля продолжения-ENTER.");
            getch();
            break;

        case 10:
            dash2();
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    if (j < 20 - i)
                        printf(" ");
                    else
                        printf("*");
                }
                printf("\n");
            }
            dash1();

            printf(" \nДля продолжения-ENTER.");
            getch();
            break;

        case 11:
            prodolgenie = false;
            break;
        default:
            printf(" Неверный пункт меню. Будьте внимательны!!!\n");
            printf(" Для продолжения-ENTER.");
            getch();
            break;
        }
    } while (prodolgenie);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}
