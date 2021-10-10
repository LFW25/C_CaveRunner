/*AUTHORS: GEORGE FRASER & LILY WILLIAMS
*/
#include "system.h"
#include "pio.h"
#include "objects.h"
#include "pacer.h"
#include "obstacles.h"
#include "runner.h"

#include <stdint.h>
#include <stdlib.h>

#define SEED 2000

int main(void)
{
    uint8_t current_column = 0;
    uint16_t counter = 1;
    
    srand(SEED); //STDLIB FUNCTION TO GENERATE PSUEDO RANDOM NUMBERS

    int random_number = rand() % 3; //CONVERTS RANDOM NUMBER TO [0,2] 

    system_init ();
    pacer_init (500); //REFRESH RATE OF 500HZ
    
    for (uint8_t i = 0; i < 7; i++) {
        if (i <= 4) {
            pio_config_set(cols[i], PIO_OUTPUT_HIGH);
        }
        pio_config_set(rows[i], PIO_OUTPUT_HIGH);
    }
    bool to_copy = false;    
    uint8_t obj_to_display[5]; //IF YOU CHECK OJECTS.C AND OBJECTS.H ITS PRETTY CLEAR WHY WE NEED THIS


    while (1)
    {
        pacer_wait ();

        if (!to_copy) {
            for (uint8_t i = 0; i < 5; i++) {
                obj_to_display[i] = obstacles[random_number][i];
            }
            to_copy = true;
        } //COPYS OBJECT TO DIPLAY

        
        if ((counter % 200) == 0) {
            move_object_left(obj_to_display);
        } //WILL MOVE THE OBJECT LEFT AT APPROX 2.5HZ

        if ((counter % 1400) == 0) {
            random_number = rand() % 3;
            to_copy = false;
        } //WHEN OBJECT IS OFF THE SCREEN, DISPLAY A NEW OBJECT

        if (counter == UINT16_MAX) {
            counter = 1;
        }

        display_column(obj_to_display[current_column]|runner[0][current_column], current_column);
    
        current_column++;
    
        if (current_column > (LEDMAT_COLS_NUM - 1))
        {
            current_column = 0;
        }
        counter++;           
    }
}