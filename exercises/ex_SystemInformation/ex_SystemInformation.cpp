// ex_SystemInformation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define SECURITY_WIN32						// To use GetComputerObjectName
#include <windows.h>
#include <stdio.h>

#include <security.h>						// To use GetComputerObjectName
#include <secext.h>							// To use GetComputerObjectName

#pragma comment(lib, "Secur32.lib")			// To use GetComputerObjectName

int main()
{
	// GetNativeSystemInfo
	// GetComputerName
	// GetWindowsDirectory
	// QueryPerformanceCounter
	// GetProductInfo
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
	// =========================================================================================
	printf("[+] QueryPerformanceCounter\n");

	LARGE_INTEGER performanceCount;
	BOOL pfReturn = ::QueryPerformanceCounter(&performanceCount);

	if (pfReturn) {
		printf("\tQuery Performance Counter    : %llu\n\n", performanceCount.QuadPart);
	}
	// =========================================================================================
	printf("[+] GetProductInfo\n");

	/*BOOL GetProductInfo(
		[in]  DWORD  dwOSMajorVersion,
		[in]  DWORD  dwOSMinorVersion,
		[in]  DWORD  dwSpMajorVersion,
		[in]  DWORD  dwSpMinorVersion,
		[out] PDWORD pdwReturnedProductType
	);*/

	DWORD  dwOSMajorVersion{ 6 };
	DWORD  dwOSMinorVersion{ 0 };
	DWORD  dwSpMajorVersion{ 0 };
	DWORD  dwSpMinorVersion{ 0 };
	DWORD pdwReturnedProductType{ 0 };

	BOOL gpiReturn = ::GetProductInfo(dwOSMajorVersion, dwOSMinorVersion, dwSpMajorVersion, dwSpMinorVersion, &pdwReturnedProductType);

	if (gpiReturn) {
		printf("\tProduct Info                 : %d\n\n", pdwReturnedProductType);
	}
	// =========================================================================================
	printf("[+] GetComputerObjectName\n");

	WCHAR lpNameBuffer[50];
	ULONG nSize = sizeof(lpNameBuffer);

	// https://learn.microsoft.com/en-us/windows/win32/api/secext/ne-secext-extended_name_format
	BOOLEAN gconResult = ::GetComputerObjectName(NameDisplay, lpNameBuffer, &nSize);
	if (gconResult) {
		printf("\tComputer Object Name         : %d\n\n", lpNameBuffer);
	}
	else {
		printf("\tGetLastErrorCode             : 0x%x\n\n", ::GetLastError());
	}

	return 0;
}
