#include "mathGame.h"
#include "ledGame.h"
#include "mainMenu.h"
#include "highestScore.h"

void setup() {
  EsploraTFT.begin();
  menuInit();
  Serial.begin(9600);
  srand(time(NULL));
}

// menuState determines which option is sellected at the moment
int menuState = MATH_SEL;
// prevGameState determines to what state return
int prevGameState = SELECTION;

void loop() {
  // select menuOption
  if (prevGameState == SELECTION) {
    // move down thorough possible options
    if (!Esplora.readButton(SWITCH_DOWN)) {
      switchMenuDown();
      updateMenuState();
      delay(100);
      while (!Esplora.readButton(SWITCH_DOWN));
    }
    // move down thorough possible options
    if (!Esplora.readButton(SWITCH_UP)) {
      switchMenuUp();
      updateMenuState();
      delay(100);
      while (!Esplora.readButton(SWITCH_UP));
    }
    // select specific option
    if (!Esplora.readButton(SWITCH_RIGHT)) {
      if (menuState == MATH_SEL) { // go to the math game
        prevGameState = MATH_GAME;
        mathGameInit();
        mathGameStart() ;
      } else if (menuState == LED_SEL) { // go to the led game
        prevGameState = LED_GAME;
        ledGameInit();
      } else if (menuState == SCORE_SEL) {  // go to the score check
        prevGameState = SCORE_CHECK;
        scoreInit();
      } else {
        prevGameState = SELECTION;
      }

      delay(100);
      while (!Esplora.readButton(SWITCH_RIGHT));
    }
  } else if (prevGameState == MATH_GAME) { // play the math game
    mathGameMain();
  } else if (prevGameState == LED_GAME) { // play the led game
    ledGameMain();
  } else if (prevGameState == SCORE_CHECK) { // show the score
    scoreMain();
  }
}
