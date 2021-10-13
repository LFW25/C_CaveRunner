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

void game_initialise_init(uint16_t pacer_rate, uint16_t num_obstacles);

void game_initialse_set_vars(void);

void game_initialise_random(uint16_t num_obstacles);

void game_initialise_set_display(uint16_t num_rows);

#endif