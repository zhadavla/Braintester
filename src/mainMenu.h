#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <Arduino.h>
#include "mainHeader.h"

void menuInit();
void updateMenuState();
void mainMenuShow();
void highlightMenuOption(int x, int y, const char *txt);

#endif
