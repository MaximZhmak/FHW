#include "cache.h"

#include <cstring>
#include <cassert>
#include <iostream>

int main()
{
    LRUCache<int, std::string> cache(3);
    cache.Put(1, "1");
    assert(cache.Exists(1));
    cache.Put(2, "2");
    cache.Put(3, "3");
    assert(cache.Size()==3);

    cache.Get(2);
    cache.Get(1);
    cache.Put(4, "4");

    assert(!cache.Exists(3) && cache.Size() == 3);


    bool exception_thrown = false;
    try
    {
        cache.Get(3);
    }
    catch (std::exception& ex)
    {
        exception_thrown = true;
    }
    assert(exception_thrown==true);

    cache.Clear();
    assert(cache.Size()==0);

    {
        LRUCache<int, std::string> cache(2);
        cache.Put(1, "one");
        cache.Put(2, "two");
        cache.Put(3, "three");
        assert(cache.Size()==2);
        assert(!cache.Exists(1));
    }

    std::cout<<"-----------------Passed-----------------"<<std::endl;
    return 0;
}
