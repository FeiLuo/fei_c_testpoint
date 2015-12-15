#include "SizeofAction.h"

SizeofAction::SizeofAction(void)
{
}

SizeofAction::~SizeofAction(void)
{
}

void SizeofAction::Action()
{
    printf("typedef struct _Empty_Struct\r\n"
        "{\r\n"
        "} Empty_Struct;\r\n"
        "sizeof(Empty_Struct)=%d\r\n\r\n", sizeof(Empty_Struct));
    
    printf("typedef struct _Int_Struct\r\n"
        "{\r\n"
        "\tUint32 m;\r\n"
        "} Int_Struct;\r\n"
        "sizeof(Int_Struct)=%d\r\n\r\n", sizeof(Int_Struct));
    
    printf("class A\r\n"
        "{\r\n"
        "};\r\n"
        "sizeof(A)=%d\n\r\n", sizeof(A1));
}
