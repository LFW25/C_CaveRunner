#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <stdint.h>

uint8_t stalagtite[] =
{
    0x01, 0x01, 0x01, 0x01, 0x00   
};

uint8_t bird[] = 
{
    0x00, 0x00, 0x00, 0x03, 0x00
};

uint8_t rock[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x01
};

uint8_t* obstacles[] = 
{
    stalagtite, rock, bird
};

#endif