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
#include "game_initialise.h"
#include "counter.h"

#include <stdbool.h>

//Displays the score
void display_character (uint8_t score)
{   
    uint8toa(score, display_score, false); //Convert score uint8_t to a string
    tinygl_text (display_score);
}

//Displays the score on a game pause and resumed when nav-north is pressed
void pause_display(uint8_t score)
{
    while(navswitch_push_event_p(NAVSWITCH_NORTH) == 0) {

        navswitch_update(); //Poll the navswitch for a resume command

        //Display the score
        tinygl_update ();
        display_character(score);
    }
}

//Displays the score on a gameover
void gameover_display(uint8_t score)
{
    while(1) {
        tinygl_update ();
        display_character(score);
    }
}

void score_increment(uint16_t pacer)
{
    if (counter % pacer == 0) {
        score++;
    } 
}