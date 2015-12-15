#pragma once
#include "ActionBase.h"

typedef struct  
{
    Uint32  mSign:1;        // sign
    Uint32  mExponent:8;    // exponent
    Uint32  mMantissa:23;    // Mantrissa
} FloatParser;

typedef struct
{
    Uint64  mSign:1;        // sign
    Uint64  mExponent:11;    // exponent
    Uint64  mMantissa:52;    // Mantrissa
} DoubleParser;

class FloatStruct :	public ActionBase
{
public:
    FloatStruct(void);
    ~FloatStruct(void);

protected:
    void PrintFloat(float f);
    void PrintDouble(double d);

    void ParseFloat(float f);
    void ParseDouble(double d);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "FloatStruct"; }
};
