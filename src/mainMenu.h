#pragma once 

#include <Arduino.h>
#include "mainHeader.h"

void menuInit();
void updateMenuState();
void switchMenuUp();
void switchMenuDown();
void mainMenuShow();
void highlightMenuOption(int x, int y, const char *txt);
