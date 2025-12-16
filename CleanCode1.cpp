#include <iostream>  
#include <iomanip>
#include <string>
#include <cctype>
#include <windows.h>

using namespace std;

const int VAGONS = 18;
const int SEATS = 36;

// Заполнение нулями
void FillWithZero(int train[VAGONS][SEATS])
{
	for (int v = 0; v < VAGONS; v++)
	{
		for (int s = 0; s < SEATS; s++) 
		{
			train[v][s] = 0;
		}
	}
}

// Заполнение на рандом
void RandomSeats(int train[VAGONS][SEATS])
{
	for (int v = 0; v < VAGONS; v++)
	{
		for (int s = 0; s < SEATS; s++)
		{
			train[v][s] = rand() % 2; 
		}
	}
}


// Забронить место
bool ReverseSeat(int train[VAGONS][SEATS], int vagon, int seat)
{
	if (vagon < 1 || vagon > VAGONS || seat < 1 || seat >> SEATS)
	{
		cout << "Неверный номер вагона или место \n"; 
		return false; 
	}

	int  v = vagon - 1; 
	int s = seat - 1;

	if (train[v][s] = 0)
	{
		train[v][s] = 1; 
		cout << "Место" << seat << "в вагоне" << vagon << " теперь забранировано вами \n"; 
		return true; 
	}
	else
	{
		cout << "Это место уже забронировано кем-то другим \n"; 
		return false; 
	}
}

// Освободить место
bool FreeSeatSpecialForYou(int train[VAGONS][SEATS], int vagon, int seat)
{
	if (vagon < 1 || vagon > VAGONS || seat < 1 || seat >> SEATS)
	{
		cout << "Неверный номер вагона или место \n";
		return false;
	}

	int  v = vagon - 1;
	int s = seat - 1;

	if (train[v][s] = 1)
	{
		train[v][s] = 0;
		cout << "Место" << seat << "в вагоне" << vagon << "освобождено \n";
		return true;
	}
	else
	{
		cout << "Место уже свободно \n";
		return false;
	}
}


// Места в свободном вагоне
int FreeInVagon(int train[VAGONS][SEATS], int vagonNumber) {
	
	int count = 0;
	int v = vagonNumber - 1; 

	for (int seat = 0; seat < SEATS; seat++) {
		if (train[v][seat] == 0) {
			count++;
		}
	}
	return count;
}

// Все свободные места
int TotalFree(int train[VAGONS][SEATS])
{
	int total = 0;

	for (int vagon = 0; vagon < VAGONS; vagon++)
	{
		for (int seat = 0; seat < SEATS; seat++) 
		{
			if (train[vagon][seat] == 0) 
			{
				total++;
			}
		}
	}
	return total;
}

// Места во всем поезде
void DisplayTrain(int train[VAGONS][SEATS])
{
	cout << "\n=== СОСТОЯНИЕ ПОЕЗДА ===\n";

	for (int v = 0; v < VAGONS; v++)
	{
		cout << "Вагон " << (v + 1) << ": ";

		for (int s = 0; s < SEATS; s++)
		{
			if (train[v][s] == 0)
			{
				cout << "O "; 
			}
			else
			{
				cout << "X "; 
			}
		}
		cout << endl;
	}
	cout << "O - свободно, X - занято\n";
}


// Главное меню. 
void ShowMenu() {
	cout << "\n=== СИСТЕМА БРОНИРОВАНИЯ ===\n";
	cout << "1. Забронировать место\n";
	cout << "2. Освободить место\n";
	cout << "3. Показать свободные места в вагоне\n";
	cout << "4. Показать все свободные места\n";
	cout << "5. Отобразить весь поезд\n";
	cout << "6. Выйти\n";
	cout << "Выберите действие: ";

}



int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	setlocale(LC_ALL, "RUS");

	

	int train[VAGONS][SEATS]; 
	int choise; 

	cout << "Выберите режим заполнения \n "; 
	cout << "1. Рандомное заполнение \n";
	cout << "2. Все места пусты\n";
	cin >> choise; 
	
	if (choise == 1)
	{
		RandomSeats(train); 
	}
	else
	{
		FillWithZero(train); 
	}
	while (true)
	{ 
	ShowMenu(); 
	int choice2 = 0; 
	cin >> choice2; 

	if (choice2 == 1)
	{
		int vagon, seat;
		cout << "Введите номер вагона (1-" << VAGONS << "): ";
		cin >> vagon;
		cout << "Введите номер места (1-" << SEATS << "): ";
		cin >> seat;

		ReverseSeat(train, vagon, seat);
	}
	else if (choice2 == 2)
	{
		int vagon1, seat1;
		cout << "Введите номер вагона (1-" << VAGONS << "): ";
		cin >> vagon1;
		cout << "Введите номер места (1-" << SEATS << "): ";
		cin >> seat1;

		FreeSeatSpecialForYou(train, vagon1, seat1);

	}

	else if (choice2 == 3)
	{
		int vagonNum;
		cout << "Введите номер вагона: ";
		cin >> vagonNum;

		int free = FreeInVagon(train, vagonNum);
		if (free == -1)
		{
			cout << "Ошибка!\n";
		}
		else
		{
			cout << "Свободных мест: " << free << endl;
		}
	}

	else if (choice2 == 4)
	{
		int allFree = TotalFree(train);
		cout << "Всего свободных мест в поезде: " << allFree << endl;
	}

	else if (choice2 == 5)
	{
		DisplayTrain(train);
	}

	else if (choice2 == 6)
	{
		break; 
	}
	else
	{
		cout << "Ошибка: выберите 1-6\n";
	}
}
	cout << "Программа завершена.\n";



}