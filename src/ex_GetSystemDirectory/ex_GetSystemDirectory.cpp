// ex_GetSystemDirectory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include<stdio.h>

int main()
{
    ; WCHAR path[MAX_PATH];
    ::GetSystemDirectory(path, MAX_PATH);

    // %ws indicate it's a UNICODE string
    printf("System Directory: %ws\n", path);

    return 0;
}