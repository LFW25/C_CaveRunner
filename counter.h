/*
@ File: Counter.h
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