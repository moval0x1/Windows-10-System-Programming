// ex_KUSER_SHARED_DATA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include<stdio.h>

int main()
{
	auto sharedUserData = (BYTE*)0x7FFE0000;

	printf("Version: %d.%d.%d\n",
		*(ULONG*)(sharedUserData + 0x26c), // major version offset
		*(ULONG*)(sharedUserData + 0x270), // minor version offset
		*(ULONG*)(sharedUserData + 0x260)  // build number offset (windows 10)
	);
}