/*
@ FILE: COLLISION.C
@ AUTHORS:
GEORGE FRASER
54510750
GHF20@UCLIVE.AC.NZ

LILY WILLIAMS
42415299
LFW25@UCLIVE.AC.NZ
@ DATE: 12 OCTOBER 2021
@ BRIEF: Checks if there has been a collision in the game
*/

#include "collision.h"

#include <stdint.h>
#include <stdbool.h>


//checks to see if runner is in correct position for object
bool collision_check(uint8_t runner_state, uint8_t obstacle)
{
    switch(obstacle) {
        case 0: //stalagtite = crouch
            if (runner_state == 1) {
                return true;
            }
            break;
        case 1: //rock = jump || super jump
            if (runner_state == 2 || runner_state == 3) {
                return true;
            }
            break;
        case 2: //bat = crouch || 
            if (runner_state == 1 || runner_state == 3) {
                return true;
            }
            break;
        case 3: //boulder = super jump
            if (runner_state == 3) {
                return true;
            }
            break;
        case 4: //tunnel = jump
            if (runner_state == 2) {
                return true;
            }
            break;
        default: //will only get here if we add an object without adding a case
            break;  
    }
    return false;
}