#include "TemplateDerived.h"

TemplateDerived::TemplateDerived(void)
{
}

TemplateDerived::~TemplateDerived(void)
{
}

void TemplateDerived::Action()
{
    SipNgHearderCallIdList callIdList;
    SipNgHearderContentTypeList contentTypeList;

    SipNgHearderCallId& callId1 = callIdList.NewElement();
    callId1.mId = 1;
    SipNgHearderCallId& callId2 = callIdList.NewElement();
    callId2.mId = 2;
    callIdList.Printf();
    SipNgHearderContentType& type1 = contentTypeList.NewElement();
    type1.mType = 11;
    SipNgHearderContentType& type2 = contentTypeList.NewElement();
    type2.mType = 12;
    contentTypeList.Printf();
}

