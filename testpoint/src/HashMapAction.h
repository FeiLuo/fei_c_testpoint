#ifndef _HashMapAction_HH__
#define _HashMapAction_HH__

#include "ActionBase.h"
#include <string>
#include <ext/hash_map>
using __gnu_cxx::hash_map;

class VLanStack
{
public:
    VLanStack();
    ~VLanStack();

    bool operator== (const VLanStack &rhs) const 
    {
        return ((mVLanNum == rhs.mVLanNum) && 
                (std::memcmp(&mVLan, &rhs.mVLan, sizeof(Uint16)*mVLanNum) == 0));
    }

    Uint8* GetHashMemory() const
    {
        return (Uint8*)&mVLan;
    }
    
    Uint32 GetHashMemoryLength() const
    {
        return (sizeof(Uint16) * mVLanNum / sizeof(Uint8));
    }

    void AddVLan(Uint8 vid);

    static const Uint32 sMaxVLanNum = 8;
    Uint32  mVLanNum;
    Uint16  mVLan[sMaxVLanNum];
};

class IpPeer
{
public:
    IpPeer() : mIpAddr(0) {};
    ~IpPeer() {};

    bool operator== (const IpPeer &rhs) const 
    {
        return ((mIpAddr == rhs.mIpAddr) && (mVLan == rhs.mVLan));
    }

    Uint32      mIpAddr;
    VLanStack   mVLan;
};

// hash_map get key function
struct HashIpPeer 
{
    // We use Justin Sobel Hash function to compute hash value here.
    // The third parameter is the initial vector of this function.
    // It can be the default value or a return value of jshasher to
    // conjunct two hash computation.
    size_t jshasher(const Uint8 *data, Uint32 len, size_t hash = 1315423911) const
    {
        for (Uint32 i = 0; i < len; ++i)
        {
            hash ^= ((hash << 5) + data[i] + (hash >> 2));
        }
        
        return hash;
    }
    
    size_t operator() (const IpPeer& peer) const
    {
        return jshasher( peer.mVLan.GetHashMemory(),
                         peer.mVLan.GetHashMemoryLength(), 
                         jshasher((Uint8*)&(peer.mIpAddr),
                                   sizeof(Uint32)/sizeof(Uint8)));
    }
};

// hash_map equal function
struct EqualIpPeer
{
    bool operator() (const IpPeer &lhs, const IpPeer &rhs) const
    {
        return (lhs == rhs);
    }
};

typedef hash_map<IpPeer, std::string, HashIpPeer, EqualIpPeer>    IpPeerMap;
typedef IpPeerMap::iterator             IpPeerMapIter;
typedef IpPeerMap::const_iterator       IpPeerMapConstIter;

class HashMapAction : public ActionBase
{
public:
    HashMapAction(void);
    ~HashMapAction(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "HashMapAction"; }

protected:
    IpPeerMap   mIpPeerMap;
};

#endif // _HashMapAction_HH__
