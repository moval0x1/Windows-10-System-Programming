// ex_GetNativeSystemInfo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include<stdio.h>

int main()
{
    SYSTEM_INFO si;
    // Double colon emphasize the fact the function is part of the Windows API
    // It also speeds up the compiler function lookup
    ::GetNativeSystemInfo(&si);

    printf("Number of Logical Processors: %d\n", si.dwNumberOfProcessors);
    printf("Page Size                   : %d bytes\n", si.dwPageSize);
    printf("Processor Mask              : 0x%p\n", (PVOID)si.dwActiveProcessorMask);
    printf("Minimum Process Address     : 0x%p\n", si.lpMinimumApplicationAddress);
    printf("Maximum Process Address     : 0x%p\n", si.lpMaximumApplicationAddress);

    return 0;
}
    
