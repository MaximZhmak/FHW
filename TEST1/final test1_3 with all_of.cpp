#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class HtmlElement
{
	int m_width;
	int m_height;
	bool m_hidden;
public:
	unsigned Width() const
	{
		return m_width;
	}
	unsigned Height() const
	{
		return m_height;
	}
	bool Hidden() const
	{
		return m_hidden;
	}
	HtmlElement(bool hidden, int width, int height) :
		m_hidden(hidden), m_width(width), m_height(height)
	{

	}
	virtual string Render() = 0;
	virtual HtmlElement* Duplicate() = 0;
};

template<typename T>
bool all_of(T* arr, size_t length, bool(*p)( T& elem))
{
	for (size_t i = 0; i<length; i++)
	{
		if (p(arr[i]))
			continue;
		else
			return false;
	}
	return true;
}

template<typename T>
bool any_of(T* arr, size_t length, bool(*p)( T& elem))
{
	for (size_t i = 0; i<length; i++)
	{
		if (p(arr[i]))
			return true;
		else
			continue;
	}
	return false;
}

template<typename T=HtmlElement*>
bool Filter(T*& elem)
{
	return elem->Hidden();
}

class HTMLButtonElement : public HtmlElement
{
	string m_button_title;
public:
	HTMLButtonElement(string name, bool hidden = false, int width = 10, int height = 10)
		: HtmlElement(hidden, width, height), m_button_title(name)
	{

	}
	const string& Title() const
	{
		return m_button_title;
	}
	string Render() override
	{
		return "<button>" + Title() + "</button>";
	}
	HtmlElement* Duplicate() override
	{
		return new HTMLButtonElement(*this);
	}

	
};
class HTMLImageElement : public HtmlElement
{
	string m_image_url;
public:
	HTMLImageElement(string name, bool hidden = false, int width = 10, int height = 10)
		: HtmlElement(hidden, width, height), m_image_url(name)
	{

	}
	const string& Url() const
	{
		return m_image_url;
	}
	string Render() override
	{
		return "<img src=\"" + Url() + "\" height=\"42\" width=\"42\"";
	}
	HtmlElement* Duplicate() override
	{
		return new HTMLImageElement(*this);
	}

};
class HTMLTextAreaDocument : public HtmlElement
{
	string m_content;
public:
	HTMLTextAreaDocument(string name, bool hidden = false, int width = 10, int height = 10)
		: HtmlElement(hidden, width, height), m_content(name)
	{

	}
	const string& Content() const
	{
		return m_content;
	}
	string Render() override
	{
		return "<textarea>" + Content() + "</textarea>";
	}
	HtmlElement* Duplicate() override
	{
		return new HTMLTextAreaDocument(*this);
	}

};



int main()
{
	HtmlElement* elements[3];
	elements[0] = new HTMLButtonElement("Confirm", true);
	elements[1] = new HTMLImageElement("../../smiley.gif");
	elements[2] = new HTMLTextAreaDocument("content-of-the-text-area");

	cout << "==========INITIAL ARRAY=========" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << elements[i]->Render() << endl;
	}
	HtmlElement* elements1[3];
	cout << "\n\n==========COPIED ARRAY=========" << endl;
	for (int i = 0; i < 3; i++)
	{
		elements1[i] = elements[i]->Duplicate();
		cout << elements1[i]->Render() << endl;
	}

	assert(all_of(elements1, 3, Filter) == 0);
	cout << all_of(elements1, 3, Filter) << endl;
	assert(any_of(elements1, 3, Filter) == 1);
	cout << any_of(elements1, 3, Filter) << endl;




	for (int i = 0; i < 3; i++)
	{
		delete elements1[i];
		delete elements[i];
	}
	return 0;	
}

