#ifndef XSDDateAction_h_
#define XSDDateAction_h_

#include "ActionBase.h"
#include "time.h"

// <xs:element name="start" type="xs:date"/> 
// 1. <start>2002-09-24</start> 
// 2. Time Zones: you can either enter a date in UTC time by adding a "Z" behind the date.
//      <start>2002-09-24Z</start> 
// 3. Time Zones: you can specify an offset from the UTC time by adding a positive or negative time behind the date 
//      <start>2002-09-24-06:00</start>
//      <start>2002-09-24+06:00</start> 
class XSDDate
{
public:
   XSDDate();
   ~XSDDate();

    bool Parse(const char* date, int nLen);

    static bool UnitTest();

    void Reset();
    void Print();

    
    Uint32  mYear;
    Uint32  mMonth;
    Uint32  mDay;
    bool    mNegative;
    Uint32  mOffsetHour;
    Uint32  mOffsetSecond;

protected:
    bool ParseOffset(const char* date, int nLen);
    bool ProcessTimeZone();

    struct tm   mTimeInfo;
    time_t      mTime;
};

// The time interval is specified in the following form "PnYnMnDTnHnMnS" where:
// P indicates the period (required) 
// nY indicates the number of years 
// nM indicates the number of months 
// nD indicates the number of days 
// T indicates the start of a time section (required if you are going to specify hours, minutes, or seconds) 
// nH indicates the number of hours 
// nM indicates the number of minutes 
// nS indicates the number of seconds
// 
// <xs:element name="period" type="xs:duration"/> 
// 1. <period>P5Y</period> 
// 2. <period>P5Y2M10D</period> 
// 3. <period>P5Y2M10DT15H</period> 
// 4. <period>PT15H</period> 
// 5. <period>-P10D</period> 
class XSDDuration
{
public:
    XSDDuration(const char* date, int nLen);
    ~XSDDuration();

    Int64 GetDuratonTimeInMilliSeconds() { return mDurationTimeInMilliSec; }

    void Print();

    static bool UnitTest();

protected: 
    bool Parse(const char* date, int nLen);
    void Reset();
    void CalculateDuratonTime();


    Int32   mNegative;  // the duration may be negative. 
    double  mYear;
    double  mMonth;
    double  mDay;
    double  mHour;
    double  mMinute;
    double  mSecond;
    
    Int64 mDurationTimeInMilliSec;
};

class XSDDateAction :	public ActionBase
{
public:
    XSDDateAction(void);
    ~XSDDateAction(void);

protected:

public:
    virtual void Action();
    virtual const char* GetClassName() { return "XSDDateAction"; }
};


#endif // XSDDateAction_h_
