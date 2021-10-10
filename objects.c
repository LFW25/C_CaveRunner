/*Authors: George Fraser & Lily Williams

Purpose of File:
Displays the runner and the obstacles on the matrix display 
*/
#include "system.h"
#include "pio.h"
#include "objects.h"

void display_column(uint8_t row_pattern, uint8_t current_column)
{
    pio_output_high(cols[previous]);
    
    previous = current_column;
    

    for (uint8_t i = 0; i < 7; i++) {
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
    for (uint8_t i = 0; i < 5; i++) {
        obstacle[i] = obstacle[i] << 1;
    }
}