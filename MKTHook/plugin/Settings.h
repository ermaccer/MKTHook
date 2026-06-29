#pragma once
#include <Windows.h>

struct eMouseSettings {
	int sens;
	bool invert_y;
	bool invert_x;
};

class eSettingsManager {
public:
	eSettingsManager();

	bool bEnableConsoleWindow;
	bool bSkipIntro;
	
	int  nGraphicsBufferSize;
	int  nAudioBufferSize;
	int  nBankSlots;

};

extern eSettingsManager* SettingsMgr;