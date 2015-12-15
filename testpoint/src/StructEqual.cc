#include "StructEqual.h"

StructEqual::StructEqual(void)
{
}

StructEqual::~StructEqual(void)
{
}

void StructEqual::Action()
{
    char* pLeaking;
    MyStruct m1, m2;
    m1.a1 = 1;
    m1.a2 = 1;
    m1.p = new char [10];
    pLeaking = m1.p;
    printf("struct 1's address is %p; m1=%d; m2=%d; p=%p\n", &m1, m1.a1, m1.a2, m1.p);

    m2.a1 = 2;
    m2.a2 = 2;
    m2.p = new char [10];
    printf("struct 2's address is %p; m1=%d; m2=%d; p=%p\n", &m2, m2.a1, m2.a2, m2.p);

    m1 = m2;
    printf("after equal: \n");
    printf("struct 1's address is %p; m1=%d; m2=%d; p=%p\n", &m1, m1.a1, m1.a2, m1.p);
    printf("struct 2's address is %p; m1=%d; m2=%d; p=%p\n", &m2, m2.a1, m2.a2, m2.p);
    printf("there are memory leaking in m1.p=%p\n", pLeaking);
}
