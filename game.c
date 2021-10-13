/*
@ File: Game.c
@ Authors:
George Fraser
54510750
ghf20@uclive.ac.nz

Lily Williams
42415299
lfw25@uclive.ac.nz
@ Date: 11 October 2021
@ Brief: Combines and initialises game files
*/

#include "uint8toa.h"
#include "navswitch.h"
#include "objects.h"
#include "pacer.h"
#include "obstacles.h"
#include "runner.h"
#include "collision.h"
#include "counter.h"
#include "scoredisplay.h"
#include "game_initialise.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define PACER_RATE 500
#define NUM_ROWS 7
#define NUM_COLS 5
#define NUM_OBSTACLES (sizeof(obstacles)/sizeof(obstacles[0]))
#define OBSTACLE_MOVING_RATE 150
#define OBSTACLE_REFRESH (OBSTACLE_MOVING_RATE * NUM_ROWS)
#define TIMEOUT_TIME (OBSTACLE_MOVING_RATE * 4)

int main(void)
{   
    game_initialise_init(PACER_RATE, NUM_OBSTACLES);
    game_initialise_set_display(NUM_ROWS);
    
    static uint8_t runner_status;
    static uint16_t obstacle_check = OBSTACLE_REFRESH-(2*OBSTACLE_MOVING_RATE);


    while (1)
    {
        pacer_wait ();
        navswitch_update(); //Poll the navswitch for player input

        if (counter % PACER_RATE == 0) {
            score++;
        } //Increments score every second

        if (to_copy == false) {
            for (uint8_t i = 0; i < NUM_COLS; i++) {
                obj_to_display[i] = obstacles[random_number][i];
            }
            to_copy = true;
        } //Copies object to display

        
        if ((counter % OBSTACLE_MOVING_RATE) == 0) {
            move_object_left(obj_to_display);
        } //Moves the object left

        if ((counter % OBSTACLE_REFRESH) == 0) {
            random_number = rand() % NUM_OBSTACLES;
            to_copy = false;
        } //When object is off the screen, display a new object


        if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {

            pause_display(score);

        } //Pauses the game when pressing nav-left, will resume on nav-right
        

        //Determine runner status
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
            if (timeout_counter >= TIMEOUT_TIME) {
                timeout = false;
                timeout_counter = 0;
            } else {
                timeout_counter++;
            }
        }

        if (counter % obstacle_check == 0) {
            if (collision_check(runner_status, random_number) == true) {
                gameover_display(score);
            }
            obstacle_check = counter + OBSTACLE_REFRESH; 
        }

        display_column(obj_to_display[current_column] | runner[runner_status][current_column], current_column);
    
        current_column++;
    
        if (current_column >= (NUM_COLS))
        {
            current_column = 0;
        }
        
        counter_increment();         
    }
}