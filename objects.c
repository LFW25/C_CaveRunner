/*
@ File: Objects.c
@ Authors:
George Fraser
54510750
ghf20@uclive.ac.nz

Lily Williams
42415299
lfw25@uclive.ac.nz
@ Date: 11 October 2021
@ Brief: Displays the obstacles and runner on the screen
*/
#include "system.h"
#include "pio.h"
#include "objects.h"
#include "game_initialise.h"
#include "navswitch.h"
#include "scoredisplay.h"
#include "counter.h"

#define NUM_ROWS 7
#define NUM_COLS 5

//This function displays the bitmap on the current column
void display_column(uint8_t row_pattern, uint8_t current_column)
{
    pio_output_high(cols[previous]);
    
    previous = current_column;
    

    for (uint8_t i = 0; i < NUM_ROWS; i++) {
        if ((row_pattern >> i) & 1) {
            pio_output_low(rows[i]);
        } else {
            pio_output_high(rows[i]);
        }
    }
    pio_output_low(cols[current_column]);
}

//This function left-shifts the obstacle bitmap
void move_object_left(uint8_t* obstacle)
{
    if ((counter % obstacle_moving_rate) == 0) {
        for (uint8_t i = 0; i < NUM_COLS; i++) {
            obstacle[i] = obstacle[i] << 1;
        }
    }
}

//Takes input from the navswitch
void take_input(void)
{
    if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {

            pause_display(score);

    }

    if (timeout == false) {

        if (navswitch_down_p (NAVSWITCH_WEST)) { //Nav-west = Jump
            runner_status = 2;
            timeout = true;
        } else if (navswitch_down_p (NAVSWITCH_EAST)) { //Nav-east = Crouch
            runner_status = 1;
            timeout = true;
        } else if (navswitch_down_p (NAVSWITCH_PUSH)) { //Nav-push = Double jump
            runner_status = 3;
            timeout = true;
        } else { //Default
            runner_status = 0;
        }
    } else {
        if (timeout_counter >= timeout_time) {
            timeout = false;
            timeout_counter = 0;
        } else {
            timeout_counter++;
        }
    }
}

//Moves the marker denoting the current column left by one
//Checks if the obstacle has moved off-screen
void column_increment(void)
{
    current_column++;
    
    if (current_column >= (NUM_COLS))
    {
        current_column = 0;
    }
}