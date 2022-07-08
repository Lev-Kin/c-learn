// Обеспечить выполнение следующих действий:
// ввод информации в файл;
// корректировка содержимого файла;
// редактирование указанной записи;
// пометка записей на удаление (логическое удаление);
// удаление записей с диска (физическое удаление);
// восстановление записей (логически удаленных);
// вставку записи в начало файла;
// вставку после (перед) указанной записью;
// просмотр записей
// всего файла;
// с указанной записи до начала файла;
// с указанной записи до конца файла;
// поиск необходимой информации;
// вывод содержимого файла на экран;
// Отладку программы производить с самостоятельно выбираемым набором
// данных. Число записей в файле - не менее 20. Поиск организовать по совпадению.

#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

///////////////////////////////////// функции ввода вывода ////////////////////////////////

void input_rec(int);
void tableUp(void);
void tableMiddle(void);
void tableDown(void);
void lineDateInTab(struct rec_base *rea, int pos);

///////////////////////////////////// функции работы с файлом /////////////////////////////

unsigned int get_rec_count(FILE *base);
int insert_record(FILE *base, struct rec_base *rea, unsigned ins_pos, enum ins_mode mode);
int read_rec(FILE *base, unsigned int pos);
int remote_reset(FILE *base);
void remote_repair(FILE *base);
void write_rec(FILE *base, unsigned int pos, struct rec_base *rea);

///////////////////////////////////// функции вспомогательные /////////////////////////////

void pause_final(enum pf_mode mode);
char *gets_s(char *, size_t);

//////////////////////////////////////////////////////////////////////////////////////////

void dash(int);
void dot(int);
void dotdot(int);
void equal(int);
void tabs(int);
void apostrophe(int);
void underscore(int);
void eatline(void);

//////////////////////////////////////////////////////////////////////////////////////////

enum pf_mode
{
    pf_pause,
    pf_cls
};
enum rec_st
{
    st_normal,
    st_deleted
};
enum ins_mode
{
    in_before,
    in_after
};

struct rec_base
{
    char firm[40];
    char surname[25];
    int birth;
    float result;
    int place;
};

const int RECORD_S = sizeof(struct rec_base);
struct rec_base **inp_1;
struct rec_base *inp_zap;

