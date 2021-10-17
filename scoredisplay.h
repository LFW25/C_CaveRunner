/*
@ File: Scoredisplay.h
@ Authors:
George Fraser
54510750
ghf20@uclive.ac.nz

Lily Williams
42415299
lfw25@uclive.ac.nz
@ Date: 12 October 2021
@ Brief: Displays the score on the pause and game-over screens
*/
#ifndef SCOREDISPLAY_H
#define SCOREDISPLAY_H

#include <stdint.h>

//Displays the score on pause or game over
char display_score[3];

//Displays the score using tiny_gl
void display_character (uint8_t score);

//Controls score display on a game pause
//Resumes game when nav-north is pressed
void pause_display(uint8_t score);

//Flashes the score on a gameover
void gameover_display(uint8_t score);

//Increments the score every second
void score_increment(uint16_t pacer);

#endif