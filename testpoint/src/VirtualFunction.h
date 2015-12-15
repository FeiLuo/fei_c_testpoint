#pragma once
#include "ActionBase.h"
#include <map>

//////////////////////////////////////////////////////////////////////////////
// Virtual Function Usage
//////////////////////////////////////////////////////////////////////////////

class VF_X
{
public:
    VF_X() {}
    virtual ~VF_X() {}

    void f2() { printf("1\n"); }
    virtual void f1() { f2(); }

    int s1;
};

class VF_Y : public VF_X
{
public:
    VF_Y() {}
    virtual ~VF_Y() {}

    void f2() { printf("2\n"); }
    virtual void f1() { f2(); }

    int s2;
};

//////////////////////////////////////////////////////////////////////////////
// Action Class 
//////////////////////////////////////////////////////////////////////////////

class VirtualFunction : public ActionBase
{
public:
    VirtualFunction(void);
    ~VirtualFunction(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "VirtualFunction"; }
};
