#pragma once

#include "mainHeader.h"
#include "mainMenu.h"
#include "helperStrFunctions.h"

#define NUM_OPTIONS 3
#define MIN_NUM 1
#define MAX_NUM_START 10
#define MAX_NUM_INC 5
#define MAX_NUM_MAX 100
#define CORRECT_ANSWERS_THRESHOLD 3

enum mathSelectionStates {
  MATH_SEL1, MATH_SEL2, MATH_SEL3
};

enum mathGameState {
  SUM, PRODUCT, SUBSTRACTION, DIVISION, INCORRECT
};

void mathGameStart() ;
void getDivision();
void getProduct() ;
void getProduct();
void remapResults();
void printResults() ;
void displayExpresion();
void displayAnswers();
void mathUserInput();
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
void generateRandomEquation();
