#include "FloatStruct.h"
#include <time.h>

FloatStruct::FloatStruct(void)
{
}

FloatStruct::~FloatStruct(void)
{
}



void FloatStruct::Action()
{
    PrintFloat(float(0.0));
    PrintFloat(float(0.1));
    PrintFloat(float(0.2));
    PrintFloat(float(0.3));
    
    PrintDouble(double(0.0));
    PrintDouble(double(0.1));
    PrintDouble(double(0.2));
    PrintDouble(double(0.3));
    
    ParseFloat(float(0.1));
    ParseDouble(double(0.1));
    
#if 0
    
#define  MAX_LOOP	3000000000
    
    Uint32 i1 = 100;
    Uint32 i2 = 1000;
    Uint32 i3 = 100000;
    
    Uint32 ii;
    
    time_t t1 = time(NULL);
    for (Uint32 i = 0; i < MAX_LOOP; i++)
    {
        ii = i3 / (i2 / i1);
    }
    time_t t2 = time(NULL);
    Int64 d1 = t2 - t1;
    
    
    float f1 = 100.0;
    float f2 = 1000.0;
    float f3 = 100000.0;
    
    Uint32 fi;
    
    t1 = time(NULL);
    for (Uint32 i = 0; i < MAX_LOOP; i++)
    {
        fi = (Uint32)(f3 / (f2 / f1));
    }
    t2 = time(NULL);
    Int64 d2 = t2 - t1;
    
    if (d1 < d2)
    {
        printf("the int calculation is faster than the float calculation!\n");
    }
    else if (d1 > d1)
    {
        printf("the float calculation is faster than the int calculation!\n");
    }
    else
    {
        printf("NO Result!!\n");
    }
#endif
}

void FloatStruct::PrintFloat(float f)
{
    Uint8* b = (Uint8*)(&f);
    
    printf("float %f's memory structure is: ", f);
    for (Uint32 i = 0; i < sizeof(float); i++)
    {
        printf("%02x ", b[i]);
    }
    printf("\n");
}


void FloatStruct::PrintDouble(double d)
{
    Uint8* b = (Uint8*)(&d);
    
    printf("double %f's memory structure is: ", d);
    for (Uint32 i = 0; i < sizeof(double); i++)
    {
        printf("%02x ", b[i]);
    }
    printf("\n");
}

void FloatStruct::ParseFloat(float f)
{
    Uint8* b = (Uint8*)(&f);
    FloatParser* parser = (FloatParser*)b;
    
    printf("\n");
    printf("Parse float %f's memory structure: \n", f);
    printf("\t1 bit mSign	    %d\n", parser->mSign);
    printf("\t8 bits mExponent  %d\n", parser->mExponent);
    printf("\t23 bits mMantissa %d\n", parser->mMantissa);
    printf("\n");
}

void FloatStruct::ParseDouble(double d)
{
    Uint8* b = (Uint8*)(&d);
    DoubleParser* parser = (DoubleParser*)b;
    
    printf("\n");
    printf("Parse double %f's memory structure: \n", d);
    printf("\tmSign	    %llu\n", parser->mSign);
    printf("\tmExponent %llu\n", parser->mExponent);
    printf("\tmMantissa %llu\n", parser->mMantissa);
    printf("\n");
}


