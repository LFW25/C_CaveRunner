/*
@ File: Game_initialise.h
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

#ifndef GAME_INITIALISE_H
#define GAME_INITIALISE_H

#include <stdint.h>

uint8_t current_column;

uint8_t score;

int random_number;

bool to_copy;

bool timeout;

uint16_t timeout_counter;

uint8_t obj_to_display[5];

uint8_t obstacle_moving_rate;

uint16_t obstacle_refresh;

uint16_t timeout_time;

uint16_t obstacle_check;

uint8_t runner_status;

//Initialises all the systems
void game_initialise_init(uint16_t pacer_rate, uint16_t num_obstacles);

//Sets all the game variables
void game_initialise_set_vars(void);

//Initialises a pseudo-random obstacle to begin
void game_initialise_random(uint16_t num_obstacles);

//Initialises the LED PIO
void game_initialise_set_display(uint16_t num_rows);

#endif