// ex_KUSER_SHARED_DATA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include<stdio.h>

int main()
{
	// https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntddk/ns-ntddk-kuser_shared_data
	// KUSER_SHARED_DATA is mapped to every process
	// to the same virtual address [0x7FFE0000]
	//
	// https://www.geoffchappell.com/studies/windows/km/ntoskrnl/inc/api/ntexapi_x/kuser_shared_data/index.htm
	// The read-only user-mode address for the shared data is 0x7FFE0000, both in 32-bit and 64-bit Windows.
	auto sharedUserData = (BYTE*)0x7FFE0000;

	printf("Version: %d.%d.%d\n",
		*(ULONG*)(sharedUserData + 0x26c), // major version offset
		*(ULONG*)(sharedUserData + 0x270), // minor version offset
		*(ULONG*)(sharedUserData + 0x260)  // build number offset (windows 10)
	);
}