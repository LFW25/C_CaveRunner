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
@ BRIEF: DISPLAYS THE OBSTACLES AND THE RUNNER ON THE SCREEN
*/
#include "system.h"
#include "pio.h"
#include "objects.h"

#define NUM_ROWS 7
#define NUM_COLS 5

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

//THIS FUNCTION LEFT SHIFTS THE OBSTACLE BITMAP
void move_object_left(uint8_t* obstacle)
{
    for (uint8_t i = 0; i < NUM_COLS; i++) {
        obstacle[i] = obstacle[i] << 1;
    }
}