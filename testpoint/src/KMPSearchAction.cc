#include "KMPSearchAction.h"
#include "KMPSearch.h"
#include <string>
using namespace std;

KMPSearchAction::KMPSearchAction()
{
}

KMPSearchAction::~KMPSearchAction()
{
}

void KMPSearchAction::Action()
{
    string str1 = "luofei";
    KMPSearch target(str1.c_str(), str1.length());

    string src1 = "llllllffffffffluoluoluofei";
    string src2 = "llllllffffffffluoluoluo";
    string src3 = "feillllllfffffffflu";

    Uint32 i = 0;
    Uint32 nLen = src1.length();

    // Find 1:
    printf("Find \"%s\" in \"%s\": ", str1.c_str(), src1.c_str());
    for (i=0; i<nLen; i++)
    {
        char c = src1.at(i);
        if (target.Match(c) != 0)
        {
            printf("find it in %d\n", i);
            break;
        }
    }
    if (i == nLen)
    {
        printf("find failed\n");
    }

    
    // Find 2: break memory find
    target.Reset();

    i = 0; 
    nLen = src2.length();
    printf("Find \"%s\" in \"%s\": ", str1.c_str(), src2.c_str());
    for (i=0; i<nLen; i++)
    {
        char c = src2.at(i);
        if (target.Match(c) != 0)
        {
            printf("find it in %d\n", i);
            break;
        }
    }
    if (i == nLen)
    {
        printf("find failed\n");
    }
    
    printf("Continue finding in \"%s\":", src3.c_str());
    i = 0; 
    nLen = src3.length();
    for (i=0; i<nLen; i++)
    {
        char c = src3.at(i);
        if (target.Match(c) != 0)
        {
            printf("find it in %d\n", i);
            break;
        }
    }
    if (i == nLen)
    {
        printf("find failed\n");
    }
}



