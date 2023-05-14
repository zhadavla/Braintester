#pragma once

#include "mainHeader.h"
#include "mainMenu.h"
#include "helperStrFunctions.h"

// threshold for detcting the joystick position
#define THRESHOLD 50

// Define enum for color options
enum ColorOption {
  GREEN,
  RED,
  BLUE,
  YELLOW,
  NONE
};

/*
   Show in which direction joystick should be moved to choose color
*/
void showHelper();
ColorOption getJoystickPosition();
/*
    Show inital image
*/
void ledGameInit();
/*
    Controls whole led game
*/
void ledGameMain() ;
/*
   Randomly generates led sequence
*/
void flashLedSequence() ;
