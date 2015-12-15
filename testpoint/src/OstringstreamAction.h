#ifndef OstringstreamAction_h
#define OstringstreamAction_h

#include "ActionBase.h"

class OstringstreamAction :public ActionBase
{
public:
    OstringstreamAction(void) {}
    ~OstringstreamAction(void) {}

public:
    virtual void Action();
    virtual const char* GetClassName() { return "OstringstreamAction"; }
};


#endif // OstringstreamAction_h

