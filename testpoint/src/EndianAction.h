#ifndef _ENDIAN_ACTION_H
#define _ENDIAN_ACTION_H

#include "ActionBase.h"

//
// how to judge big endian or little endian
// 

typedef union _EndianType
{
    char    mChar[8];
    Uint16  mUint16[4];
    Uint32  mUint32[2];
    Uint64  mUint64;
} EndianType;


class EndianAction : public ActionBase
{
public:
    EndianAction(void);
    ~EndianAction(void);

    // 
    void PrintBigOrLittle(bool isBigEndian);
    
public:
    virtual void Action();
    virtual const char* GetClassName() { return "EndianAction"; }
};

#endif /* _ENDIAN_ACTION_H */
