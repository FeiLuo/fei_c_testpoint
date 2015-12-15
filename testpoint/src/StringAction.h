#pragma once
#include "ActionBase.h"

class StringAction : public ActionBase
{
public:
    StringAction(void);
    ~StringAction(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "StringAction"; }
};
