// ex_GetVersionEx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// To remove the warning about GetVersionEx be deprecated
#define BUILD_WINDOWS
#include <windows.h>
#include<stdio.h>

int main()
{
	OSVERSIONINFO vi = { sizeof(vi) };
	::GetVersionEx(&vi);


	printf("Version: %d.%d.%d\n", vi.dwMajorVersion, vi.dwMinorVersion, vi.dwBuildNumber);
}