#include "ConstAction.h"

ConstAction::ConstAction(void)
{
}

ConstAction::~ConstAction(void)
{
}

void ConstAction::Action()
{
    const int ACTION_SIZE = 10;
    int* lp = new int [ACTION_SIZE];
    int* rp = new int [ACTION_SIZE];
    for (int i = 0; i < ACTION_SIZE; i++)
    {
        lp[i] = i;
        rp[i] = i + ACTION_SIZE;
    }


    printf("const int * p1 = lp;\n");
    printf("int const * p2 = lp;\n");
    printf("int * const p3 = lp;\n");
    printf("To judge which one is const\n"
           "\tyou can check who is nearer to const, '*' or p1/p2/p3\n\n");

    const int * p1 = lp;
    p1 = rp;
    // *p1 = 0;
    printf("const int *p1 = lp;\n");
    printf("const is near \'*\', content, content is unchanged!\n\n");

    int const * p2 = lp;
    p2 = rp;
    // *p2 = 0;
    printf("int const *p2 = lp;\n");
    printf("const is near \'*\', content, content is unchanged!\n\n");

    int * const p3 = lp;
    // p3 = rp;
    *p3 = 0;
    printf("int * const p3 = lp;\n");
    printf("const is near pointer parameter, pointer is unchanged!\n\n");
}

