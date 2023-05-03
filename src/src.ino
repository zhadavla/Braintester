#include "mathGame.h" 
#include "mainMenu.h"

void setup() {
    EsploraTFT.begin();
    Serial.begin(9600);
    srand(time(NULL));
}

void loop() {  
  if (!Esplora.readButton(SWITCH_DOWN) && prevState != MATH_GAME){
    downSwitch();
    updateMenuState();
    delay(100);
    while (!Esplora.readButton(SWITCH_DOWN));
  }
  if (!Esplora.readButton(SWITCH_UP) && prevState != MATH_GAME){
    if (menuState == MATH_SEL)
      menuState = SCORE_SEL;
    else if (menuState == LED_SEL)
      menuState = MATH_SEL;
    else if (menuState == SCORE_SEL)
      menuState = LED_SEL;
    updateMenuState();
    delay(100);
    while(!Esplora.readButton(SWITCH_UP));
  }
  
  if (!Esplora.readButton(SWITCH_RIGHT) && prevState != MATH_GAME){
    if (menuState == MATH_SEL){
      menuState = MATH_GAME;
      prevState = MATH_GAME;
    }
      
    
    updateMenuState();
    Serial.println("THERE 1");
    delay(100);
    while (!Esplora.readButton(SWITCH_RIGHT));
  }

  if (!Esplora.readButton(SWITCH_LEFT)){
     if (menuState == MATH_GAME){
      menuState = MATH_SEL;
      prevState = -1;
      mainMenuShow();
     }
      
    updateMenuState();
    Serial.println("THERE 4");
    delay(100);
    while (!Esplora.readButton(SWITCH_LEFT));
  }
}

void downSwitch(){
  switch(menuState) {
  case MATH_SEL:
    menuState = SCORE_SEL;
    break;
  case LED_SEL:
    menuState = MATH_SEL;
    break;
  case SCORE_SEL:
    menuState = LED_SEL;
    break;
}
}
