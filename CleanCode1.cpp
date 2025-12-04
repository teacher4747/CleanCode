#include <iostream>  
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	// Задача 1 
		cout << "Здравствуйте, введите целое шестизначное число ниже";
		int number = 0;
		cin >> number;

		if (number > 999999 || number < 100000) {
			cout << "Число должно быть шестизначным";
			return 1;
		}
		int firstpart = number / 1000;
		int secondpart = number % 1000;
		int sumFirst = (firstpart / 100) + ((firstpart / 10) % 10) + (firstpart % 10);
		int sumSecond = (secondpart / 100) + ((secondpart / 10) % 10) + (secondpart % 10);

		if (sumFirst == sumSecond) {
			cout << "Число счастливое!" << endl;
		}
		else {
			cout << "Число не является счастливым." << endl;
		}


//Задача 2
string numberStr;


cout << "Введите четырехзначное число: ";
cin >> numberStr;


if (numberStr.length() != 4) {
	cout << "Ошибка! Введите ровно четыре цифры." << endl;
	return 1;
}


for (char c : numberStr) {
	if (!isdigit(c)) {
		cout << "Ошибка! Введены не только цифры." << endl;
		return 1;
	}
}


cout << "\nИсходное число: " << numberStr << endl;


swap(numberStr[0], numberStr[1]);
swap(numberStr[2], numberStr[3]);


cout << "Результат после замены: " << numberStr << endl;

// Задача 3 
	int max = 0;
	int number1;
	cout << "Введите первое число ";
	cin >> number1;
	number1 = max;
	for (int i = 0; i < 6; i++) {
		cout << "Введите число\n1";
		cin >> number1;
		if (number1 > max) {
			max = number1;
		}
		cout << "Максимальное число: " << max << endl;
	}

}