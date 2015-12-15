#include "TypeTransfer.h"

TypeTransfer::TypeTransfer(void)
{
}

TypeTransfer::~TypeTransfer(void)
{
}

void TypeTransfer::Action()
{
    // static_cast
    // 1. 消除强制转换的警告
    // 

    printf("static_cast, dynamic_cast, etc will remove warning information when compile ");

    int i = 0x7fff;
    long l;
    float f;

    // 1.1. typical castless conversion
    l = i;
    f = i;  // warning here
    printf("castless conversion: i=0x%x 0d%d; long=%ld; float=%f\n", i, i, l, f);

    l = static_cast<long>(i);
    f = static_cast<float>(i);	// no warning
    printf("static_cast conversion: i=0x%x 0d%d, long=%ld, float=%f\n", i, i, l, f);

    // 1.2. Narrowing conversion
    i = l;
    i = f;  // warning here
    i = static_cast<int>(l);
    i = static_cast<int>(f);

    // const_cast


}
