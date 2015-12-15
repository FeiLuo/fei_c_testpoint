#ifndef XercesAction_H__
#define XercesAction_H__

#include "ActionBase.h"

class XercesAction : public ActionBase
{
public:
    XercesAction();
    ~XercesAction();

public:
    void ParseXmlFile();
    void ParseXmlFromMemory();

    void PrintDOMNode(void* node);
        
public:
    virtual void Action();
    virtual const char* GetClassName() { return "XercesAction"; }
    
protected:
};

#endif // XercesAction_H__
