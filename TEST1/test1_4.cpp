#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
bool all_of(T* arr, size_t length, bool(*p)(const T& elem));

template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T& elem));

template<typename T>
bool Filter(const T& elem)
{
   return elem > 1 && elem < 10 ? true : false;
}


int main()
{
   const int size=5;
    int array[size]={1,2,4,6,8};



     assert(all_of(array,size, Filter)==0);
     cout<<all_of(array,size, Filter)<<endl;
     assert(any_of(array,size, Filter)==1);
     cout<<any_of(array,size, Filter)<<endl;


     double array1[size]={1.0, 2.0, 4.0, 6.0 ,8.0};
     assert(all_of(array1,size, Filter)==0);
     cout<<all_of(array1,size, Filter)<<endl;
     assert(any_of(array1,size, Filter)==1);
     cout<<any_of(array1,size, Filter)<<endl;

}

template<typename T>
bool all_of(T* arr, size_t length, bool(*p)(const T& elem))
{
    for (size_t i=0;i<length;i++)
    {
        if (p(arr[i]))
            continue;
        else
            return false;
    }
    return true;
}

template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T& elem))
{
    for (int i=0;i<length;i++)
    {
        if (p(arr[i]))
          return true;
        else
           continue;
    }
    return false;
}


