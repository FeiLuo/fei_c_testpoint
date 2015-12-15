#include "OperatorNew.h"

using namespace std;

Exercise::Exercise()
    : m_mem(0)
{
    printf("Exercise::Exercise()\n");
}

Exercise::Exercise(int nValue)
    : m_mem(nValue)
{
    printf("Exercise::Exercise(int %d)\n", nValue);
}

Exercise::~Exercise()
{
    printf("Exercise::~Exercise()\n");
}

void* Exercise::operator new(size_t nSize)
{
    char* ptr = ::new char [nSize];
    printf("void*(%p) Exercise::operator new(size_t %d)\n", ptr, nSize);
    
    return ptr;
}

void* Exercise::operator new[](size_t nSize)
{
    char* ptr = ::new char [nSize];
    printf("void*(%p) Exercise::operator new[](size_t %d)\n", ptr, nSize);
    
    return ptr;
}

void* Exercise::operator new(size_t nSize, char* pStart)
{
    Exercise* ptr = ::new (pStart) Exercise;
    printf("void*(%p) Exercise::operator new(size_t %d, char* %p)\n", ptr, nSize, pStart);
    
    return ptr;
}

void Exercise::operator delete(void* p, size_t nSize)
{
    printf("void Exercise::operator delete(void* %p, size_t %d)\n", p, nSize);
    
    ::delete (Uint8*)p;
    return;
}

void Exercise::operator delete[](void* p, size_t nSize)
{
    printf("void Exercise::operator delete[](void* %p, size_t %d)\n", p, nSize);
    
    ::delete[] (Uint8*)p;
    return;
}

void Exercise::operator delete(void* p, char* pStart)
{
    printf("void Exercise::operator delete(void* %p, char* %p)\n", p, pStart);
    
    return;
}

void Exercise::SetValue(int nValue)
{
    m_mem = nValue;
}

OperatorNew::OperatorNew(void)
{
}

OperatorNew::~OperatorNew(void)
{
}

void OperatorNew::Action()
{
    Exercise* ps = new Exercise(1);
    delete ps;
    
    //int size = sizeof(Exercise);
    Exercise* ps1 = new Exercise [10];
    ps1[0].SetValue(0);
    ps1[1].SetValue(1);
    ps1[2].SetValue(2);
    delete[] ps1;
    
    char* pBuff = new char[100];
    Exercise* ps2 = new (pBuff) Exercise;
    delete ps2;
}

