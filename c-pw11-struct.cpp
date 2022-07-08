/*
// Телефонный справочник жителей города оформлен в виде массива
// структур. Номера телефонов шестизначные. Составить программу,
// которая вводит исходный справочник в диалоге, выводит массив
// структур в виде таблицы и выполняет указанное задание.
// Со структурами осуществлять работу не прибегая к указателям на
// структуры

// Задача 1:
// Заменить адрес владельца телефона «651480» на адрес:
// улица «Пирогова», дом «4», квартира «17».

#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

#define LIM 42

//////////////////////////////// функции ввода вывода /////////////////////////////////////////////////

void outputTablе1(struct People *, int);
void outputTablе2(struct People *, int);

//////////////////////////////// функции вспомогательные ///////////////////////////////////////////////

void dash(int);
void dot(int);
void dotdot(int);
void equal(int);
void tabs(int);
void apostrophe(int);
void underscore(int);
void eatline(void);

struct People
{
	char surname[LIM];
	char name[LIM];
	char midname[LIM];
	char street[LIM];
	int home;
	int flat;
	int phone;
};

int main(void)
{
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	People *ptrpeople = nullptr;
	People *tmp = nullptr;

	int count = 0;
	int menu;
	int option;

	char enter; // для подтверждения
	char repeat;

	bool example = false; // обработка примера по условию
	bool show_example = false;
	bool memory = false; // проверка перевыделение памяти
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
		printf("\t   ***| Практическая №11 Задача 1 (телефонный справочник) |***\n\n");
		printf("\t________________________| Главное меню |________________________________\n");
		printf("\t  Выберите ПУНКТ меню:\n");
		printf("\t1:Добавление записи.\n");
		printf("\t2:Просмотреть записи.\n");
		printf("\t3:Редактирование записи (поиск по номеру телефона).\n");
		printf("\t4:Удаление записи.\n");
		printf("\t5: | ВыхоД |\n     |\n     '->");
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
					ptrpeople = (People *)calloc(1, sizeof(People));
					if (ptrpeople)
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

						tmp = (People *)realloc(ptrpeople, (count + 1) * sizeof(People *));
						if (tmp)
						{
							ptrpeople = tmp;
							memory = true;
						}
						else
						{
							printf("\tНе удалось выделить память под %d указатель на структуру!\n", count);
							memory = false;
							free(ptrpeople);
						}

						if (memory)
						{
							if (example == false)
							{
								printf("\n\tДобавлен пример по условию в Запись 1.\n");

								strcpy_s(ptrpeople[count].surname, "Иванов");
								strcpy_s(ptrpeople[count].name, "Иван");
								strcpy_s(ptrpeople[count].midname, "Иванович");
								strcpy_s(ptrpeople[count].street, "Строителей");

								ptrpeople[count].home = 123;
								ptrpeople[count].flat = 123;
								ptrpeople[count].phone = 651480;

								example = true;
								show_example = true;
							}
							else
							{
								printf("\n");
								dot(26);
								printf("\n");
								printf("\n\t===  Вводим %2d  запись  ===\n\n", count + 1);

								// защита ввода фамилия
								do
								{
									printf("\tФамилия: ");
									gets_s(ptrpeople[count].surname);

								} while (ptrpeople[count].surname[0] == '\0' || (int)strlen(ptrpeople[count].surname) > 11);

								// защита ввода имя
								do
								{
									printf("\tИмя: ");
									gets_s((ptrpeople + count)->name);

								} while (ptrpeople[count].name[0] == '\0' || (int)strlen(ptrpeople[count].name) > 11);

								// защита ввода отчество
								do
								{
									printf("\tОтчество: ");
									gets_s(ptrpeople[count].midname);

								} while (ptrpeople[count].midname[0] == '\0' || (int)strlen(ptrpeople[count].midname) > 11);

								// защита ввода улица
								do
								{
									printf("\tУлица: ");
									gets_s(ptrpeople[count].streеt);

								} while (ptrpeople[count].streеt[0] == '\0' || (int)strlen(ptrpeople[count].streеt) > 11);

								printf("\t.  .  .  .  .  .  .  .  .\n\n");
								// защита ввода номер дома
								do
								{
									while (1)
									{
										char ch = 0;
										printf("\tДом: ");

										if (!scanf_s("%d", &ptrpeople[count].home) || getchar() != '\n')
										{
											while ((ch = getchar()) != '\n' && ch != EOF)
												;
										}
										else
											break;
									}

								} while (ptrpeople[count].home > 999 || ptrpeople[count].home <= 0);

								do
								{
									while (1)
									{
										char ch = 0;
										printf("\tКвартира: ");

										if (!scanf_s("%d", &ptrpeople[count].flat) || getchar() != '\n')
										{
											while ((ch = getchar()) != '\n' && ch != EOF)
												;
										}
										else
											break;
									}

								} while (ptrpeople[count].flat > 999 || ptrpeople[count].flat <= 0);

								do
								{
									while (1)
									{
										char ch = 0;
										printf("\tТелефон: ");

										if (!scanf_s("%d", &ptrpeople[count].phone) || getchar() != '\n')
										{
											while ((ch = getchar()) != '\n' && ch != EOF)
												;
										}
										else
											break;
									}

								} while (ptrpeople[count].phone >= 1000000 || ptrpeople[count].phone <= 0);
							}

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
			if (memory)
			{
				printf("\n\t\t      _______| Выбран 2 пункт меню |_______\n\n\n");

				if (count != 0)
				{
					outputTablе1(ptrpeople, count);
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
			if (memory)
			{
				int record;
				int findphone;
				bool find = false;
				char choise;

				printf("\n\t\t      _______| Выбран 3 пункт меню |_______\n\n");
				printf("\t1:Редактировать запись в таблице (поиск по номеру телефона).\n");
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
							outputTablе1(ptrpeople, count);
						}
						else
						{
							printf("\n\n\tСписок пуст.");
							break;
						}

						if (show_example)
						{
							printf("\t\tОбрабaтываем пример согласно условию.\n\n");

							findphone = 651480;

							for (int i = 0; i < count; i++)
							{
								if (findphone == ptrpeople[i].phone)
								{
									find = true;
									record = i + 1;
									printf("\n\tНайден Телефон %d абонента в записи %d.", ptrpeople[i].phone, i + 1);
								}
							}

							strcpy_s(ptrpeople[record - 1].streеt, "Пирогова");

							ptrpeople[record - 1].home = 4;
							ptrpeople[record - 1].flat = 17;
							ptrpeople[record - 1].phone = findphone;

							printf("\n\tЗапись под номером %d отредактирована.\n", record);

							show_example = false;
						}
						else
						{
							find = false;

							do
							{
								while (1)
								{
									char ch = 0;
									printf("\n\tВидите номер телефона абонента для редактирования его данных:");
									printf("\n     |\n     '-> ");
									if (!scanf_s("%d", &findphone) || getchar() != '\n')
									{
										while ((ch = getchar()) != '\n' && ch != EOF)
											;
									}
									else
										break;
								}

							} while (findphone >= 1000000 || findphone <= 0);

							for (int i = 0; i < count; i++)
							{
								if (findphone == (ptrpeople + i)->phone)
								{
									find = true;
									record = i + 1;
									printf("\n\tНайден Телефон %d абонента в записи %d.", ptrpeople[i].phone, i + 1);
								}
							}

							if (find)
							{
								printf("\n");
								dot(26);
								printf("\n\n");

								outputTablе2(ptrpeople, record - 1);

								printf("\n\t===  Редактируем %2d  запись  ===\n\n", record);

								// защита ввода фамилия
								do
								{
									printf("\tФамилия: ");
									gets_s(ptrpeople[record - 1].surname);

								} while (ptrpeople[record - 1].surname[0] == '\0' || (int)strlen(ptrpeople[record - 1].surname) > 11);

								// защита ввода имя
								do
								{
									printf("\tИмя: ");
									gets_s(ptrpeople[record - 1].name);

								} while (ptrpeople[record - 1].name[0] == '\0' || (int)strlen(ptrpeople[record - 1].name) > 11);

								// защита ввода отчество
								do
								{
									printf("\tОтчество: ");
									gets_s(ptrpeople[record - 1].midname);

								} while (ptrpeople[record - 1].midname[0] == '\0' || (int)strlen(ptrpeople[record - 1].midname) > 11);

								// защита ввода улица
								do
								{
									printf("\tУлица: ");
									gets_s((ptrpeople + (record - 1))->streеt);

								} while (ptrpeople[record - 1].streеt[0] == '\0' || (int)strlen(ptrpeople[record - 1].streеt) > 11);

								printf("\t.  .  .  .  .  .  .  .  .\n\n");
								// защита ввода номер дома
								do
								{
									while (1)
									{
										char ch = 0;
										printf("\tДом: ");

										if (!scanf_s("%d", &ptrpeople[record - 1].home) || getchar() != '\n')
										{
											while ((ch = getchar()) != '\n' && ch != EOF)
												;
										}
										else
											break;
									}

								} while (ptrpeople[record - 1].home > 999 || ptrpeople[record - 1].home <= 0);

								do
								{
									while (1)
									{
										char ch = 0;
										printf("\tКвартира: ");

										if (!scanf_s("%d", &ptrpeople[record - 1].flat) || getchar() != '\n')
										{
											while ((ch = getchar()) != '\n' && ch != EOF)
												;
										}
										else
											break;
									}

								} while (ptrpeople[record - 1].flat > 999 || ptrpeople[record - 1].flat <= 0);

								printf("\t");
								dot(15);
								printf("\n");

								choise = 0;
								printf("\tЖелаете изменить номер телефона абонента?\n");
								printf("     |  Нажмите (y/n).\n     '-> ");
								choise = getche();
								if (choise == 'y' || choise == 'Y')
								{
									printf("\n");
									do
									{
										while (1)
										{
											char ch = 0;
											printf("\tТелефон: ");

											if (!scanf_s("%d", &ptrpeople[record - 1].phone) || getchar() != '\n')
											{
												while ((ch = getchar()) != '\n' && ch != EOF)
													;
											}
											else
												break;
										}

									} while (ptrpeople[record - 1].phone >= 1000000 || ptrpeople[record - 1].phone <= 0);
								}
								else
								{
									printf("\n\tНомер абонента остался без изменений.");
								}

								printf("\n\tЗапись под номером %d отредактирована.\n", record);
							}
							else
							{
								printf("\n\tАбонент с телефонным номером %d в справочнике не найден.\n", findphone);
							}
						}

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
			if (memory)
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
							outputTablе1(ptrpeople, count);
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
						if (id == 1)
						{
							if (count == 1)
							{
								ptrpeople = nullptr;

								count--;

								tmp = (People *)realloc(ptrpeople, (count + 1) * sizeof(People *));
								ptrpeople = tmp;
							}
							else
							{
								for (int i = id - 1; i < count; i++)
								{
									strcpy_s(ptrpeople[i].surname, ptrpeople[i + 1].surname);
									strcpy_s(ptrpeople[i].name, ptrpeople[i + 1].name);
									strcpy_s(ptrpeople[i].midname, ptrpeople[i + 1].midname);
									strcpy_s(ptrpeople[i].streеt, ptrpeople[i + 1].streеt);

									ptrpeople[i].home = ptrpeople[i + 1].home;
									ptrpeople[i].flat = ptrpeople[i + 1].flat;
									ptrpeople[i].phone = ptrpeople[i + 1].phone;
								}

								count--;

								tmp = (People *)realloc(ptrpeople, (count + 1) * sizeof(People *));
								ptrpeople = tmp;
							}
						}
						else
						{
							for (int i = id - 1; i < count; i++)
							{
								strcpy_s(ptrpeople[i].surname, ptrpeople[i + 1].surname);
								strcpy_s(ptrpeople[i].name, ptrpeople[i + 1].name);
								strcpy_s(ptrpeople[i].midname, ptrpeople[i + 1].midname);
								strcpy_s(ptrpeople[i].streеt, ptrpeople[i + 1].streеt);

								ptrpeople[i].home = ptrpeople[i + 1].home;
								ptrpeople[i].flat = ptrpeople[i + 1].flat;
								ptrpeople[i].phone = ptrpeople[i + 1].phone;
							}

							count--;

							tmp = (People *)realloc(ptrpeople, (count + 1) * sizeof(People *));
							ptrpeople = tmp;
						}

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

	if (memory)
	{
		free(ptrpeople);
	}

	ptrpeople = nullptr;
	tmp = nullptr;

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
void outputTablе1(People *point, int n)
{
	printf(" Таблица - Всех записей\n");
	printf(" .____________________________________________________________________________.\n");
	printf(" | №|  Фамилия   |    Имя     |  Отчество  |   Улица    | Дом | Кв. | Телефон |\n");
	printf(" |--|------------|------------|------------|------------|-----|-----|---------|\n");

	for (int i = 0; i < n; i++)
	{
		printf(" |%2d| %-11s| %-11s| %-11s| %-11s| %3d | %3d |  %6d |", i + 1,
			   point[i].surname,
			   point[i].name,
			   point[i].midname,
			   point[i].streеt,
			   point[i].home,
			   point[i].flat,
			   point[i].phone);

		if (i != n - 1)
			printf("\n");
	}

	printf("\n");
	printf(" |__|____________|____________|____________|____________|_____|_____|_________|\n\n");
}

// вывод таблицы запись которой редактируем
void outputTablе2(struct People *point, int n)
{
	printf("\tТаблица - Обработки данных.\n");
	printf(" .____________________________________________________________________________.\n");
	printf(" | №|  Фамилия   |    Имя     |  Отчество  |   Улица    | Дом | Кв. | Телефон |\n");
	printf(" |--|------------|------------|------------|------------|-----|-----|---------|\n");
	printf(" |%2d| %-11s| %-11s| %-11s| %-11s| %3d | %3d |  %6d |", n + 1,
		   point[n].surname,
		   point[n].name,
		   point[n].midname,
		   point[n].streеt,
		   point[n].home,
		   point[n].flat,
		   point[n].phone);

	printf("\n");
	printf(" |__|____________|____________|____________|____________|_____|_____|_________|\n\n");
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

// Дана таблица участников соревнований по бегу в виде массива структур.
// Составить программу, в которой в диалоге вводится исходный массив,
// выводится массив структур в виде таблицы и выполняется задание
// соответствующего варианта. Массив заполняется произвольными данными.
// Со структурами работать только через указатели на структуру.

// Задача 2:
// Определить количество участников с именем «Павел».

#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

#define LIM 42

//////////////////////////////// функции ввода вывода /////////////////////////////////////////////////

void outputTablе1(struct People *, int);

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

struct People
{
	char surname[LIM];
	char name[LIM];
	char midname[LIM];
	int birth;
	int result;
};

int main(void)
{
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	People *ptrpeople = nullptr;
	People *tmp = nullptr;

	int count = 0;
	int menu;
	int option;

	char enter; // для подтверждения
	char repeat;

	bool example = false; // обработка примера по условию
	bool show_example = false;
	bool memory = false; // проверка перевыделение памяти
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
		printf("\t    ***| Практическая №11 Задача 2  (таблица участников) |***\n\n");
		printf("\t________________________| Главное меню |________________________________\n");
		printf("\t  Выберите ПУНКТ меню:\n");
		printf("\t1:Добавление записи.\n");
		printf("\t2:Просмотреть записи.\n");
		printf("\t3:Определение кол-во участников (поиск по имени).\n");
		printf("\t4:Удаление записи.\n");
		printf("\t5: | ВыхоД |\n     |\n     '->");
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
					ptrpeople = (People *)calloc(2, sizeof(People));
					if (ptrpeople)
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
						tmp = (People *)realloc(ptrpeople, (count + 2) * sizeof(People *));
						if (tmp)
						{
							ptrpeople = tmp;
							memory = true;
						}
						else
						{
							printf("\tНе удалось выделить память под %d указатель на структуру!\n", count);
							memory = false;
							free(ptrpeople);
						}

						if (memory)
						{
							if (example == false)
							{
								printf("\n\tДобавлен пример по условию в Запись 1.\n");

								strcpy_s((ptrpeople + count)->surname, "Петров");
								strcpy_s((ptrpeople + count)->name, "Павел");
								strcpy_s((ptrpeople + count)->midname, "Петрович");

								(ptrpeople + count)->birth = 1975;
								(ptrpeople + count)->result = 12;

								example = true;
								show_example = true;
							}
							else
							{
								printf("\n");
								dot(26);
								printf("\n");
								printf("\n\t===  Вводим %2d  запись  ===\n\n", count + 1);

								// защита ввода фамилия
								do
								{
									printf("\tФамилия: ");
									gets_s((ptrpeople + count)->surname, 41);

								} while (ptrpeople[count].surname[0] == '\0' || (int)strlen((ptrpeople + count)->surname) > 11);

								// защита ввода имя
								do
								{
									printf("\tИмя: ");
									gets_s((ptrpeople + count)->name, 41);

								} while (ptrpeople[count].name[0] == '\0' || (int)strlen((ptrpeople + count)->name) > 11);

								// защита ввода отчество
								do
								{
									printf("\tОтчество: ");
									gets_s((ptrpeople + count)->midname, 41);

								} while (ptrpeople[count].midname[0] == '\0' || (int)strlen((ptrpeople + count)->midname) > 11);

								printf("\t.  .  .  .  .  .  .  .  .\n\n");
								// защита ввода год рождения
								do
								{
									while (1)
									{
										char ch = 0;
										printf("\tГод рождения: ");

										if (!scanf_s("%d", &(ptrpeople + count)->birth) || getchar() != '\n')
										{
											while ((ch = getchar()) != '\n' && ch != EOF)
												;
										}
										else
											break;
									}

								} while ((ptrpeople + count)->birth > 2021 || (ptrpeople + count)->birth <= 0);

								do
								{
									while (1)
									{
										char ch = 0;
										printf("\tРезультат: ");

										if (!scanf_s("%d", &(ptrpeople + count)->result) || getchar() != '\n')
										{
											while ((ch = getchar()) != '\n' && ch != EOF)
												;
										}
										else
											break;
									}

								} while ((ptrpeople + count)->result >= 60 || (ptrpeople + count)->result <= 0);
							}

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
			if (memory)
			{
				printf("\n\t\t      _______| Выбран 2 пункт меню |_______\n\n\n");

				if (count != 0)
				{
					outputTablе1(ptrpeople, count);
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
			if (memory)
			{
				char findname[LIM] = {"Павел"}; // Искомое имя согласно условию
				char choise;
				int times = 0; // сколько раз искомое имя встречается в таблице.

				printf("\n\t\t      _______| Выбран 3 пункт меню |_______\n\n");
				printf("\t1:Определение кол-во участников (поиск по имени).\n");
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
							outputTablе1(ptrpeople, count);
						}
						else
						{
							printf("\n\n\tСписок пуст.");
							break;
						}

						if (show_example)
						{
							printf("\n\tОбрабaтываем пример согласно условию.\n");

							for (int i = 0; i < count; i++)
							{
								if (strcmp(findname, (ptrpeople + i)->name) == 0)
									times++;
							}

							printf("\n\tИмя %s встречается в записях %d раз(a).\n\n", findname, times);

							if (times)
							{
								times = 0;
								printf(" Таблица - Искомого имени (из таблицы всех участников).\n");

								tableUp();
								for (int i = 0; i < count; i++)
								{
									if (strcmp(findname, (ptrpeople + i)->name) == 0)
									{
										times++;
										printf(" |%2d| %-11s| %-11s| %-11s|     %4d     |       %2d       |", times,
											   (ptrpeople + i)->surname,
											   (ptrpeople + i)->name,
											   (ptrpeople + i)->midname,
											   (ptrpeople + i)->birth,
											   (ptrpeople + i)->result);

										printf("\n");
									}
								}
								tableDown();
							}
							else
							{
								printf("\tУчастник соревнований по имени %s в таблице не найден.\n", findname);
							}

							show_example = false;
						}
						else
						{
							do
							{
								char ch = 0;
								printf("\n\tВидите имя для поиска в таблице участников:");
								printf("\n     |\n     '-> ");
								gets_s(findname, 41);

							} while (findname[0] == '\0' || (int)strlen(findname) > 11);

							for (int i = 0; i < count; i++)
							{
								if (strcmp(findname, (ptrpeople + i)->name) == 0)
									times++;
							}

							printf("\n\tИмя %s встречается в записях %d раз(a).\n\n", findname, times);

							if (times)
							{
								times = 0;
								printf(" Таблица - Искомого имени (из таблицы всех участников).\n");

								tableUp();
								for (int i = 0; i < count; i++)
								{
									if (strcmp(findname, (ptrpeople + i)->name) == 0)
									{
										times++;
										printf(" |%2d| %-11s| %-11s| %-11s|     %4d     |       %2d       |", times,
											   (ptrpeople + i)->surname,
											   (ptrpeople + i)->name,
											   (ptrpeople + i)->midname,
											   (ptrpeople + i)->birth,
											   (ptrpeople + i)->result);

										printf("\n");
									}
								}
								tableDown();
							}
							else
							{
								printf("\n\tУчастник соревнований по имени %s в таблице не найден.\n", findname);
							}
						}

						printf("\t");
						dotdot(40);
						printf("\n\tY - Найти другое имя участника.");
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
			if (memory)
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
							outputTablе1(ptrpeople, count);
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
						if (id == 1)
						{
							if (count == 1)
							{
								ptrpeople = nullptr;

								count--;

								tmp = (People *)realloc(ptrpeople, (count + 1) * sizeof(People *));
								ptrpeople = tmp;
							}
							else
							{
								for (int i = id - 1; i < count; i++)
								{
									strcpy_s(ptrpeople[i].surname, ptrpeople[i + 1].surname);
									strcpy_s(ptrpeople[i].name, ptrpeople[i + 1].name);
									strcpy_s(ptrpeople[i].midname, ptrpeople[i + 1].midname);

									ptrpeople[i].birth = ptrpeople[i + 1].birth;
									ptrpeople[i].result = ptrpeople[i + 1].result;
								}

								count--;

								tmp = (People *)realloc(ptrpeople, (count + 1) * sizeof(People *));
								ptrpeople = tmp;
							}
						}
						else
						{
							for (int i = id - 1; i < count; i++)
							{
								strcpy_s(ptrpeople[i].surname, ptrpeople[i + 1].surname);
								strcpy_s(ptrpeople[i].name, ptrpeople[i + 1].name);
								strcpy_s(ptrpeople[i].midname, ptrpeople[i + 1].midname);

								ptrpeople[i].birth = ptrpeople[i + 1].birth;
								ptrpeople[i].result = ptrpeople[i + 1].result;
							}

							count--;

							tmp = (People *)realloc(ptrpeople, (count + 1) * sizeof(People *));
							ptrpeople = tmp;
						}

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

	if (memory)
	{
		free(ptrpeople);
	}

	ptrpeople = nullptr;
	tmp = nullptr;

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
void outputTablе1(People *point, int n)
{
	printf(" Таблица - Всех участников соревновани.\n");
	printf(" ._________________________________________________________________________.\n");
	printf(" | №|  Фамилия   |    Имя     |  Отчество  | Год рождения | Результат, сек |\n");
	printf(" |--|------------|------------|------------|--------------|----------------|\n");

	for (int i = 0; i < n; i++)
	{
		printf(" |%2d| %-11s| %-11s| %-11s|     %4d     |       %2d       |", i + 1,
			   (point + i)->surname,
			   (point + i)->name,
			   (point + i)->midname,
			   (point + i)->birth,
			   (point + i)->result);

		if (i != n - 1)
			printf("\n");
	}

	printf("\n");
	printf(" |__|____________|____________|____________|______________|________________|\n\n");
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
	printf(" ._________________________________________________________________________.\n");
	printf(" | №|  Фамилия   |    Имя     |  Отчество  | Год рождения | Результат, сек |\n");
	printf(" |--|------------|------------|------------|--------------|----------------|\n");
}

void tableDown(void)
{
	printf(" |__|____________|____________|____________|______________|________________|\n\n");
}
