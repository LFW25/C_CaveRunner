/*
@ FILE: COLLISION.H
@ AUTHORS:
GEORGE FRASER
54510750
GHF20@UCLIVE.AC.NZ

LILY WILLIAMS
42415299
LFW25@UCLIVE.AC.NZ
@ DATE: 12 OCTOBER 2021
@ BRIEF: Initialises collision detection in the game
*/

#ifndef COLLISION_H
#define COLLISION_H

#include <stdint.h>
#include <stdbool.h>

//Returns true if there is a collision in the game, otherwise false
bool collision_check(uint8_t runner_state, uint8_t obstacle);

#endif