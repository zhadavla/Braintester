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
