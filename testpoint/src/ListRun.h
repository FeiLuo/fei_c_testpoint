#pragma once
#include "ActionBase.h"
#include "List.h"


class MyNode : public Node
{
public:
    MyNode() : nCount(0) {}
    MyNode(Uint32 num) : nCount(num) {}
    ~MyNode() {}
    void Printf()
    {
        printf("MyNode %d\n", nCount);
    }

    Uint32 nCount;
};

typedef List<MyNode>        MyNodeList;
typedef Iterator<MyNode>    MyNodeIter;

class ListRun : public ActionBase
{
public:
    ListRun(void);
    ~ListRun(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "ListRun"; }
};
