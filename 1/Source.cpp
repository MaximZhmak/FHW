#include <iostream>

using namespace std;



void main()
{
	setlocale(0, "rus");


	int number = 0;
	////1. Проверка четности введенного числа

	//cout << "Введите число: ";
	//cin >> number;
	////1.1 
	//if (number % 2 == 0)
	//	cout << "Четное" << endl;
	//else
	//	cout << "Нечетное" << endl;
	////1.2 
	//cout << "Введите число: ";
	//cin >> number;
	//if ((number & 1) == 0)
	//	cout << "Четное" << endl;
	//else
	//	cout << "Нечетное" << endl;


	////2 Сумма все цифр трехзначного числа

	//cout << "Введите трехзначное число: ";
	//cin >> number;
	//if (number < 100 || number > 999)
	//{
	//	cout << "Вы ввели не трехзначное число" << endl;;
	//	return;
	//}
	//else
	//{
	//	int a = number / 100;
	//	int b = (number % 100) / 10;
	//	int c = (number % 100) % 10;

	//	cout << "Сумма цифр = ";
	//	cout << a + b + c;
	//	cout << endl;
	//}
	//system("pause");

	////3 вывести все числа от 0 до 1000, которые одновременно содержат в себе цифры 1 и 7

	//for (int i = 10; i < 1000; i++)
	//{
	//	if (i < 100)
	//	{
	//		int a = i / 10;
	//		int b = i % 10;
	//		if (a == 1 && b == 7 || a == 7 && b == 1)
	//			cout << i << "\t";
	//	}
	//	else
	//	{
	//		int a = i / 100;
	//		int b = (i % 100) / 10;
	//		int c = (i % 100) % 10;

	//		if (a == 1 && b == 7 ||
	//			a == 1 && c == 7 ||
	//			b == 1 && c == 7 ||
	//			c == 1 && a == 7 ||
	//			c == 1 && b == 7 ||
	//			a == 7 && b == 1 ||
	//			a == 7 && c == 1)
	//			cout << i << "\t";
	//	}

	//}

	//4. Пересекаются ли окружности?

	int x1, x2, r1, r2, y1, y2;
	cout << "Введите Координаты центра первой окружности -";
	cout << "x1 :";
	cin >> x1;
	cout << "y1 :";
	cin >> y1;
	cout << "Введите радиус первой окружности :";
	cin >> r1;

	cout << "Введите Координаты центра второй окружности -";
	cout << "x2 :";
	cin >> x2;
	cout << "y2 :";
	cin >> y2;
	cout << "Введите радиус второй окружности :";
	cin >> r2;

	//найти расстояние мужду центрами двух окружностей
	double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	if (distance > (r1 + r2))
		cout << "Окружности не пересекаются" << endl;
	else if (distance == (r1 + r2))
		cout << "Окружности касаются" << endl;
	else if (distance < r1&&r2 < r1 ||
		     distance < r2&&r1 < r2)
		cout << "Одна окружность содержит другую*" << endl;
	else
		cout << "Окружности пересекаются" << endl;

	//5 Является ли введенное число кубом целого числа? 

	//cout << "Enter number: ";
	//cin >> number;
	//double result = 0;
	//for (int i = 0; i <= 100; i++)
	//{
	//	result = pow(i, 3);
	//	if (result == number)
	//	{
	//		cout << "yes: " << i << " ^ 3= " << number << endl;
	//		return;
	//	}
	//}
	//cout << "no" << endl;

	//6.1 Является ли введенное число степенью двойки? 

	//cout<<"Enter number: ";
	//cin >> number;
	//double result = 0;
	//for (int i=0;number>result;i++)
	//{
	//	result = pow(2, i);
	//    if (result == number)
	//    {
	//		cout << "yes: 2^" << i << +" = " << number << endl;
	//        return;
	//    }
	//}
	//cout<<"no"<<endl;


	//6.2
	//cout<<"Enter number: ";
	//cin >> number;
	//if ((number & (number - 1)) == 0)
	//	cout << "true";
	//else
	//	cout << "false";




}
