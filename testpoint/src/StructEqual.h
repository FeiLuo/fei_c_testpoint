#pragma once

//
// struct equal will lead to memory copy;
// 

#include "ActionBase.h"

typedef struct  
{
    int     a1;
    int     a2;
    char*   p;
} MyStruct;

class StructEqual : public ActionBase
{
public:
    StructEqual(void);
    virtual ~StructEqual(void);

    virtual void Action();
    virtual const char* GetClassName() { return "StructEqual"; }
};

