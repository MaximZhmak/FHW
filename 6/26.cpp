#include <iostream>
#include <string>

using namespace std;

class Device
{
private:
	string m_name;
	bool m_power;
public:
	Device(string name) :m_name(name), m_power(false)
	{

	}

	bool GetPower() const
	{
		return m_power;
	}
	string GetName() const
	{
		return m_name;
	}

	void TurnOn()
	{
		cout << "Device Turning On..." << endl;
		m_power = true;
	}
	void TurnOff()
	{
		cout << "Device Turning Off..." << endl;
		m_power = false;
	}
	virtual void GetStatus() const = 0;
	virtual ~Device() {};
};

class Printer :virtual public Device
{
	string m_type;
public:
	Printer(string name, string type) :Device(name), m_type(type)
	{

	}
	string GetType() const
	{
		return m_type;
	}
	void GetStatus() const override
	{
		if (GetPower())
		{
			cout << GetName()
				<< " "
				<< GetType()
				<< " "
				<< "Printer: Power ON"
				<< endl;
		}
		else
			cout << "Printer: Power OFF" << endl;
	}

	void Print()
	{
		cout << "Print" << endl;
	}
	~Printer() {}
};

class Scanner :virtual public Device
{
	int m_dpi;
public:
	Scanner(string name, int dpi) :Device(name), m_dpi(dpi)
	{

	}
	int GetDpi() const
	{
		return m_dpi;
	}
	void GetStatus() const override
	{
		if (GetPower())
		{
			cout << GetName()
				<< " "
				<< GetDpi()
				<< "dpi "
				<< "Scanner: Power ON"
				<< endl;
		}
		else
			cout << "Scanner: Power OFF" << endl;
	}

	void Scan()
	{
		cout << "Scan" << endl;
	}
	~Scanner() {}
};

class MFU :public Printer, public Scanner
{
	string m_guarantee;
public:
	MFU(string name, int dpi, string type, string quarantee) :
		Device(name),
		Scanner(name, dpi),
		Printer(name, type),
		m_guarantee(quarantee)
	{

	}
	string GetGuarantee() const
	{
		return m_guarantee;
	}

	void GetStatus() const override
	{
		
		if (GetPower())
		{
			Printer::GetStatus();
			Scanner::GetStatus();
			cout << "Guarantee: "<<GetGuarantee()
				<< endl
				<< "MFU: Power ON"
				<< endl;
		}
		else
			cout << "MFU: Power OFF" << endl;
	}
	~MFU() {};
};

int main()
{
	MFU mfu("Canon", 1200, "laser", "expired");

	mfu.TurnOn();
	mfu.GetStatus();

	mfu.Print();
	mfu.Scan();

	mfu.TurnOff();
	mfu.GetStatus();
}