// ex_handling_HRESULT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include<stdio.h>

int main()
{
	IGlobalInterfaceTable* pGit;
	HRESULT hr = ::CoCreateInstance(CLSID_StdGlobalInterfaceTable, nullptr, CLSCTX_ALL, IID_IGlobalInterfaceTable, (void**)&pGit);
	
	if (FAILED(hr)){
		printf("Error: %08X\n", hr);
	}
	else {
		// do work;
		pGit->Release(); // release interface pointer
	}
}