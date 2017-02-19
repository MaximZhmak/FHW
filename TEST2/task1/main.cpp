#include <iostream>
#include "range.h"
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
    for(auto  i: Range<0, 100, 9>())
        cout<<i<<" ";
    cout<<endl;

    Range<0, 30> range;
    assert(count_if(range.begin(), range.end(), [](int e){return e>20;})==9);

    Range<10, 20, 30>range1;
     assert(count_if(range1.begin(), range1.end(),[](int e){return e>10;})==0);

    int i=0;
    for (auto elem : Range<1, 5>())
    {
        assert(elem==++i);
    }
    i=0;
    for (auto elem : Range<0, 10, 2>())
    {
        assert(elem == i);
        i+=2;
    }

    for (auto elem : Range<20, 50, 1000>())
    {
        assert(elem==20);
    }


    cout<<"Passed"<<endl;
    return 0;
}
