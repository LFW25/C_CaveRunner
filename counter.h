/*
@ FILE: COUNTER.H
@ AUTHORS:
GEORGE FRASER
54510750
GHF20@UCLIVE.AC.NZ

LILY WILLIAMS
42415299
LFW25@UCLIVE.AC.NZ
@ DATE: 12 OCTOBER 2021
@ BRIEF: Initialises a loop counter for the game
*/

#ifndef COUNTER_H
#define COUNTER_H

#include <stdint.h>

uint16_t counter;

//Initialises the counter at the beginning of the game
void counter_init(void);

//Adds one to the counter and calls counter_check_max
void counter_increment(void);

//Avoids uint16 overflow
void counter_check_max(void);

#endif //COUNTER_H