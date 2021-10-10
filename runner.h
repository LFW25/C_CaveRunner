#ifndef RUNNER_H
#define RUNNER_H

#include <stdint.h>

uint8_t runner_regular[] = 
{
    0x00, 0x00, 0x00, 0x20, 0x20
};

uint8_t runner_crouch[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x20
};

uint8_t runner_jump[] = 
{
    0x00, 0x20, 0x20, 0x00, 0x00
};

uint8_t* runner[] = 
{
    runner_regular, runner_crouch, runner_jump
};

#endif