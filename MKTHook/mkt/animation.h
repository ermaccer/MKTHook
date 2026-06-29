#pragma once

// frame encoding:
// (id * 12) + 4
#define COMMAND_FRAME	0x93
#define COMMAND_STOP	0x00
#define COMMAND_JMP		0x01
#define COMMAND_MIRROR	0x02
#define COMMAND_ADD_X	0x03
#define COMMAND_ADD_XY	0x04
#define COMMAND_INST	0x05
#define COMMAND_FUNC	0x06
#define COMMAND_SOUND	0x07
#define COMMAND_MY_FUNC	0x08
#define COMMAND_FLIP	0x09
#define COMMAND_10		0x0A
#define COMMAND_MY_SND	0x0F


void dump_animation(int id, int ptr);

/*

    for (int i = 0; i < 80; i++)
    {

        dump_animation(i, *(int*)(0x04F5658 + (i * sizeof(int))));
    }


*/