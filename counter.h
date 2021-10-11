#ifndef COUNTER_H
#define COUNTER_H

#include <stdint.h>

uint16_t counter;

void counter_init(void);

void counter_increment(void);

static void counter_check_max(void);

#endif //COUNTER_H