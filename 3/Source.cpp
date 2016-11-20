#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

//14. генератор паролей
char*password()
{
	srand(time(0));
	char*pass = new char[9];
	char*symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";
	bool condition1, condition2, condition3;
	condition1 = condition2 = condition3 = false;
	do
	{
		for (int i = 0; i < 8; i++)
		{
			pass[i] = symbols[rand() % strlen(symbols)];
		}
		pass[8] = '\0';
		for (int i = 0; i < 8; i++)
		{
			if (pass[i] > 47 && pass[i] < 58) //есть цифры
			{
				condition1 = true;
				break;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (pass[i] > 64 && pass[i] < 91) //есть большие буквы
			{
				condition2 = true;
				break;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (pass[i] > 96 && pass[i] < 123) //есть маленькие буквы
			{
				condition3 = true;
				break;
			}
		}
	} while (condition1 == false ||
		condition2 == false ||
		condition3 == false);
	delete[]symbols;
	return pass;
}
//15.
int **CreateMatrix(int n, int m)
{
	srand(time(0));
	//создание двумерного динам.массива
	int **array = new int*[n];
	for (int i = 0; i < n; i++)
		array[i] = new int[m];
	//заполнение двум.дин.массива
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			array[i][j] = (rand() % 21);
	return array;
}
void PrintMatrix(int**matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
}
int **TurnMatrix(int**matrix, int n, int m)
{
	int **new_array = new int*[n];
	for (int i = 0; i < m; i++)
		new_array[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			new_array[i][j] = matrix[j][i];
	return new_array;
}
//16.
int Determinant(int **matrix, int n, int m)
{
	return matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[0][1] * matrix[1][2] * matrix[2][0] +
		matrix[0][2] * matrix[1][0] * matrix[2][1] -
		matrix[0][2] * matrix[1][1] * matrix[2][0] -
		matrix[0][0] * matrix[1][2] * matrix[2][1] -
		matrix[0][1] * matrix[3][2] * matrix[2][2];

}
//17.
void MultMatrix(int **matrix1, int n1, int m1, int**matrix2)
{

	int **NEWMATRIX = new int *[n1];
	for (int i = 0; i < n1; i++)
		NEWMATRIX[i] = new int[m1];
	//умножение матриц
	cout << "Произведение матриц: " << endl;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			NEWMATRIX[i][j] = matrix1[i][j] * matrix2[i][j];
			cout << setw(3) << NEWMATRIX[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < n1; i++)
	{
		delete[]NEWMATRIX[i];
	}
	delete[]NEWMATRIX;
}
//18.
struct Professor
{
	char name[20];
	unsigned short age;
	unsigned int salary;
};
struct Student
{
	char name[20];
	unsigned short age;
	float gpa;
	Professor*supervisor;
};
int GroupGPA(Student*group, int count)
{
	float sum = 0;
	for (int i = 0; i < count; i++)
		sum += group[i].gpa;
	return sum / count;
}
Student * BestStudent(Student*group, int count)
{
	Student*best_student = &group[0];
	for (int i = 1; i < count; i++)
	{
		if (best_student->gpa < group[i].gpa)
			best_student = &group[i];
	}
	return best_student;
}
Student * WorstStudent(Student*group, int count)
{
	Student*worst_student = &group[0];
	for (int i = 1; i < count; i++)
	{
		if (worst_student->gpa > group[i].gpa)
			worst_student = &group[i];
	}
	return worst_student;
}
void PrintStudents(Student*group, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (group[i].supervisor->age > 50)
			cout << group[i].name << endl;
	}
}


int main()
{
	setlocale(0, "rus");
	//14
	cout << password() << endl;
	////15
	int n, m;
	cout << "enter n: ";
	cin >> n;
	cout << "enter m: ";
	cin >> m;
	int**matrix = CreateMatrix(n, m);
	PrintMatrix(matrix, n, m);
	cout << "New Matrix: \n";
	matrix = TurnMatrix(matrix, n, m);
	PrintMatrix(matrix, n, m);
	for (int i = 0; i < n; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;

	////16.
	cout << "Matrix: " << endl;
	int **matrix_2 = CreateMatrix(3, 3);
	PrintMatrix(matrix_2, 3, 3);
	cout << "Matrix determinant = " << Determinant(matrix_2, 3, 3) << endl;
	for (int i = 0; i <3; i++)
	{
		delete[]matrix_2[i];
	}
	delete[]matrix_2;

	//17. 
	cout << "=================Matrix multiplication====================\n";
	int n, m;
	cout << "Введите кол-во строк  ";
	cin >> n;
	cout << "Введите кол-во столбцов ";
	cin >> m;
	int **matrix1 = new int*[n];
	//создание матрицы1
	for (int i = 0; i < n; i++)
		matrix1[i] = new int[m];
	//заполнение матрицы
	cout << "Первая матрица: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "[" << i << "][" << j << "] :";
			cin >> matrix1[i][j];
		}
		cout << endl;
	}
	int **matrix2 = new int*[n];
	//создание матрицы2
	for (int i = 0; i < n; i++)
		matrix2[i] = new int[m];
	//заполнение матрицы
	cout << "Вторая матрица: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout <<"["<<i<<"]["<<j<<"] :";
			cin >> matrix2[i][j];			
		}
		cout << endl;
	}
	MultMatrix(matrix1, n, m, matrix2);
	for (int i = 0; i < n; i++)
	{
		delete[]matrix1[i];
		delete[]matrix2[i];
	}
	delete[]matrix1;
	delete[]matrix2;

	//18.
	Professor professors[5];
	Student group[8];
	int count = sizeof(group) / sizeof(Student);
	cout << "Средний балл группы: " << GroupGPA(group, count) << endl;
	cout << "Лучший студент: " <<BestStudent(group,count)->name << endl;
	cout << "Худший студент: " <<WorstStudent(group,count)->name << endl;
	cout << "Список студентов с научными руководителями старше 50ти лет: " << endl;
	PrintStudents(group, count);

	return 1;
}