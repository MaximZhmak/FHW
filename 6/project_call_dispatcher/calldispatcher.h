#ifndef CALLDISPATCHER_H
#define CALLDISPATCHER_H

#include <string>
#include <memory>
#include <map>

class Object;

class CallDispatcher
{
    typedef std::multimap<std::pair<Object*, std::string>, std::pair<Object*, std::string>> map;

    map m_map;

public:

    typedef std::shared_ptr<CallDispatcher> Ptr;
    typedef std::multimap<std::pair<Object*, std::string>, std::pair<Object*, std::string>> :: iterator map_iterator;


    CallDispatcher();

    void connect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);
    void disconnect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);
    void sendSignal(Object* sender, const std::string& singal);
};

#endif // CALLDISPATCHER_H
