#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");

int _tmain()
{
	HANDLE hMapFile;

	LPCTSTR pBuf;

	CHAR szName[BUF_SIZE];

	printf("Input created file mapping object name:\n");

	gets_s(szName, sizeof(szName));

	hMapFile = OpenFileMapping(
		FILE_MAP_ALL_ACCESS,   
		FALSE,                
		szName);             

	if (hMapFile == NULL)
	{
		_tprintf(TEXT("Could not open file mapping object (%d).\n"),
			GetLastError());

		system("pause");

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

	printf("Message:\n");

	printf("%s\n", pBuf);

	printf("**************DONE**************\n");

	UnmapViewOfFile(pBuf);

	CloseHandle(hMapFile);

	system("pause >> NUL");

	return 0;
}