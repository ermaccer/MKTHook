#include "bank.h"
#include "plugin/Settings.h"
#include "utils/MemoryMgr.h"


static AudioBank pBanks[MAX_BANKS] = {};

void init_bank_hook()
{
	int bankNum = SettingsMgr->nBankSlots;

	// num

	Memory::VP::Patch<unsigned char>(0x41B90D + 3, bankNum);
	Memory::VP::Patch<unsigned char>(0x41B956 + 3, bankNum);
	Memory::VP::Patch<unsigned char>(0x41B90D + 3, bankNum);

	// array
	int val = (int)&pBanks[0];
	Memory::VP::Patch<int>(0x41B922 + 3, val);
	Memory::VP::Patch<int>(0x41B96B + 3, val);
	Memory::VP::Patch<int>(0x41B97C + 3, val);
	Memory::VP::Patch<int>(0x41B9E3 + 3, val);
	Memory::VP::Patch<int>(0x41BA5F + 3, val);
	Memory::VP::Patch<int>(0x41BB19 + 3, val);
	Memory::VP::Patch<int>(0x41BC0A + 3, val);
}
