#include "mathGame.h" 
#include "mainMenu.h"

void setup() {
    EsploraTFT.begin();
    Serial.begin(9600);
    srand(time(NULL));
}

int menuState = MATH_SEL;
int prevState = -1;

void loop() {  
  if (!Esplora.readButton(SWITCH_DOWN) && prevState != MATH_GAME){
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
    case MATH_GAME:
      mathGameMain();
      break;
   }
  
}
