#ifndef _PCapReplayer_h_
#define _PCapReplayer_h_

#include "PCapFile.h"

class PCapReplayer
{
public:
    PCapReplayer();
    ~PCapReplayer();

protected:
    PCapFile*       mPCapFile;
    PCapTimer*      mTimer;
};

#endif //_PCapReplayer_h_