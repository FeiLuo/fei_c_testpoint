#include "ExceptionAction.h"
#include <typeinfo>
#include <iostream>

ExceptionAction::ExceptionAction(void)
{
}

ExceptionAction::~ExceptionAction(void)
{
}

void ExceptionAction::Action()
{
    try
    {
        Polymorphic *pb = 0;
        typeid(*pb);
    }
    catch (exception& e)
    {
        cerr << "exception caught: " << e.what() << endl;
    }
}
