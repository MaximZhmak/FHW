#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

char *arab2roman(unsigned short int arab);
unsigned short int roman2arab(const char *roman);

class RomanNumber
{
private:
	unsigned short int m_number;
	static const int arabar[];
	static const char *romanar[];

public:
	RomanNumber(const char * string)
	{
		m_number = roman2arab(string);
	}
	RomanNumber(unsigned short int value) : m_number(value)
	{

	}

	//---------------------------------------------------------

	explicit operator unsigned short int() const
	{
		return m_number;
	}

	//----------------------------------------------------------
	RomanNumber operator+(const RomanNumber &num) const
	{
		unsigned short int rhs = static_cast<unsigned short>(num);
		return RomanNumber(m_number + rhs);
	}
	RomanNumber operator-(const RomanNumber &num) const
	{
		if (m_number > static_cast<unsigned short>(num))
		{
			unsigned short int rhs = static_cast<unsigned short>(num);
			return RomanNumber(m_number - rhs);
		}
	}
	RomanNumber operator*(const RomanNumber &num) const
	{
		unsigned short int rhs = static_cast<unsigned short>(num);
		return RomanNumber(m_number * rhs);
	}
	RomanNumber operator/(const RomanNumber &num) const
	{
		if (this->m_number > static_cast<unsigned short>(num))
		{
			unsigned short int rhs = static_cast<unsigned short>(num);
			return RomanNumber(m_number / rhs);
		}
	}

	RomanNumber operator+(const int value)
	{
		m_number += value;
		return *this;
	}
	RomanNumber operator-(const int value)
	{
		if (m_number > value)
		{
			m_number -= value;
			return *this;
		}
	}
	RomanNumber operator*(const int value)
	{
		m_number *= value;
		return *this;
	}
	RomanNumber operator/(const int value)
	{
		if (this->m_number > value)
		{
			m_number /= value;
			return *this;
		}
	}

	//----------------------------------------------------------
	RomanNumber& operator+=(const RomanNumber &num)
	{
		m_number += static_cast<unsigned short>(num);
		return *this;
	}
	RomanNumber& operator-=(const RomanNumber &num)
	{
		if (m_number > static_cast<unsigned short>(num))
		{
			m_number -= static_cast<unsigned short>(num);
			return *this;
		}
	}
	RomanNumber& operator*=(const RomanNumber &num)
	{
		m_number *= static_cast<unsigned short>(num);
		return *this;
	}
	RomanNumber& operator/=(const RomanNumber &num)
	{
		if (m_number > static_cast<unsigned short>(num))
		{
			m_number /= static_cast<unsigned short>(num);
			return *this;
		}
	}

	RomanNumber& operator+=(const int value)
	{
		m_number += value;
		return *this;
	}
	RomanNumber& operator-=(const int value)
	{
		if (m_number > value)
		{
			m_number -= value;
			return *this;
		}
	}
	RomanNumber& operator*=(const int value)
	{
		m_number *= value;
		return *this;
	}
	RomanNumber& operator/=(const int value)
	{
		if (this->m_number > value)
		{
			m_number /= value;
			return *this;
		}
	}

	//----------------------------------------------------------
	bool operator==(const RomanNumber&num) const
	{
		return m_number == static_cast<unsigned short>(num);
	}
	bool operator!=(const RomanNumber&num) const
	{
		return !(*this == num);
	}
	bool operator<(const RomanNumber&num)const
	{
		return m_number < static_cast<unsigned short>(num);
	}
	bool operator>(const RomanNumber&num)const
	{
		return m_number > static_cast<unsigned short>(num);
	}
	bool operator<=(const RomanNumber&num)const
	{
		return m_number <= static_cast<unsigned short>(num);
	}
	bool operator>=(const RomanNumber&num)const
	{
		return m_number >= static_cast<unsigned short>(num);
	}

	bool operator==(const int value)const
	{
		return m_number == value;
	}
	bool operator!=(const int value)const
	{
		return !(*this == value);
	}
	bool operator<(const int value)const
	{
		return m_number < value;
	}
	bool operator>(const int value)const
	{
		return m_number > value;
	}
	bool operator<=(const int value)const
	{
		return m_number <= value;
	}
	bool operator>=(const int value)const
	{
		return m_number >= value;
	}

