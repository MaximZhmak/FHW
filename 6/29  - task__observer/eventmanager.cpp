#include "eventmanager.h"
#include <algorithm>
#include <iostream>

using namespace std;


EventManager& EventManager::getInstance()
{
    static EventManager inst;
    return inst;
}

void EventManager::publishEvent(const Event& ev) const
{
    for(const auto& listener:m_listeners)
    {
        if(auto temp = listener.lock())
            temp.get()->notify(ev);
    }
}

void EventManager::addListener(shared_ptr<EventListener>& listener)
{
    auto it = find_if(m_listeners.begin(),
                      m_listeners.end(),
                      [listener](const std::weak_ptr<EventListener>& l)
    {
        return listener==l.lock();
    }
    );
    if(it==m_listeners.end())
    {m_listeners.push_back(listener);

        cout<<"\tlistener added"<<endl;
        return;
    }
    cout<<"\tlistener not added"<<endl;
}

void EventManager::removeListener(shared_ptr<EventListener>& listener)
{
    m_listeners.erase(std::remove_if(m_listeners.begin(),
                                     m_listeners.end(),
                                     [listener](const std::weak_ptr<EventListener>& l)
    {
        return (listener == l.lock());
    }),
                      m_listeners.end()
                      );
    cout<<"\tlistener deleted"<<endl;

}

