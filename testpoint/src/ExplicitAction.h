#ifndef __ExplicitAction_H_
#define __ExplicitAction_H_

#include "ActionBase.h"

///////////////////////////////////////////////////////////////////////////////
// Explicit Test Class 1
///////////////////////////////////////////////////////////////////////////////
class ExplicitStringA
{
public:
    ExplicitStringA(const char* p);
    ExplicitStringA(Uint32 nSize);
    ~ExplicitStringA();
    
protected:
    char* mBuff;
};

///////////////////////////////////////////////////////////////////////////////
// Explicit Test Class 2
///////////////////////////////////////////////////////////////////////////////
class ExplicitStringB
{
public:
    explicit ExplicitStringB(const char* p);
    explicit ExplicitStringB(Uint32 nSize);
    ~ExplicitStringB();
    
protected:
    char* mBuff;
};


///////////////////////////////////////////////////////////////////////////////
// Prime Explicit Class
///////////////////////////////////////////////////////////////////////////////
class ExplicitAction : public ActionBase
{
public:
    ExplicitAction(void);
    ~ExplicitAction(void);
    
public:
    virtual void Action();
    virtual const char* GetClassName() { return "ExplicitAction"; }

};


#endif // __ExplicitAction_H_
