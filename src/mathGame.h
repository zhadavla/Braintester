#pragma once 

#include <Arduino.h>
#include "mainHeader.h"
#include "mainMenu.h"
#include "helperStrFunctions.h"

enum mathSelectionStates {
  SEL1, SEL2, SEL3
};

enum mathGameState {
  SUM, PRODUCT, SUBSTRACTION, DIVISION, INCORRECT
};

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
