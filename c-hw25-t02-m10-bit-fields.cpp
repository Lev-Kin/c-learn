/*
// 1. Написать программу для хранения в битовом поле информации о
//     конфигурации компьютера. Например:
//     Корпус: AT – 0, ATX – 1;
//     Видео:   на борту - 0, карта - 1 и так далее.

#include <windows.h>
#include <stdio.h>

void dash(int);
void dot(int);
void dotdot(int);
void equal(int);
void tabs(int);
void apostrophe(int);
void underscore(int);
void eatline(void);

typedef struct
{
	unsigned cpu : 1;
	unsigned gpu : 1;
	unsigned box : 1;
	unsigned cool : 1;
	unsigned mother : 1;
	unsigned storage : 1;

} Сomputer;

int main(void)
{
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	system("cls");
	equal(80);
	printf("\n");
	tabs(9);
	printf("\n");
	apostrophe(80);
	printf("\n");
	printf("\t    ***| Программа конфигурации компьютера в битовом поле |***\n\n\n");

	Сomputer PC;
	int i;

	printf("\t   Процесс работы:\n");
	printf("\t1. Заполните посредством выбора предложенную конфигурацию.\n");
	printf("\t2. Введенные вами данные будут обработаны.\n");
	printf("\t3. Далее составляется таблица с выбранной вами конфигурацией.\n");

	printf("\n");
	dash(80);
	printf("\n\n");

	printf("\tВыбирайте комплектующие компьютера посредством нажатия 1 или 0.\n");
	printf("\tЗаносим значения конфигурации компьютера:\n\n");

	do
	{
		while (1)
		{
			char ch = 0;
			printf("\tПроцессор:\n\t(1-AMD, 0-INTEL) -> ");

			if (!scanf_s("%d", &i) || getchar() != '\n')
			{
				while ((ch = getchar()) != '\n' && ch != EOF)
					;
			}
			else
				break;
		}

	} while (i > 1 || i <= -1);
	PC.cpu = i;

	printf("\tВыбор процессора сделан.\n");
	dot(26);
	printf("\n\n");

	do
	{
		while (1)
		{
			char ch = 0;
			printf("\tМатеринская плата:\n\t(1-ATX, 0-mATX) -> ");

			if (!scanf_s("%d", &i) || getchar() != '\n')
			{
				while ((ch = getchar()) != '\n' && ch != EOF)
					;
			}
			else
				break;
		}

	} while (i > 1 || i <= -1);
	PC.mother = i;

	printf("\tВыбор материнской платы сделан.\n");
	dot(26);
	printf("\n\n");

	do
	{
		while (1)
		{
			char ch = 0;
			printf("\tВидеокарта:\n\t(1-ATI, 0-NVIDEO) -> ");

			if (!scanf_s("%d", &i) || getchar() != '\n')
			{
				while ((ch = getchar()) != '\n' && ch != EOF)
					;
			}
			else
				break;
		}

	} while (i > 1 || i <= -1);
	PC.gpu = i;

	printf("\tВыбор видеокарты сделан.\n");
	dot(26);
	printf("\n\n");

	do
	{
		while (1)
		{
			char ch = 0;
			printf("\tНакопитель:\n\t(1-HDD, 0-SSD) -> ");

			if (!scanf_s("%d", &i) || getchar() != '\n')
			{
				while ((ch = getchar()) != '\n' && ch != EOF)
					;
			}
			else
				break;
		}

	} while (i > 1 || i <= -1);
	PC.storage = i;

	printf("\tВыбор накопителя сделан.\n");
	dot(26);
	printf("\n\n");

	do
	{
		while (1)
		{
			char ch = 0;
			printf("\tОхлаждение:\n\t(1-Воздушное, 0-Жидкостное) -> ");

			if (!scanf_s("%d", &i) || getchar() != '\n')
			{
				while ((ch = getchar()) != '\n' && ch != EOF)
					;
			}
			else
				break;
		}

	} while (i > 1 || i <= -1);
	PC.cool = i;

	printf("\tВыбор охлаждения сделан.\n");
	dot(26);
	printf("\n\n");

	do
	{
		while (1)
		{
			char ch = 0;
			printf("\tКорпус:1\n\t(1-Full-Tower, 0-Full-Desktop) -> ");

			if (!scanf_s("%d", &i) || getchar() != '\n')
			{
				while ((ch = getchar()) != '\n' && ch != EOF)
					;
			}
			else
				break;
		}

	} while (i > 1 || i <= -1);
	PC.box = i;

	printf("\tВыбор корпуса сделан.\n");
	dash(80);
	printf("\n\n\n");

	printf("\tТаблица - Выбранной комплектации компьютера.\n");
	printf("\t._____________________________________________.\n");
	printf("\t|  №  | Названия комплектующей |  Тип выбора  |\n");
	printf("\t|-----|------------------------|--------------|\n");
	printf("\t|  1  | Процессор              | %-12s |\n", PC.cpu ? "AMD" : "INTEL");
	printf("\t|  2  | Материнская плата      | %-12s |\n", PC.mother ? "ATX" : "mATX");
	printf("\t|  3  | Видеокарта             | %-12s |\n", PC.gpu ? "ATI" : "NVIDEO");
	printf("\t|  4  | Накопитель             | %-12s |\n", PC.storage ? "HDD" : "SSD");
	printf("\t|  5  | Охлаждение             | %-12s |\n", PC.cool ? "Воздушное" : "Жидкостное");
	printf("\t|  6  | Корпус                 | %-12s |\n", PC.box ? "Full-Tower" : "Full-Desktop");
	printf("\t|_____|________________________|______________|\n\n");

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

//============================================================================
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

// 2. Написать программу учёта сдачи зачётов при помощи битовых полей.
//     Должны использоваться следующие поля:
//     фамилия,
//     группа,
//     зачёты (битовое поле).
//     Предусмотреть вывод списков сдавших все зачёты и должников по
//     группам и в алфавитном порядке.

#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define LIM 30

//////////////////////////////// функции ввода вывода /////////////////////////////////////////////////

void outputTablе1(struct Student *, int);
void outputTablе2(struct Student *, int);

//////////////////////////////// функции сортировки ///////////////////////////////////////////////////

void sortSurname(struct Student *, int);
void sortGroup(struct Student *, int);
void separate(struct Student *, int);

//////////////////////////////// функции вспомогательные ///////////////////////////////////////////////

void dash(int);
void dot(int);
void dotdot(int);
void equal(int);
void tabs(int);
void apostrophe(int);
void underscore(int);
void eatline(void);
void tableUp(void);
void tableDown(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Student
{
	char surname[LIM];
	int group;
	unsigned subject1 : 1;
	unsigned subject2 : 1;
	unsigned subject3 : 1;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Student *ptrstudent = nullptr;

	int count = 0;
	int menu;
	int option;

	int offset; // зачет

	char enter; // для подтверждения
	char repeat;

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
		printf("\t***| Программа учета сдачи предметов при помощи битовых полей |***\n\n");
		printf("\t________________________| Главное меню |________________________________\n");
		printf("\t  Выберите ПУНКТ меню:\n");
		printf("\t1:Добавление записи.\n");
		printf("\t2:Просмотреть записи.\n");
		printf("\t3:Редактирование записей.\n");
		printf("\t4:Удаление записи.\n");
		printf("\t5:Студенты получившие и не получившие зачеты по предметам. (по алфавиту)\n");
		printf("\t6:Студенты получившие и не получившие зачеты по предметам. (по группам)\n");
		printf("\t7: | ВыхоД |\n     |\n     '->");
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
					ptrstudent = (Student *)calloc(1, sizeof(Student));
					if (ptrstudent)
					{
						work = true;
					}
					else
						printf("\tНет возможности выделить память под первый элемент массива структур.\n");
				}

				if (work)
				{
					do
					{
						ptrstudent = (Student *)realloc(ptrstudent, (count + 1) * sizeof(Student));
						if (ptrstudent)
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
								gets_s((ptrstudent + count)->surname, 29);

							} while (ptrstudent[count].surname[0] == '\0' || (int)strlen((ptrstudent + count)->surname) > 11);

							// защита ввода группа
							do
							{
								while (1)
								{
									char ch = 0;
									printf("\t Группа: ");

									if (!scanf_s("%d", &(ptrstudent + count)->group) || getchar() != '\n')
									{
										while ((ch = getchar()) != '\n' && ch != EOF)
											;
									}
									else
										break;
								}

							} while ((ptrstudent + count)->group > 99 || (ptrstudent + count)->group <= 0);

							printf("\t.  .  .  .  .  .  .  .  .\n\n");

							// предметы сдал или не сдал
							do
							{
								while (1)
								{
									char ch = 0;
									printf("\tПредмет 1:\n\t(1-Сдал, 0-Не сдал) -> ");

									if (!scanf_s("%d", &offset) || getchar() != '\n')
									{
										while ((ch = getchar()) != '\n' && ch != EOF)
											;
									}
									else
										break;
								}

							} while (offset > 1 || offset <= -1);
							(ptrstudent + count)->subject1 = offset;

							do
							{
								while (1)
								{
									char ch = 0;
									printf("\tПредмет 2:\n\t(1-Сдал, 0-Не сдал) -> ");

									if (!scanf_s("%d", &offset) || getchar() != '\n')
									{
										while ((ch = getchar()) != '\n' && ch != EOF)
											;
									}
									else
										break;
								}

							} while (offset > 1 || offset <= -1);
							(ptrstudent + count)->subject2 = offset;

							do
							{
								while (1)
								{
									char ch = 0;
									printf("\tПредмет 3:\n\t(1-Сдал, 0-Не сдал) -> ");

									if (!scanf_s("%d", &offset) || getchar() != '\n')
									{
										while ((ch = getchar()) != '\n' && ch != EOF)
											;
									}
									else
										break;
								}

							} while (offset > 1 || offset <= -1);
							(ptrstudent + count)->subject3 = offset;

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
					outputTablе1(ptrstudent, count);
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
							outputTablе1(ptrstudent, count);
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
						printf("\n\n");

						outputTablе2(ptrstudent, record - 1);

						printf("\n\t===  Редактируем %2d  запись  ===\n\n", record);

						// защита ввода фамилия
						do
						{
							printf("\tФамилия: ");
							gets_s((ptrstudent + (record - 1))->surname, 29);

						} while (ptrstudent[(record - 1)].surname[0] == '\0' || (int)strlen((ptrstudent + (record - 1))->surname) > 11);

						// защита ввода группа
						do
						{
							while (1)
							{
								char ch = 0;
								printf("\t Группа: ");

								if (!scanf_s("%d", &(ptrstudent + (record - 1))->group) || getchar() != '\n')
								{
									while ((ch = getchar()) != '\n' && ch != EOF)
										;
								}
								else
									break;
							}

						} while ((ptrstudent + (record - 1))->group > 99 || (ptrstudent + (record - 1))->group <= 0);

						printf("\t.  .  .  .  .  .  .  .  .\n\n");

						// предметы сдал или не сдал
						do
						{
							while (1)
							{
								char ch = 0;
								printf("\tПредмет 1:\n\t(1-Сдал, 0-Не сдал) -> ");

								if (!scanf_s("%d", &offset) || getchar() != '\n')
								{
									while ((ch = getchar()) != '\n' && ch != EOF)
										;
								}
								else
									break;
							}

						} while (offset > 1 || offset <= -1);
						(ptrstudent + (record - 1))->subject1 = offset;

						do
						{
							while (1)
							{
								char ch = 0;
								printf("\tПредмет 2:\n\t(1-Сдал, 0-Не сдал) -> ");

								if (!scanf_s("%d", &offset) || getchar() != '\n')
								{
									while ((ch = getchar()) != '\n' && ch != EOF)
										;
								}
								else
									break;
							}

						} while (offset > 1 || offset <= -1);
						(ptrstudent + (record - 1))->subject2 = offset;

						do
						{
							while (1)
							{
								char ch = 0;
								printf("\tПредмет 3:\n\t(1-Сдал, 0-Не сдал) -> ");

								if (!scanf_s("%d", &offset) || getchar() != '\n')
								{
									while ((ch = getchar()) != '\n' && ch != EOF)
										;
								}
								else
									break;
							}

						} while (offset > 1 || offset <= -1);
						(ptrstudent + (record - 1))->subject3 = offset;

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
							outputTablе1(ptrstudent, count);
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
							ptrstudent[i] = ptrstudent[i + 1];

						count--;

						ptrstudent = (Student *)realloc(ptrstudent, (count + 1) * sizeof(Student));

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
					sortSurname(ptrstudent, count);
					separate(ptrstudent, count);
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
					sortGroup(ptrstudent, count);
					separate(ptrstudent, count);
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

	if (ptrstudent)
	{
		free(ptrstudent);
	}

	ptrstudent = nullptr;

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
void outputTablе1(struct Student *point, int n)
{
	printf("\tТаблица - Всех записей\n");
	printf("\t._____________________________________________________________.\n");
	printf("\t|  №  |   Фамилия   | Группа | Предмет1 | Предмет2 | Предмет3 |\n");
	printf("\t|-----|-------------|--------|----------|----------|----------|\n");

	for (int i = 0; i < n; i++)
	{
		printf("\t| %2d  | %-11s |   %2d   | %-8s | %-8s | %-8s |",
			   i + 1, (point + i)->surname, (point + i)->group,
			   (point + i)->subject1 ? "ЗАЧЕТ" : "НЕЗАЧЕТ",
			   (point + i)->subject2 ? "ЗАЧЕТ" : "НЕЗАЧЕТ",
			   (point + i)->subject3 ? "ЗАЧЕТ" : "НЕЗАЧЕТ");

		if (i != n - 1)
			printf("\n");
	}

	printf("\n");
	printf("\t|_____|_____________|________|__________|__________|__________|\n\n");
}

// вывод таблицы запись которой редактируем
void outputTablе2(struct Student *point, int n)
{
	printf("\tТаблица - Обработки данных.\n");
	printf("\t._____________________________________________________________.\n");
	printf("\t|  №  |   Фамилия   | Группа | Предмет1 | Предмет2 | Предмет3 |\n");
	printf("\t|-----|-------------|--------|----------|----------|----------|\n");
	printf("\t| %2d  | %-11s |   %2d   | %-8s | %-8s | %-8s |", n + 1, (point + n)->surname, (point + n)->group,
		   (point + n)->subject1 ? "ЗАЧЕТ" : "НЕЗАЧЕТ",
		   (point + n)->subject2 ? "ЗАЧЕТ" : "НЕЗАЧЕТ",
		   (point + n)->subject3 ? "ЗАЧЕТ" : "НЕЗАЧЕТ");
	printf("\n");
	printf("\t|_____|_____________|________|__________|__________|__________|\n\n");
}

// сортировка по группу
void sortGroup(struct Student *point, int n)
{
	Student temp;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (point[i].group > point[j].group)
			{
				temp = point[i];
				point[i] = point[j];
				point[j] = temp;
			}
}

// сортировка по фамилии
void sortSurname(struct Student *point, int n)
{
	Student temp;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(point[i].surname, point[j].surname) > 0)
			{
				temp = point[i];
				point[i] = point[j];
				point[j] = temp;
			}
}

// распределение студентов по категориям
void separate(struct Student *point, int n)
{
	bool passed = false;	// получили по всем предметам зачет
	bool nopassed = false;	// не сдали ни одного предмета
	bool indefined = false; // некоторые предметы сданы

	int j = 0;
	int k = 0;
	int t = 0;

	for (int i = 0; i < n; i++)
	{
		if (point[i].subject1 && point[i].subject2 && point[i].subject3)
		{
			passed = true;
		}
		if (!point[i].subject1 && !point[i].subject2 && !point[i].subject3)
		{
			nopassed = true;
		}
		if ((point[i].subject1 && point[i].subject2 && point[i].subject3) == (!point[i].subject1 && !point[i].subject2 && !point[i].subject3))
		{
			indefined = true;
		}
	}

	if (passed)
	{
		printf("\tТаблица - Студенты получившие зачет по всем предметам.\n");
		tableUp();
		for (int i = 0; i < n; i++)
		{
			if (point[i].subject1 && point[i].subject2 && point[i].subject3)
			{
				printf("\t| %2d  | %-11s |   %2d   | %-8s | %-8s | %-8s |", j + 1, (point + i)->surname, (point + i)->group,
					   (point + i)->subject1 ? "ЗАЧЕТ" : "НЕЗАЧЕТ",
					   (point + i)->subject2 ? "ЗАЧЕТ" : "НЕЗАЧЕТ",
					   (point + i)->subject3 ? "ЗАЧЕТ" : "НЕЗАЧЕТ");
				printf("\n");
				j++;
			}
		}
		tableDown();
		printf("\n");
	}

	if (nopassed)
	{
		printf("\tТаблица - Студенты не получившие зачет по всем предметам.\n");
		tableUp();
		for (int i = 0; i < n; i++)
		{
			if (!point[i].subject1 && !point[i].subject2 && !point[i].subject3)
			{
				printf("\t| %2d  | %-11s |   %2d   | %-8s | %-8s | %-8s |", k + 1, (point + i)->surname, (point + i)->group,
					   (point + i)->subject1 ? "ЗАЧЕТ" : "НЕЗАЧЕТ",
					   (point + i)->subject2 ? "ЗАЧЕТ" : "НЕЗАЧЕТ",
					   (point + i)->subject3 ? "ЗАЧЕТ" : "НЕЗАЧЕТ");
				printf("\n");
				k++;
			}
		}
		tableDown();
		printf("\n");
	}

	if (indefined)
	{
		printf("\tТаблица - Студенты получившие хоть один зачет по предмету.\n");
		tableUp();
		for (int i = 0; i < n; i++)
		{
			if ((point[i].subject1 && point[i].subject2 && point[i].subject3) == (!point[i].subject1 && !point[i].subject2 && !point[i].subject3))
			{
				printf("\t| %2d  | %-11s |   %2d   | %-8s | %-8s | %-8s |", t + 1, (point + i)->surname, (point + i)->group,
					   (point + i)->subject1 ? "ЗАЧЕТ" : "НЕЗАЧЕТ",
					   (point + i)->subject2 ? "ЗАЧЕТ" : "НЕЗАЧЕТ",
					   (point + i)->subject3 ? "ЗАЧЕТ" : "НЕЗАЧЕТ");
				printf("\n");
				t++;
			}
		}
		tableDown();
	}

	if (passed == false)
	{
		printf("\tСтуденты получившие зачет по все предметам, не найдены.\n");
	}
	if (nopassed == false)
	{
		printf("\tСтуденты не получивших зачет по всем предметам, не найдены.\n");
	}
	if (indefined == false)
	{
		printf("\tСтуденты имеющие разные зачеты по всем предметам, не найдены.\n");
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

void tableUp(void)
{
	printf("\t._____________________________________________________________.\n");
	printf("\t|  №  |   Фамилия   | Группа | Предмет1 | Предмет2 | Предмет3 |\n");
	printf("\t|-----|-------------|--------|----------|----------|----------|\n");
}

void tableDown(void)
{
	printf("\t|_____|_____________|________|__________|__________|__________|\n\n");
}
*/

