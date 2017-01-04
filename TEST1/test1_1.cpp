#include <iostream>
#include <cassert>

using namespace std;


template <class T>
void Print(T array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}



template <class T>
class ImmutableBuffer
{
private:

	int m_size;
	ImmutableBuffer& operator=(const ImmutableBuffer& object)
	{
		if (&object != this)
		{
			delete[]m_array;
			m_size = object.m_size;
			m_array = new T[m_size];
			for (int i = 0; i < m_size; i++)
			{
				m_array[i] = object.m_array[i];
			}
		}
		return *this;
	}

public:
	T* m_array;
	ImmutableBuffer() {}
	ImmutableBuffer(T* array, const int size) :m_size(size)
	{
		m_array = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_array[i] = array[i];
		}
	}
	ImmutableBuffer(const ImmutableBuffer& object) :m_size(object.m_size)
	{

		m_array = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_array[i] = object.m_array[i];
		}
	}


	const T&operator[](int index) const
	{
		if (index >= 0 && index < m_size)
		{
			return m_array[index];
		}
	}
	~ImmutableBuffer()
	{
		delete[]m_array;
		m_array = nullptr;
	}

	bool operator == (const ImmutableBuffer<T>& obj2)const
	{
		if (m_size != obj2.m_size)
		{
			return false;
		}
		else
		{
			for (int i = 0; i <m_size; i++)
			{
				if (m_array[i] != obj2.m_array[i])
				{
					return false;
				}
			}
		}
		return true;
	}
	bool operator !=(const ImmutableBuffer<T>& obj)const
	{
		return !(this == obj);
	}
	template<class T> 
	friend ostream& operator<<(ostream& os, const ImmutableBuffer<T> obj);

};


template<class T>
ostream& operator<<(ostream& os, const ImmutableBuffer<T> obj)
{
	for (int i = 0; i < obj.m_size; i++)
	{
		os << obj.m_array[i] << " ";
	}
	return os;
}



int main()
{
	const int size = 5;
	int array1[size] = { 1,2,3,4,5 };
	ImmutableBuffer<int> buffer(array1, size);
	cout << buffer << endl;
	ImmutableBuffer<int> buffer1(buffer);

	cout << buffer1 << endl;
	ImmutableBuffer<int> buffer3 = buffer1;
	cout << buffer3 << endl;


	assert(buffer[0] == buffer1[0]);
	assert(buffer1 == buffer3);
	
	return 0;
}
