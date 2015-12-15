#include "VirtualFunction.h"

VirtualFunction::VirtualFunction(void)
{
}

VirtualFunction::~VirtualFunction(void)
{
}

void VirtualFunction::Action()
{
    //printf("X::f1=%p X::f2=%p X::s1=%p\n", &X::f1, &X::f2, &X::s1);
    //printf("Y::f1=%p Y::f2=%p Y::s2=%p\n", &Y::f1, &Y::f2, &Y::s2);

    // virtual functions
    VF_Y y;
    y.f1();
    y.f2();

    VF_X& rx = y;
    rx.f1();
    rx.f2();

    VF_X* px = &y;
    px->f1();
    px->f2();

    VF_X* x1 = new VF_Y();
    x1->f1();
    x1->f2();
}

