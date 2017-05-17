#pragma once
#include "Mem.h"
#include <vector>
#include <stdint.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <float.h>
#include <cstdio>
#include <winsock.h>
#include <windows.h>
#include <fcntl.h>
#include <stdlib.h>
#include <io.h>

using namespace std;

DWORD pID = (DWORD)GetCurrentProcessId;
HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, false, pID);

LPCSTR CsHell = "Cshell.dll";
DWORD dwCSH = (DWORD)GetModuleHandleA(CsHell);

LPCSTR WolfTeamBin = "Wolfteam.bin";
DWORD dwWBin = (DWORD)GetModuleHandleA(WolfTeamBin);

DWORD GetPointer(std::vector<DWORD>Pointer, uint8_t MODE)
{
		// Use ur way to get pointer ;)
}

static void EditMemory(void *adr, void *ptr, int size)
{
	DWORD OldProtection;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy(adr, ptr, size);
	VirtualProtect(adr, size, OldProtection, &OldProtection);
}

DWORD Crosshair_, WindowShxt;

void WINAPI MainThread()
{
	AllocConsole();
	
	SetConsoleTitleA("con_Nect..Log");
	Sleep(100);
	while (1){
		ProcMem mem("WolfTeam");
		cout << "lmao?!" << endl;
		Crosshair_ = dwCSH + 0x68BBC4;  
		WindowShxt = dwWBin + 0x266A6C; 	//For avoid wrong clicks
		int PtrTriggerAddy = mem.read<int>((DWORD)Crosshair_);
			if (PtrTriggerAddy > 0){
				 // You can find the attack function in game, but i used this one
				Sleep(30);
				mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
				Sleep(30);
				mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
				Sleep(60);	
				// you may change the sleep delay?
			}
		}
	}

int hCrt, i;
FILE *hf;
HANDLE hConsole;
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:

		if (CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, NULL, 0, NULL) == NULL) {
			return FALSE;
		}
		break;

	case DLL_PROCESS_DETACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}
