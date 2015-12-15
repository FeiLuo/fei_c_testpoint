#pragma once

#include "ActionBase.h"
#include "CoreEvent.h"
#include "Tick.h"

class CoreEventAction;

class TestTimer : public CoreEvent
{
public:
    TestTimer(CoreEventAction* testAction);
    virtual ~TestTimer();

    // virtual functions from CoreEvent
    virtual void ExecuteFunction();

protected:
    CoreEventAction* mTestAction;
};

class CoreEventAction : public ActionBase
{
public:
    CoreEventAction() : mTimer(NULL), mTick(0), mFiredCount(0) {}
    virtual ~CoreEventAction() {}

    void TimerFired();

    // overwirte delete, we don't need to delete this class;
    void operator delete(void *, size_t);
    
    // virtual functions from ActionBase
public:
    virtual void Action();
    virtual const char* GetClassName() { return "CoreEventAction"; }

protected:
    TestTimer*  mTimer; 
    Ticks       mTick;
    Uint64      mFiredCount;
};

