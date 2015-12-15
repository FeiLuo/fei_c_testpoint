#pragma once
#include "ActionBase.h"
#include "List.h"
#include <iostream>
using namespace std;

class ASDurationNode;

typedef List<ASDurationNode>            ASDurationList;
typedef List<ASDurationNode>::Iterator  ASDurationListIter;

class ASDurationNode : public Node
{
public:
    ASDurationNode();
    ASDurationNode(Uint64 startTime, Uint64 endTime);
    ~ASDurationNode();

    Uint64  mDurationStartTime;
    Uint64  mDurationEndTime;
};

class ASDurationManager
{
public:
    ASDurationManager();
    ~ASDurationManager();

    void MergeDuration(Uint64 startTime, Uint64 endTime);
    bool IsTimeInDuration(Uint64 nTime);

    void Print(ostream& os = cout);

protected:
    ASDurationList      mDurationList;
    ASDurationListIter  mCurrentIter;
};


class Duration : public ActionBase
{
public:
    Duration(void);
    ~Duration(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "Duration"; }
};
