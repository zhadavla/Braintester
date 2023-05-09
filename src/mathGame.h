
#ifndef MATH_GAME_H
#define MATH_GAME_H

#include <Arduino.h>
#include "mainHeader.h"

char* makeEquationString(int x, int y, char operation);
char* intToCStr(int num);
void showNextEquation();
void mathGameLabel();
void mathGameMain();
void getNextEquation();
void getSum();

#endif 
