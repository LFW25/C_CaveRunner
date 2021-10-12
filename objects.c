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
    for (uint8_t i = 0; i < NUM_COLS; i++) {
        obstacle[i] = obstacle[i] << 1;
    }
}