#include "mainMenu.h"
#include "mathGame.h"

void menuInit(){
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

void mainMenuShow(){
  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(0, 255, 0);
  EsploraTFT.setTextSize(3);
  EsploraTFT.text("Main menu", 0, 0);
  EsploraTFT.setTextSize(2);
}

void switchMenuUp(){
  switch (menuState) {
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

void switchMenuDown(){
  switch (menuState) {
    case MATH_SEL:
      menuState = LED_SEL;
      break;
    case LED_SEL:
      menuState = SCORE_SEL;
      break;
    case SCORE_SEL:
      menuState = MATH_SEL;
      break;
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

void highlightMenuOption(int x, int y, const char *txt) {
    const char *text = txt;
    EsploraTFT.stroke(255, 0, 0);  
    EsploraTFT.text(txt, x, y);
    EsploraTFT.stroke(0, 255, 255);  
    if (y == 25) {
        EsploraTFT.text("LEDs", 50, 50);
        EsploraTFT.text("Highest score", 5, 75);
    } else if (y == 50) {
        EsploraTFT.text("Math game", 30, 25);
        EsploraTFT.text("Highest score", 5, 75);
    } else {
        EsploraTFT.text("Math game", 30, 25);
        EsploraTFT.text("LEDs", 50, 50);
    }
}
