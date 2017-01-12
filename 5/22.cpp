#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class String
{
	char* m_buffer;
	size_t* m_refCounter;

	void Attach(const String& rhs)
	{

		m_refCounter = rhs.m_refCounter;
		m_buffer = rhs.m_buffer;
		(*m_refCounter)++;
	}
	void Detach()
	{
		(*m_refCounter)--;

		m_buffer = nullptr;

	}
public:
	String(const char* value)
		: m_buffer(new char[strlen(value) + 1]),
		m_refCounter(new size_t(0))
	{
		strcpy(m_buffer, value);
		(*m_refCounter)++;
	}

	String(const String& rhs)
		: m_buffer(rhs.m_buffer)
		, m_refCounter(rhs.m_refCounter)
	{
		(*m_refCounter)++;
	}

	~String()
	{
		(*m_refCounter)--;

		if (*m_refCounter == 0)
		{
			if (m_buffer)
			{
				delete[] m_buffer;
				m_buffer = nullptr;
			}
		}
	}


	String& operator=(const String& rhs)
	{
		if (rhs.m_buffer != m_buffer)
		{
			Detach();
			Attach(rhs);
		}
		return *this;
	}

	String& operator=(const char* value)
	{
		char* temp = new char[strlen(value) + 1]();
		strcpy(temp, value);

		Detach();

		delete[]m_buffer;
		m_buffer = new char[strlen(temp) + 1];
		strcpy(m_buffer, temp);


		delete[]temp;

		return *this;
	}
	const char& operator[](const size_t index) const
	{
		return m_buffer[index];
	}


	size_t GetCount() const
	{
		return *m_refCounter;
	}
	void SetElem(size_t index, char value)
	{

		char* temp = new char[strlen(m_buffer) + 1]();
		strcpy(temp, m_buffer);
		temp[index] = value;

		Detach();

		delete[]m_buffer;
		m_buffer = new char[strlen(temp) + 1];
		strcpy(m_buffer, temp);

		delete[]temp;
	}
	
	char* GetBuffer() const
	{
		return m_buffer;
	}
};



int main(int argc, char *argv[])
{

	String s("abc");
	assert(s.GetCount() == 1);

	{
		String s2 = s;
		assert(s.GetCount() == 2);
		assert(s2.GetCount() == 2);
	}

	assert(s.GetCount() == 1);

	String s3 = s;
	assert(s.GetCount() == 2);

	String s4("xyz");
	s3 = s4;

	assert(s.GetCount() == 1);
	
	s4.SetElem(0, '@');

	assert(s3[0] == 'x');
	assert(s4[0] == '@');


	assert(s3.GetCount() == s4.GetCount() && s4.GetCount() == 1);

	assert(strcmp(s.GetBuffer(), "abc") == 0);


	cout << "PASSED" << endl;
	return 0;
}