#ifndef PCapPlayAction_H_
#define PCapPlayAction_H_

#include "ActionNode.h"
#include <string>

class PCapFile;
class PCapActionOption;

class PCapPlayAction : public ActionNode
{
public:
    PCapPlayAction();
    ~PCapPlayAction();

    void ProcessAction();

    PCapActionOption* GetPCapActionOption() { return mOption; }
    void SetPCapActionOption(PCapActionOption* option) { mOption = option; }

    void SetPcapFile(char* filename) { mPcapFileName = filename; }
   
protected:
    std::string         mPcapFileName;
    PCapFile*           mPcapFile;
    PCapActionOption*   mOption;
};

#endif // PCapPlayAction_H_
