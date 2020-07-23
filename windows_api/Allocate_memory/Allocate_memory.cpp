#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "user32.lib")

int  main()
{
	int size = 1024 * 1024 * 1024;
	byte* arr = (byte*)VirtualAlloc(NULL, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	for (int i = 0; i < size; i++) { arr[i] = 0; }
	{
		SYSTEM_INFO siSysInfo; // Copy the hardware information to the SYSTEM_INFO structure. 
		GetSystemInfo(&siSysInfo); // Display the contents of the SYSTEM_INFO structure. 
		printf("_________________________________________\n");
		printf("Hardware information: \n");
		printf("_________________________________________\n");
		printf("OEM ID: %u\n", siSysInfo.dwOemId);
		printf("Number of processors: %u\n", siSysInfo.dwNumberOfProcessors);
		printf("Page size: %u\n", siSysInfo.dwPageSize);
		printf("Processor type: %u\n", siSysInfo.dwProcessorType);
		printf("Active processor mask: %u\n", siSysInfo.dwActiveProcessorMask);
		printf("_________________________________________\n");
		printf("Minimum application address: %lx\n", siSysInfo.lpMinimumApplicationAddress);
		printf("Maximum application address: %lx\n", siSysInfo.lpMaximumApplicationAddress);
		printf("_________________________________________\n");
		Sleep(10000);
		system("pause >> NUL");
	}
}
