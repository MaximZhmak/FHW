#include <iostream>
#include <cassert>

using namespace std;

template <class T, size_t quantity>
class Vector
{
	size_t m_size;
	T* m_data;

public:
	Vector() :m_size(quantity)
	{
		m_data = new T[m_size]();
	}

	Vector(const Vector& vect) : m_size(vect.m_size)
	{
		m_data = new T[m_size];
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = vect.m_data[i];
		}
	}
	~Vector()
	{
		delete[]m_data;
	}

	Vector& operator=(const Vector& vect)
	{
		if (&vect != this)
		{
			delete[]m_data;
			m_size = vect.m_size;
			m_data = new T[m_size];
			for (size_t i = 0; i < m_size; i++)
			{
				m_data[i] = vect.m_data[i];
			}			
		}
		return *this;
	}

	void push_back(const T& elem)
	{
		m_size++;
		T*temp = new T[m_size];

		for (size_t i = 0; i < m_size; i++)
		{
			temp[i] = m_data[i];
		}
		temp[m_size - 1] = elem;
		delete[]m_data;
		m_data = new T[m_size];
		m_data = temp;
	}
	size_t size() const
	{
		return m_size;
	}

	size_t capacity() const
	{
		return quantity;
	}

	T& operator[](size_t pos)
	{
		return m_data[pos];
	}

	const T& operator[](size_t pos) const
	{
		return m_data[i];
	}

	void insert(size_t pos, const T& value)
	{
		m_size++;
		T*temp = new T[m_size];
		for (size_t i = 0; i < pos; i++)
		{
			temp[i] = m_data[i];
		}
		temp[pos] = value;
		for (size_t i = pos + 1; i < length; i++)
		{
			temp[i] = m_data[i - 1];
		}
		delete[]m_data;
		m_data = new T[m_size];
		m_data = temp;
	}
	void erase(size_t pos)
	{
		m_size--;
		T *temp = new T[m_size];
		for (size_t i = 0; i < pos; i++)
		{
			temp[i] = m_data[i];
		}
		for (size_t i = pos; i < m_size; i++)
		{
			temp[i] = m_data[i + 1];
		}
		delete[]m_data;
		m_data = new T[m_size];
		m_data = temp;
	}
	T& front()
	{
		return m_data[0];
	}
	T& back()
	{
		return m_data[m_size - 1];
	}



	bool operator==(const Vector& vect) const
	{
		if (m_size != vect.m_size)
		{
			return false;
		}
		else
		{
			for (size_t i = 0; i < m_size; i++)
			{
				if (m_data[i] != vect.m_data[i])
				{
					return false;
				}
			}
		}
		return true;
	}
	
	bool operator <(const Vector& vect) const
	{
		if (m_size < vect.m_size)
		{
			return true;
		}
		else if (m_size > vect.m_size)
		{
			return false;
		}
		else if (m_size == vect.m_size)
		{
			for (size_t i = 0; i < m_size; i++)
			{
				if (m_data[i] != vect.m_data[i])
				{
					if (m_data[i] < vect.m_data[i])
						continue;
					else if (m_data[i] > vect.m_data[i])
						return false;
				}
			}
			return true;
		}
		return false;
	}
	bool operator <=(const Vector& vect) const
	{
		if (m_size <= vect.m_size)
		{
			return true;
		}
		else if (m_size > vect.m_size)
		{
			return false;
		}
		else if (m_size == vect.m_size)
		{
			for (size_t i = 0; i < m_size; i++)
			{
				if (m_data[i] != vect.m_data[i])
				{
					if (m_data[i] <= vect.m_data[i])
						continue;
					else if (m_data[i] > vect.m_data[i])
						return false;
				}
			}
			return true;
		}
		return false;
	}
	bool operator >(const Vector& vect) const
	{
		return !(this < vect);
	}
	bool operator >=(const Vector& vect) const
	{
		return !(this >= vect);
	}
	bool operator!=(const Vector& vect) const
	{
		return !(this == vect);
	}
};




int main()
{
	const size_t initial_capacity = 3;
	Vector <int, initial_capacity> vect1;

	Vector <int, initial_capacity> vect2;
	vect2 = vect1;
	assert(vect1 == vect2);

	Vector <int, initial_capacity> vect3(vect2);
	assert(vect3 == vect2);

	vect1.push_back(1);
	assert(vect1.back() == 1);
	assert(vect1.size() == 4);
	assert(vect1[3] == 1);

	vect1.erase(0);
	vect1.erase(0);
	vect1.erase(0);

	assert(vect1.front() == 1);
	assert(vect1 < vect2);
	assert(vect1 <= vect2);

	cout << "PASSED" << endl;
	return 0;
}