// 3. Создать битовое поле для хранения времени (часы, минуты, секунды,
//     миллисекунды). Написать функции для установки и получения
//     времени в(из) битовое(-го) поле(-я).

#include <windows.h>
#include <stdio.h>
#include <conio.h> // getch()

/////////////////////////////////////////////////////

void setTime(struct Time *, int, int, int, int);
void getTime(struct Time *, int *, int *, int *, int *);

/////////////////////////////////////////////////////

void dash(int);
void dot(int);
void dotdot(int);
void equal(int);
void tabs(int);
void apostrophe(int);
void underscore(int);
void eatline(void);

//////////////////////////////////////////////////////

struct Time
{
	unsigned hours : 5;
	unsigned minutes : 6;
	unsigned seconds : 6;
	unsigned milliseconds : 10;
};

int main(void)
{
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Time t;

	int hours;
	int minutes;
	int seconds;
	int milliseconds;

	char repeat;
	do
	{
		system("cls");
		equal(80);
		printf("\n");
		tabs(9);
		printf("\n");
		apostrophe(80);
		printf("\n");
		printf("       ***| Установка и получение времени в(из) битовое(-го) поле(-я) |***\n\n\n");

		printf("\t\tВводите значения для времени:\n\n");

		do
		{
			while (1)
			{
				char ch = 0;
				printf("\t         Введите Часы (0-23) -> ");

				if (!scanf_s("%d", &hours) || getchar() != '\n')
				{
					while ((ch = getchar()) != '\n' && ch != EOF)
						;
				}
				else
					break;
			}

		} while (hours >= 24 || hours <= -1);

		do
		{
			while (1)
			{
				char ch = 0;
				printf("\t       Введите Минуты (0-59) -> ");

				if (!scanf_s("%d", &minutes) || getchar() != '\n')
				{
					while ((ch = getchar()) != '\n' && ch != EOF)
						;
				}
				else
					break;
			}

		} while (minutes >= 60 || minutes <= -1);

		do
		{
			while (1)
			{
				char ch = 0;
				printf("\t      Введите Секунды (0-59) -> ");

				if (!scanf_s("%d", &seconds) || getchar() != '\n')
				{
					while ((ch = getchar()) != '\n' && ch != EOF)
						;
				}
				else
					break;
			}

		} while (seconds >= 60 || seconds <= -1);

		do
		{
			while (1)
			{
				char ch = 0;
				printf("\tВведите Миллисекунды (0-999) -> ");

				if (!scanf_s("%d", &milliseconds) || getchar() != '\n')
				{
					while ((ch = getchar()) != '\n' && ch != EOF)
						;
				}
				else
					break;
			}

		} while (milliseconds >= 1000 || milliseconds <= -1);

		printf("\n");
		dot(26);
		printf("\n");

		setTime(&t, hours, minutes, seconds, milliseconds);
		printf("\n\tВремя установлено в битовое поле:\n");
		printf("\t(H:m:s:ms) - формат времени.\n");
		printf("\t%d:%d:%d:%d.  \n", t.hours, t.minutes, t.seconds, t.milliseconds);

		getTime(&t, &hours, &minutes, &seconds, &milliseconds);
		printf("\n\tВремя полученное из битового поля:\n");
		printf("\t(H:m:s:ms) - формат времени.\n");
		printf("\t%d:%d:%d:%d.  \n\n", hours, minutes, seconds, milliseconds);

		printf("\t.......................");
		printf("\n\tY - Повторить.");
		printf("\n     |  Q - ВыхоД из программы.\n     '->");
		repeat = getche();
	} while (repeat == 'y' || repeat == 'Y');

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

// функция установки времени
void setTime(struct Time *ptime, int hours, int minutes, int seconds, int milliseconds)
{
	ptime->hours = hours;
	ptime->minutes = minutes;
	ptime->seconds = seconds;
	ptime->milliseconds = milliseconds;
}
// функция получение времени
void getTime(struct Time *ptime, int *phours, int *pminutes, int *pseconds, int *pmilliseconds)
{
	*phours = ptime->hours;
	*pminutes = ptime->minutes;
	*pseconds = ptime->seconds;
	*pmilliseconds = ptime->milliseconds;
}

//============================================================================
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
