#pragma once

#include "ActionBase.h"
#include <set>

///////////////////////////////////////////////////////////////////////////////
// Set Test Element Class
///////////////////////////////////////////////////////////////////////////////

class Set_Element
{
public:
    Set_Element();
    Set_Element(Uint32 value);
    ~Set_Element();
    
    inline Uint32 GetElementValue() const { return mElementValue; }
    inline void SetElementValue(Uint32 nValue) { mElementValue = nValue; }
    
    friend bool operator<(const Set_Element& lhs, const Set_Element& rhs)
        { return lhs.mElementValue < rhs.mElementValue; }

    inline void EnableDestructorPrint(bool isEnable=true) 
        { mIsPrintDestructor = isEnable; }
        
protected:
    Uint32  mElementValue;
    bool    mIsPrintDestructor;
};


class CompareElement
{
public:
    bool operator()(const Set_Element& lhs, const Set_Element& rhs)
    {
        return !(lhs < rhs);
    }
};

///////////////////////////////////////////////////////////////////////////////
// Prime Set Class
///////////////////////////////////////////////////////////////////////////////

class STLSet : public ActionBase
{
public:
    STLSet(void);
    ~STLSet(void);
    
public:
    virtual void Action();
    virtual const char* GetClassName() { return "STLSet"; }

protected:
    void Constructor();
    void Destructor_Clear();

    // Print all elements in set
    template <class Type>
    void PrintSetElement(Type& es);
};

