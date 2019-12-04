#include <stdio.h>
#include <Windows.h>
#include <vector>

using namespace std;

#define N 4

vector<float> S;

vector<float> R;

CRITICAL_SECTION cs;

DWORD WINAPI firstThread(LPVOID arg)
{
	EnterCriticalSection(&cs);

	printf("\n I am first thread\n");

	int i = 0;

	while (i < 500)
	{
		S.push_back(i++);

	}

	LeaveCriticalSection(&cs);

	return NULL;
}

DWORD WINAPI secondThread(LPVOID arg)
{
	EnterCriticalSection(&cs);

	printf("\n I am second thread\n");

	if (!S.empty())
	{
		int currentNumber = S.back();

		S.pop_back();

		R.push_back(pow(currentNumber, 2));
	}
	else
	{
		Sleep(1000);
	}

	LeaveCriticalSection(&cs);

	return NULL;
}


DWORD WINAPI thirdThread(LPVOID arg)
{
	EnterCriticalSection(&cs);

	printf("\n I am third thread\n");

	if (!S.empty())
	{
		float currentNumber = S.back();

		S.pop_back();

		R.push_back(currentNumber / 3);
	}
	else
	{
		Sleep(1000);
	}

	LeaveCriticalSection(&cs);

	return NULL;
}

DWORD WINAPI fourthThread(LPVOID arg)
{
	EnterCriticalSection(&cs);

	printf("\n I am fourth thread\n");

	DWORD id = (DWORD)arg;

	if (!R.empty())
	{

		printf("\nnumber is %3f \n", R.back());

		R.pop_back();
	}
	else
	{

		printf("\nR is empty\n");

		Sleep(1000);
	}

	LeaveCriticalSection(&cs);

	return NULL;
}

int main()
{
	InitializeCriticalSection(&cs);

	DWORD id[N];

	int i = 0;

	HANDLE threads[N];

	EnterCriticalSection(&cs);

	threads[0] = CreateThread(NULL, NULL, firstThread, &i, NULL, &id[i]);

	threads[1] = CreateThread(NULL, NULL, secondThread, &i, NULL, &id[++i]);

	threads[2] = CreateThread(NULL, NULL, thirdThread, &i, NULL, &id[++i]);

	threads[3] = CreateThread(NULL, NULL, fourthThread, &i, NULL, &id[++i]);

	LeaveCriticalSection(&cs);

	WaitForMultipleObjects(N, threads, true, NULL);

	for (int i = 0; i < N; i++)
	{
		CloseHandle(threads[i]);
	}

	Sleep(5000);

	return 0;
}