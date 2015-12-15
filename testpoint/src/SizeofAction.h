#pragma once
#include "ActionBase.h"

#pragma pack(push)
#pragma pack(4)

class A1
{
};

typedef struct _Empty_Struct
{
} Empty_Struct;

typedef struct _Int_Struct
{
    Uint32 m;
} Int_Struct;

#pragma pack(pop)


class SizeofAction : public ActionBase
{
public:
    SizeofAction(void);
    ~SizeofAction(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "SizeofAction"; }
};
