#include "ScanfAction.h"
#include <iostream>
using namespace std;

ScanfAction::ScanfAction(void)
{
}

ScanfAction::~ScanfAction(void)
{
}

void ScanfAction::ParseIP(const char* addr)
{
    char strAddr[100] = {0};
    Uint32 nPort;
    Uint32 nRet = sscanf(addr, "[%[0-9a-fA-F:]]:%d", strAddr, &nPort);
    if (nRet == 0)
    {
        cout << "this is a IPv4 address" << endl;
    }
    else if (nRet == 1)
    {
        cout << "IPv6 Address is " << strAddr << endl;
    }
    else if (nRet == 2)
    {
        cout << "IPv6 Address is " << strAddr << "; Port is " << nPort << endl;
    }
}


void ScanfAction::Action()
{
    const char* p1 = "[2001::1]";
    const char* p2 = "[2001::1]:554";
    const char* p3 = "192.168.1.1";
    const char* p4 = "[200a::F]";
    const char* p5 = "[20ga::F]:554";

    ParseIP(p1);
    ParseIP(p2);
    ParseIP(p3);
    ParseIP(p4);
    ParseIP(p5);
}



