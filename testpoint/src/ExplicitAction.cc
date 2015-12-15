#include "ExplicitAction.h"
#include <string.h>


///////////////////////////////////////////////////////////////////////////////
// Explicit Test Class 1
///////////////////////////////////////////////////////////////////////////////
ExplicitStringA::ExplicitStringA(const char* p)
{
    Uint32 nLen = strlen(p);
    mBuff = new char [nLen+1];
    strcpy((char*)mBuff, p);
}

ExplicitStringA::ExplicitStringA(Uint32 nSize)
{
    mBuff = new char [nSize+1];
    memset(mBuff, nSize+1, 0);
}

ExplicitStringA::~ExplicitStringA()
{
}

///////////////////////////////////////////////////////////////////////////////
// Explicit Test Class 2
///////////////////////////////////////////////////////////////////////////////
ExplicitStringB::ExplicitStringB(const char* p)
{
    Uint32 nLen = strlen(p);
    mBuff = new char [nLen+1];
    strcpy(mBuff, p);
}

ExplicitStringB::ExplicitStringB(Uint32 nSize)
{
    mBuff = new char [nSize+1];
    memset(mBuff, nSize+1, 0);
}

ExplicitStringB::~ExplicitStringB()
{
}

///////////////////////////////////////////////////////////////////////////////
// Prime Explicit Class
///////////////////////////////////////////////////////////////////////////////

ExplicitAction::ExplicitAction(void)
{
}

ExplicitAction::~ExplicitAction(void)
{
}

void ExplicitAction::Action()
{
    ExplicitStringA eStringA1("abc");
    ExplicitStringA eStringA2(10);
    ExplicitStringB eStringB1("abc");
    ExplicitStringB eStringB2(10);

    ExplicitStringA eStringA3 = "abc";
    ExplicitStringA eStringA4 = 10;
    // ExplicitStringB eStringB3 = "abc";
    // ExplicitStringB eStringB4 = 10;

    printf("ExplicitStringA has not \'explicit\', but ExplicitStringB has it: \n"
        "\tExplicitStringA eStringA1(\"abc\"); \t\t OK!\n"
        "\tExplicitStringA eStringA2(10);      \t\t OK!\n"
        "\tExplicitStringB eStringB1(\"abc\"); \t\t OK!\n"
        "\tExplicitStringB eStringB2(10);      \t\t OK!\n"
        "\n"
        "\tExplicitStringA eStringA3 = \"abc\";\t\t OK!\n"
        "\tExplicitStringA eStringA4 = 10;     \t\t OK!\n"
        "\tExplicitStringB eStringB3 = \"abc\";\t\t Failed!\n"
        "\tExplicitStringB eStringB4 = 10;     \t\t Failed!\n"
        );
}

