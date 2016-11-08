#include <iostream>
#include <time.h>
using namespace std;
//7
char*cat(char*string1, char* string2)
{
	int lenght = strlen(string1) + strlen(string2) + 1;
	char* stringnew = new char[lenght];
	for (int i = 0; i < strlen(stringnew); i++)
	{
		if (i < strlen(string1))
			stringnew[i] = string1[i];
		else
			stringnew[i] = string2[i - strlen(string1)];
	}
	stringnew[lenght - 1] = '\0';
	return stringnew;

}
//8
void RepeatCount(char*string)
{
	int i = 0;
	char*string1 = new char[strlen(string)];
	for (i = 0; i < strlen(string); i++)
	{

		int count = 0;
		cout << string[i] << "\t";
		string1[i] = string[i];
		for (int j = 0; j < strlen(string); j++)
		{
			if (tolower(string1[j]) == tolower(string[i]))
				count++;
		}
		cout << count << endl;
	}

}
//9
char*shiffredRaw(char*string)
{
	char table[] = { 'q','w','e','r','t','y','u','i','o','p' };
	char*newstring = new char[strlen(string) + 1];
	for (size_t i = 0; i < strlen(string); i++)
	{

	}


	return string;
}
//10
char*MakeCaps(char*string)
{
	char*str1 = new char[strlen(string) + 1];
	if (string[0] > 96 && string[0] < 123)
		str1[0] = string[0] - 32;
	else
		str1[0] = string[0];
	for (int i = 1; i < strlen(string); i++)
	{
		if (string[i] == 32)
		{
			str1[i] = string[i];
			str1[i + 1] = string[i + 1] - 32;
			i++;
		}

		else
		{
			str1[i] = string[i];
		}

	}
	str1[strlen(string)] = '\0';
	return str1;
}
//11
char*CuttedString(char*string)
{
	int lenght = strlen(string);
	char* str = new char[lenght];
	for (int i = 0; i < strlen(string); i++)
	{
		str[i] = string[i + 1];
		if (string[i + 2] == 32)
		{
			str[i + 1] = 32;
			str[i + 2] = string[i + 2];
			i += 2;

		}
	}
	str[lenght] = '\0';
	return str;
}
//12
void SwapArray()
{
	int *mas = new int[12];
	int mas1[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	for (int i = 0; i < sizeof(mas1) / sizeof(int); i++)
	{
		if ((i % 2 == 1) && i < sizeof(mas1) / sizeof(int) - 1)
		{
			int temp = mas1[i];
			mas1[i] = mas1[i + 1];
			mas1[i + 1] = temp;
		}
		cout << mas1[i] << " ";
	}
}
//13
void RandomizeArray()
{
	int Array[50];
	for (int i = 0, j = 0; i < 100; i++)
	{
		if ((i % 2) == 1)
		{
			Array[j] = i;
			cout << Array[j] << " ";
			j++;
		}
	}
	cout << "=========================================================" << endl;
	srand(time(0));

	for (int i = 0; i < 50; i++)
	{
		cout << Array[rand() % 51] << " ";
	}




}


void main()
{
	////	7. Напишите функцию cat(), которая принимает в качестве аргументов две C - строки и возвращает конкатенированную C - строку.
	////Используйте оператор new для выделения памяти под результат
	//cout << cat("Maxim ", "Zhmak") << endl;

	////8. Подсчитать количество повторений разных символов во введенной пользователем строке.
	//char*string = new char[20];
	//cin.getline(string,19);
	//RepeatCount(string);
	//
	////9.
	//char*string1 = new char[30];
	//cin.getline(string1, 29);
	//cout << shiffredRaw(string1);

	//10
	//cout << MakeCaps("just another string with few words") << endl;

	//11. Дана строка символов, которая обязательно заканчивается символом точки. Удалить из строки первые буквы каждого слова.
	//cout << CuttedString("just another string with few words") << endl;
	//12
	//SwapArray();
	//13
	RandomizeArray();


}