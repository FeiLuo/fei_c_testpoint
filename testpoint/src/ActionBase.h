#ifndef __ACTIONBASE_H__
#define __ACTIONBASE_H__

#include "CoreTypes.h"
#include <list>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class ActionBase;
typedef std::list<ActionBase*>      ActionList;
typedef ActionList::iterator        ActionListIter;
typedef ActionList::const_iterator  ActionListConstIter;

class ActionBase
{
public:
    ActionBase(void);
    virtual ~ActionBase(void);

    void PrintTitle();

    virtual void Action() = 0;
    virtual const char* GetClassName() = 0;
};

#endif // __ACTIONBASE_H__
