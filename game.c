/*AUTHORS: GEORGE FRASER & LILY WILLIAMS
*/
#include "system.h"
#include "pio.h"
#include "objects.h"
#include "pacer.h"

#include <stdint.h>


int main(void)
{
    uint8_t current_column = 0;
  
    system_init ();
    pacer_init (500);
    
    for (uint8_t i = 0; i < 7; i++) {
        if (i <= 4) {
            pio_config_set(cols[i], PIO_OUTPUT_HIGH);
        }
        pio_config_set(rows[i], PIO_OUTPUT_HIGH);
    }
    

    while (1)
    {
        pacer_wait ();
        
        display_column(bitmap[current_column], current_column);
    
        current_column++;
    
        if (current_column > (LEDMAT_COLS_NUM - 1))
        {
            current_column = 0;
        }           
    }
}