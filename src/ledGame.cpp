#include "ledGame.h"

void ledGameInit() {
  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(0, 255, 255);
  EsploraTFT.setTextSize(3);
  EsploraTFT.text("Led Game", 0, 0);
  EsploraTFT.setTextSize(2);
}

void ledGameStart() {
  EsploraTFT.stroke(0, 0, 255);
  EsploraTFT.text("Press", 10, 40);
  EsploraTFT.text("right switch", 10, 60);
  EsploraTFT.text("to start!", 10, 80);
  EsploraTFT.stroke(0, 255, 255);
}

void ledGameMain() {


  if (!Esplora.readButton(SWITCH_LEFT)) {
    menuState = MATH_SEL;
    prevGameState = SELECTION;
    menuInit();
    delay(100);
    while (!Esplora.readButton(SWITCH_LEFT));
  }

//  if (!Esplora.readButton(SWITCH_RIGHT)) {
//    Serial.println("MAXXXXXXXXXXXXXXXX: " + String(max_num));
//
//    userInput();
//    generateRandomEquation();
//    displayMathMenu();
//    delay(100);
//    while (!Esplora.readButton(SWITCH_RIGHT));
//  }
//
//  if (!Esplora.readButton(SWITCH_UP)) {
//
//    mathSwitchUp();
//    displayAnswers();
//
//    delay(100);
//    while (!Esplora.readButton(SWITCH_UP));
//  }
//
//  if (!Esplora.readButton(SWITCH_DOWN)) {
//
//    mathSwitchDown();
//    displayAnswers();
//
//
//    delay(100);
//    while (!Esplora.readButton(SWITCH_DOWN));
//  }

}
