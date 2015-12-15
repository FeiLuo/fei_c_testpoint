#pragma once

// Try Template class derive

#include "ActionBase.h"
#include "List.h"

class SipNgHeaderBase : public Node
{
public:
    SipNgHeaderBase() {}
    virtual ~SipNgHeaderBase() {}

    virtual void Printf() = 0;
};

class SipNgHearderCallId : SipNgHeaderBase
{
public:
    SipNgHearderCallId() : SipNgHeaderBase() {}
    virtual ~SipNgHearderCallId() {}

    static const char* GetName() { return "SipNgHearderCallId"; }
    void Printf() 
    { printf("SipNgHearderCallId mId = %d\n", mId ); }

    Uint32 mId;
};

class SipNgHearderContentType : SipNgHeaderBase
{
public:
    SipNgHearderContentType() : SipNgHeaderBase() {}
    virtual ~SipNgHearderContentType() {}

    static const char* GetName() 
    { return "SipNgHearderContentType"; }

    void Printf() 
    { printf("SipNgHearderContentType mType = %d\n", mType ); }

    Uint32 mType;
};

template<class Type>
class SipNgHeaderList
{
public:
    typedef typename List<Type>::Iterator               SipNgHeaderIter;
    typedef typename List<Type>::Const_Iterator         ConstSipNgHeaderIter;
    typedef typename List<Type>::Reverse_Iterator       SipNgHeaderReverseIter;
    typedef typename List<Type>::Const_Reverse_Iterator ConstSipNgHeaderReverseIter;

    SipNgHeaderList() {};
    
    virtual ~SipNgHeaderList() 
    {
        mCollection.Clear(); 
    }

    Type& NewElement()
    {
        Type* newElement = new Type();
        mCollection.Push_Back(newElement);
        return *newElement;
    }

    virtual void Printf()
    {
        printf("Printf %s List\n", Type::GetName());
        SipNgHeaderIter iter = mCollection.Begin();
        for (; iter != mCollection.End(); ++iter)
        {
            Type& nElement = *iter;
            nElement.Printf();
        }
        printf("\n");
    }

protected:
    List<Type>  mCollection;
};

template<class Type>
class SipNgHeaderFeedBackList : public SipNgHeaderList<Type>
{
public:
    typedef SipNgHeaderList<Type>                       _Base;
    typedef typename _Base::SipNgHeaderIter             SipNgHeaderIter;
    typedef typename _Base::ConstSipNgHeaderIter        ConstSipNgHeaderIter;
    typedef typename _Base::SipNgHeaderReverseIter      SipNgHeaderReverseIter;
    typedef typename _Base::ConstSipNgHeaderReverseIter ConstSipNgHeaderReverseIter;

    SipNgHeaderFeedBackList() : _Base() {}
    virtual ~SipNgHeaderFeedBackList() {}
};


class TemplateDerived : public ActionBase
{
public:
    TemplateDerived(void);
    virtual ~TemplateDerived(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "TemplateDerived"; }
};

typedef SipNgHeaderList<SipNgHearderCallId>                 SipNgHearderCallIdList;
typedef SipNgHeaderFeedBackList<SipNgHearderContentType>    SipNgHearderContentTypeList;

