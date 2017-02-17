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

    auto it = find_if(m_pairs.begin(), m_pairs.end(),
                      [sender,signal,receiver, slot]
                      (const Pair& p )
    {
        return (p.m_sender   == sender   &&
                p.m_signal     == signal     &&
                p.m_receiver == receiver &&
                p.m_slot         == slot) ;
    }
    );
    if(it == m_pairs.end())
    {
        m_pairs.push_back(Pair(sender, signal, receiver, slot));
        std::cout<<"Sender - receiver connected via "<<signal<<" "<<slot<<std::endl;
    }
    else
          std::cout<<"Sender - receiver are already connected via "<<signal<<" "<<slot<<std::endl;
}

void CallDispatcher::disconnect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    bool found=false;
    m_pairs.erase(std::remove_if(m_pairs.begin(),
                                 m_pairs.end(),
                                 [sender, signal, receiver, slot, &found]
                                 (const Pair& p)
    {
        if (p.m_sender   == sender   &&
                p.m_signal     == signal     &&
                p.m_receiver == receiver &&
                p.m_slot         == slot)
        {
            found=true;
            return true;
        }
        return false;
    }),
                              m_pairs.end() );

    if (found)
        std::cout<<"Sender - receiver disconnected via "<<signal<<" "<<slot<<std::endl;

}

void CallDispatcher::sendSignal(Object *sender, const std::string& signal)
{
        for (const Pair& pair : m_pairs)
        {
            if(pair.m_sender == sender && pair.m_signal == signal)
                pair.m_receiver->dispatchMethod(signal);
        }
}
