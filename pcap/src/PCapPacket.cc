#include "PCapPacket.h"
#include "PCapFile.h"

PCapPacket::PCapPacket(PCapFile* pcap, 
        Uint8*  buff,
        Uint32 nLen,
        StandardPCapRecordHeader* rcdHeader, 
        PatchedPCapRecordHeaderExt* extHeader)
  : m_PCapFile(pcap),
    m_RecordHeader(rcdHeader),
    m_RecordHeaderExt(extHeader),
    m_EthHeader(NULL),
    m_ARPHeader(NULL),
    m_IPHeader(NULL),
    m_ICMPHeader(NULL),
    m_UDPHeader(NULL),
    m_TCPHeader(NULL),
    m_Buffer(buff),
    m_BufferLen(nLen)
{
}

PCapPacket::~PCapPacket()
{
}

string PCapPacket::GetErrorMsg()
{
    string msg = m_ErrorMsg.str();
    m_ErrorMsg.str("");
    return msg;
}

bool PCapPacket::ParsePacket()
{
    if (m_BufferLen <= sizeof(EthernetHeader))
    {
        m_ErrorMsg << "PCapPacket::"<< __FUNCTION__ 
            << ": Parse Eth header error!"
            << endl;
        return false;
    }

#define PARSE_MOVE(x) {pBuff+=(x); nLen-=(x); }

    // Ethernet Header
    Uint8* pBuff = m_Buffer;
    Uint32 nLen = m_BufferLen;
    
    m_EthHeader = (EthernetHeader*)pBuff;


/*
    EthernetHeader*             m_EthHeader;
    ARPHeader*                  m_ARPHeader;
    IPHeader*                   m_IPHeader;
    ICMPHeader*                 m_ICMPHeader;
    UDPHeader*                  m_UDPHeader;
    TCPHeader*                  m_TCPHeader;
*/
    // IP or ARP
    PARSE_MOVE(sizeof(EthernetHeader));
    
    Uint16 ethernetType = NtoH16(m_EthHeader->type);
    if (ethernetType == ETHER_ARP) 
    {
        // ARP 
        if (nLen < sizeof(ARPHeader))
        {
            m_ErrorMsg << "PCapPacket::"<< __FUNCTION__
                << ": Parse ARP header error!"
                << endl;
            return false;
        }
        m_ARPHeader = (ARPHeader*)pBuff;
        PARSE_MOVE(sizeof(ARPHeader));
    }
    else if (ethernetType == ETHER_IP)
    {
        // IP
        if (nLen < sizeof(IPHeader))
        {
            m_ErrorMsg << "PCapPacket::"<< __FUNCTION__ 
                << ": Parse IP header error!"
                << endl;
            return false;
        }
        m_IPHeader= (IPHeader*)pBuff;
        PARSE_MOVE(sizeof(IPHeader));

        Uint8 protocol = m_IPHeader->protocol;
        switch ( protocol )
        {
            case IP_ICMP :
                m_ICMPHeader = (ICMPHeader*)pBuff;
                PARSE_MOVE(sizeof(ICMPHeader));
                break;
            case IP_TCP :
                m_TCPHeader = (TCPHeader*)pBuff;
                PARSE_MOVE(sizeof(TCPHeader));
                break;
            case IP_UDP :
                m_UDPHeader = (UDPHeader*)pBuff;
                PARSE_MOVE(sizeof(m_UDPHeader));
                break;
            default:
                m_ErrorMsg << "PCapPacket::"<< __FUNCTION__ 
                    << ": Unknown Protocol type in IP header!"
                    << endl;
                return false;
        }
    }
    else
    {
        // do nothing
    }
    
    
    

    
    return true;
}


