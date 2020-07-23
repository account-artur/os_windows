#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

#define BUF_SIZE 256

int _tmain()
{
	HANDLE hMapFile;
	LPCTSTR pBuf;

	CHAR szName[BUF_SIZE];

	printf("Create file mapping object name:\n");

	gets_s(szName, sizeof(szName));

	hMapFile = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,   
		FALSE,                
		szName);              

	if (hMapFile == NULL)
	{

		hMapFile = CreateFileMapping(
			INVALID_HANDLE_VALUE,   
			NULL,                    
			PAGE_READWRITE,          
			0,                      
			BUF_SIZE,                
			szName);                 

		if (hMapFile == NULL)
		{
			_tprintf(TEXT("Could not create file mapping object (%d).\n"),
				GetLastError());
			return 1;
		}
		pBuf = (LPTSTR)MapViewOfFile(hMapFile, 
			FILE_MAP_ALL_ACCESS,
			0,
			0,
			BUF_SIZE);

		if (pBuf == NULL)
		{
			_tprintf(TEXT("Could not map view of file (%d).\n"),
				GetLastError());

			CloseHandle(hMapFile);

			return 1;
		}

		CHAR szMsg[BUF_SIZE];

		printf("Create message:\n");

		gets_s(szMsg, sizeof(szMsg));

		printf("**************DONE**************\n");

		CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));
		_getch();

		system("pause >> NUL");

	}
	else
	{
		pBuf = (LPTSTR)MapViewOfFile(hMapFile,
			FILE_MAP_ALL_ACCESS,
			0,
			0,
			BUF_SIZE);

		if (pBuf == NULL)
		{
			_tprintf(TEXT("Could not map view of file (%d).\n"),
				GetLastError());

			CloseHandle(hMapFile);

			return 1;
		}

		MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);

	}

	UnmapViewOfFile(pBuf);

	CloseHandle(hMapFile);

	return 0;
}
