#include <iostream>
#include <string>
#include <memory>

#include "event.h"
#include "eventlistener.h"
#include "eventmanager.h"

using namespace std;


struct FileLogger : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ <<"  "<< ev.getDescription() << endl;
    }
};

struct ConnectionMgr : EventListener
{
    void notify(const Event& ev) override
    {
            cout << __PRETTY_FUNCTION__ <<"  "<< ev.getDescription() << endl;
    }
};

struct EventHandler : EventListener
{
    void notify(const Event& ev) override
    {
            cout << __PRETTY_FUNCTION__ <<"  "<< ev.getDescription() << endl;
    }
};


int main()
{
    shared_ptr<EventListener> evListener1 = make_shared<FileLogger>();
    shared_ptr<EventListener> evListener2 = make_shared<ConnectionMgr>();
    shared_ptr<EventListener> evListener3 = make_shared<EventHandler>();

    Event connectionError("connection failed");

    //-----------------------------------------------------
    cout<<"Adding Listeners to EventManager..."<<endl;
    EventManager::getInstance().addListener(evListener1);
    EventManager::getInstance().addListener(evListener2);
    EventManager::getInstance().addListener(evListener3);

    cout<<"--------------------------------------------------------------"<<endl;

    cout<<"Trying to add existing Listener to EventManager..."<<endl;
    EventManager::getInstance().addListener(evListener1);
    cout<<"--------------------------------------------------------------"<<endl;

    cout<<"Event Happened"<<endl;
    EventManager::getInstance().publishEvent(connectionError);

    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Removing Listeners from EventManager..."<<endl;
    EventManager::getInstance().removeListener(evListener1);
    EventManager::getInstance().removeListener(evListener2);

    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Event Happened"<<endl;
    EventManager::getInstance().publishEvent(connectionError);

    EventManager::getInstance().removeListener(evListener3);
    {
        //test : expired listener - not notified
        cout<<"--------------------------------------------------------------"<<endl;
        shared_ptr<EventListener> listener = make_shared<ConnectionMgr>();
        EventManager::getInstance().addListener(listener);
    }

    EventManager::getInstance().publishEvent(Event("XXX"));



    return 0;
}
