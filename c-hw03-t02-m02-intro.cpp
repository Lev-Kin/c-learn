/*
// 1. Пользователь вводит с клавиатуры время в секундах. Необходимо написать программу, которая переведет введенные пользователем секунды  в часы, минуты, секунды и выведет их на экран.

#include <windows.h>
#include <iostream>

// определение пространства имен,
// в котором есть cout<< и cin>>
using namespace std;
// Главная функция
int main()
{
    //Вызов команды ОС очистки экрана
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //Объявляем переменные и инициализируем их
    int hour, min, sec = 0;
    //Приглашение ввести количество секунд
    cout << "Введите количество секунд чтобы перевести \n";
    cout << "в Часы : минуты : секунды \n";
    //Считываем секунды с клавиатуры
    cin >> sec;

    //Вычисляем значение переменных часы, минуты
    hour = sec / 60 / 60;
    min = sec / 60;

    //Выводим результат на экран Часы минуты секунды
    cout << hour << " Hour : " << min%60 << " min : " << sec%60 << " sec""\n";
    return 0;
    }


// 2.  Написать программу, которая преобразует введенное с клавиатуры дробное число в денежный формат. Например, число 12,5 должно быть преобразовано к виду 12 рублей 50 коп.

#include <iostream>

using namespace std;

int main() {

    double numvod; // дробное число
    int rub, kop; // целая часть числа
    cout << "Ввидите число подобного типа 12.50 \n";
    cout << "Чтобы получить руб и коп \n";

    cin >> numvod;

    rub = int(numvod); // привод к целочисленному значению
    kop = (numvod - rub) * 100;
    cout << rub << " рублей  " << kop << " коп.  \n";
}


// 3. Написать программу, вычисляющую, с какой скоростью бегун пробежал дистанцию. Рекомендуемый вид экрана во время выполнения программы приведен ниже:

// Наименование программы:
// Вычисление скорости бега
// ---------------------------------------
// Ввод исходных данных:
// Введите длину дистанции (метров) = 1000
// Введите время (мин.сек) = 3.25
// ---------------------------------------
// Вывод полученных данных:
// Дистанция: 1000 м
// Время: 3 мин 25 сек = 205 сек
// Вы бежали со скоростью 17.56 км/ч

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

    cout << "Наименование программы:\n";
    cout << "Вычисление скорости бега\n";
    cout.fill('-');
    cout << setw(42);
    cout << "\n";

    double dis, min_sec, sec, sum_sec;
    cout << "Ввод исходных данных:\n";
    cout << "Введите длину дистанции (метров) = "; cin >> dis;
    cout << "Введите время (мин.сек) = "; cin >> min_sec;
    sec = (min_sec - int(min_sec)) * 100;
    sum_sec = int(min_sec) * 60 + sec;

    cout.fill('-');
    cout << setw(42);
    cout << "\n";

    cout << "Вывод полученых данных:\n";
    cout << "Дистанция " << dis << " м" << endl;
    cout << "Время: " << int(min_sec) << " мин " << sec << " секунд = " << sum_sec << " сек.\n";
    cout << "Вы бежали со скоростью: " << (dis / sum_sec) * 3.6 << " км/ч" << endl;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// 4. Пользователь указывает цену одной минуты исходящего звонка с одного мобильного оператора другому, а также продолжительность разговора в минутах и секундах. Необходимо вычислить денежную сумму на которую был произведен звонок.

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

    double price, price_sec, min, sec;
    cout << "\n Введите стоимость звонк за минуту ";
    cin >> price;
    cout << "\n Введите кол-во минут ";
    cin >> min;
    cout << "\n Введите кол-во секунд ";
    cin >> sec;
    price_sec = price / 60;
    cout << "\n Стоимость составит " << price * min + price_sec * sec;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// 5. Написать программу, которая преобразует введенное пользователем количество дней в количество полных недель и оставшихся дней. Например, пользователь ввел 17 дней, программа должна вывести на экран 2 недели и 3 дня.

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

    cout << "\n";
    int day;
    cout << "Введите кол-во дней ";
    cin >> day;
    cout << "\nЭто " << int(day / 7) << " недели и " << day - (int(day / 7)) * 7 << " днея.";
    cout << "\n";

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// 6. Пользователь вводит номер года. Необходимо написать программу, которая выведет количество дней в этом году.

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

    cout << "\n";
    int year;
    cout << "Введите год ";
    cin >> year;
    //високосный год - когда он кратен 4, но при этом не кратен 100, либо кратен 400
    cout << "\nВ введенном " << year << " году " << 365 + (int)((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) << " дней.";
    cout << "\n";

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}
*/

// 7. Пользователь вводит с клавиатуры денежную сумму в рублях и копейках (рубли и копейки вводятся в разные переменные). Сумма может быть введена как правильно (например 19руб. 90 коп), так и неправильно (например 22руб. 978 коп). Написать программу, которая, осуществит корректировку введенной денежной суммы в правильную форму.
// Например, если пользователь ввел 11руб 150 коп, программа должна вывести на экран сумму 12руб. 50 коп.

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rub, kop; // инициализация переменных для ввода
    cout << "Введите количество рублей. \n";
    cin >> rub;
    cout << "Введите количество копеек. \n";
    cin >> kop;

    rub += kop / 100; // + рубли от переизбыточных копеек
    kop = kop % 100;

    cout << rub << " рублей " << kop << " коп.  \n";

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}
