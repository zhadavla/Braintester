#pragma once

#include <Arduino.h>
#include "mainHeader.h"
#include "mainMenu.h"
#include "helperStrFunctions.h"

enum ledSelectionStates {
  LED_SEL1, LED_SEL2, LED_SEL3
};


void ledGameInit();
void ledGameStart();
void ledGameMain() ;
void flashLedSequence() ;
void ledSwitchUp();
void ledSwitchDown();
