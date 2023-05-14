#pragma once 

// To detect which option is sellected
enum MENU_STATES{
  MATH_SEL, LED_SEL, SCORE_SEL
};

// To detect in which game state
enum GAME_STATES{
  SELECTION, MATH_GAME, LED_GAME, SCORE_CHECK
};

extern int menuState;
extern int prevGameState;
extern int prevState;
extern int MATH_MAX_SCORE;
extern int LED_MAX_SCORE;

#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>
#include <time.h>
