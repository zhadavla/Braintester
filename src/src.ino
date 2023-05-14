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
  if (prevGameState == SELECTION) {
    if (!Esplora.readButton(SWITCH_DOWN)) {
      switchMenuDown();
      updateMenuState();
      delay(100);
      while (!Esplora.readButton(SWITCH_DOWN));
    }

    if (!Esplora.readButton(SWITCH_UP)) {
      switchMenuUp();
      updateMenuState();
      delay(100);
      while (!Esplora.readButton(SWITCH_UP));
    }

    if (!Esplora.readButton(SWITCH_RIGHT)) {
      if (menuState == MATH_SEL) {
        prevGameState = MATH_GAME;
        mathGameInit();
        mathGameStart() ;
      } else if (menuState == LED_SEL) {
        prevGameState = LED_GAME;
        ledGameInit();
        ledGameStart();
      } else if (menuState == SCORE_SEL) {
        prevGameState = SCORE_CHECK;
        scoreInit();
      }
      else
        prevGameState = SELECTION;
        
      delay(100);
      while (!Esplora.readButton(SWITCH_RIGHT));
    }
  } else if (prevGameState == MATH_GAME) {
    mathGameMain();
  } else if (prevGameState == LED_GAME) {
    ledGameMain();
  } else if (prevGameState == SCORE_CHECK) {
    scoreMain();
  }
}
