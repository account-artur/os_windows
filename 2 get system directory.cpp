#include <iostream>                  
#include <windows.h>                 
#include <stdio.h>                   
#include <tchar.h>		     

#define INFO_BUFFER_SIZE 32767
DWORD  bufCharCount = INFO_BUFFER_SIZE;
TCHAR  infoBuf[INFO_BUFFER_SIZE];

int main()
{

	if (!GetSystemDirectory(infoBuf, INFO_BUFFER_SIZE))
		_tprintf(TEXT("GetSystemDirectory"));
	_tprintf(TEXT("\nSystem Directory: %s \n"), infoBuf);

    return 0;
}
