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
        if( (*m_refCounter)==0)
        {
               delete[]m_buffer;
        }
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
        Detach();
    }


    String& operator=(const String& rhs)
    {

        if (rhs.m_buffer != m_buffer
                && GetCount()>1)
        {
            Detach();
            Attach(rhs);
        }
        else
        {
            m_buffer=rhs.GetBuffer();
        }
        return *this;
    }

    String& operator=(const char* value)
    {
        if (GetCount()>1)
        {
            Detach();
        }
            delete[]m_buffer;
            m_buffer = new char[strlen(value) + 1];
            strcpy(m_buffer, value);

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

        if (GetCount()>1)
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
        else
        {
            m_buffer[index]=value;
        }
    }

    char* GetBuffer() const
    {
        return m_buffer;
    }
};



int main()
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

    {
                  String s1("abc");
                  s1.SetElem(0, 'x');
                  assert(s1.GetCount() == 1);
    }

    {
             String s1 = "abc";
             s1 = "xyz";
             assert(s1.GetCount() == 1);
     }
    cout << "PASSED" << endl;
    return 0;
}
