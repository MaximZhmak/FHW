#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

//14. password generator
char*password()
{
	srand(time(0));
	const int size = 9;
	char*pass = new char[size];
	const char *symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789";
	bool condition1, condition2, condition3;
	condition1 = condition2 = condition3 = false;

	do
	{
		for (int i = 0; i < size - 1; i++)
		{
			pass[i] = symbols[rand() % strlen(symbols)];
			if (pass[i] >= '0' && pass[i] <= '9') //numbers
			{
				condition1 = true;
			}
			if (pass[i] >= 'A' && pass[i] <= 'Z') //capital letters
			{
				condition2 = true;
			}
			if (pass[i] >= 'a' && pass[i] <= 'z') //small letters
			{
				condition3 = true;
			}
		}

		pass[size - 1] = '\0';
	} while (condition1 == false ||
		condition2 == false ||
		condition3 == false);

	return pass;
}
//15.
int **CreateMatrix(int n, int m)
{

	//craeting 2D array
	int **array = new int*[n];
	for (int i = 0; i < n; i++)
		array[i] = new int[m];
	//initializing 2D array
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
int** TurnMatrix(int**matrix, int n, int m)
{
	//creating new turned matrix
	int **new_array = new int*[m];
	for (int i = 0; i < m; i++)
	{
		new_array[i] = new int[n];
	}
	//initializing new turned matrix
	for (int i = 0; i < m; i++)//
	{
		for (int j = 0; j < n; j++)
		{
			new_array[i][j] = matrix[n - 1 - j][i];
		}
	}
	return new_array;
}
//16.
int Determinant(int **matrix)
{
	return matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[0][1] * matrix[1][2] * matrix[2][0] +
		matrix[0][2] * matrix[1][0] * matrix[2][1] -
		matrix[0][2] * matrix[1][1] * matrix[2][0] -
		matrix[0][0] * matrix[1][2] * matrix[2][1] -
		matrix[0][1] * matrix[1][0] * matrix[2][2];

}
//17.
void MultMatrix(int **matrix1, int n1, int m1, int l1, int**matrix2)
{
	int **new_matrix = new int*[n1];
	for (int i = 0; i < n1; i++)
	{
		new_matrix[i] = new int[l1];
	}
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < l1; j++)
		{
			for (int k = 0; k < m1; k++)
			{
				new_matrix[i][j] = matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	cout << "Result of matrix multiplication: " << endl;
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < l1; j++)
		{
			cout << new_matrix[i][j] << " ";
		}
		cout << endl;
	}
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
	srand(time(0));

	//14
	cout << password() << endl;
	////15
	int n, m;
	cout << "enter n: ";
	cin >> n;
	cout << "enter m: ";
	cin >> m;
	int**matrix = CreateMatrix(n, m);
	int**matrix2;
	PrintMatrix(matrix, n, m);
	cout << "New Matrix: \n";
	matrix2 = TurnMatrix(matrix, n, m);
	PrintMatrix(matrix2, m, n);
	for (int i = 0; i < n; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;

	////16.
	cout << "Matrix: " << endl;
	int **matrix_2 = CreateMatrix(3, 3);
	PrintMatrix(matrix_2, 3, 3);
	cout << "Matrix determinant = " << Determinant(matrix_2) << endl;
	for (int i = 0; i < 3; i++)
	{
		delete[]matrix_2[i];
	}
	delete[]matrix_2;

	//17. 
	cout << "=================Matrix multiplication====================\n";
	int k = 0;
	cout << "Enter  number of rows of first matrix: ";
	cin >> n;
	cout << "Enter number of cols of first matrix: ";
	cin >> m;
	cout << "Enter number of cols of second matrix: ";
	cin >> k;

	int **matrix1 = new int*[n];
	////matrix1 creation
	for (int i = 0; i < n; i++)
		matrix1[i] = new int[m];
	////initializing matrix1
	cout << "First matrix: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "[" << i << "][" << j << "] :";
			cin >> matrix1[i][j];
		}
		cout << endl;
	}
	matrix2 = new int*[m];
	////matrix2 creation
	for (int i = 0; i < m; i++)
		matrix2[i] = new int[k];
	////initializing matrix1
	cout << "Second matrix: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << "[" << i << "][" << j << "] :";
			cin >> matrix2[i][j];
		}
		cout << endl;
	}
	MultMatrix(matrix1, n, m,k, matrix2);
	for (int i = 0; i < n; i++)
	{
		delete[]matrix1[i];
		delete[]matrix2[i];
	}
	delete[]matrix1;
	delete[]matrix2;

	////18.
	Professor professors[5];
	Student group[8];
	int count = sizeof(group) / sizeof(Student);
	cout << "Group GPA: " << GroupGPA(group, count) << endl;
	cout << "Best student: " << BestStudent(group, count)->name << endl;
	cout << "Worst student: " << WorstStudent(group, count)->name << endl;
	cout << "List of students with supervisors older than 50: " << endl;
	PrintStudents(group, count);

	return 0;
}