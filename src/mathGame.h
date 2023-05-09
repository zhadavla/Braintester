
#ifndef MATH_GAME_H
#define MATH_GAME_H

#include <Arduino.h>
#include "mainHeader.h"
#include "mainMenu.h"

enum mathSelectionStates{
  SEL1, SEL2, SEL3
};

enum mathGameState{
  SUM, PRODUCT, SUBSTRACTION, DIVISION
};

enum answers{
  CORRECT, INCORRECT  
};

void displayExpresion();
void displayAnswers();
void getRandomCoordinates();
void updatemathSelectedOption();
void displayMathMenu();
void mathSwitchUp();
void mathSwitchDown();
char* makeEquationString(int x, int y, char operation);
char* intToCStr(int num);
void showNextEquation();
void mathGameInit();
void getNextEquation();
void getSum();
void mathGameSwitch();
void mathGameMain();

#endif 
