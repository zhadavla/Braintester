#include "mainHeader.h"
#include "mainMenu.h"

void setup() {
  Serial.begin(9600);
   EsploraTFT.begin();
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.stroke(255, 255, 0);
    EsploraTFT.setTextSize(3);
    EsploraTFT.text("Main menu", 0, 0);
    EsploraTFT.setTextSize(2);
    EsploraTFT.stroke(0, 0, 255); // Math game selected at the begining
    EsploraTFT.text("Math game", 30, 25);
    EsploraTFT.stroke(100, 255, 255); // std color for menuState
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
