/*
@ File: Objects.h
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
#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdbool.h>
#include <stdint.h>
#include "system.h"
#include "pio.h"

uint8_t previous;

uint8_t current_column;

static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO, 
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};

/** Define PIO pins driving LED matrix columns.  */
static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};

//This function displays the bitmap on the current column
void display_column(uint8_t row_pattern, uint8_t current_column);

//This function left-shifts the obstacle bitmap
void move_object_left(uint8_t* obstacle);

// Takes input from the navswitch
void take_input(void);

//Moves the marker denoting the current column left by one
//Checks if the obstacle has moved off-screen
void column_increment(void);

#endif //OBJECTS_H