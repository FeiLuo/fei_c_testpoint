#ifndef _EVENT_LOG_ACTION_H
#define _EVENT_LOG_ACTION_H

#include "ActionBase.h"

class EventLogAction : public ActionBase
{
public:
    EventLogAction();
    ~EventLogAction();

public:
    virtual void Action();
    virtual const char* GetClassName() { return "EventLogAction"; }
};


#endif // _EVENT_LOG_ACTION_H

