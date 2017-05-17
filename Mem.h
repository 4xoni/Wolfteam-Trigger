#pragma once
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#define PROCMEM_H //Define Now

#define WIN32_LEAN_AND_MEAN //Excludes Headers We Wont Use (Increase Compile Time)

#include <windows.h> //Standard Windows Functions/Data Types
#include <iostream> //Constains Input/Output Functions (cin/cout etc..)
#include <TlHelp32.h> //Contains Read/Write Functions
#include <string> //Support For Strings
#include <sstream> //Supports Data Conversion

class ProcMem{

private:
	HANDLE hProcess; //Handle for this class
	DWORD Proc_ID; //Varible to store Process ID

public:

	DWORD *base; //Stores Module Base Address

	ProcMem(LPCSTR WindowName); //Constructor - Finds Process Via Window Name

	//READ MEMORY
	template <class cData>

	cData read(DWORD(Address)){
		int a;
		try{
			if (Proc_ID > 0){
				cData B;// Generic Varible to store Address+Value
				ReadProcessMemory(hProcess, (LPVOID)(Address), &B, sizeof(B), NULL);
				return B;
			}
			else{
				throw 1; //Throw Error Number / Defined In Catch
			}
		} //Try End
		catch (int error){
			if (a = !1){
				cout << "Trying 2find.." << endl;
				a = 1;
			}
		} // Catch End

		return 0;
	} //Read End

	//WRITE MEMORY
	template <class cData>

	cData write(DWORD(Address), cData B){
		int a = 0;
		try{
			if (Proc_ID > 0){
				WriteProcessMemory(hProcess, (LPVOID)(Address), &B, sizeof(B), NULL);
				return B;
			}
			else{
				throw 1; //Throw Error Number / Defined In Catch
			}
		} // Try End
		catch (int error){
			// cout << "No Memory Found, ERROR: " << error << endl;
			if (a == 0){
				cout << "Trying 2find s4 window.." << endl;
				a = 1;
			}
		} //Catch End

		return 0;
	} //Write End

};