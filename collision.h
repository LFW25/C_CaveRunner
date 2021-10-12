/*
@ File: Collision.h
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

#ifndef COLLISION_H
#define COLLISION_H

#include <stdint.h>
#include <stdbool.h>

//Returns true if there is a collision in the game, otherwise false
bool collision_check(uint8_t runner_state, uint8_t obstacle);

#endif