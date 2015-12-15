#pragma once
#include "ActionBase.h"

class TimeScale_Test
{
public:
    TimeScale_Test() {}
    virtual ~TimeScale_Test() {}
};

class TimeScale_Test1 : public TimeScale_Test
{
public:
    TimeScale_Test1() {}
    ~TimeScale_Test1() {}
};

class TimeScale : public ActionBase
{
public:
    TimeScale(void);
    ~TimeScale(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "TimeScale"; }
};
