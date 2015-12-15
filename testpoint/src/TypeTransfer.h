#pragma once

// static_cast:转换，避免警告 
// const_cast: 强制转换const或volatile
// dynamic_cast: 类型安全的向下转换
// reinterpret_cast: 重解释转换，最不安全的转换

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
