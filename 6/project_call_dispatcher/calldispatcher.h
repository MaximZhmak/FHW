#ifndef CALLDISPATCHER_H
#define CALLDISPATCHER_H

#include <string>
#include <memory>
#include <vector>

class Object;

struct Pair
{
    Object*m_sender;
    Object*m_receiver;
    std::string m_signal;
    std::string m_slot;
    Pair(Object* sender, const std::string& signal, Object* receiver, const std::string& slot)
        : m_sender(sender),
          m_receiver(receiver),
          m_signal(signal),
          m_slot(slot)
    {}
};


class CallDispatcher
{
private:

    std::vector<Pair> m_pairs;

    //...

public:
    typedef std::shared_ptr<CallDispatcher> Ptr;

    CallDispatcher();

    void connect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);
    void disconnect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);

    void sendSignal(Object* sender, const std::string& singal);
};

#endif // CALLDISPATCHER_H
