/*
@ FILE: GAME.C
@ AUTHORS:
GEORGE FRASER
54510750
GHF20@UCLIVE.AC.NZ

LILY WILLIAMS
42415299
LFW25@UCLIVE.AC.NZ
@ DATE: 11 OCTOBER 2021
@ BRIEF: COMBINES AND INITIALISES THE GAME FILES
*/
#include "system.h"
#include "pio.h"
#include "navswitch.h"
#include "objects.h"
#include "pacer.h"
#include "obstacles.h"
#include "runner.h"

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


int main(void)
{
    uint8_t current_column = 0;
    uint16_t counter = 1;
    uint8_t score = 0; //overflow will happen after about 4 minutes
    
    srand(SEED); //STDLIB FUNCTION TO GENERATE PSUEDO RANDOM NUMBERS

    int random_number = rand() % NUM_OBSTACLES; //CONVERTS RANDOM NUMBER TO [0,NUM_OBSTACLES-1] 

    system_init ();
    pacer_init (PACER_RATE); //REFRESH RATE OF 500HZ
    
    for (uint8_t i = 0; i < NUM_ROWS; i++) {
        if (i < NUM_COLS) {
            pio_config_set(cols[i], PIO_OUTPUT_HIGH);
        }
        pio_config_set(rows[i], PIO_OUTPUT_HIGH);
    }
    bool to_copy = false;
    uint8_t obj_to_display[NUM_COLS]; //IF YOU CHECK OBJECTS.C AND OBJECTS.H ITS PRETTY CLEAR WHY WE NEED THIS
    uint8_t runner_status = 1;
    bool timeout = false;
    uint16_t timeout_counter = 0;

    while (1)
    {
        pacer_wait ();
        navswitch_update(); // POLL THE NAVSWITCH

        if (counter % PACER_RATE == 0) {
            score++;
        } //increments score every second

        if (to_copy == false) {
            for (uint8_t i = 0; i < NUM_COLS; i++) {
                obj_to_display[i] = obstacles[random_number][i];
            }
            to_copy = true;
        } //COPIES OBJECT TO DISPLAY

        
        if ((counter % OBSTACLE_MOVING_RATE) == 0) {
            move_object_left(obj_to_display);
        } //WILL MOVE THE OBJECT LEFT AT APPROX 2.5HZ

        if ((counter % OBSTACLE_REFRESH) == 0) {
            random_number = rand() % NUM_OBSTACLES;
            to_copy = false;
        } //WHEN OBJECT IS OFF THE SCREEN, DISPLAY A NEW OBJECT

        static bool pause_flag = 0;
        if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
            pause_flag = 1;
            uint8_t previous_display = {obj_to_display[current_column] | runner[runner_status][current_column], current_column};
            while(pause_flag == 1) {
                display_column(0x50, 0);
                display_column(0x50, 1);
                display_column(0x50, 2);
                navswitch_update();
                if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
                    pause_flag = 0;
                    display_column(obj_to_display[current_column] | runner[runner_status][current_column], current_column);
                }
            }
        } //PAUSES THE GAME WHEN PRESSING THE NAVSWITCH LEFT, RESUME WHEN PUSHING RIGHT
        

        //DETERMINE RUNNER STATUS
        static uint8_t runner_status = 0;
        if (timeout == false) {

            if (navswitch_down_p (NAVSWITCH_WEST)) { // NAV WEST = JUMP
                runner_status = 2;
            } else if (navswitch_down_p (NAVSWITCH_EAST)) { // NAV EAST = CROUCH
                runner_status = 1;
            } else if (navswitch_down_p (NAVSWITCH_PUSH)) { // BUTTON PRESS = DOUBLE JUMP
                runner_status = 3;
            } else { // DEFAULT
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

        display_column(obj_to_display[current_column] | runner[runner_status][current_column], current_column);
    
        current_column++;
    
        if (current_column >= (NUM_COLS))
        {
            current_column = 0;
        }
        
        counter++;

        if (counter == UINT16_MAX) {
            counter = 1;
        }           
    }
}