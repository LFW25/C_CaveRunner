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
#include "pacer.h"
#include "uint8toa.h"
#include "navswitch.h"
#include "scoredisplay.h"
#include "game_initialise.h"
#include "counter.h"

#include <stdbool.h>

//Displays the score using tiny_gl
void display_character (uint8_t score)
{   
    uint8toa(score, display_score, false); //Convert score uint8_t to a string
    tinygl_text (display_score);
}

//Controls score display on a game pause
//Resumes game when nav-north is pressed
void pause_display(uint8_t score)
{
    while(navswitch_push_event_p(NAVSWITCH_NORTH) == 0) {

        navswitch_update(); //Poll the navswitch for a resume command

        //Display the score
        tinygl_update ();
        display_character(score);
    }
    tinygl_clear();
}

//Flashes the score on a gameover
void gameover_display(uint8_t score)
{
    uint32_t task_counter = 1;
    while(1) {
        while(1) {
            pacer_wait();
            tinygl_update ();
            display_character(score);
            task_counter++;
            if (task_counter % 300 == 0) {
                break;
            }
        }
        
        while(1) {
            pacer_wait();
            tinygl_update();
            tinygl_clear();
            task_counter++;
            if (task_counter % 300 == 0) {
                break;
            }
        }
        
    }
    
}

//Increments the score every second
void score_increment(uint16_t pacer)
{
    if (counter % pacer == 0) {
        score++;
    } 
}