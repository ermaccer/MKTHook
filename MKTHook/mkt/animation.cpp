#include "animation.h"
#include <string>


const char* szInternalNames[] = {
    "f",
    "stop",
    "jump",
    "mirror",
    "add_x",
    "add_xy",
    "instant",
    "function",
    "sound",
    "my_function",
    "flip",
    "offset_xy",
    "my_sound",
};

void dump_animation(int id, int ptr)
{
    int* p = (int*)ptr;

    int srcPtr = ptr;

    printf("\n\n\n# Animation ID: %d\n", id);
    printf("[ANIM_%X]\n", ptr);
	while (true)
	{
        unsigned int raw = (unsigned int)*p++;

        if ((raw >> 24) == COMMAND_FRAME)
        {
            int data = raw & 0xFFFFFF;
            printf("f(%d)\n", (data - 4) / 12);
            continue;
        }

        int cmd = raw;
        int arg;
        short x;
        short y;

        switch (cmd)
        {
        case COMMAND_STOP:
            printf("stop()\n");
            return;
        case COMMAND_JMP:
            printf("jump(ANIM_%X)\n", *p++);
            return;
        case COMMAND_MIRROR:
            printf("mirror()\n");
            break;
        case COMMAND_ADD_X:
            printf("add_x(%d)\n", *p++);
            break;
        case COMMAND_ADD_XY:
            arg = *p++;
            x = (short)(arg & 0xFFFF);
            y = (short)((arg >> 16) & 0xFFFF);
            printf("add_xy(%d, %d)\n", x, y);
            break;
        case COMMAND_INST:
            printf("instant()\n");
            break;
        case COMMAND_FUNC:
            printf("function(0x%X)\n", *p++);
            break;
        case COMMAND_SOUND:
            printf("sound(%d)\n", *p++);
            break;
        case COMMAND_MY_FUNC:
            printf("my_function(0x%X)\n", *p++);
            break;
        case COMMAND_FLIP:
            printf("flip()\n");
            break;
        case COMMAND_10:
            arg = *p++;
            x = (short)(arg & 0xFFFF);
            y = (short)((arg >> 16) & 0xFFFF);
            printf("offset_xy(%d, %d)\n", x, y);
            break;
        case COMMAND_MY_SND:
            printf("my_sound(%d)\n", *p++);
            break;
        default:
            printf("unknown_0x%X()\n", cmd);
            return;
        }
	}


}
