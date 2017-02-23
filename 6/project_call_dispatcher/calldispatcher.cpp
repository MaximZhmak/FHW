#include "calldispatcher.h"
#include <algorithm>
#include <iostream>
#include "object.h"


CallDispatcher::CallDispatcher()
{
    //...
}

void CallDispatcher::connect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    auto it = m_map.find({sender,signal});

    if (it != m_map.end())
    {
        std::pair<map_iterator, map_iterator>pair = m_map.equal_range({sender, signal});
        for (map_iterator it = pair.first; it!=pair.second; ++it)
        {
            if(it->second.first ==receiver && it->second.second == slot)
            {
                std::cout<<"\tconnection already exists"<<std::endl;
                return;
            }
        }
    }

    m_map.insert({{sender, signal},{receiver, slot}});
    std::cout<<"connection added"<<std::endl;
}

void CallDispatcher::disconnect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    auto it = m_map.find({sender, signal});

    if (it!=m_map.end())
    {
        std::pair<map_iterator, map_iterator> pair = m_map.equal_range({sender, signal});

        for(map_iterator it = pair.first;it!=pair.second;++it)
        {
            if (it->second.first == receiver && it->second.second == slot)
            {
                m_map.erase(it);
                break;
            }
        }
    }

    std::cout<<"connection deleted"<<std::endl;
}


void CallDispatcher::sendSignal(Object *sender, const std::string& signal)
{
    auto it = m_map.find({sender, signal});

    if (it != m_map.end())
    {
        std::pair<map_iterator, map_iterator> pair =
                m_map.equal_range({sender, signal});
        for (map_iterator it = pair.first; it!=pair.second;++it)
        {
            std::pair<Object*, std::string> rec = it->second;
            rec.first->dispatchMethod(rec.second);
        }
    }
}
