#pragma once
#include "ActionBase.h"
using namespace std;

/*
class exception 
{
public:
    exception () throw();
    exception (const exception&) throw();
    exception& operator= (const exception&) throw();
    virtual ~exception() throw();
    virtual const char* what() const throw();
};
*/

class Polymorphic
{
public:
    Polymorphic() {}
    virtual ~Polymorphic() {}
    
    virtual void Member() {}
};


class ExceptionAction : public ActionBase
{
public:
    ExceptionAction(void);
    ~ExceptionAction(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "ExceptionAction"; }
};
