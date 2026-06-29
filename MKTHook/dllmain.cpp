// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "utils/MemoryMgr.h"
#include "plugin/Settings.h"
#include "bank.h"
#include "mkt/animation.h"
#include "character.h"
#include "generic.h"

void Init()
{
    //AllocConsole();
    //freopen("CONIN$", "r", stdin);
    //freopen("CONOUT$", "w", stdout);
    //freopen("CONOUT$", "w", stderr);


    // skip 16 bit warning
    Memory::VP::Patch<char>(0x4100F8, 0xEB);

    if (SettingsMgr->bSkipIntro)
        Memory::VP::InjectHook(0x41E7B0, 0x41E814, Memory::HookType::Jump);

    Memory::VP::Patch<int>(0x417951 + 1, SettingsMgr->nGraphicsBufferSize);
    Memory::VP::Patch<int>(0x417973 + 1, SettingsMgr->nGraphicsBufferSize);

    Memory::VP::Patch<int>(0x417962 + 1, SettingsMgr->nAudioBufferSize);
    Memory::VP::Patch<int>(0x4179A3 + 1, SettingsMgr->nAudioBufferSize);

    init_bank_hook();

    Memory::VP::InjectHook(0x4738B5, LoadAllFighters_Hook, Memory::HookType::Call);
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Init();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

