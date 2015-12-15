#include "OstringstreamAction.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void OstringstreamAction::Action()
{
    ostringstream os;

    int     myInt   = 1;
    Uint8   myUint8 = 1;
    bool    myBool  = true;
    short   myShort = 1;

    os << "int : " << myInt << endl;
    cout << os.str();
    os.str("");

    os << "Uint8 : " << (unsigned short)myUint8 << endl;
    cout << os.str();
    os.str("");

    os << "Bool : " << myBool << endl;
    cout << os.str();
    os.str("");

    os << "Short : " << myShort << endl;
    cout << os.str();
    os.str("");
}


