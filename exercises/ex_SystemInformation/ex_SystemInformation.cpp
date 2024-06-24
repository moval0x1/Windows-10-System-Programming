// ex_SystemInformation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include<stdio.h>

int main()
{
	// GetNativeSystemInfo
	// GetComputerName
	// GetWindowsDirectory
	// QueryPerformanceCounter
	// GetPrductInfo
	// GetComputerObjectName
	// Handl errors if they occur


	// =========================================================================================
	printf("[+] GetNativeSystemInfo\n");
	SYSTEM_INFO si;
	// Double colon emphasize the fact the function is part of the Windows API
	// It also speeds up the compiler function lookup
	::GetNativeSystemInfo(&si);

	printf("\tNumber of Logical Processors : %d\n", si.dwNumberOfProcessors);
	printf("\tPage Size                    : %d bytes\n", si.dwPageSize);
	printf("\tProcessor Mask               : 0x%p\n", (PVOID)si.dwActiveProcessorMask);
	printf("\tMinimum Process Address      : 0x % p\n", si.lpMinimumApplicationAddress);
	printf("\tMaximum Process Address      : 0x%p\n\n", si.lpMaximumApplicationAddress);
	// =========================================================================================
	printf("[+] GetComputerName\n");

	WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1]{};
	DWORD cnSize = sizeof(computerName);
	BOOL cnReturn = ::GetComputerName(computerName, &cnSize);

	if (cnReturn) {
		printf("\tComputer Name                : %ws\n\n", computerName);
	}
	// =========================================================================================
	printf("[+] GetWindowsDirectory\n");

	WCHAR winPath[MAX_COMPUTERNAME_LENGTH + 1];
	int winPathSize = sizeof(winPath);
	int wdReturn = ::GetWindowsDirectory(winPath, winPathSize);

	if (wdReturn) {
		printf("\tWindows Directory            : %ws\n\n", winPath);
	}
	return 0;
}
