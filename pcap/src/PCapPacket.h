#ifndef _PCAP_PACKET_H_
#define _PCAP_PACKET_H_

#include "CoreTypes.h"
#include "PCap.h"

#include <iostream>
#include <sstream>

class PCapFile;

class PCapPacket
{
public:
    PCapPacket(PCapFile* pcap, 
        Uint8*  buff,
        Uint32 nLen,
        StandardPCapRecordHeader* rcdHeader = NULL, 
        PatchedPCapRecordHeaderExt* extHeader = NULL);
    ~PCapPacket();

    std::string GetErrorMsg();
    bool ParsePacket();

    bool    IsEth()         { return (m_EthHeader != NULL); }
    bool    IsARP()         { return (m_ARPHeader != NULL); }
    bool    IsIP()          { return (m_IPHeader != NULL); }
    bool    IsICMP()        { return (m_ICMPHeader != NULL); }
    bool    IsUDP()         { return (m_UDPHeader != NULL); }
    bool    IsTCP()         { return (m_TCPHeader != NULL); }

protected:
    PCapFile*                   m_PCapFile;
    StandardPCapRecordHeader*   m_RecordHeader;
    PatchedPCapRecordHeaderExt* m_RecordHeaderExt;
    
    EthernetHeader*             m_EthHeader;
    ARPHeader*                  m_ARPHeader;
    IPHeader*                   m_IPHeader;
    ICMPHeader*                 m_ICMPHeader;
    UDPHeader*                  m_UDPHeader;
    TCPHeader*                  m_TCPHeader;

    Uint8*                      m_Buffer;       // share same packet memory with PCapFile
    Uint32                      m_BufferLen;

    std::ostringstream      m_ErrorMsg;
};
#endif /* _PCAP_PACKET_H_ */
