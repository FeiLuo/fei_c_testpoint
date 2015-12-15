#include "PCapActionOption.h"
#include "GlobalVariable.h"
using namespace std;

PCapActionOption::PCapActionOption()
{
}

PCapActionOption::~PCapActionOption()
{
}

void PCapActionOption::SetOutFile(string filename)
{
    mOutFile = GlobalVariable::GetInstance().mConfigPath + filename;
} 

