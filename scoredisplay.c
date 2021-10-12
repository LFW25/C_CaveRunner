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

#include "system.h"
#include "tinygl.h"
#include "../../fonts/font5x7_1.h"
#include "uint8toa.h"

#include <stdbool.h>

//Displays the score on pause or game over
//Maybe move to its own module?
void display_character (uint8_t score)
{
    char display_score[4];
    
    uint8toa(score, &display_score, true); //Convert score uint8_t to a string
    tinygl_text (display_score);
}