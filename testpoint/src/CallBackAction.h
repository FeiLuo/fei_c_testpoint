#ifndef _CallBackAction_H__
#define _CallBackAction_H__

#include "ActionBase.h"

typedef bool (*log_func_t)(const char* fmt, ...);

class CallBackExample
{
public:
    CallBackExample() {}
    ~CallBackExample(){}

    static bool CallBackLog(const char* fmt, ...);
};

class CallBackAction : public ActionBase
{
public:
    CallBackAction();
    ~CallBackAction();
    
public:
    virtual void Action();
    virtual const char* GetClassName() { return "CallBackAction"; }
    
protected:
    void RegisterCallback(log_func_t ptr_log) { mLogFunc = ptr_log; }

    log_func_t mLogFunc;
};



#endif // _CallBackAction_H__
