/*
@ File: Runner.h
@ Authors:
George Fraser
54510750
ghf20@uclive.ac.nz

Lily Williams
42415299
lfw25@uclive.ac.nz
@ Date: 11 October 2021
@ Brief: Defines the runner positions
*/
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

uint8_t runner_doublejump[] = 
{
    0x00, 0x20, 0x20, 0x00, 0x00
};

uint8_t runner_jump[] =
{
    0x00, 0x00, 0x20, 0x20, 0x00
};

uint8_t* runner[] = 
{
    runner_regular, runner_crouch, runner_jump, runner_doublejump
};

#endif