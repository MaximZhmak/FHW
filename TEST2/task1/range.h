#ifndef RANGE_H
#define RANGE_H

#include <algorithm>


template <int B, int E, int S=1>
class Range
{
public:
    class iterator: public std::iterator<
                                            std::input_iterator_tag,
                                            int,
                                            int,
                                            const int*,
                                            int>
    {
        int m_begin, m_end, m_step;
    public:
        explicit iterator(int b, int e, int s) : m_begin(b), m_end(e), m_step(s) {}
        iterator& operator++()
        {
            m_begin+= m_step;
                  if ((m_step > 0 && m_begin >= m_end) ||
                      (m_step < 0 && m_begin <= m_end))
                  {
                    m_begin = m_end;
                  }
                  return *this;
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator == (iterator rhs) const
        {
            return (m_begin == rhs.m_begin && m_end == rhs.m_end && m_step == rhs.m_step);
        }
        bool operator!=(iterator rhs) const
        {
            return !(*this==rhs);
        }
        reference operator*()const {return m_begin;}
    };
    iterator begin()
    {
        return iterator(B, E, S);
    }
    iterator end()
    {
        return iterator(E,E,S);
    }
};

















//template <typename T>
//class MyIterator: public std::iterator<std::input_iterator_tag, int, int, int>
//{
//private:
//    int m_start;
//    int m_end;
//    int m_step;

//public:
//    explicit MyIterator( int start, int end, int step) : m_start(start), m_end(end),  m_step(step){}

//     int operator*()const
//    {
//        return m_start;
//    }
//    const MyIterator& operator++()
//    {
//        m_start+=m_step;

//        if((m_step > 0  && m_start >= m_end) ||
//            (m_step < 0  && m_start <= m_end))
//                m_start=m_end;

//        return *this;
//    }
//    MyIterator operator++(int)
//    {
//        MyIterator tmp(*this);
//        ++(*this);
//        return tmp;
//    }
//    bool operator==(const MyIterator& rhs)
//    {
//        return (m_start == rhs.m_start &&
//                      m_step   == rhs.m_step  &&
//                      m_end    == rhs.m_end);
//    }
//    bool operator!=(const MyIterator& rhs)
//    {
//        return !(*this == rhs);
//    }
//};

//template <int B,  int E, int S=1>
//class Range
//{
//public:
//        MyIterator begin()const
//        {
//            return MyIterator(B,E, S);
//        }
//        MyIterator end() const
//        {
//            return MyIterator(E,E,S);
//        }
//};




#endif // RANGE_H
