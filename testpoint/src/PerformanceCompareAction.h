#ifndef PerformanceCompareAction_h__
#define PerformanceCompareAction_h__

#include "ActionBase.h"

class PerformanceCompareAction : public ActionBase
{
public:
    PerformanceCompareAction(void);
    ~PerformanceCompareAction(void);
    
protected:
    Uint32 Performance1(Uint32 value);
    Uint32 Performance2(Uint32 value);
        
public:
    virtual void Action();
    virtual const char* GetClassName() { return "PerformanceCompareAction"; }
};

#endif // PerformanceCompareAction_h__
