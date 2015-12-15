#include "OperatorSample.h"

// main class
OperatorSample::OperatorSample(void)
{
}

OperatorSample::~OperatorSample(void)
{
}

void OperatorSample::Action()
{
    Integer a;
    +a;
    -a;
    ~a;
}

// sample class
const Integer& operator+(const Integer& a)
{
    printf("%s\n", __FUNCTION__);
    return (a);
}

const Integer operator-(const Integer& a)
{
    printf("%s\n", __FUNCTION__);
    return (-a.i);
}

const Integer operator~(const Integer& a)
{
    printf("%s\n", __FUNCTION__);
    return (~a.i);
}

Integer* operator&(Integer& a)
{
    printf("%s\n", __FUNCTION__);
    return (a.This());
}

int operator!(const Integer& a)
{
    printf("%s\n", __FUNCTION__);
    return !(a.i);
}

const Integer operator <<(const Integer& left, const Integer& right)
{
    printf("%s\n", __FUNCTION__);
    return Integer(left.i << right.i);
}





