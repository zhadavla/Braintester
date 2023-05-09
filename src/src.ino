#include "mathGame.h" 
#include "mainMenu.h"

void setup() {
    EsploraTFT.begin();
    menuInit();
    Serial.begin(9600);
    srand(time(NULL));
}

int menuState = MATH_SEL;
int prevGameState = SELECTION;
int prevState = -1;

void loop() {  
  if (prevGameState == SELECTION){
     if (!Esplora.readButton(SWITCH_DOWN)){
        switchMenuDown();
        updateMenuState();
        delay(100);
        while (!Esplora.readButton(SWITCH_DOWN));
      }

    if (!Esplora.readButton(SWITCH_UP)){
      switchMenuUp();
      updateMenuState();
      delay(100);
      while(!Esplora.readButton(SWITCH_UP));
    }

    if (!Esplora.readButton(SWITCH_RIGHT)){
      if (menuState == MATH_SEL){
        prevGameState = MATH_GAME;
        mathGameInit();
      }
      else
        prevGameState = SELECTION;
      delay(100);
      while (!Esplora.readButton(SWITCH_RIGHT));
      }
    }
    
  
  if (prevGameState == MATH_GAME){
    mathGameMain();
  }
}
