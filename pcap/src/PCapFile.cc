#include "PCapFile.h"
#include "PCapPacket.h"
#include "Exception.h"

#include <string.h>     // for memcpy()
#include <errno.h>

using namespace std;

    
PCapFile::PCapFile()
  : m_PCapHeader(NULL),
    m_Buffer(NULL),
    m_BufferLen(0),
    mSwapped(false),
    mPatched(false)
{
}

PCapFile::~PCapFile()
{
    if (m_Buffer != NULL)
        delete [] m_Buffer;

    m_PCapPacketList.Clear();
}

bool PCapFile::ParseMemory(Uint8* pMem, Uint32 nLen)
{
    if (m_Buffer != NULL)
        delete [] m_Buffer;

    m_BufferLen = nLen;
    m_Buffer = new Uint8 [m_BufferLen];
    memcpy(m_Buffer, pMem, m_BufferLen);

    if (!ParseFileHeader())
    {
        throw FileError("PCapFile::ParseMemory", GetErrorMsg());
        return false;
    }

    // PCap Recodrer 
    Uint8* pBuff = m_Buffer + sizeof(PCapFileHeader);
    Uint8* pEnd = m_Buffer + nLen;
    StandardPCapRecordHeader* rcdHeader;
    while (pBuff < pEnd)
    {
        // PCap Recorder Header
        rcdHeader = (StandardPCapRecordHeader*)pBuff;
        pBuff += sizeof(StandardPCapRecordHeader);

        // If the record headers are patched, grab the patched extension.
        PatchedPCapRecordHeaderExt *patchedExt = NULL;
        if (mPatched) 
        {
            patchedExt = (PatchedPCapRecordHeaderExt*)pBuff;
            pBuff += sizeof(PatchedPCapRecordHeaderExt);
        }

        // Process capture data
        PCapPacket* pk = new PCapPacket(this, pBuff, rcdHeader->captureLength,
                                        rcdHeader, patchedExt);
        if (!pk->ParsePacket())
        {
            m_ErrorMsg << pk->GetErrorMsg() << endl;
            delete pk;
            throw FileError("PCapFile::ParseMemory", GetErrorMsg());
            return false;
        }
        m_PCapPacketList.Push_Back(pk);

        // PCap Recorder
        pBuff += rcdHeader->captureLength;
    }
    
    return true;
}

bool PCapFile::ParseFileHeader()
{
    if (m_BufferLen < sizeof(PCapFileHeader))
    {
        m_ErrorMsg << "it's not a pcap file!" << endl;
    }


    // PCap file header
    m_PCapHeader = (PCapFileHeader*) m_Buffer;
    if (m_PCapHeader->Magic == PCAP_STANDARD_MAGIC) 
    {
        mSwapped = false;
        mPatched = false;
    }
    else if (m_PCapHeader->Magic == PCAP_PATCHED_MAGIC) 
    {
        mSwapped = false;
        mPatched = true;
    }
    else if (m_PCapHeader->Magic == NtoH32(PCAP_STANDARD_MAGIC)) 
    {
        mSwapped = true;
        mPatched = false;
    }
    else if (m_PCapHeader->Magic == NtoH32(PCAP_PATCHED_MAGIC)) 
    {
        mSwapped = true;
        mPatched = true;
    } 
    else 
    {
        m_ErrorMsg << "it's not a pcap file!" << endl;
        return false;
    }
    return true;
}

string PCapFile::GetErrorMsg()
{
    string msg = m_ErrorMsg.str();
    m_ErrorMsg.str("");
    return msg;
}

bool PCapFile::SaveToPcapFile(const string& fileName)
{
    FILE* fp = fopen(fileName.c_str(), "w");
    if(fp == NULL) 
    {
        m_ErrorMsg << "Could not open PCap file " 
            << fileName << ", " 
            << strerror(errno);
        throw FileError("PCapFile::SaveToPcapFile", GetErrorMsg());
    }

    if(fwrite(m_Buffer, m_BufferLen, 1, fp) != 1)
    {
        m_ErrorMsg << "SaveToPCapFile " << fileName 
            << " Error, " 
            << strerror(errno);
        throw FileError("PCapFile::SaveToPcapFile",GetErrorMsg());
    }
    fclose(fp);
}


