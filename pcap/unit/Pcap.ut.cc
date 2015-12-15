#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "PCapFile.h"

using namespace std;

int main( int argc, char **argv )
{
    FILE* pFile = fopen(argv[1], "rb");
    if ( pFile == NULL )
    {
        cout << "open " << argv[1] << "error!" << endl;
    }
    
    // obtain file size:
    fseek (pFile , 0 , SEEK_END);
    Uint32 nLen = ftell (pFile);
    rewind (pFile);

    Uint8* pBuffer = (Uint8*)malloc(nLen);
    Uint32 nRet = fread(pBuffer, 1, nLen, pFile);
    if ( nRet != nLen )
    {
        cout << "read " << argv[1] << "error!" << endl;
    }

    PCapFile* pcap = new PCapFile();
    if (!pcap->ParseMemory(pBuffer, nLen))
    {
        cout << pcap->GetErrorMsg() << endl;
    }

    free(pBuffer);

    fclose(pFile);
    return 0;
}

