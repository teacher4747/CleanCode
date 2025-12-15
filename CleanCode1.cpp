#include <iostream>  
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

int main()

{
	setlocale(LC_ALL, "RUS");
	 // 1 
	string text; 
	cout << "Здравствуйте, введите ваше предложение ниже: " << endl; 
	getline(cin, text);

	for (int i = 0; i < text.length(); i++) 
	{

		if (text.length() == 0) {
			cout << "Вы ничего не ввели!" << endl;
		}

		if (i == 0 || text[i - 1] == ' ')
		{
			text[i] = toupper(text[i]);
		}
		else 
		{
			text[i] = tolower(text[i]);
		}
	}
	


}