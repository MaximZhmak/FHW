#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <cstring>

using namespace std;

struct RepeatingSymbol
{
	char symb;
	int count;
};

bool AlreadyAdded(const char symbol, RepeatingSymbol* array, int currentIndex)
{
	for (int i = 0; i < currentIndex; i++)
	{
		if (symbol == array[i].symb)
		{
			array[i].count++;
			return true;
		}
	}
	return false;
}

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
void RepeatCount()
{
	cout << "Enter string for counting repeats: ";
	char*string = new char[20];
	cin.getline(string, 19);
	RepeatingSymbol * array = new RepeatingSymbol[strlen(string)];
	int repeats = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (AlreadyAdded(string[i], array, i)==false)
		{
			array[i].count = 1;
			array[i].symb = string[i];
		}
		else
		{
			repeats++;
		}
	}
	for (int i = 0; i < strlen(string)-repeats; i++)
	{
		if (array[i].count != 0)
			cout << array[i].symb << " = " << array[i].count << endl;
	}
	delete[]string;
	string = nullptr;
	delete[]array;
	array = nullptr;
}
//9
char*shiffredRaw(char* string)
{
	const char*table = "abcdefgh123456-0";
	for (size_t i = 0; i < strlen(string); i++)
	{
		for (int j = 0; j < strlen(table); j++)
		{
			if (string[i] == table[j])
			{
				string[i] = table[(j + 5) % strlen(table)];
				break;
			}
		}
	}
	return string;
}
//10
void MakeCaps(char*string)
{
	char*str1 = new char[strlen(string)+1]();
	if (string[0] >= 'a' && string[0] <= 'z')
		str1[0] = toupper(string[0]);
	else
		str1[0] = string[0];
	for (int i = 1; i < strlen(string); i++)
	{
		str1[i] = string[i];
		if (string[i] == ' ')
		{
			str1[i + 1] = toupper(string[i + 1]);		
			i++;
		}
	}
	cout << str1 << endl;
	delete[]str1;
	str1 = nullptr;
}
//11
char*CuttedString(char*string)
{
	int j = 0;
	int lenght = strlen(string)-1;
	char* str = new char[lenght];
	for (int i = 1; i < strlen(string); i++)
	{
		str[j] = string[i];
		j++;
		if (string[i] == ' ')
		{
			i++;
			lenght--;
		}
	}
	
	str[lenght] = '\0';
	return str;
}
//12
void SwapArray()
{
	int mas1[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	for (int i = 0; i < sizeof(mas1) / sizeof(int); i++)
	{
		if ((i % 2 == 1) && i < sizeof(mas1) / sizeof(int) - 1)
		{
			swap(mas1[i], mas1[i + 1]);
		}
		cout << mas1[i] << " ";
	}
}
//13
void RandomizeArray()
{
	const int size = 50;
	int Array[size];
	for (int i = 1, j = 0; i < size*2; i += 2)
	{
		Array[j] = i;
		cout << Array[j] << " ";
		j++;
	}
	cout << "\n=========================================================" << endl;
	
	srand(time(0));
	
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		j = rand() % size;
		swap(Array[i], Array[j]);
		cout << Array[i] << " ";
	}
}


void main()
{
	//	7. 

	cout << cat("Maxim ", "Zhmak") << endl;

	//8. 
	RepeatCount();
	//9.
	cout << "Enter string: ";
	char*string1 = new char[30];
	cin.getline(string1, 29);
	cout << shiffredRaw(string1) << endl;
	delete[]string1;
	string1 = nullptr;
	////10
	char* text = "just another string with few words";
	MakeCaps(text);
	//11. 
	cout << CuttedString("a b c d") << endl;
	//12
	SwapArray();
	////13
	RandomizeArray();
}