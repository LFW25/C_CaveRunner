/*
@ FILE: COUNTER.C
@ AUTHORS:
GEORGE FRASER
54510750
GHF20@UCLIVE.AC.NZ

LILY WILLIAMS
42415299
LFW25@UCLIVE.AC.NZ
@ DATE: 12 OCTOBER 2021
@ BRIEF: Keeps track of the loop count in the game
*/

#include "counter.h"

#include <stdint.h>

//Initialises the counter at the beginning of the game
void counter_init(void)
{
    counter = 1;
}

//Avoids uint16 overflow
static void counter_check_max(void)
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

