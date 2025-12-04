#include <iostream>  
#include <iomanip>
#include <string>

int main()
{
	setlocale(LC_ALL, "RUS");

	//1 ЗАДАЧА
	std::cout << "Здравствуйте, введите расстояние до аэропорта (в км) и время, за которое нужно доехать (в часах) \n";
	double distance = 0;
	std::cin >> distance;
	double time = 0;
	std::cin >> time;
	double speed = (distance / time);
	std::cout << "Вам нужно ехать со скоростью " << speed << " км в ч."; 

		// 2 ЗАДАЧА
		std::cout << "Здравствуйте, введите время начала поездки, например 19:45:32 нижe \n";
	int hourse = 0;
	std::cin >> hourse;
	int minutes = 0;
	std::cin >> minutes;
	int seconds = 0;
	std::cin >> seconds;
	std::cout << "Пожалуйста, теперь введите конец поездки точно так же \n";
	int hourse1 = 0;
	std::cin >> hourse1;
	int minutes1 = 0;
	std::cin >> minutes1;
	int seconds1 = 0;
	std::cin >> seconds1;
	int start_time = hourse * 3600 + minutes * 60 + seconds;

	int end_time = hourse1 * 3600 + minutes1 * 60 + seconds1;

	if (end_time < start_time) {
		end_time += 24 * 3600;
	}


	int duration_seconds = end_time - start_time;


	int duration_minutes = (duration_seconds + 59) / 60;


	double tariff_per_minute = 2.0;
	double final_sum = duration_minutes * tariff_per_minute;

	std::cout << "С вас " << final_sum << " гривен";


	using namespace std;

	//Задача 3


	double distance1, fuelConsumption;
	double price1, price2, price3;


	cout << "Введите расстояние (км): ";
	cin >> distance1;

	cout << "Введите расход бензина на 100 км (л): ";
	cin >> fuelConsumption;

	cout << "Введите стоимость первого вида бензина (руб/л): ";
	cin >> price1;

	cout << "Введите стоимость второго вида бензина (руб/л): ";
	cin >> price2;

	cout << "Введите стоимость третьего вида бензина (руб/л): ";
	cin >> price3;


	double totalFuel = (distance1 * fuelConsumption) / 100.0;


	double cost1 = totalFuel * price1;
	double cost2 = totalFuel * price2;
	double cost3 = totalFuel * price3;


	cout << "\n" << string(60, '=') << endl;
	cout << "СРАВНИТЕЛЬНАЯ ТАБЛИЦА СТОИМОСТИ ПОЕЗДКИ" << endl;
	cout << string(60, '=') << endl;


	cout << left << setw(20) << "Вид бензина"
		<< setw(20) << "Цена (руб/л)"
		<< setw(20) << "Стоимость поездки" << endl;
	cout << string(60, '-') << endl;


	cout << fixed << setprecision(2);
	cout << left << setw(20) << "Бензин 1"
		<< setw(20) << price1
		<< setw(20) << cost1 << " руб." << endl;

	cout << left << setw(20) << "Бензин 2"
		<< setw(20) << price2
		<< setw(20) << cost2 << " руб." << endl;

	cout << left << setw(20) << "Бензин 3"
		<< setw(20) << price3
		<< setw(20) << cost3 << " руб." << endl;

	cout << string(60, '=') << endl;
}