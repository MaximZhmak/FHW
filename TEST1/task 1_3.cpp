#include <iostream>
using namespace std;

//1
class HTMLElement
{
public:
    unsigned Width() const;
    unsigned Height() const;
    bool Hidden() const;

    virtual HTMLElement* Duplicate()=0;
    virtual string Render()=0;
};

class HTMLButtonElement: public HTMLElement
{
   string m_button_title;
   bool m_hidden;
   public:

   HTMLButtonElement(string name, bool hidden):m_button_title(name), m_hidden(hidden)
   {

   }
   HTMLElement* Duplicate()
   {
       return  new HTMLButtonElement(*this);
   }

   const bool& Hidden() const
   {
       return m_hidden;
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
        bool m_hidden;
public:
     HTMLImageElement(string url, bool hidden):m_image_url(url), m_hidden(hidden)
     {

     }
     const bool& Hidden() const
     {
         return m_hidden;
     }
    const string& Url() const
    {
        return m_image_url;
    }
    string Render()
    {
       return "<img src=\""+Url()+"  \" height=\"42\" width=\"42\"";
    }
    HTMLElement* Duplicate()
    {
        return  new HTMLImageElement(*this);
    }
};

class HTMLTextAreaElement: public HTMLElement
{
    string m_content;
      bool m_hidden;

public:
    HTMLTextAreaElement(string text, bool hidden):m_content(text),  m_hidden(hidden)
    {

    }
    const bool& Hidden() const
    {
        return m_hidden;
    }
    const string& Content() const
    {
        return m_content;
    }
    string Render()
    {
       return "<textarea\n>"+Content()+"\n</textarea>";
    }
    HTMLElement* Duplicate()
    {
        return  new HTMLTextAreaElement(*this);
    }

};

int main()
{
 HTMLElement* elements[3];
 elements[0] = new HTMLButtonElement("Confirm" , true);
 elements[1] = new HTMLImageElement("../../smiley.gif", false);
 elements[2] = new HTMLTextAreaElement("content-of-the-text-area", false);

 for (int i=0;i<3;i++)
     {
          cout<<elements[i]->Render()<<endl;
     }


 cout<<"\n\nCOPIED ARRAY"<<endl;
  HTMLElement* elements1[3];
  for (int i=0;i<3;i++)
      {
      elements1[i]=elements[i]->Duplicate();
           cout<<elements1[i]->Render()<<endl;
      }



return 0;
}

