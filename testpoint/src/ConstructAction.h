#pragma once
#include "ActionBase.h"

// Action 1: 
class ConstructA
{
public:
    ~ConstructA() { printf("~ConstructA()\n"); }
};

class ConstructB : public ConstructA
{
public:
    ~ConstructB() { printf("~ConstructB()\n"); }
};

class ConstructC : public ConstructB
{
public:
    ~ConstructC() { printf("~ConstructC()\n"); }
};

// Action 2: 
class ConstructA2
{
public:
    virtual ~ConstructA2() { printf("~ConstructA2()\n"); }
};

class ConstructB2 : public ConstructA2
{
public:
    ~ConstructB2() { printf("~ConstructB2()\n"); }
};

class ConstructC2 : public ConstructB2
{
public:
    ~ConstructC2() { printf("~ConstructC2()\n"); }
};

// Action Class
class ConstructAction : public ActionBase
{
public:
    ConstructAction(void);
    ~ConstructAction(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "ConstructAction"; }
};
