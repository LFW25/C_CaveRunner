/*
@ File: Game_initialise.c
@ Authors:
George Fraser
54510750
ghf20@uclive.ac.nz

Lily Williams
42415299
lfw25@uclive.ac.nz
@ Date: 13 October 2021
@ Brief: Initialises all the necessary modules for the game to run
*/
#include "system.h"
#include "counter.h"
#include "../../fonts/font3x5_1.h"
#include "tinygl.h"
#include "pio.h"
#include "game_initialise.h"
#include "pacer.h"
#include "objects.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


//Initialises all the systems
void game_initialise_init(uint16_t pacer_rate, uint16_t num_obstacles)
{
    system_init ();
    counter_init();
    pacer_init (pacer_rate); //Refresh rate of 500Hz
    tinygl_init (pacer_rate); //Setup for score display
    tinygl_font_set (&font3x5_1);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_STEP);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
    srand(time(NULL));
    game_initialise_random(num_obstacles);
    game_initialise_set_vars();
    
}

//Sets all the game variables
void game_initialise_set_vars(void)
{
    score = 0;
    current_column = 0;
    to_copy = false;
    timeout = false;
    timeout_counter = 0;
    obstacle_moving_rate  = 125;
    obstacle_refresh = (obstacle_moving_rate * 6);
    timeout_time = (obstacle_moving_rate * 4);
    obstacle_check = obstacle_refresh-(2*obstacle_moving_rate); 
}

//Initialises a pseudo-random obstacle to begin
void game_initialise_random(uint16_t num_obstacles)
{
    random_number = rand() % num_obstacles;
}

//Initialises the LED PIO
void game_initialise_set_display(uint16_t num_rows)
{
    for (uint8_t i = 0; i < num_rows; i++) {
        if (i < num_rows) {
            pio_config_set(cols[i], PIO_OUTPUT_HIGH);
        }
        pio_config_set(rows[i], PIO_OUTPUT_HIGH);
    }
}