int main(void)
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE *base;

    int read_c;
    int work;
    int rea;
    int i = 0;
    int count;

    int main_menu;
    int add_menu = -1;
    int option;

    //=======================================================================================
    equal(80);
    printf("\n");
    tabs(9);
    printf("\n");
    apostrophe(80);
    printf("\n");
    inp_1 = (struct rec_base **)calloc(1, sizeof(struct rec_base *));
    base = fopen("Протокол соревнований.dat", "r+b");
    if (base == NULL)
    {
        base = fopen("Протокол соревнований.dat", "w+b");
        fclose(base);

        base = fopen("Протокол соревнований.dat", "r+b");
        printf("\n\tБаза данных создана. Записей в ней нет.\n");
    }
    else
    {
        read_c = read_rec(base, i);
        if (read_c)
            printf("\n\tБаза данных уже существует. В ней имеются записи.\n");
        else
        {
            printf("\n\tБаза данных уже существует. Записей в ней нет.\n");
        }
    }
    printf("\n");
    dotdot(80);
    printf("\n");
    tabs(9);
    printf("\n");
    equal(80);
    printf("\n\tДля продолжения нажмите-<ENTER>");
    getch();
    //=======================================================================================

    do
    {
        system("cls");
        equal(80);
        printf("\n");
        tabs(9);
        printf("\n");
        apostrophe(80);
        printf("\n");
        printf("\t   ***| Работа с файлами на уровне потокового ввода-вывода |***\n\n");
        printf("\t________________________| Главное меню |________________________________\n");
        printf("\t   Выберите ПУНКТ меню работы подменю:\n");
        printf("\t-----------------------------------------\n");
        printf("\t1) Ввод информации в базу данных (добавление в конец базы).\n");
        printf("\t2) Просмотр записей.\n");
        printf("\t3) Корректировка содержимого файла.\n");
        printf("\t4) Выборка по фамилии.\n");
        printf("\t5)   | ВыхоД |\n");
        printf("     |\n     '->");
        main_menu = 0;
        scanf("%d", &main_menu);
        eatline();
        switch (main_menu)
        {
        case 1: //ввод информации в базу данных
        {
            count = 0;
            printf("\n");
            dash(80);
            printf("\n\t\t      _______| Выбран 1 пункт меню |_______\n\n");
            printf("\t1) Ввести записи в базу данных (добавить).\n");
            printf("\t2)  | Отмена |"); // оставить как есть

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
                    printf("\n");
                    dot(26);
                    printf("\n");

                    fseek(base, 0, SEEK_END);
                    count++;
                    input_rec(count);

                    printf("\t");
                    dotdot(31);
                    printf("\n\tБудете ещё вводить информацию?:");
                    printf("\n\tДа-1, Нет-0:");
                    printf("\n     |\n     '->");
                    scanf("%d", &work);
                    eatline();
                } while (work == 1);

                for (i = 0; i < count; i++)
                    fwrite(inp_1[i], RECORD_S, 1, base);

                fflush(base);

                for (i = 0; i < count; i++)
                    free(inp_1[i]);
            }
        }
        break;

        case 2: // просмотр записей
        {
            do
            {
                printf("\n");
                dash(80);
                printf("\n\t\t      _______| Выбран 2 пункт меню |_______\n\n");
                printf("\t   Выберите вариант работы подпрограммы:\n");
                printf("\t---------------------------------------------\n");
                printf("\t   Просмотр записей ...\n");
                printf("\t1) ...всего файла.\n");
                printf("\t2) ...с указанной записи и до начала файла.\n");
                printf("\t3) ...с указанной записи и до конца файла.\n");
                printf("\t4)  | Возврат в Главное меню |");
                add_menu = 0;
                printf("\n     |\n     '->");
                scanf("%d", &add_menu);
                eatline();
                printf("\n");
                dot(26);
                printf("\n\n");
                switch (add_menu)
                {
                case 1:
                {
                    printf("\t\t\t    ___| Выбран 1 Вариант |___\n\n");
                    tableUp();
                    tableMiddle();
                    i = 0;
                    rea = read_rec(base, i);
                    while (rea)
                    {
                        lineDateInTab(inp_zap, i + 1);
                        i++;
                        free(inp_zap);

                        rea = read_rec(base, i);
                        if (rea)
                            tableMiddle();
                    }
                    tableDown();
                }
                break;

                case 2:
                {
                    unsigned int pos;
                    printf("\t\t\t    ___| Выбран 2 Вариант |___\n\n");
                    printf("\tВведите позицию:");
                    printf("\n     |\n     '->");
                    scanf("%d", &pos);
                    eatline();
                    if (pos > 0 && pos <= get_rec_count(base))
                    {
                        printf("\n");
                        dot(26);
                        printf("\n\n");
                        tableUp();
                        tableMiddle();
                        for (i = 0; i < (int)pos; i++)
                        {
                            read_c = read_rec(base, i);
                            lineDateInTab(inp_zap, i + 1);
                            free(inp_zap); //освобождение после удачного чтения

                            if (i < (int)pos - 1)
                                tableMiddle();
                        }
                        tableDown();
                    }
                    else
                        printf("\n\tОшибка: некорректный ввод позиции.");
                }
                break;

                case 3:
                {
                    int pos;
                    printf("\t\t\t    ___| Выбран 3 Вариант |___\n\n");
                    printf("\tВведите позицию:");
                    printf("\n     |\n     '->");
                    scanf("%d", &pos);
                    eatline();
                    int rec_count = get_rec_count(base);
                    if (pos > 0 && pos <= rec_count)
                    {
                        printf("\n");
                        dot(26);
                        printf("\n\n");
                        tableUp();
                        tableMiddle();
                        for (i = pos - 1; i < rec_count; i++)
                        {
                            read_c = read_rec(base, i);
                            lineDateInTab(inp_zap, i + 1);
                            free(inp_zap); //освобождение после удачного чтения

                            if (i < rec_count - 1)
                                tableMiddle();
                        }
                        tableDown();
                    }
                    else
                        printf("\n\tОшибка: некорректный ввод позиции.");
                }
                break;

                case 4:
                    break;

                default:
                    printf("\tОшибка: некорректный ввод варианта работы.");
                }

                if (add_menu != 4)
                    pause_final(pf_pause);
                else
                    pause_final(pf_cls);

            } while (add_menu != 4);

            add_menu = -1;
        }
        break;

        case 3: // корректировка содержимого в базе данных
        {
            do
            {
                printf("\n");
                dash(80);
                printf("\n\t\t      _______| Выбран 3 пункт меню |_______\n\n");
                printf("\t   Выберите вариант работы подменю:\n");
                printf("\t--------------------------------------\n");
                printf("\t1) Редактирование указанной записи.\n");
                printf("\t2) Пометка записи на удаление (логическое удаление).\n");
                printf("\t3) Удаление записей с диска (физическое удаление).\n");
                printf("\t4) Восстановление записей (логически удаленных).\n");
                printf("\t5) Вставка записи в начало файла.\n");
                printf("\t6) Вставка после (перед) указанной записью.\n");
                printf("\t7)  | Возврат в Главное меню |");
                add_menu = 0;
                printf("\n     |\n     '->");
                scanf("%d", &add_menu);
                eatline();
                printf("\n");
                dot(26);
                printf("\n\n");
                switch (add_menu)
                {
                case 1:
                {
                    unsigned int pos;
                    printf("\t\t\t    ___| Выбран 1 Вариант |___\n\n");
                    printf("\tВведите позицию редактируемой записи:");
                    printf("\n     |\n     '->");
                    scanf("%d", &pos);
                    eatline();
                    if (pos > 0 && pos <= get_rec_count(base))
                    {
                        read_c = read_rec(base, pos - 1);
                        if (inp_zap->surname[0] != '#')
                        {
                            printf("\n");
                            dot(26);
                            printf("\n\n");
                            printf("\tКорректируем выбранную запись.\n");
                            tableUp();
                            tableMiddle();
                            lineDateInTab(inp_zap, pos);
                            free(inp_zap); //освобождение после удачного чтения
                            tableDown();
                            input_rec(1);
                            write_rec(base, pos - 1, inp_1[0]);
                        }
                        else
                            printf("\n\tВыбранная запись не может быть отредактирована,\n\tт.к. помечена на удаление.\n");
                    }
                    else
                        printf("\n\tОшибка: некорректный ввод позиции.");
                }
                break;

                case 2:
                {
                    unsigned int pos;
                    char buf[40];
                    printf("\t\t\t    ___| Выбран 2 Вариант |___\n\n");
                    printf("\tВведите позицию записи которую желаете пометить на удаление:");
                    printf("\n     |\n     '->");
                    scanf("%d", &pos);
                    eatline();
                    if (pos > 0 && pos <= get_rec_count(base))
                    {
                        read_c = read_rec(base, pos - 1);
                        if (inp_zap->surname[0] != '#')
                        {
                            printf("\n");
                            dot(26);
                            printf("\n\n");
                            printf("\tКорректируем выбранную запись.\n");
                            tableUp();
                            tableMiddle();
                            lineDateInTab(inp_zap, pos);
                            tableDown();
                            //добавлям в начало имени зарезервированный символ # для отметки о логическом удалении
                            strcpy(buf, inp_zap->surname);
                            inp_zap->surname[0] = '#';
                            strcpy(inp_zap->surname + 1, buf);
                            //запись в файл
                            write_rec(base, pos - 1, inp_zap);
                            printf("\n\tЛогическое удаление успешно проведено.\n");
                        }
                        else
                            printf("\n\tВыбранная запись не может быть отредактирована,\n\tт.к. помечена на удаление.\n");

                        free(inp_zap); //освобождение
                    }
                    else
                        printf("\n\tОшибка: некорректный ввод позиции.");
                }
                break;

                case 3:
                {
                    char ch;
                    printf("\t\t\t    ___| Выбран 3 Вариант |___\n\n");
                    printf("\tВы уверены, что хотите >>>>ФИЗИЧЕСКИ УДАЛИТЬ<<<< помеченные записи?");
                    printf("\n\ty - Да.");
                    printf("\n     |  n - Нет.\n     '->");
                    ch = getchar();
                    if (ch == 'y' || ch == 'Y')
                    {
                        printf("\n");
                        dot(26);
                        printf("\n\n");

                        if (remote_reset(base))
                            printf("\tФизическое удаление записей успешно завершено.\n");
                        else
                            printf("\tНа каком-то этапе работы с файлом произошел сбой.\n");
                    }
                }
                break;

                case 4:
                {
                    printf("\t\t\t    ___| Выбран 4 Вариант |___\n\n");
                    remote_repair(base);
                    printf("\tВосстановление помеченных к удалению записей произведено.\n");
                }
                break;

                case 5:
                {
                    printf("\t\t\t    ___| Выбран 5 Вариант |___\n");
                    input_rec(1);

                    if (insert_record(base, inp_1[0], 0, in_before))
                        printf("\n\tВставка записи в начало файла произведена успешно.\n");
                    else
                        printf("\n\tНа каком-то этапе работы с файлом произошел сбой.\n");
                }
                break;

                case 6:
                {
                    unsigned int pos;
                    printf("\t\t\t    ___| Выбран 6 Вариант |___\n\n");
                    printf("\tВведите позицию записи возле которой желаете произвести вставку\n\tновой записи:");
                    printf("\n     |\n     '->");
                    scanf("%d", &pos);
                    eatline();
                    if (pos > 0 && pos <= get_rec_count(base))
                    {
                        enum ins_mode mode = in_before;
                        printf("\n\tВведите режим вставки:\n");
                        printf("\tПеред записью - 0, После записи - 1");
                        printf("\n     |\n     '->");
                        scanf("%d", &mode);
                        eatline();
                        if (mode == in_before || mode == in_after)
                        {
                            printf("\n");
                            dot(26);
                            printf("\n\n");

                            input_rec(1);

                            if (insert_record(base, inp_1[0], pos - 1, mode))
                                printf("\n\tВставка записи произведена успешно.\n");
                            else
                                printf("\n\tНа каком-то этапе работы с файлом произошел сбой.\n");
                        }
                        else
                            printf("\n\tОшибка: некорректный ввод режима вставки.");
                    }
                    else
                        printf("\n\tОшибка: некорректный ввод позиции.");
                }
                break;

                case 7:
                    break;

                default:
                    printf("\tОшибка: некорректный ввод варианта работы.");
                }

                if (add_menu != 7)
                    pause_final(pf_pause);
                else
                    pause_final(pf_cls);

            } while (add_menu != 7);

            add_menu = -1;
        }
        break;

        case 4: // поиск информации по фамилии
        {
            char s[25];
            unsigned int count_r = get_rec_count(base);
            printf("\n");
            dash(80);
            printf("\n\t\t      _______| Выбран 4 пункт меню |_______\n\n");
            printf("\t1) Произвести поиск по фамилии (в базе данных).\n");
            printf("\t2)  | Отмена |"); // оставить как есть

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

            printf("\n");
            dot(26);
            printf("\n\n");

            if (option == 1)
            {
                printf("\tВведите фамилию как фильтр: \n");
                do
                {
                    printf("\tФамилия: ");
                    gets_s(s, 25);

                } while (s[0] == '\0' || (int)strlen(s) > 20);

                printf("\n");
                dot(26);
                printf("\n\n");

                tableUp();
                for (i = 0; i < (int)count_r; i++)
                {
                    read_c = read_rec(base, i);
                    if (!strcmp(s, inp_zap->surname))
                    {
                        if (i != (int)count_r - 1)
                            tableMiddle();
                        lineDateInTab(inp_zap, i + 1);
                    }
                }
                tableDown();

                free(inp_zap); //освобождение после удачного чтения

                printf("\n");
                dotdot(80);
                printf("\n");
                tabs(9);
                printf("\n");
                equal(80);
                printf("\n\tДля продолжения нажмите-<ENTER>");
                getch();
            }
        }
        break;

        case 5:
            break;

        default:
        {
            printf("\n\tОшибка: некорректный ввод ПУНКТА меню работы.");
            pause_final(pf_pause);
        }
        }

        if (main_menu != 5 && add_menu != -1)
            pause_final(pf_pause);
        else
            pause_final(pf_cls);

    } while (main_menu != 5);

    free(inp_1);
    fclose(base);

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

