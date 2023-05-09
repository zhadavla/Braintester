#include "mathGame.h" 
#include "mainMenu.h"

void setup() {
    EsploraTFT.begin();
    menuInit();
    Serial.begin(9600);
    srand(time(NULL));
}

int menuState = MATH_SEL;
int gameState = SELECTION;
int prevState = -1;

void loop() {  
  if (gameState == SELECTION){
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
        gameState = MATH_GAME;
        mathGameInit();
      }
      else
        gameState = SELECTION;
      delay(100);
      while (!Esplora.readButton(SWITCH_RIGHT));
      }
    }
    
  
  if (gameState == MATH_GAME){
    mathGameMain();
  }
}
