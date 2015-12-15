#pragma once

// static_cast:ת�������⾯�� 
// const_cast: ǿ��ת��const��volatile
// dynamic_cast: ���Ͱ�ȫ������ת��
// reinterpret_cast: �ؽ���ת�������ȫ��ת��

#include "ActionBase.h"

class TypeTransfer : public ActionBase
{
public:
    TypeTransfer(void);
    ~TypeTransfer(void);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "TypeTransfer"; }
};
