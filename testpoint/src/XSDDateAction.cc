#include "XSDDateAction.h"
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// XSDDate
///////////////////////////////////////////////////////////////////////////////
XSDDate::XSDDate()
{
    Reset();
}

XSDDate::~XSDDate()
{
}

void XSDDate::Reset()
{
    mYear = 0;
    mMonth = 0;
    mDay = 0;
    mNegative = false;
    mOffsetHour = 0;
    mOffsetSecond = 0;
    memset(&mTimeInfo, 0, sizeof(mTimeInfo));
    memset(&mTime, 0, sizeof(mTime));
}

bool XSDDate::Parse(const char* date, int nLen)
{
    Reset();
    
    static char temp[100];
    memset(temp, 0, sizeof(temp));
    Int32 nRet = sscanf(date, "%d-%d-%d%s", &mYear, &mMonth, &mDay, temp);
    if (nRet < 3)
        return false;

    if (nRet == 3)
        return true;

    mTimeInfo.tm_year = mYear - 1900;
    mTimeInfo.tm_mon  = mMonth;
    mTimeInfo.tm_mday = mDay;

    switch (temp[0])
    {
        case 'Z':
            return ProcessTimeZone();
        case '-':
            mNegative = true;
            return ParseOffset(temp+1, strlen(temp)-1);
            break;
        case '+':
            mNegative = false;
            return ParseOffset(temp+1, strlen(temp)-1);
            break;
        default:
            return false;
    }
    
    return true;
}

bool XSDDate::ParseOffset(const char* date, int nLen)
{
    Int32 nRet = sscanf(date, "%d:%d", &mOffsetHour, &mOffsetSecond);
    if (nRet != 2)
        return false;

    Int32 nSec = mOffsetHour * 60 + mOffsetSecond;

    

    return true;
}

bool XSDDate::ProcessTimeZone()
{
    return true;
}

bool XSDDate::UnitTest()
{
    const char* p1 = "2002-09-24";
    const char* p2 = "2002-09-24Z";
    const char* p3 = "2002-09-24-06:00";
    const char* p4 = "2002-09-24+06:00";

    XSDDate d1;
    d1.Parse(p1, strlen(p1));
    d1.Print();
    d1.Parse(p2, strlen(p2));
    d1.Print();
    d1.Parse(p3, strlen(p3));
    d1.Print();
    d1.Parse(p4, strlen(p4));
    d1.Print();

    return true;
}

void XSDDate::Print()
{
    cout << "Year " << mYear << "; "
        << "Month " << mMonth << "; "
        << "Day " << mDay << "; "
        << "Negative " << mNegative << "; "
        << "Hour " << mOffsetHour << "; "
        << "Minute " << mOffsetSecond << "; "
        << endl;
}


///////////////////////////////////////////////////////////////////////////////
// XSDDuration
///////////////////////////////////////////////////////////////////////////////
XSDDuration::XSDDuration(const char* date, int nLen)
{
    Parse(date, nLen);
}

XSDDuration::~XSDDuration()
{
}

void XSDDuration::Reset()
{
    mNegative = 1;
    mYear   = 0.0;
    mMonth  = 0.0;
    mDay    = 0.0;
    mHour   = 0.0;
    mMinute = 0.0;
    mSecond = 0.0;

    mDurationTimeInMilliSec = 0;
}

bool XSDDuration::Parse(const char* date, int nLen)
{
    Reset();

    if (nLen < 3)
        return false;

    const char* pBegin = date;
    
    if ((*pBegin == '-'))
    {
         if (*(pBegin+1) != 'P')
         {
            return false;
         }
        mNegative = -1;
        pBegin+=2;
    }
    else
    {
        if (*pBegin != 'P')
            return false;
        
        pBegin++;
    }

    // indentify 'M', if the 'T' occurs , it means minute otherwise it is month
    bool bMinute = false;
    
    char* pEnd;
    double dValue;
    char cc;
    
    while (pBegin <= (date + nLen))
    {
        cc = *pBegin;
        if (isdigit(cc) != 0)
        {
            dValue = strtod(pBegin, &pEnd);
            pBegin = pEnd;
        }
        else
        {
            switch (cc)
            {
                case 'Y':
                    mYear = dValue;
                    break;
                case 'M':
                    if (!bMinute)   // month
                        mMonth = dValue;
                    else            // minute
                        mMinute = dValue;
                    break;
                case 'D':
                    mDay = dValue;
                    break;
                case 'T':
                    bMinute = true;
                    break;
                case 'H':
                    mHour = dValue;
                    break;
                case 'S':
                    mSecond= dValue;
                    break;
                case '\0':
                    CalculateDuratonTime();
                    return true;
                default:
                    Reset();
                    return false;
            }
            pBegin += 1;
            dValue = 0.0;
        }
    }

    return true;
}

void XSDDuration::CalculateDuratonTime()
{
    static const Uint64 MILLISEC_PER_SECOND = (1000);
    static const Uint64 MILLISEC_PER_MINUTE = (60 * MILLISEC_PER_SECOND);
    static const Uint64 MILLISEC_PER_HOUR   = (60 * MILLISEC_PER_MINUTE);
    static const Uint64 MILLISEC_PER_DAY    = (24 * MILLISEC_PER_HOUR);
    static const Uint64 MILLISEC_PER_MONTH  = (30 * MILLISEC_PER_DAY);
    static const Uint64 MILLISEC_PER_YEAR   = (365 * MILLISEC_PER_DAY);

    mDurationTimeInMilliSec = ((Int64)( mYear * MILLISEC_PER_YEAR +
                                        mMonth * MILLISEC_PER_MONTH +
                                        mDay * MILLISEC_PER_DAY +
                                        mHour * MILLISEC_PER_HOUR +
                                        mMinute * MILLISEC_PER_MINUTE +
                                        mSecond * MILLISEC_PER_SECOND )) * mNegative;
}

void XSDDuration::Print()
{
    printf("Negative %d; Year %f, Month %f, Day %f, Hour %f, Minute %f, Second %f\n",
        mNegative, mYear, mMonth, mDay, mHour, mMinute, mSecond);
}

bool XSDDuration::UnitTest()
{
    const char* p1 = "P5Y";
    const char* p2 = "P5Y2M10D";
    const char* p3 = "P5Y2M10DT15H";
    const char* p4 = "PT15H";
    const char* p5 = "-P10D";

    XSDDuration d1(p1, strlen(p1));
    d1.Print();
    
    XSDDuration d2(p2, strlen(p2));
    d2.Print();
    
    XSDDuration d3(p3, strlen(p3));
    d3.Print();
    
    XSDDuration d4(p4, strlen(p4));
    d4.Print();
    
    XSDDuration d5(p5, strlen(p5));
    d5.Print();

    return true;
}


XSDDateAction::XSDDateAction(void)
{
}

XSDDateAction::~XSDDateAction(void)
{
}

void XSDDateAction::Action()
{
    XSDDate::UnitTest();
    XSDDuration::UnitTest();
}
