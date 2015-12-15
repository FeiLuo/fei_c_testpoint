#pragma once
#include "ActionBase.h"

class Prim : public ActionBase
{
public:
    Prim(void);
    ~Prim(void);

    void minSpant_Prim(Uint32* GE, Uint32 n);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "PrimSort"; }
};
