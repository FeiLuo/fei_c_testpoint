#include "Prim.h"


Prim::Prim(void)
{
}

Prim::~Prim(void)
{
}

void Prim::Action()
{
    Uint32 GE[6][6] = {
        { UINT32_MAX, 16, 20, 19, UINT32_MAX, UINT32_MAX },
        { 16, UINT32_MAX, 11, UINT32_MAX, 6, 5 },
        { 20, 11, UINT32_MAX, 22, 14, UINT32_MAX },
        { 19, UINT32_MAX, 22, UINT32_MAX, 18, UINT32_MAX},
        { UINT32_MAX, 6, 14, 18, UINT32_MAX, 9 },
        { UINT32_MAX, 5, UINT32_MAX, UINT32_MAX, 9, UINT32_MAX}
    };
    
    minSpant_Prim(GE[0], 6);
}

void Prim::minSpant_Prim(Uint32* GEValue, Uint32 n)
{
    Uint32* lowcost = new Uint32 [n];
    Uint32* teend = new Uint32 [n];
    Uint32 i, j, k, mincost;
    
    Uint32** GE = new Uint32* [n];
    for (i = 0; i < n; i++)
    {
        GE[i] = new Uint32 [n];
        memcpy(GE[i], &GEValue[i*n], n*sizeof(Uint32));
    }
    
    lowcost[0] = 0;
    teend[0] = 0;
    for (j = 1; j < n; j++)
    {
        teend[j] = 0;
        lowcost[j] = GE[0][j];
    }
    
    for (i = 1; i < n; i++)
    {
        mincost = UINT32_MAX;
        j = 1;
        while (j < n)
        {
            if ((lowcost > 0) && (mincost > lowcost[j]))
            {
                mincost = lowcost[j];
                k = j;
            }
            j++;
        }
        
        printf("(%d, %d)\r\n", teend[k], k);
        lowcost[k] = 0;
        for (j = 0; j < n; j++)
        {
            if (GE[k][j] < lowcost[j])
            {
                lowcost[j] = GE[k][j];
                teend[j] = k;
            }
        }
    }
    
    printf("\r\n");
    
}