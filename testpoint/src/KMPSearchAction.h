#ifndef KMPSearchAction_H__
#define KMPSearchAction_H__

#include "ActionBase.h"

class KMPSearchAction : public ActionBase
{
public:
    KMPSearchAction();
    ~KMPSearchAction();
    
public:
    virtual void Action();
    virtual const char* GetClassName() { return "KMPSearchAction"; }
};


#endif // KMPSearchAction_H__
