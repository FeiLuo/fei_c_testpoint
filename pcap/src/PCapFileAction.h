#ifndef _PCapFileAction_h__
#define _PCapFileAction_h__

#include "ActionNode.h"

class PCapFileFuncAction : public ActionNode
{
public:
    PCapFileFuncAction();
    ~PCapFileFuncAction();
};

class PCapFileAction : public ActionNode
{
public:
    PCapFileAction();
    ~PCapFileAction();

    ActionNodeList*     mFuncActionList;
};



#endif // _PCapFileAction_h__
