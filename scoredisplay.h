/*
@ File: Scoredisplay.c
@ Authors:
George Fraser
54510750
ghf20@uclive.ac.nz

Lily Williams
42415299
lfw25@uclive.ac.nz
@ Date: 12 October 2021
@ Brief: Displays the score on the pause and game-over screens
*/
#ifndef SCOREDISPLAY_H
#define SCOREDISPLAY_H

#include "system.h"
#include "tinygl.h"
#include "../../fonts/font5x7_1.h"
#include "uint8toa.h"

//Displays the score on pause or game over
//Maybe move to its own module?
void display_character (uint8_t score);

#endif