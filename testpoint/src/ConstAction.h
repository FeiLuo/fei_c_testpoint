#pragma once
#include "ActionBase.h"

class ConstAction : public ActionBase
{
public:
    ConstAction(void);
    ~ConstAction(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "ConstAction"; }
};
