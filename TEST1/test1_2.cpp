#include <iostream>
using namespace std;

//1
class HTMLElement
{
public:
    unsigned Width() const;
    unsigned Height() const;
    bool Hidden() const;
    virtual string Render()=0;
};

class HTMLButtonElement: public HTMLElement
{
   string m_button_title;

   public:

   HTMLButtonElement(string name):m_button_title(name)
   {

   }
    const string& Title() const
    {
        return m_button_title;
    }
    string Render()
    {
        return "<button>"+Title()+"</button>";
    }
};

class HTMLImageElement: public HTMLElement
{
     string m_image_url;
public:
     HTMLImageElement(string url):m_image_url(url)
     {

     }
    const string& Url() const
    {
        return m_image_url;
    }
    string Render()
    {
       return "<img src=\""+Url()+"\" height=\"42\" width=\"42\"";
    }
};

class HTMLTextAreaDocument: public HTMLElement
{
    string m_content;

public:
    HTMLTextAreaDocument(string text):m_content(text)
    {

    }

    const string& Content() const
    {
        return m_content;
    }
    string Render()
    {
        string result = "<textarea>"+Content()+"</textarea>";
       return result;
    }
};

int main()
{
 HTMLElement* elements[3];
 elements[0] = new HTMLButtonElement("Confirm");
 elements[1] = new HTMLImageElement("../../smiley.gif");
 elements[2] = new HTMLTextAreaDocument("content-of-the-text-area");

 for (int i=0;i<3;i++)
     {
          cout<<elements[i]->Render()<<endl;
     }


 delete[]elements;
return 0;
}

