#pragma once
// references char anyway
#define MAX_BANKS 255

struct AudioBank {
	short slot;
};


void init_bank_hook();