#include "PCapPlayAction.h"
#include "GlobalVariable.h"
#include "Exception.h"
#include "PCapFile.h"
#include "PCapActionOption.h"

using namespace std;

PCapPlayAction::PCapPlayAction()
  : ActionNode(ACTION_PCAP),
    mPcapFile(NULL),
    mOption(NULL)
{
}

PCapPlayAction::~PCapPlayAction()
{
    if (mPcapFile != NULL)
        delete mPcapFile;
}

void PCapPlayAction::ProcessAction()
{
    if (mPcapFileName.empty())
    {
        string errorMsg = "mPcapFileName is empty!";
        throw ProgramError("PCapPlayAction::ProcessAction", errorMsg);
    }
    
    string filePath = GlobalVariable::GetInstance().mConfigPath + mPcapFileName;
    FILE* pFile = fopen(filePath.c_str(), "rb");
    if ( pFile == NULL )
    {
        string errorMsg = "open \"" + filePath + "\" error!";
        throw ProgramError("PCapPlayAction::ProcessAction", errorMsg);
    }
    
    // obtain file size:
    fseek (pFile , 0 , SEEK_END);
    Uint32 nLen = ftell (pFile);
    rewind (pFile);

    Uint8* pBuffer = (Uint8*)malloc(nLen);
    Uint32 nRet = fread(pBuffer, 1, nLen, pFile);
    if ( nRet != nLen )
    {
        string errorMsg = "read \"" + filePath + "\" error!";
        throw ProgramError("PCapPlayAction::ProcessAction", errorMsg);
    }

    mPcapFile = new PCapFile();
    if (!mPcapFile->ParseMemory(pBuffer, nLen))
    {
        throw ProgramError("PCapPlayAction::ProcessAction", "Parse Pcap Error!");
    }

    if (mOption != NULL)
    {
        string outfile = mOption->GetOutFile();
        if (!outfile.empty())
        {
            mPcapFile->SaveToPcapFile(outfile);
        }
    }

    free(pBuffer);

    fclose(pFile);
    return;
}



