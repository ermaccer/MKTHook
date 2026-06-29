#include "Settings.h"
#include "../utils/IniReader.h"
#include <Windows.h>
eSettingsManager* SettingsMgr = new eSettingsManager;

eSettingsManager::eSettingsManager()
{
	CIniReader ini("mkthook.ini");
	//CIniReader user("mk1hook_user.ini");


	bEnableConsoleWindow = ini.ReadBoolean("Settings", "bEnableConsoleWindow", true);
	bSkipIntro = ini.ReadBoolean("Settings", "bSkipIntro", true);

	nGraphicsBufferSize = ini.ReadInteger("Limits", "nGraphicsBufferSize", 0x200000);
	nAudioBufferSize = ini.ReadInteger("Limits", "nAudioBufferSize", 0x480000);
	nBankSlots = ini.ReadInteger("Limits", "nBankSlots", 40);
}
