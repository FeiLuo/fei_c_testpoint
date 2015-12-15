#ifndef _PCapTimer_H_
#define _PCapTimer_H_

#include "CoreEvent.h"

class PCapTimer : public CoreEvent
{
public:
    PCapTimer();
    ~PCapTimer();

    virtual void ExecuteFunction();

};

#endif // _PCapTimer_H_
