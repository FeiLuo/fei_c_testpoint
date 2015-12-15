#pragma once

// ÖØÔØ²Ù×÷·û

#include "ActionBase.h"

class OperatorSample :public ActionBase
{
public:
    OperatorSample(void);
    ~OperatorSample(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "OperatorSample"; }
};

class Integer
{
    long i;
    Integer* This() { return this; }

public:
    Integer(long ll = 0) : i(0) { }
    ~Integer() {};

    friend const Integer& operator+ (const Integer& a);
    friend const Integer operator- (const Integer& a);
    friend const Integer operator~ (const Integer& a);
    friend Integer* operator& (Integer& a);
    friend int operator! (const Integer& a);

    friend const Integer operator <<(const Integer& left, const Integer& right);

};

