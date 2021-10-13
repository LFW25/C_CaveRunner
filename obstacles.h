/*
@ File: Obstacles.h
@ Authors:
George Fraser
54510750
ghf20@uclive.ac.nz

Lily Williams
42415299
lfw25@uclive.ac.nz
@ Date: 11 October 2021
@ Brief: Defines the obstacles the runner must dodge
*/

#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <stdint.h>

uint8_t stalagtite[] =
{
    0x03, 0x03, 0x03, 0x03, 0x00   
};

uint8_t bat[] = 
{
    0x00, 0x00, 0x00, 0x03, 0x00
};

uint8_t rock[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x03
};

uint8_t boulder[] =
{
    0x00, 0x00, 0x00, 0x03, 0x03
};

uint8_t tunnel[] =
{
    0x03, 0x03, 0x00, 0x00, 0x03
};

uint8_t* obstacles[] = 
{
    stalagtite, rock, bat, boulder, tunnel
};

#endif