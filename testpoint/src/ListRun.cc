#include "ListRun.h"

ListRun::ListRun(void)
{
}

ListRun::~ListRun(void)
{
}

void ListRun::Action()
{
    MyNodeList list;

    for (Uint32 i = 0; i < 10; i++)
    {
        MyNode* node = new MyNode(i);
        list.Push_Back(node);
    }

    MyNodeIter iter = list.Begin();
    for ( ; iter != list.End(); ++iter )
    {
        MyNode& node = *iter;
        node.Printf();
    }

    list.Clear();
}

