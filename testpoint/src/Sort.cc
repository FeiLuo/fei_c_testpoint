#include "Sort.h"

Sort::Sort(void)
{
}

Sort::~Sort(void)
{
}

void Sort::Action()
{
    Int32 orderData[] = { 10, 20, 30, 40, 50, 60 };
    Int32 nOrder = sizeof(orderData)/sizeof(Int32);
    PrintArray(orderData, nOrder);
    
    Int32 searchData = 30;
    Int32 nRet = HalfSearch(orderData, nOrder, searchData);
    printf("search %d at %d\r\n", searchData, nRet + 1);
    
    searchData = 20;
    nRet = HalfSearch(orderData, nOrder, searchData);
    printf("search %d at %d\r\n", searchData, nRet + 1);
    
    Int32 Data[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
    Int32 nData = sizeof(Data)/sizeof(Int32);
    InsertSort(Data, nData);
    SelectionSort(Data, nData);
    BubbleSort(Data, nData);
    QuickSort(Data, nData);
//    HeapSort(Data, nData);
    
}

void Sort::PrintArray(Int32* data, Int32 n)
{
    for (Int32 i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\r\n");
}

Int32 Sort::HalfSearch(Int32* data, Int32 n, Int32 value)
{
    printf("\r\nHalf Search.....\r\n");
    Int32 mid, high, low;
    
    low = 0;
    high = n - 1;
    
    while (low <= high)
    {
        mid = (low + high) / 2;
        
        if (value == data[mid])
            return mid;
        if (value < data[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return -1;
}


void Sort::InsertSort(Int32* Data, Int32 n)
{
    printf("\r\nInsert Sort.....\r\n");
    Int32* K = new Int32 [n];
    memcpy(K, Data, n * sizeof(Int32));
    PrintArray(K, n);
    
    Int32 i, j;
    Int32 temp, mid, high, low;
    for (i = 1; i <= n-1; i++)
    {
        temp = K[i];
        
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (temp < K[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        for (j = i-1; j >= low; j--)
        {
            K[j+1] = K[j];
        }
        
        K[low] = temp;
        
        PrintArray(K, n);
    }
    
    delete [] K;
}

void Sort::SelectionSort(Int32* data, Int32 n)
{
    printf("\r\nSelection Sort.....\r\n");
    Int32* K = new Int32 [n];
    memcpy(K, data, n * sizeof(Int32));
    PrintArray(K, n);
    
    Int32 i, j, d, temp;
    
    for (i = 0; i < n; i++)
    {
        d = i;
        for (j = i + 1; j < n; j++)
        {
            if ( K[j] < K[d])
            {
                d = j;
            }
        }
        
        temp = K[d];
        K[d] = K[i];
        K[i] = temp;
        
        PrintArray(K, n);
    }
    
    delete [] K;
}

void Sort::BubbleSort(Int32* data, Int32 n)
{
    printf("\r\nBubble Sort.....\r\n");
    Int32* K = new Int32 [n];
    memcpy(K, data, n * sizeof(Int32));
    PrintArray(K, n);
    
    Int32 i, j, flag=1, temp;
    
    i = n -1;
    while ((flag == 1) && (i > 0))
    {
        flag = 0;
        
        for (j=1; j<=i; j++)
        {
            if (K[j-1] > K[j])
            {
                temp = K[j-1];
                K[j-1] = K[j];
                K[j] = temp;
                
                flag = 1;
            }
        }
        
        PrintArray(K, n);
        i--;
    }
    
    delete [] K;
}

void Sort::Quick(Int32* data, Int32 start, Int32 end)
{
    int i,j, temp;
    if (start < end)
    {
        i = start;
        j = end + 1;
        while(1)
        {
            do 
            {
                i++;
            } while (!(data[start] <= data[i] || i==end));
            
            do 
            {
                j--;
            } while (!(data[start] >= data[j] || j == end));
            
            if (i < j)
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
            else
            {
                break;
            }
        }
        
        temp = data[end];
        data[end] = data[j];
        data[j] = temp;
        
        Quick(data, start, j-1);
        Quick(data, j+1, end);
    }
}

void Sort::QuickSort(Int32* data, Int32 n)
{
    printf("\r\nHeap Sort.....\r\n");
    Int32* K = new Int32 [n];
    memcpy(K, data, n * sizeof(Int32));
    PrintArray(K, n);
    
    Quick(K, 0, n-1);
    
    delete [] K;
}


void Sort::HeapAdjust(Int32* data, Int32 i, Int32 n)
{
    Int32 j, temp;
    
    temp = data[i];
    j = 2 * i + 1;
    while (j<=n)
    {
        if (j<n && data[j]<data[j+1])
            j++;
        
        if (temp >= data[j])
            break;
        
        data[(j-1)/2] = data[j];
        j=2*j;
    }
    data[(j-1)/2] = temp;
}

void Sort::HeapSort(Int32* data, Int32 n)
{
    printf("\r\nHeap Sort.....\r\n");
    Int32* K = new Int32 [n];
    memcpy(K, data, n * sizeof(Int32));
    PrintArray(K, n);
    
    Int32 i, temp;
    for (i=(n-1)/2; i>=0; i--)
    {
        HeapAdjust(K, i, n-1);
        PrintArray(K, n);
    }
    for (i=n-2; i>1; i--)
    {
        temp = K[i+1];
        K[i+1] = K[1];
        K[1] = temp;
        HeapAdjust(K, 1, i);
    }
    delete [] K;
}
