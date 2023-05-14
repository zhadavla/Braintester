#pragma once

#include <Arduino.h>
#include "mainHeader.h"

/*
   Initialize the menu
*/
void menuInit();
/*
   Highlight selected option
*/
void updateMenuState();
/*
   Just change menu state when the up button pressed
*/
void switchMenuUp();
/*
   Just change menu state when the down button pressed
*/
void switchMenuDown();
/*
   Shows the main menu
*/
void mainMenuShow();
/*
   Highlights selected menu option

   @param x, y position
   @param txt text to highlight
*/
void highlightMenuOption(int x, int y, const char *txt);
