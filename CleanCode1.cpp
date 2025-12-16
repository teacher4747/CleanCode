#include <iostream>    
#include <iomanip>
#include <string>
#include <cctype>
#include <windows.h>
#include <cstdlib>
#include <ctime> 

using namespace std;

const int MAX_SIZE = 1000; 

// Созадть массив
int* CreateArray(int size)
{
    int* array = new int[size];
    return array;
}

// Инициализировать массив
void FillArray(int* array, int size)
{  
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
}

// Вывести массив 
void PrintArray(int* array, int size)
{
    if (array == nullptr || size == 0)
    {
        cout << "Массив пуст!\n";
        return;
    }
    cout << "\nМассив [" << size << " элементов]:\n";
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] = " << array[i] << endl;
    }
}

// Меню 
void ArrayMenu() {
    cout << "\n=== ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ ===\n";
    cout << "1. Удаление массива\n";
    cout << "2. Изменить последний элемент массива\n";
    cout << "3. Показать массив\n";
    cout << "4. Выход\n";
    cout << "Выберите действие: ";
}

// Удалить массив 
void DeleteArray(int*& array, int& size)
{
    if (array != nullptr)
    {
        delete[] array;
        array = nullptr;
        size = 0;
        cout << "Массив успешно удалён.\n";
    }
    else 
    {
        cout << "Массив уже пуст или не был создан.\n";
    }
}

// Поменять последнее число 
void SetLastElement(int* array, int size, int newDigit)
{
    if (size > 0)
    {
        cout << "\nМеняем последний элемент с " << array[size - 1]
            << " на " << newDigit << endl;
        array[size - 1] = newDigit;
        PrintArray(array, size);
    }
    else 
    {
        cout << "Ошибка: массив пуст!\n";
    }
}

int main() 
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");

    int size = 0;
    int* myArray = nullptr;

    
    cout << "=== СОЗДАНИЕ МАССИВА ===\n";
    cout << "Введите размер массива: ";
    cin >> size;

    if (size <= 0 || size > MAX_SIZE) 
    {
        cout << "Неверный размер!\n";
        return 1;
    }

    myArray = CreateArray(size);
    FillArray(myArray, size);

    cout << "\nСоздан массив на " << size << " элементов\n";
    PrintArray(myArray, size);

    
    while (true)
    {
        ArrayMenu();
        int choice;
        cin >> choice;

        if (choice == 1)
        {
           
            DeleteArray(myArray, size);
        }
        else if (choice == 2) 
        {
            
            if (size > 0)
            {
                int digit;
                cout << "Введите новое значение для последнего элемента: ";
                cin >> digit;
               SetLastElement(myArray, size, digit);
            }
            else 
            {
                cout << "Массив пуст! Сначала создайте массив.\n";
            }
        }
        else if (choice == 3) 
        {
            
            PrintArray(myArray, size);
        }
        else if (choice == 4) 
        {
           
            cout << "Выход из программы...\n";
            break;
        }
        else 
        
        {
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }

    if (myArray != nullptr) 
    {
        delete[] myArray;
    }

    return 0;
}