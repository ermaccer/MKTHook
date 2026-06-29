#include "fixes.h"

void ForceLoadEnduranceCharacters()
{
    short* map_start = *(short**)0x55455C;

    if (map_start)
    {
        short  map_position = *(short*)0x554560;
        int    entry = map_start[map_position];

        // asset links from the big string list
        short* id_table = (short*)0x53F31C;
        // asset queue
        short* fighter_ids = (short*)0x55EA50;

        // is endurance
        if (entry & 0x80)
        {
            int slot = entry & 0x7F;
            int endurance_addr = 0x56982E;
            short* endurance_entry = *(short**)(endurance_addr + slot * 4);

            // instead of sending character id to asset queue, first get asset id from current characters
            // and make sure they will be loaded
            for (int i = 0; endurance_entry[i] != -1; i++)
            {
                short assetSlot = id_table[endurance_entry[i]];
                bool inList = false;

                for (int a = 0; a < 4; a++)
                {
                    if (fighter_ids[a] == assetSlot)
                        inList = true;
                }

                if (inList)
                    continue;

                for (int a = 0; a < 4; a++)
                {
                    if (fighter_ids[a] == -1)
                    {
                        fighter_ids[a] = assetSlot;
                        break;
                    }
                }
            }
        }
    }


}
