/*
@ File: Counter.c
@ Authors:
George Fraser
54510750
ghf20@uclive.ac.nz

Lily Williams
42415299
lfw25@uclive.ac.nz
@ Date: 12 October 2021
@ Brief: Keeps track of the loop count in the game
*/

#include "counter.h"

#include <stdint.h>

//Initialises the counter at the beginning of the game
void counter_init(void)
{
    counter = 1;
}

//Avoids uint16_t overflow
void counter_check_max(void)
{
    if (counter == UINT16_MAX) {
        counter = 0;
    }
}

//Adds one to the counter and calls counter_check_max
void counter_increment(void)
{
    counter_check_max();
    counter++;  
}

