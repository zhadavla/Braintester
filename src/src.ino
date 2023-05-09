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
        if (menuState == MATH_SEL)
          menuState = LED_SEL;
        else if (menuState == LED_SEL)
          menuState = SCORE_SEL;
        else if (menuState == SCORE_SEL)
          menuState = MATH_SEL;
        updateMenuState();
        delay(100);
        while (!Esplora.readButton(SWITCH_DOWN));
      }


    if (!Esplora.readButton(SWITCH_UP)){
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


    if (!Esplora.readButton(SWITCH_RIGHT)){
      if (menuState == MATH_SEL){
        gameState = MATH_GAME;
        mathGameMain();
      }
        
      else
        gameState = SELECTION;
      
      
      delay(100);
      while (!Esplora.readButton(SWITCH_RIGHT));
      }
    }


    
  if (gameState == MATH_GAME){
    if (!Esplora.readButton(SWITCH_LEFT)){
     
    menuState = MATH_SEL;
    gameState = SELECTION;
    menuInit();
    
    
    delay(100);
    while (!Esplora.readButton(SWITCH_LEFT));
    }
  }
}


void updateMenuState(){
  switch (menuState){
    case MATH_SEL: 
       highlightMenuOption(30, 25, "Math game");
       break;
    case LED_SEL:
       highlightMenuOption(50, 50, "LEDs");
       break;
    case SCORE_SEL:
      highlightMenuOption(5, 75, "Highest score");
      break;
   }
  
}
