#include "STLSet.h"
using namespace std;

typedef set<int>            IntSet;
typedef set<int>::iterator  IntSetIter;

bool SetElementCompare(const Set_Element& lhs, const Set_Element& rhs)
{
    return !(lhs < rhs);
}

Set_Element::Set_Element()
  : mElementValue(0),
    mIsPrintDestructor(false)
{
}

Set_Element::Set_Element(Uint32 value) 
  : mElementValue(value),
    mIsPrintDestructor(false)
{
}


Set_Element::~Set_Element()
{
    if (mIsPrintDestructor)
    {
        printf("%s is called! mElementValue= %d\n", __FUNCTION__, mElementValue);
    }
}

STLSet::STLSet(void)
{
}

STLSet::~STLSet(void)
{
}

void STLSet::Action()
{
    printf("lower_bound means \">=\"; while upper_bound \">\"\n");
    
    IntSet myset;
    IntSetIter it, itlow, itup, ittop;
    
    printf("Inset number to myset: ");
    for (int i=1; i<10; i++)  
    {
        myset.insert(i*10);
        printf("%d ", i*10);
    }
    printf("\n");
    
    itlow = myset.lower_bound(35);
    printf("myset.lower_bound(35) is %d\n", *itlow);
    
    itup  = myset.upper_bound(35);
    printf("myset.upper_bound(35) is %d\n", *itup);
    
    ittop = myset.lower_bound(1000);
    if (ittop == myset.end())
        printf("Arrive the end of set\n");
    else
        printf("myset.lower_bound(1000) is %d\n", *ittop);
    
    itlow = myset.lower_bound(40);
    printf("myset.lower_bound(40) is %d\n", *itlow);
    
    itup  = myset.upper_bound(40);
    printf("myset.upper_bound(40) is %d\n", *itup);

    // All set functions
    Constructor();

    Destructor_Clear();
}

void STLSet::Constructor()
{
    // 1. 
    // explicit set ( const Compare& comp = Compare(),
    //                const Allocator& = Allocator() );
    // 2. 
    // template <class InputIterator>
    //   set ( InputIterator first, InputIterator last,
    //         const Compare& comp = Compare(), const Allocator& = Allocator() );
    // 3. 
    // set ( const set<Key,Compare,Allocator>& x );

    Set_Element e1[] = {
        Set_Element(1),
        Set_Element(2),
        Set_Element(4),
        Set_Element(3),
        Set_Element(5)
    };

    typedef set<Set_Element>                   ElementSet;
    typedef set<Set_Element, CompareElement>   ElementCompareSet;

    // 1. 
    set<Set_Element> es1;

    // 2. 
    set<Set_Element> es2(e1, e1+5);  // +5 ??
    PrintSetElement<ElementSet>(es2);

    set<Set_Element> es3(es2.begin(), es2.end());
    PrintSetElement<ElementSet>(es2);

    // 3. 
    set<Set_Element> es4(es3);
    PrintSetElement<ElementSet>(es4);

    // my compare function
    set<Set_Element, CompareElement> es5(es2.begin(), es2.end());
    PrintSetElement<ElementCompareSet>(es5);
}

void STLSet::Destructor_Clear()
{
    // set::~set()

    // 1. 
    Set_Element e1[] = {
        Set_Element(1),
        Set_Element(2),
        Set_Element(4),
        Set_Element(3),
        Set_Element(5)
    };
    e1[0].EnableDestructorPrint(true);
    e1[1].EnableDestructorPrint(true);
    e1[2].EnableDestructorPrint(true);
    e1[3].EnableDestructorPrint(true);
    e1[4].EnableDestructorPrint(true);

    printf("~set() and clear() will call each of the contained element's destructors.\n");
    set<Set_Element> es1(e1, e1+5);
    es1.clear();
    // es1.~set();     // it will lead to crash since the ~set() will be called twice. 
    printf("Finished at here!\n");

    e1[0].EnableDestructorPrint(false);
    e1[1].EnableDestructorPrint(false);
    e1[2].EnableDestructorPrint(false);
    e1[3].EnableDestructorPrint(false);
    e1[4].EnableDestructorPrint(false);
    
    // 2. 
    #define ELEMENT_NUMBER 5
    
    Set_Element* e2 = new Set_Element [ELEMENT_NUMBER];
    set<Set_Element*> es2;

    for (Uint32 i=0; i<ELEMENT_NUMBER; i++)
    {
        e2[i].SetElementValue(i+10);
        e2[i].EnableDestructorPrint(true);
        es2.insert(&e2[i]);
    }

    es2.clear();
    // es2.~set();

    for (Uint32 i=0; i<ELEMENT_NUMBER; i++)
    {
        e2[i].EnableDestructorPrint(false);
    }
    delete [] e2;
}

template <class Type>
void STLSet::PrintSetElement(Type& es)
{
    typename Type::iterator iter = es.begin();
    for(; iter != es.end(); iter++)
    {
        Set_Element e = *iter;
        printf("%d ", e.GetElementValue());
    }
    printf("\n");
}


