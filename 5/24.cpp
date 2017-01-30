#include <iostream>

using namespace std;


template <class T>
void PrintArray(const T* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
template <class T>
void InitializeArray(T* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = i;
	}
}

template <class T>
T* Map(T array[], int size, T(*f)(T& num))
{
	for (int i = 0; i < size; i++)
	{
		array[i] = f(array[i]);
	}
	return array;
}

template <class T>
T* Filter(T array[], int &size, bool(*f)(const T& num))
{
	T * temp_array = new T[size];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (f(array[i]))
		{
			temp_array[j] = array[i];
			j++;
		}
	}
	size = j;
	return temp_array;
}
template <class T>
T Reduce(const T array[], int size, T(*f)(const T& num1, const T& num2))
{
	T value = 0;
	for (int shift = 1; shift < size; shift++)
	{
		value = f(value, array[shift]);
	}
	return value;
}


//funcs for map
template <class T>
T Increment(T& num)
{
	return ++num;
}
template <class T>
T Decrement(T&num)
{
	return --num;
}
//funcs for filter
template <class T, int N>
bool MoreThanN(const T& num)
{
	return num > N;
}
template <class T, int N>
bool LessThanN(const T& num)
{
	return !MoreThanN<T, N>(num);
}
//funcs for reduce
template <class T>
T Sum(const T& num1, const T& num2)
{
	return num1 + num2;
}
template <class T>
T Subs(const T& num1, const T& num2)
{
	return num1 - num2;
}



int main()
{
	const int size = 20;
	int array[size] = {};
	InitializeArray(array, size);

	double arrayD[size] = {};
	InitializeArray(arrayD, size);

	cout << "Initial array: ";
	PrintArray(array, size);
	PrintArray(arrayD, size);
	//map

	cout << "Incremented array: ";
	PrintArray(Map(array, size, Increment), size);

	cout << "Decremented array: ";
	PrintArray(Map(arrayD, size, Decrement), size);




	//filter

	int new_size = size;
	int*array1 = Filter(array, new_size, LessThanN<int,10>);
	cout << "Elements of Array1 that are Less Then 10: " << endl;
	PrintArray(array1, new_size);


	new_size = size;
	delete[]array1;

	double*	arrayD1 = Filter(arrayD, new_size, MoreThanN<double, 10>);
	cout << "Elements of Array1 that are More Then 10: " << endl;
	PrintArray(arrayD1, new_size);


	//reduce

	cout << "Sum of elements of array: ";
	cout << Reduce(array, size, Sum) << endl;


	cout << "Difference between elements of array: ";
	cout << Reduce(arrayD, size, Subs) << endl;


	return 0;
}
