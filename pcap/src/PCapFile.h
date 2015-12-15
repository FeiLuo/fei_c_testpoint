#ifndef _PCAP_FILE_H
#define _PCAP_FILE_H

#include "CoreTypes.h"
#include "List.h"
#include "PCap.h"

#include <iostream>
#include <sstream>
#include <string>

class PCapPacket;

class PCapFile
{
public:
    PCapFile();
    ~PCapFile();

    bool ParseMemory(Uint8* pMem, Uint32 nLen);

    std::string GetErrorMsg();

    bool SaveToPcapFile(const std::string& fileName);

protected:
    
    bool ParseFileHeader();
    
protected:

    PCapFileHeader*         m_PCapHeader;
    Uint8*                  m_Buffer;
    Uint32                  m_BufferLen;

    List<PCapPacket>        m_PCapPacketList;

    bool    mSwapped;
    bool    mPatched;
    
    std::ostringstream      m_ErrorMsg;

};

#endif /* _PCAP_FILE_H */

