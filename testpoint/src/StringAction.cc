#include "StringAction.h"
#include <string>
#include <vector>
using namespace std;

StringAction::StringAction(void)
{
}

StringAction::~StringAction(void)
{
}

void StringAction::Action()
{
    string str(100, 'a');
    
    Uint32 nSize = str.size();
    Uint32 nCapacity = str.capacity();
    
    printf("original string's size is %d; capacity is %d\n", nSize, nCapacity);
    
    str = "123";
    str.clear();
    nSize = str.size();
    nCapacity = str.capacity();
    printf("after clear, string's size is %d; capacity is %d\n", nSize, nCapacity);
    
    str = "123";
    str.erase();
    nSize = str.size();
    nCapacity = str.capacity();
    printf("after earse, string's size is %d; capacity is %d\n", nSize, nCapacity);

    str = "luofei/";
    printf("before earse, \"%s\"; ", str.c_str());
    if (str.at(str.length() - 1) == '/')
    {
        str.erase(str.length()-1, 1);
    }
    printf("after earse, \"%s\";\n", str.c_str());

    str = "luofei";
    printf("before earse, \"%s\"; ", str.c_str());
    if (str.at(str.length() - 1) == '/')
    {
        str.erase(str.length()-1, 1);
    }
    printf("after earse, \"%s\";\n", str.c_str());


    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    
    nSize = v1.size();
    nCapacity = v1.capacity();
    printf("original vecotor's size is %d; capacity is %d\n", nSize, nCapacity);
    
    v1.clear();
    nSize = v1.size();
    nCapacity = v1.capacity();
    printf("after clear, string's size is %d; capacity is %d\n", nSize, nCapacity);

    vector<int> v2;
    v1.swap(v2);
    nSize = v1.size();
    nCapacity = v1.capacity();
    printf("after swap, string's size is %d; capacity is %d\n", nSize, nCapacity);
}


