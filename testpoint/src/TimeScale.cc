#include "TimeScale.h"
#include "Tick.h"


TimeScale::TimeScale(void)
{
}

TimeScale::~TimeScale(void)
{
}

void TimeScale::Action()
{
#define  MAX_LOOP   10000000

    TimeScale_Test1* p1 = new TimeScale_Test1();
    TimeScale_Test* p = (TimeScale_Test1*)p1;

    TimeScale_Test1 *p2;
    Ticks t1_1 = Tick::CurrentTime();
    for (Uint32 i = 0; i < MAX_LOOP; i++)
    {
        p2 = dynamic_cast<TimeScale_Test1 *>(p);
    }
    Ticks t1_2 = Tick::CurrentTime();
    Uint64 d1 = Tick::TicksToMicroseconds(t1_2 - t1_1);

    Ticks t2_1 = Tick::CurrentTime();
    for (Uint32 i = 0; i < MAX_LOOP; i++)
    {
        p2 = static_cast<TimeScale_Test1 *>(p);
    }
    Ticks t2_2 = Tick::CurrentTime();
    Uint64 d2 = Tick::TicksToMicroseconds(t2_2 - t2_1);

    printf("loop %d times, dynamic_cast cost %llu ms, static_cast cost %llu ms\r\n", MAX_LOOP, d1, d2);
    if (d2 > d1)
        printf("static_cast() is slower than dynamic_cast\r\n");
    else
        printf("static_cast() is faster than dynamic_cast\r\n");

}
