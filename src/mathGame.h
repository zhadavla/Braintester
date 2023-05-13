#pragma once

#include <Arduino.h>
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
  SEL1, SEL2, SEL3
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
void userInput();
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
