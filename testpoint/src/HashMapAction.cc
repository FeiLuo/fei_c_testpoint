#include "HashMapAction.h"

VLanStack::VLanStack()
  : mVLanNum(0)
{
    memset(mVLan, 0, sizeof(mVLan));
}

VLanStack::~VLanStack()
{
}

void VLanStack::AddVLan(Uint8 vid)
{
    mVLan[mVLanNum] = vid;
    mVLanNum++;
}


HashMapAction::HashMapAction()
{
}

HashMapAction::~HashMapAction()
{
}

void HashMapAction::Action()
{
    IpPeer p1, p2, p3, p4, p5;

    p1.mIpAddr = 1;
    p1.mVLan.AddVLan(1);
    p1.mVLan.AddVLan(2);

    p2.mIpAddr = 1;
    p2.mVLan.AddVLan(1);
    p2.mVLan.AddVLan(1);
    
    p3.mIpAddr = 1;
    p3.mVLan.AddVLan(1);
    p3.mVLan.AddVLan(2);

    if (p1 == p2)
        printf("p1 == p2\n");
    else
        printf("p1 != p2\n");

    if (p1 == p3)
        printf("p1 == p3\n");
    else
        printf("p1 != p3\n");

    mIpPeerMap[p1] = "p1";
    mIpPeerMap[p2] = "p2";

    IpPeerMapIter iter = mIpPeerMap.find(p3);
    if (iter != mIpPeerMap.end())
    {
        std::string s1 = (iter->second);
        printf("find p3 get name: %s\n", s1.c_str());
    }

}

