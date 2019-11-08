#include <iostream>                  
#include <windows.h>                 
#include <stdio.h>                   
#include <tchar.h>

using namespace std;
int main()
{   
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int n;
  double ResFree = 0, ResAll = 0;
  stringstream ss;
  ULARGE_INTEGER free, all;
  char ar[5];
  
  DWORD dr = GetLogicalDrives();
  for (int x = 0; x < 26; x++)
  {
    n = ((dr >> x) & 1);
    if (n)
    {
        ss << (char)(65 + x) << ":" << ' ';
        all.QuadPart = 0;
        free.QuadPart = 0;
        ss >> ar;
        GetDiskFreeSpaceEx(ar, &free, NULL, NULL);
        ResFree += ((double)free.QuadPart / (1024 * 1024 * 1024));
        ResAll += ((double)all.QuadPart / (1024 * 1024 * 1024));
    }
  }
   printf("Free space: %.2f GB.",ResFree, ResAll - ResFree, ResAll);
   return 0;
}
