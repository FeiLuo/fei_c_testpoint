#ifndef MemCopyAction_h__
#define MemCopyAction_h__

#include "ActionBase.h"

class MemCopyAction : public ActionBase
{
public:
    MemCopyAction(void);
    ~MemCopyAction(void);

protected:

public:
    virtual void Action();
    virtual const char* GetClassName() { return "MemCopyAction"; }
};


#endif // MemCopyAction_h__
