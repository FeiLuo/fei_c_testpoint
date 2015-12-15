#include "PerformanceCompareAction.h"
#include <iostream>
#include "Tick.h"
using namespace std;

PerformanceCompareAction::PerformanceCompareAction(void)
{
}

PerformanceCompareAction::~PerformanceCompareAction(void)
{
}

Uint32 PerformanceCompareAction::Performance1(Uint32 value)
{
    Uint32 ret;
    switch(value)
    {
        case 1:
            ret = value + 1;
            break;
        case 2:
            ret = value + 3;
            break;
        case 3:
            ret = value + 5;
            break;
        case 4:
            ret = value + 1;
            break;
        case 5:
            ret = value + 6;
            break;
        case 6:
            ret = value + 8;
            break;
        case 7:
            ret = value + 9;
            break;
        case 8:
            ret = value + 10;
            break;
        case 9:
            ret = value + 13;
            break;
        default: 
            ret = value;
            break;
    }
    return ret;
}

Uint32 PerformanceCompareAction::Performance2(Uint32 value)
{
    Uint32 ret;
    switch(value)
    {
       case 9:
            ret = value + 13;
            break;
       case 1:
            ret = value + 1;
            break;
        case 2:
            ret = value + 3;
            break;
        case 3:
            ret = value + 5;
            break;
        case 4:
            ret = value + 1;
            break;
        case 5:
            ret = value + 6;
            break;
        case 6:
            ret = value + 8;
            break;
        case 7:
            ret = value + 9;
            break;
        case 8:
            ret = value + 10;
            break;
        default: 
            ret = value;
            break;
    }
    return ret;
}

void PerformanceCompareAction::Action()
{
    Uint32 ret;
    #define MAX_LOOP 100000000
    
    Ticks t1, t2;
    Uint64 delta1, delta2;

    // initialization
    t1 = Tick::CurrentTime();
    for (Uint32 i=0; i<MAX_LOOP; i++)
    {
        ret = Performance1(1);
    }
    t2 = Tick::CurrentTime();
    delta1 = Tick::TicksToMicroseconds(t2-t1);
    
    // calculate Performance1
    t1 = Tick::CurrentTime();
    for (Uint32 i=0; i<MAX_LOOP; i++)
    {
        ret = Performance1(1);
    }
    t2 = Tick::CurrentTime();
    delta1 = Tick::TicksToMicroseconds(t2-t1);
    
    // calculate Performance2
    t1 = Tick::CurrentTime();
    for (Uint32 i=0; i<MAX_LOOP; i++)
    {
        ret = Performance2(1);
    }
    t2 = Tick::CurrentTime();
    delta2 = Tick::TicksToMicroseconds(t2-t1);
    
    if (delta1 < delta2)
    {
        cout << delta1 << ":" << delta2 << "(ms): the case order will effect the performance\n";
    }
    else 
    {
        cout << delta1 << ":" << delta2 << "(ms): the case order will not effect the performance\n";
    }
    
    
}

