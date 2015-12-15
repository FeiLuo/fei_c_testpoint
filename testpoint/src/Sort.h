#pragma once
#include "ActionBase.h"

class Sort : public ActionBase
{
public:
    Sort(void);
    ~Sort(void);

    void InsertSort(Int32* data, Int32 n);
    void SelectionSort(Int32* data, Int32 n);
    void BubbleSort(Int32* data, Int32 n);

    void Quick(Int32* data, Int32 n, Int32 t);
    void QuickSort(Int32* data, Int32 n);

    void HeapAdjust(Int32* data, Int32 i, Int32 n);
    void HeapSort(Int32* data, Int32 n);

    void PrintArray(Int32* data, Int32 n);

    Int32 HalfSearch(Int32* data, Int32 n, Int32 value);

public:
    virtual void Action();
    virtual const char* GetClassName() { return "Sort"; }

};
