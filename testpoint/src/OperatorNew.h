#pragma once

// 1. Exercise* ps1 = new Exercise [10];    new一次，10次构造
// 2. delete[] ps1;                         调用10次析构，delete一次
// 3. 重点学习new,delete的重载

#include "ActionBase.h"

class Exercise
{
public:
    Exercise();
    Exercise(int nValue);
    virtual ~Exercise();

    void SetValue(int nValue);

public:
    // default new
    void* operator new(size_t);
    // array new
    void* operator new[](size_t nSize);
    // placement new
    void* operator new(size_t, char*);

    // default delete
    void operator delete(void *, size_t);
    // array delete
    void operator delete[](void *, size_t);
    // placement delete
    void operator delete(void *, char *);

private:
    int m_mem;
};

class OperatorNew : public ActionBase
{
public:
    OperatorNew(void);
    ~OperatorNew(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "OperatorNew"; }
};

