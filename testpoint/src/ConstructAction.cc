#include "ConstructAction.h"

ConstructAction::ConstructAction(void)
{
}

ConstructAction::~ConstructAction(void)
{
}

void ConstructAction::Action()
{
    // Action 1:
    ConstructA* a1 = new ConstructC();
    delete a1;
    printf("the logic of no virtual for de-construct function is error!\n\n");

    // Action 2:
    ConstructA2* a2 = new ConstructC2();
    delete a2;
    printf("all are right!\n");

}
