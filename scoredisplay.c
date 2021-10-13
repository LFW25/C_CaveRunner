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


#include "tinygl.h"
#include "uint8toa.h"
#include "navswitch.h"
#include "scoredisplay.h"

#include <stdbool.h>

//Displays the score on pause or game over
//Maybe move to its own module?
void display_character (uint8_t score)
{
    char display_score[4];
    
    uint8toa(score, display_score, true); //Convert score uint8_t to a string
    tinygl_text (display_score);
}

void pause_display(uint8_t score)
{
    while(navswitch_push_event_p(NAVSWITCH_NORTH) == 0) {

        navswitch_update(); //Poll the navswitch for a resume command

        //Display the score
        tinygl_update ();
        display_character(score);
    }
}

void gameover_display(uint8_t score)
{
    while(1) {
        tinygl_update ();
        display_character(score);
    }
}