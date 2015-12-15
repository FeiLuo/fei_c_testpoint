#include "EndianAction.h"

EndianAction::EndianAction(void)
{
}

EndianAction::~EndianAction(void)
{
}

void EndianAction::PrintBigOrLittle(bool isBigEndian)
{
    if (isBigEndian == 1)
    {
        printf("this is Big endian \n");
    }
    else
    {
        printf("this is Little endian \n");
    }
}

void EndianAction::Action()
{
    // solution 1:
    union w
    {
        int a;
        char b;
    } c;
    c.a = 1;
    PrintBigOrLittle(c.b == 0);

    // solution 2:
    Uint32 num,*p;
    p = &num;
    num = 0;
    *(Uint8*)p = 0xff;
    PrintBigOrLittle(num == 0xf);


    // solution 3:
    static union { Uint8 my8[4]; Uint32 my32; } endian_test = {{ 0, 0, 0, 1 } };
    #define IS_BIG_ENDIAN ((char)endian_test.my32)
    PrintBigOrLittle(IS_BIG_ENDIAN);

    // solution 4

    #ifdef __LITTLE_ENDIAN__
    PrintBigOrLittle(false);
    #else
    PrintBigOrLittle(true);
    #endif

    // bytes order
    EndianType e1;
    e1.mUint64 = 0x1122334455667788ll;
    for (Uint32 i=0; i<8; i++)
    {
        printf("0x%2x ", e1.mChar[i]);
    }
    printf("\n");
}

