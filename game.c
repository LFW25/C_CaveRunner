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
#include "system.h"
#include "pio.h"
#include "navswitch.h"
#include "objects.h"
#include "pacer.h"
#include "obstacles.h"
#include "runner.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "uint8toa.h"
#include "collision.h"
#include "counter.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define SEED 2000
#define PACER_RATE 500
#define NUM_ROWS 7
#define NUM_COLS 5
#define NUM_OBSTACLES (sizeof(obstacles)/sizeof(obstacles[0]))
#define OBSTACLE_MOVING_RATE 150
#define OBSTACLE_REFRESH (OBSTACLE_MOVING_RATE * NUM_ROWS)
#define TIMEOUT_TIME (OBSTACLE_MOVING_RATE * 4)

//Displays the score on pause or game over
//Maybe move to its own module?
void display_character (uint8_t score)
{
    char display_score[4];
    
    uint8toa(score, &display_score, true); //Convert score uint8_t to a string
    tinygl_text (display_score);
}


int main(void)
{
    uint8_t current_column = 0;
    //uint16_t counter = 1;
    uint8_t score = 0; //Overflow in 4 minutes (Max score = 240) 
    
    srand(SEED); //stdlib function to generate pseudo random numbers for obstacle generation

    int random_number = rand() % NUM_OBSTACLES; //Converts random number to [0, NUM_OBSTACLES-1] 

    system_init ();
    counter_init();
    pacer_init (PACER_RATE); //Refresh rate of 500Hz

    tinygl_init (PACER_RATE); //Setup for score display
    tinygl_font_set (&font5x7_1);
    
    for (uint8_t i = 0; i < NUM_ROWS; i++) {
        if (i < NUM_COLS) {
            pio_config_set(cols[i], PIO_OUTPUT_HIGH);
        }
        pio_config_set(rows[i], PIO_OUTPUT_HIGH);
    }
    bool to_copy = false;
    bool timeout = false;
    static bool pause_flag = 0;

    uint8_t obj_to_display[NUM_COLS]; //IF YOU CHECK OBJECTS.C AND OBJECTS.H ITS PRETTY CLEAR WHY WE NEED THIS
    uint16_t timeout_counter = 0;
    static uint8_t runner_status;
    static uint16_t obstacle_check = OBSTACLE_REFRESH-OBSTACLE_MOVING_RATE;


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

            pause_flag = 1;

            //Save the previous display in case of overwrite
            uint8_t previous_display = {obj_to_display[current_column] | runner[runner_status][current_column], current_column};
            while(pause_flag == 1) {

                //Display pause sign in top left
                display_column(0x50, 0);
                display_column(0x50, 1);
                display_column(0x50, 2);

                navswitch_update(); //Poll the navswitch for a resume command

                //Display the score
                tinygl_update ();
                display_character(score);
                
                if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
                    //Game is resumed, display objects and runner again
                    pause_flag = 0;
                    display_column(obj_to_display[current_column] | runner[runner_status][current_column], current_column);
                }
            }
        } //Pauses the game when pressing nav-left, resume on nav-right
        

        //Determine runner status
        if (timeout == false) {

            if (navswitch_down_p (NAVSWITCH_WEST)) { //Nav-west = Jump
                runner_status = 2;
            } else if (navswitch_down_p (NAVSWITCH_EAST)) { //Nav-east = Crouch
                runner_status = 1;
            } else if (navswitch_down_p (NAVSWITCH_PUSH)) { //Nav-push = Double jump
                runner_status = 3;
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
            if (collision_check(runner_status, random_number)) {
                break;
            }
            obstacle_check = OBSTACLE_REFRESH+OBSTACLE_MOVING_RATE; 
        } //Collision detection. Will break while loop but needs to display soimething instead?

        display_column(obj_to_display[current_column] | runner[runner_status][current_column], current_column);
    
        current_column++;
    
        if (current_column >= (NUM_COLS))
        {
            current_column = 0;
        }
        
        counter_increment();
        /*counter++;

        if (counter == UINT16_MAX) {
            counter = 1;
        }
        */           
    }
}