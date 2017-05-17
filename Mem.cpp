#pragma once
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include "Mem.h"

using namespace std;
int varBase = 0;
ProcMem::ProcMem(LPCSTR WindowName){

	HWND hWindow = FindWindowA(NULL, WindowName); //Get the process window by name

	if (hWindow){
		DWORD pID = (DWORD)GetCurrentProcessId;
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pID);
		GetWindowThreadProcessId(hWindow, &Proc_ID); //Gets The Process ID From The Process Window and stores it in the temp address of Proc_ID
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Proc_ID); //Declare hProcess As The HANDLE for the Process And Give It Full Access
		//cout << "\nProcess Running!" << endl;
		HANDLE hModule = INVALID_HANDLE_VALUE; //Declare Function Handle [Must Be Separate Handle]
		MODULEENTRY32 ePoint; //Declare Entry Point Variable
		hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, Proc_ID); //Take a snapshot of all modules in the specified process.
		ePoint.dwSize = sizeof(MODULEENTRY32); //Set the size of the structure before using it.
		Module32First(hModule, &ePoint); //Initialize function to get Process Module Information from (hModule), and store in address of (ePoint)
		base = (DWORD*)ePoint.modBaseAddr; //Copy the Module Base Address to (base - Public Variable)
		if (varBase == 0){
			cout << "Base" << endl;
			varBase = 1;
		}
		CloseHandle(hModule); 
	}
}