//=================================== ввод вывод ==================================================
//
void input_rec(int count_rec)
{
    int i = 0;
    if (count_rec == 1)
    {
        inp_1[i] = (struct rec_base *)calloc(1, RECORD_S);
    }
    else
    {
        i = count_rec - 1;
        inp_1[i] = (struct rec_base *)calloc(1, RECORD_S);
    }
    if (inp_1[i])
    {
        printf("\n\t===  Вводим запись  ===\n\n");

        // защита ввода организация
        do
        {
            printf("\t1. Организация: ");
            gets_s(inp_1[i]->firm, 40);

        } while (inp_1[i]->firm[0] == '\0' || (int)strlen(inp_1[i]->firm) > 30);

        // защита ввода фамилия
        do
        {
            printf("\t2. Фамилия: ");
            gets_s(inp_1[i]->surname, 25);

        } while (inp_1[i]->surname[0] == '\0' || (int)strlen(inp_1[i]->surname) > 20);

        // защита ввода год рождения
        do
        {
            while (1)
            {
                char ch = 0;
                printf("\t3. Год рождения: ");

                if (!scanf_s("%d", &inp_1[i]->birth) || getchar() != '\n')
                {
                    while ((ch = getchar()) != '\n' && ch != EOF)
                        ;
                }
                else
                    break;
            }

        } while (inp_1[i]->birth >= 2021 || inp_1[i]->birth <= 0);

        printf("\t.  .  .  .  .  .  .  .  .  .  .  .\n");

        // защита ввода результат
        do
        {
            while (1)
            {
                char ch = 0;
                printf("\t4. Результат (0.1 - 99.99): ");

                if (!scanf_s("%f", &inp_1[i]->result) || getchar() != '\n')
                {
                    while ((ch = getchar()) != '\n' && ch != EOF)
                        ;
                }
                else
                    break;
            }

        } while (inp_1[i]->result > 99 || inp_1[i]->result <= 0);

        // защита ввода занятое место
        do
        {
            while (1)
            {
                char ch = 0;
                printf("\t5. Занятое место (1 - 100): ");

                if (!scanf_s("%d", &inp_1[i]->place) || getchar() != '\n')
                {
                    while ((ch = getchar()) != '\n' && ch != EOF)
                        ;
                }
                else
                    break;
            }

        } while (inp_1[i]->place > 99 || inp_1[i]->place <= 0);
    }
    else
        printf("\n\tНет возможности перевыделить память.\n");
}
void tableUp(void)
{
    printf(" .____________________________________________________________________________.\n");
    printf(" | № |                     Информация                     | Результат | Место |");
}
void tableMiddle(void)
{
    printf("\n");
    printf(" |---|----------------------------------------------------|-----------|-------|");
}
void tableDown(void)
{
    printf("\n");
    printf(" |___|____________________________________________________|___________|_______|\n\n");
}
void lineDateInTab(struct rec_base *buffer_basa, int pos)
{
    printf("\n |   |");
    (buffer_basa->surname[0] == '#') ? printf(" DEL") : printf(" ");
    printf(("1. Организация: %32s |           |       |"), buffer_basa->firm);

    printf("\n |%3d|", pos);
    (buffer_basa->surname[0] == '#') ? printf((" 2. Фамилия: %38s "), buffer_basa->surname + 1) : printf((" 2. Фамилия: %38s "), buffer_basa->surname);
    printf("|           |       |");

    printf("\n |   | 3. Год Рождения: %33d |%10.2f |   %2d  | ", buffer_basa->birth, buffer_basa->result, buffer_basa->place);
}

