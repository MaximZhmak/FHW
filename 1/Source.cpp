#include <iostream>

using namespace std;



void main()
{
	setlocale(0, "rus");


	int number = 0;
	////1. �������� �������� ���������� �����

	//cout << "������� �����: ";
	//cin >> number;
	////1.1 
	//if (number % 2 == 0)
	//	cout << "������" << endl;
	//else
	//	cout << "��������" << endl;
	////1.2 
	//cout << "������� �����: ";
	//cin >> number;
	//if ((number & 1) == 0)
	//	cout << "������" << endl;
	//else
	//	cout << "��������" << endl;


	////2 ����� ��� ���� ������������ �����

	//cout << "������� ����������� �����: ";
	//cin >> number;
	//if (number < 100 || number > 999)
	//{
	//	cout << "�� ����� �� ����������� �����" << endl;;
	//	return;
	//}
	//else
	//{
	//	int a = number / 100;
	//	int b = (number % 100) / 10;
	//	int c = (number % 100) % 10;

	//	cout << "����� ���� = ";
	//	cout << a + b + c;
	//	cout << endl;
	//}
	//system("pause");

	////3 ������� ��� ����� �� 0 �� 1000, ������� ������������ �������� � ���� ����� 1 � 7

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

	//4. Do these circles intersect?

	int x1, x2, r1, r2, y1, y2;
	cout << "Please enter coordinates of first circle -";
	cout << "x1 :";
	cin >> x1;
	cout << "y1 :";
	cin >> y1;
	cout << "Please enter radius of first circle :";
	cin >> r1;

	cout << "Please enter coordinates of second circle -";
	cout << "x2 :";
	cin >> x2;
	cout << "y2 :";
	cin >> y2;
	cout << "Please enter radius of first circle :";
	cin >> r2;

	//find distance between centers of two circles
	auto distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	if (r1 > distance + r2 || r2>distance+r1)
		cout << "One circle contains another" << endl; 
	else if (r1+r2>distance)
		cout << "Circles intersect" << endl;
	else
		cout << "Circles do not intersect" << endl;	

			//5 �������� �� ��������� ����� ����� ������ �����? 

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

			//6.1 �������� �� ��������� ����� �������� ������? 

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
