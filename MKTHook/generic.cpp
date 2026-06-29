#include "generic.h"
#include "fixes.h"

#include "plugin/Settings.h"


void LoadAllFighters_Hook()
{
	if (SettingsMgr->bForceCharacterLoadingForEndurance)
		ForceLoadEnduranceCharacters();

	((void(__cdecl*)())0x41C5AF)();
}