	//----------------------------------------------------------
	RomanNumber operator++(int num)
	{
		RomanNumber tmp(*this);
		m_number++;
		return tmp;
	}
	RomanNumber operator--(int num)
	{
		RomanNumber tmp(*this);
		m_number--;
		return tmp;
	}
	RomanNumber operator--()
	{
		--m_number;
		return *this;
	}
	RomanNumber operator++()
	{
		++m_number;
		return *this;
	}
	//----------------------------------------------------------
	friend  ostream& operator<< (ostream& os, RomanNumber num);
	friend istream& operator >> (istream& is, RomanNumber& num);
	//----------------------------------------------------------

};

const int arabar[] = { 1,   4,    5,   9,    10,  40,  50,   90,  100, 400,  500, 900,  1000 };
const char *romanar[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };



ostream& operator<< (ostream& os, RomanNumber num)
{
	os << arab2roman(static_cast<unsigned short>(num));
	return os;
}
istream& operator >> (istream& is, RomanNumber&num)
{
	is >> num.m_number;
	return is;
}


char *arab2roman(unsigned short int arab) {
	static char roman[80];
	const int m = sizeof(arabar) / sizeof(int) - 1, arabmax = arabar[m];
	const char romanmax = romanar[m][0];
	int i, n;
	if (!arab) {
		*roman = 0;
		return roman;
	}
	i = 0;
	while (arab > arabmax) {
		roman[i++] = romanmax;
		arab -= arabmax;
	}
	n = m;
	while (arab > 0) {
		if (arab >= arabar[n]) {
			roman[i++] = romanar[n][0];
			if (n & 1)
				roman[i++] = romanar[n][1];
			arab -= arabar[n];
		}
		else
			n--;
	}
	roman[i] = 0;
	return roman;
}
unsigned short int roman2arab(const char *roman) {
	const int m = sizeof(arabar) / sizeof(int) - 1;
	unsigned short int arab;
	int len, n, i, pir;
	len = strlen(roman);

	arab = 0;
	n = m;
	i = 0;
	while (n >= 0 && i < len) {
		pir = n & 1;
		if (roman[i] == romanar[n][0] && (!pir || roman[i + 1] == romanar[n][1])) {
			arab += arabar[n];
			i += 1 + pir;
		}
		else
			n--;
	}
	return arab;
}


int main()
{
	auto num0 = RomanNumber("XIX");
	RomanNumber num1("L");
	RomanNumber num2("X");
	RomanNumber num3("I");
	RomanNumber num4("X");
	RomanNumber num5("III");

	cout << "num0 = " << num0
		<< ", num1 = " << num1
		<< ", num2 = " << num2
		<< ", num3 = " << num3
		<< ", num4 = " << num4
		<< ", num5 = " << num5
		<< endl
		<< endl;



	cout << "num1 + num2: " << num1 + num2 << endl;
	cout << "num1 - num2: " << num1 - num2 << endl;
	cout << "num1 * num2: " << num1 * num2 << endl;
	cout << "num1 / num2: " << num1 / num2 << endl << endl;

	cout << "num3 += num1: " << (num3 += num1) << endl;
	cout << "num3 -= num1: " << (num3 -= num1) << endl;
	cout << "num3 *= num2: " << (num3 *= num2) << endl;
	cout << "num1 /= num2: " << (num1 /= num2) << endl;


	assert(num2 == num4);
	assert(num4 != num5);
	assert(num4 > num5);
	assert(num4 >= num5);
	assert(num5 <= num4);
	assert(num0 + num5 < 1000);

	assert(num0 == 19);
	assert(++num0 == 20);




	cout << "num1++ : " << num1++ << endl;
	cout << "num4-- : " << num4-- << endl;
	cout << "++num1 : " << ++num1 << endl;
	cout << "--num4 : " << --num4 << endl;

	cout << "Enter new value for num1: ";
	cin >> num1;
	cout << num1 << endl;


	return 0;
}