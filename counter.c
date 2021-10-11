#include "counter.h"

#include <stdint.h>

void counter_init(void)
{
    counter = 1;
}

static void counter_check_max(void)
{
    if (counter == UINT16_MAX) {
        counter = 0;
    }
}

void counter_increment(void)
{
    counter_check_max();
    counter++;  
}

