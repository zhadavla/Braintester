#pragma once 

enum MENU_STATES{
  MATH_SEL, LED_SEL, SCORE_SEL
};

enum GAME_STATES{
  SELECTION, MATH_GAME, LED_GAME
};

extern int menuState;
extern int prevGameState;
extern int prevState;

#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>
#include <time.h>
