#include "CallBackAction.h"
#include <iostream>
#include <stdarg.h>
using namespace std;

bool my_log(const char* fmt, ...)
{
    char buf[8192];
    va_list args;

    va_start(args, fmt);
    vsnprintf(buf, 8100, fmt, args);
    va_end(args);

    cout << "From my_log(): "<< buf;
    return true;
}

bool CallBackExample::CallBackLog(const char* fmt, ...)
{
    char buf[8192];
    va_list args;

    va_start(args, fmt);
    vsnprintf(buf, 8100, fmt, args);
    va_end(args);

    cout << "From CallBackExample::CallBackLog():" << buf;
    return true;
}

CallBackAction::CallBackAction()
{
}

CallBackAction::~CallBackAction()
{
}

void CallBackAction::Action()
{
    RegisterCallback(my_log);
    for (Uint32 i=0; i<10; i++)
    {
        mLogFunc("this is callback test%d \n", i+1);
    }

    mLogFunc = CallBackExample::CallBackLog;
    for (Uint32 i=0; i<10; i++)
    {
        mLogFunc("this is callback test%d \n", i+1);
    }
}
