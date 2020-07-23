#include <iostream>                  
#include <windows.h>                 
#include <stdio.h>                   
#include <tchar.h>

#define INFO_BUFFER_SIZE 32767
DWORD  bufCharCount = INFO_BUFFER_SIZE;
TCHAR  infoBuf[INFO_BUFFER_SIZE];


int main()
{

	bufCharCount = INFO_BUFFER_SIZE;
	if (!GetComputerName(infoBuf, &bufCharCount))
		_tprintf(TEXT("GetComputerName"));
	_tprintf(TEXT("\nComputer name: %s \n"), infoBuf);

    return 0;
}
