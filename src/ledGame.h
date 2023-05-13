#pragma once

#include <Arduino.h>
#include "mainHeader.h"
#include "mainMenu.h"
#include "helperStrFunctions.h"

#define THRESHOLD 50

enum ledUserInput {
  LED_SEL1, LED_SEL2, LED_SEL3
};

enum JoystickPosition {
  UP, DOWN, LEFT, RIGHT
};

// Define enum for color options
enum ColorOption {
  GREEN,
  RED,
  BLUE, 
  YELLOW
};


int getJoystickPosition();
void ledGameInit();
void ledGameStart();
void ledGameMain() ;
void flashLedSequence() ;
void ledSwitchUp();
void ledSwitchDown();
