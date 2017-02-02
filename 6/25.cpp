#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>

using namespace std;

template<typename T, int N>
class stack
{
	T m_data[N];
	size_t m_count;
public:
	stack() :m_data(), m_count(0) {}

	void push(const T& value)
	{
		m_data[m_count++] = value;
	}

	T pop()
	{
		return m_data[--m_count];
	}
};

template<int N>
class stack<bool, N>
{
	char m_data[N];
	size_t m_count;
public:
	stack() :m_data(), m_count(0) {}

	void push(const bool& value)
	{
		int bit_num = m_count / 8;
		int bit_offset = m_count % 8;

		m_data[bit_num] ^= (-value ^ m_data[bit_num]) & (1 << (7 - bit_offset));
		m_count++;
	}

	bool pop()
	{
		int num_elem = (m_count - 1) / 8;
		int offset_elem = (m_count - 1) % 8;
		m_count--;
		return  m_data[num_elem] & (1 << (7 - offset_elem));
	}
};

int main()
{
	
	vector<int>vect(0);
	stack<bool, 4> stack;
	const size_t size = 10;
	for (size_t i = 0; i < size; i++)
	{
		auto num = rand() % 2;
		vect.push_back(num);
		stack.push(num);
	}
	for (int i = size - 1; i >= 0; i--)
		assert(vect[i] == stack.pop());

	cout << "PASSED" << endl;
	return 0;
}