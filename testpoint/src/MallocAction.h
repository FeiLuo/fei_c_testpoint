#ifndef Malloc_Action_h
#define Malloc_Action_h

#include "ActionBase.h"

class MallocAction : public ActionBase
{
public:
    MallocAction();
    ~MallocAction();

protected:

public:
    virtual void Action();
    virtual const char* GetClassName() { return "MallocAction"; }
};

#endif // Malloc_Action_h