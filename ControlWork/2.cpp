#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
bool is_sorted(T* arr, size_t length)
{
	for (size_t i = 1; i < length; i++)
	{
		if (arr[i - 1] < arr[i])
			continue;
		else
			return false;
	}
	return true;
}


template<typename T>
size_t count_if(T* arr, size_t length, bool(*p)(const T& elem))
{
	size_t count = 0;

	for (size_t i = 0; i < length; i++)
	{
		if (p(arr[i]))
			count++;
	}

	return count;
}

template <typename T>
bool moreThanTwo(const T& elem)
{
	if (elem > 2)
		return true;
	else
		return false;
}

int main()
{
	const size_t size = 5;
	const int array1[] = { 1, 2, 3, 4, 5 };
	assert(count_if(array1, size, moreThanTwo) == 3);

	const double arrayD[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	assert(count_if(arrayD, size, moreThanTwo) == 3);

	//------------------------------------------------

	assert(is_sorted(array1, size));
	const char array2[] = "abcde";
	assert(is_sorted(array2, size));

	cout << "PASSED" << endl;
	return 0;
}



