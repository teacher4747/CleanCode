#include <iostream>    
#include <iomanip>
#include <string>
#include <cctype>
#include <windows.h>
#include <cstdlib>
#include <ctime> 

using namespace std;

const int MAX_SIZE = 1000;

// Создать массив
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
    for (int i = 0; i < size; i++) 
    {
        cout << "[" << i << "] = " << array[i] << endl;
    }
}

// Меню 
void ArrayMenu() 
{
    cout << "\n=== ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ ===\n";
    cout << "1. Удаление массива\n";
    cout << "2. Изменить последний элемент массива\n";
    cout << "3. Показать массив\n";
    cout << "4. Вставить элемент по указанному индексу\n";
    cout << "5. Удалить элемент по указанному индексу\n";
    cout << "6. Выход\n";
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
    else {
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



// ========== UPDATE LOOOOL ==========



// Функция вставки элемента по индексу
int* InsertElement(int* oldArray, int& size, int index, int newValue)
{
    if (index < 0 || index > size) {
        cout << "Ошибка: неверный индекс для вставки!\n";
        return oldArray;
    }

    int* newArray = new int[size + 1];

    for (int i = 0; i < index; i++)
    {
        newArray[i] = oldArray[i];
    }

    newArray[index] = newValue;

    for (int i = index; i < size; i++) {
        newArray[i + 1] = oldArray[i];
    }

    delete[] oldArray;
    size++;

    cout << "Элемент " << newValue << " вставлен на позицию " << index << endl;
    return newArray;
}

// Функция удаления элемента по индексу
int* DeleteElement(int* oldArray, int& size, int index)
{
    if (size == 0)
    {
        cout << "Ошибка: массив пуст!\n";
        return oldArray;
    }

    if (index < 0 || index >= size)
    {
        cout << "Ошибка: неверный индекс для удаления!\n";
        return oldArray;
    }

    if (size == 1) 
    {
        delete[] oldArray;
        size = 0;
        cout << "Удалён последний элемент. Массив теперь пуст.\n";
        return nullptr;
    }

    int* newArray = new int[size - 1];

    for (int i = 0; i < index; i++) {
        newArray[i] = oldArray[i];
    }

    for (int i = index + 1; i < size; i++) {
        newArray[i - 1] = oldArray[i];
    }

    delete[] oldArray;
    size--;

    cout << "Элемент с индексом " << index << " удалён\n";
    return newArray;
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
        cout << "Неверный или слишкоб большой размер!\n";
        return 1;
    }

    myArray = CreateArray(size);
    FillArray(myArray, size);

    cout << "\nСоздан массив на " << size << " элементов\n";
    PrintArray(myArray, size);

    while (true) {
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
            
            if (size == 0) 
            {
                cout << "Массив пуст! Создайте массив сначала.\n";
                continue;
            }
            int index, value;
            cout << "Введите индекс для вставки (0-" << size << "): ";
            cin >> index;
            cout << "Введите значение нового элемента: ";
            cin >> value;
            myArray = InsertElement(myArray, size, index, value);
        }

        else if (choice == 5)
        {
            if (size == 0)
            {
                cout << "Массив пуст! Нечего удалять.\n";
                continue;
            }
            int index;
            cout << "Введите индекс для удаления (0-" << size - 1 << "): ";
            cin >> index;
            myArray = DeleteElement(myArray, size, index);
        }

        else if (choice == 6) 
        {
            cout << "Выход из программы...\n";
            break;
        }

        else {
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }

    
    if (myArray != nullptr) 
    {
        delete[] myArray;
    }

    return 0;
}