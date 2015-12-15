#include "AllActions.h"
#include "CallBackAction.h"
#include "ConstructAction.h"
#include "ConstAction.h"
#include "CoreEventAction.h"
#include "Duration.h"
#include "MemCopyAction.h"
#include "EndianAction.h"
#include "ExceptionAction.h"
#include "ExplicitAction.h"
#include "EventLogAction.h"
#include "FloatStruct.h"
#include "HashMapAction.h"
#include "KMPSearchAction.h"
#include "ListRun.h"
#include "MallocAction.h"
#include "OperatorNew.h"
#include "OperatorSample.h"
#include "OstringstreamAction.h"
#include "PerformanceCompareAction.h"
#include "Prim.h"
#include "ScanfAction.h"
#include "SizeofAction.h"
#include "Sort.h"
#include "STLSet.h"
#include "StringAction.h"
#include "StructEqual.h"
#include "TemplateDerived.h"
#include "TimeScale.h"
#include "TypeTransfer.h"
#include "VirtualFunction.h"
#include "XercesAction.h"
#include "XSDDateAction.h"

void AllActions::RunAllActions()
{
    ActionList myActions;
    myActions.push_back(new CallBackAction());
    myActions.push_back(new ConstructAction());
    myActions.push_back(new ConstAction());
    myActions.push_back(new CoreEventAction());
    myActions.push_back(new Duration());
    myActions.push_back(new EndianAction());
    myActions.push_back(new ExceptionAction());
    myActions.push_back(new ExplicitAction());
    myActions.push_back(new EventLogAction());
    myActions.push_back(new FloatStruct());
    myActions.push_back(new HashMapAction());
    myActions.push_back(new KMPSearchAction());
    myActions.push_back(new ListRun());
    myActions.push_back(new MallocAction());
    myActions.push_back(new MemCopyAction());
    myActions.push_back(new OperatorNew());
    myActions.push_back(new OperatorSample());
    myActions.push_back(new OstringstreamAction());
    myActions.push_back(new PerformanceCompareAction());
    myActions.push_back(new Prim());
    myActions.push_back(new ScanfAction());
    myActions.push_back(new SizeofAction());
    myActions.push_back(new Sort());
    myActions.push_back(new STLSet());
    myActions.push_back(new StringAction());
    myActions.push_back(new StructEqual());
    myActions.push_back(new TemplateDerived());
    myActions.push_back(new TimeScale());
    myActions.push_back(new TypeTransfer());
    myActions.push_back(new VirtualFunction());
    myActions.push_back(new XercesAction());
    myActions.push_back(new XSDDateAction());
    
    // do test action and then remove it
    ActionListIter iter = myActions.begin();
    for (; iter != myActions.end(); iter++)
    {
        ActionBase* action = *iter;
        action->PrintTitle();
        action->Action();
        delete action;
    }
    myActions.clear();
}

