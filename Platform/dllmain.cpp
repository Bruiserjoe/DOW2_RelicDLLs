// dllmain.cpp : Defines the entry point for the DLL application.
#include "Platform.hpp"

HWND hwndGlobal = nullptr;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
    if (dwReason == 1) {
        DisableThreadLibraryCalls(hModule);
    }
    return TRUE;
}

