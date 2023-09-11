// #include "pch.h"

#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_RAND_S
#define _H3API_PATCHER_X86_
#define _H3API_NO_VALIDATION_
#define _H3API_LIBRARY_

#pragma warning(disable : 4996)


#include "H3API/single_header/H3API.hpp"



Patcher* _P;
PatcherInstance* _PI;


int __stdcall FirstLoHook(LoHook* h, HookContext* c)
{
    char TextBuffer[] = "WARNING: You are under cheats.\n";
    if (h3::H3Main::Get()->isCheater) {
        FASTCALL_12(void, 0x4F6C00, TextBuffer, 1, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0);
    }
    return EXEC_DEFAULT;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    static bool plugin_On = false;

    if ( DLL_PROCESS_ATTACH == ul_reason_for_call )
    {
        if ( !plugin_On )
        {
            plugin_On = true;
            _P = GetPatcher();
            _PI = _P->CreateInstance((char*)"HD.Plugin.CheatDetector");
            _PI->WriteLoHook(0x4C80F4, FirstLoHook);
        }
    }

    return TRUE;
}
