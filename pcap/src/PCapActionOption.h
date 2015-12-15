#ifndef _PCAPACTIONOPTION_H_
#define _PCAPACTIONOPTION_H_

#include "CoreTypes.h"
#include <string>

class PCapActionOption
{
public:
    PCapActionOption();
    ~PCapActionOption(); 

    void SetOutFile(std::string filename);
    std::string& GetOutFile() { return mOutFile; }

protected:
    std::string     mOutFile;
};

#endif // _PCAPACTIONOPTION_H_

