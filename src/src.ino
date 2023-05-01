#include "mathGame.h" 
#include "mainMenu.h"

void setup() {
  Serial.begin(9600);
   EsploraTFT.begin();
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.stroke(0, 255, 0);
    EsploraTFT.setTextSize(3);
    EsploraTFT.text("Main menu", 0, 0);
    EsploraTFT.setTextSize(2);
    EsploraTFT.stroke(255, 0, 0);
    EsploraTFT.text("Math game", 30, 25);
    EsploraTFT.stroke(0, 255, 255); 
    EsploraTFT.text("LEDs\n ", 50, 50);
    EsploraTFT.text("Highest score\n ", 5, 75);
}

int menuState = MATH_SEL;

void loop() {  
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
    if (menuState == MATH_SEL)
      menuState = MATH_GAME;
    
    updateMenuState();
    Serial.println("THERE 1");
    delay(100);
    while (!Esplora.readButton(SWITCH_RIGHT));
  }

  if (!Esplora.readButton(SWITCH_LEFT)){
     if (menuState == MATH_GAME){
      menuState = MATH_SEL;
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
