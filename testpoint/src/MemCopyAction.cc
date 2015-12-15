#include "MemCopyAction.h"
#include "Tick.h"

MemCopyAction::MemCopyAction(void)
{
}

MemCopyAction::~MemCopyAction(void)
{
}

void MemCopyAction::Action()
{
    #define MAX_LOOP  10000000
    #define STRING_LEN 12
    
    Uint8 sour[STRING_LEN+1] = "123456789";
    Uint8 dest[STRING_LEN+1];
    
    Uint32 i = 0;

    Ticks t1, t2;
    Uint64 delta;

    // 
    // 1. memcpy
    // 
    t1 = Tick::CurrentTime();
    for ( i=0; i<MAX_LOOP; i++)
    {
        memcpy(dest, sour, STRING_LEN);
    }
    t2 = Tick::CurrentTime();
    delta = Tick::TicksToMicroseconds(t2-t1);

    printf("memcpy performance : %llu ms\n", delta);

    t1 = Tick::CurrentTime();
    for ( i=0; i<MAX_LOOP; i++)
    {
        memmove(dest, sour, STRING_LEN);
    }
    t2 = Tick::CurrentTime();
    delta = Tick::TicksToMicroseconds(t2-t1);

    printf("memmove performance : %llu ms\n", delta);
}
