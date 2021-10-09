#ifndef OBJECTS_H
#define OBJECTS_H

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


static const uint8_t bitmap[] =
{
    0x04, 0x04, 0x04, 0x24, 0x20
     
}; //This Bit map is specific tot the runner and the stalagtite


void display_column(uint8_t row_pattern, uint8_t current_column);

#endif //OBJECTS_H