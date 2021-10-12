/*
@ File: Collision.c
@ Authors:
George Fraser
54510750
ghf20@uclive.ac.nz

Lily Williams
42415299
lfw25@uclive.ac.nz
@ Date: 12 October 2021
@ Brief: Checks for collisions between runner and obstacles
*/

#include "collision.h"

#include <stdint.h>
#include <stdbool.h>


//C to see if runner is in correct position for object
bool collision_check(uint8_t runner_state, uint8_t obstacle)
{
    switch(obstacle) {
        case 0: //Stalagtite = crouch
            if (runner_state == 1) {
                return false;
            }
            break;
        case 1: //Rock = jump || super jump
            if (runner_state == 2 || runner_state == 3) {
                return false;
            }
            break;
        case 2: //Bat = crouch || 
            if (runner_state == 1 || runner_state == 3) {
                return false;
            }
            break;
        case 3: //Boulder = super jump
            if (runner_state == 3) {
                return false;
            }
            break;
        case 4: //Tunnel = jump
            if (runner_state == 2) {
                return false;
            }
            break;
        default: //Will only get here if we add an object without adding a case
            break;  
    }
    return true;
}