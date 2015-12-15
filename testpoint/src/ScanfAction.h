#ifndef _ScanfAction_H_
#define _ScanfAction_H_

#include "ActionBase.h"

class ScanfAction : public ActionBase
{
public:
    ScanfAction(void);
    ~ScanfAction(void);
    
protected:
    void ParseIP(const char* addr);
        
public:
    virtual void Action();
    virtual const char* GetClassName() { return "ScanfAction"; }
};

#endif // _ScanfAction_H_
