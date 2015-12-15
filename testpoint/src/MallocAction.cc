#include "MallocAction.h"

MallocAction::MallocAction()
{
}

MallocAction::~MallocAction()
{
}

void MallocAction::Action()
{
    void* p1 = malloc(12);
    free(p1);
}