//=================================== работа с файлом =============================================
//
unsigned int get_rec_count(FILE *base)
{
    long cur_pos = ftell(base);
    fseek(base, 0, SEEK_END);
    long count_r = ftell(base) / RECORD_S;
    fseek(base, cur_pos, SEEK_SET);
    return (count_r);
}
int insert_record(FILE *base, struct rec_base *rea, unsigned ins_pos, enum ins_mode mode)
{
    FILE *base_n;
    unsigned rc;
    int read_c;
    int res;
    int i;

    rc = get_rec_count(base);
    base_n = fopen("Протокол соревнований_n.dat", "a+b");
    fseek(base_n, 0, SEEK_SET);

    if (ins_pos == (rc - 1) && mode) // часный случай - вставка в конец файла
    {
        fseek(base, 0, SEEK_END);
        res = fwrite(rea, RECORD_S, 1, base);
        fflush(base);
        return (res);
    }
    else // общий случай
    {
        fseek(base, 0, SEEK_SET);
        for (i = 0; (!mode && (i < (int)ins_pos)) || (mode && (i <= (int)ins_pos)); i++)
        {
            read_c = read_rec(base, i);
            fwrite(inp_zap, RECORD_S, 1, base_n);
            free(inp_zap);
        }
        fwrite(rea, RECORD_S, 1, base_n);
        if (!mode)
            i = (int)ins_pos;
        else
            i = (int)ins_pos + 1;
        for (; i < (int)rc; i++)
        {
            read_c = read_rec(base, i);
            fwrite(inp_zap, RECORD_S, 1, base_n);
            free(inp_zap);
        }
        fflush(base_n);
        fclose(base_n);
        fflush(base);
        fclose(base);
        return ((!remove("Протокол соревнований.dat")) && (!rename("Протокол соревнований_n.dat", "Протокол соревнований.dat")) && ((base = fopen("Протокол соревнований.dat", "r+b")) != NULL));
    }
}
int read_rec(FILE *base, unsigned int pos)
{
    int read_c;
    //отсчет pos с нуля
    fseek(base, RECORD_S * pos, SEEK_SET);
    inp_zap = (struct rec_base *)calloc(1, RECORD_S);
    read_c = fread(inp_zap, RECORD_S, 1, base);

    if (read_c)
    {
        return (read_c);
    }
    else //освобождение памяти после неудачного чтения
    {
        free(inp_zap);
        return (read_c);
    }
}
int remote_reset(FILE *base)
{
    FILE *base_n;
    struct rec_base *rea;
    int read_c;

    base_n = fopen("Протокол соревнований_n.dat", "a+b");
    fseek(base_n, 0, SEEK_SET);
    fseek(base, 0, SEEK_SET);

    rea = (struct rec_base *)calloc(1, RECORD_S);
    read_c = fread(rea, RECORD_S, 1, base);
    while (read_c && !feof(base))
    {
        if (rea->surname[0] != '#')
            fwrite(rea, RECORD_S, 1, base_n);
        read_c = fread(rea, RECORD_S, 1, base);
    }
    fflush(base_n);
    fclose(base_n);
    fflush(base);
    fclose(base);
    return ((!remove("Протокол соревнований.dat")) && (!rename("Протокол соревнований_n.dat", "Протокол соревнований.dat")) && ((base = fopen("Протокол соревнований.dat", "r+b")) != NULL));
}
void remote_repair(FILE *base)
{
    unsigned rc;
    int i;
    char buf[40];
    int read_c;

    rc = get_rec_count(base);
    fseek(base, 0, SEEK_SET);
    for (i = 0; i < (int)rc; i++)
    {
        read_c = read_rec(base, i);
        if (inp_zap->surname[0] == '#')
        {
            strcpy(buf, inp_zap->surname + 1);
            strcpy(inp_zap->surname, buf);
            write_rec(base, i, inp_zap);
        }
        free(inp_zap);
    }
    fflush(base);
}
void write_rec(FILE *base, unsigned int pos, struct rec_base *rea)
{
    long cur_pos = ftell(base);
    fseek(base, RECORD_S * pos, SEEK_SET);
    int write_c = fwrite(rea, RECORD_S, 1, base);
    if (write_c != 1)
        printf("\n\tВозможно, не всё записалось...\n");
    else
        fflush(base);
    fseek(base, cur_pos, SEEK_SET);
}

//================================== вспомогательные ==============================================
//
void pause_final(enum pf_mode mode)
{
    if (!mode)
    {
        printf("\n\t");
        system("pause");
    }
}
char *gets_s(char *str, size_t num)
{
    int n;

    char *s = fgets(str, num, stdin);
    fseek(stdin, 0, SEEK_END); // очищаем поток ввода
    if (s)
    {
        n = strlen(str) - 1;
        str += n;
        if (*str == '\n')
            *str = '\0';
    }

    return s;
}

//=================================================================================================
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
