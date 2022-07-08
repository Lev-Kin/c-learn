/*
// 1. Написать программу, которая преобразует введенное с клавиатуры дробное число в формат расстояния в километрах и метрах.
// Например,
// Введите дробное число -> 11.25
// м. — это 11 км 250 метров.

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
 
using namespace std;
 
int main() {
	system("cls");
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
 
	double vvod; // инициализация дробной переменной для ввода
	cout << "Введите дробное число. \n";
	cin >> vvod;
 
	double m = (vvod - int(vvod))*1000; // отделения метров от дробной части 
 
	cout << "\n";
	cout << vvod << " м. - это  " << int(vvod) << " км " << m << " метров.  \n";
	cout << "\n";
	SetConsoleCP(i1);
	SetConsoleOutputCP(i1);
	return 0;
}

// 2.  Написать программу, которая проверяет, является ли введенное пользователем    
//      целое число четным. Ниже приведен рекомендуемый вид экрана программы во 
//      время выполнения программы.
// Введите целое число и нажмите <Enter> -> 23
// Число 23 — нечетное.

#include <windows.h>
#include <iostream>
#include <conio.h>
 
using namespace std;
 
int main(void)
{
	system("cls");
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
 
	int x; // объявляем целое число
	cout << "Введите целое число и нажмите <Enter> -> ";
	cin >> x; // введите целое число
	if (x % 2 == 0) // число является целым если делиться на 2 без остатка
		cout << "Число "<< x <<" - четное." << endl;
	else
		cout << "Число " << x << " - нечетное." << endl;
 
	SetConsoleCP(i1);
	SetConsoleOutputCP(i1);
	return 0;
}
*/
 
// 3.  Написать программу, которая вычисляет оптимальный вес для пользователя,  
//      сравнивает его с реальным и выдает рекомендацию о необходимости поправиться  
//      или похудеть. Оптимальный вес вычисляется по формуле: Рост (см) — 100. 
//      Рекомендуемый вид экрана во время выполнения программы приведен ниже.
// Введите в одной строке через пробел 
// рост (см) и вес (кг), затем нажмите <Enter> 
// ->170 68 
// Вам надо поправиться на 2.00 кг. 

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
 
using namespace std;
 
int main(void)
{
	system("cls");
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
 
	// объявляем переменные
	float weight, height, weight_optimal, diet;
 
	printf("Введите в одной строке, через пробел \n");
	printf("рост (см) и вес (кг), затем нажмите <Enter> \n");
	printf("-> ");
	scanf("%f%f", &height, &weight);
	weight_optimal = height - 100;
 
	if (weight == weight_optimal)
		printf("Ваш вес оптимален!");
	else
		if (weight < weight_optimal)
		{
			diet = weight_optimal - weight;
			printf("Вам надо поправится на %2.2f кг\n", diet);
		}
		else
		{
			diet = weight - weight_optimal;
			printf("Вам надо похудеть на %2.2f кг\n", diet);
		}
 
	SetConsoleCP(i1);
	SetConsoleOutputCP(i1);
	return 0;
}

