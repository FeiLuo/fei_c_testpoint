#include "CoreEventAction.h"
//
// TestTimer class
//
TestTimer::TestTimer(CoreEventAction* testAction)
  : CoreEvent(1),
    mTestAction(testAction)
{
}

TestTimer::~TestTimer()
{
    printf("TestTimer::~TestTimer()\n");
}

void TestTimer::ExecuteFunction()
{
    mTestAction->TimerFired();
}

//
// CoreEventAction class
//
void CoreEventAction::TimerFired()
{
    mFiredCount++;

    #define MAX_LOOP 4
    
    Ticks cur = Tick::CurrentTime();
    Uint64 deltaTime = Tick::TicksToMilliseconds(cur - mTick);
    mTick = cur;
    
    printf("CoreEventAction::TimerFired(): delta time %llu ms\n", deltaTime);

    if (mFiredCount == 1)
    {
        mTimer->SetPostExecuteAction(CoreEvent::ReInsert);
        mTimer->SetExpireTime(Tick::SecondsToTicks(1));
        mTimer->Start();
    }

    if (mFiredCount == MAX_LOOP)
    {
        mTimer->SetPostExecuteAction(CoreEvent::Delete);
    }
}

void CoreEventAction::operator delete(void* p, size_t nSize)
{
    // do nothing
    return;
}

void CoreEventAction::Action()
{
    mTimer = new TestTimer(this);
    mTick = Tick::CurrentTime();
    mTimer->Start(2000);
}

