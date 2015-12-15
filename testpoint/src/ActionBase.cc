#include "ActionBase.h"

ActionBase::ActionBase(void)
{
}

ActionBase::~ActionBase(void)
{
}

void ActionBase::PrintTitle()
{
    printf("\n");
    printf("//====================================================\n");
    printf("// %s\n", GetClassName());
    printf("//====================================================\n");
}


