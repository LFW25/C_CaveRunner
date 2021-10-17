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

int main(void)
{   
    game_initialise_init(PACER_RATE, NUM_OBSTACLES);
    game_initialise_set_display(NUM_ROWS);

    while (1)
    {
        pacer_wait ();
        navswitch_update(); //Poll the navswitch for player input

        score_increment(PACER_RATE); //Increments score every second

        if (!to_copy) {
            for (uint8_t i = 0; i < NUM_COLS; i++) {
                obj_to_display[i] = obstacles[random_number][i];
            }
            to_copy = true;
        } //Copies object to display

        move_object_left(obj_to_display);

        if ((counter % obstacle_refresh) == 0) {
            random_number = rand() % NUM_OBSTACLES;
            to_copy = false;
            obstacle_moving_rate--;
        } //When object is off the screen, display a new object
        
        take_input();

        if (counter % obstacle_check == 0) {
            if (collision_check(runner_status, random_number)) {
                gameover_display(score);
            }
            obstacle_check = counter + obstacle_refresh; 
        } //Checks for a collision between runner and obstacle

        display_column(obj_to_display[current_column] | runner[runner_status][current_column], current_column);
    
        column_increment();
        
        counter_increment();         
    }
}