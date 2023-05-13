#include "highestScore.h"

void scoreInit(){
  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(255, 0, 255);
  EsploraTFT.setTextSize(3);
  EsploraTFT.text("Highest", 15, 5);
  EsploraTFT.text("score", 30, 35);
  EsploraTFT.setTextSize(2);
  EsploraTFT.stroke(255, 0, 0);
  EsploraTFT.text("LED game: ", 5, 65);
  EsploraTFT.text(ft_itoa(LED_MAX_SCORE), 120, 65);
  EsploraTFT.stroke(0, 255, 255);
  EsploraTFT.text("MATH game: ", 5, 85);
  EsploraTFT.text(ft_itoa(MATH_MAX_SCORE), 130, 85);
}

void scoreMain(){
  if (!Esplora.readButton(SWITCH_LEFT)) {
    menuState = MATH_SEL;
    prevGameState = SELECTION;
    menuInit();
    delay(100);
    while (!Esplora.readButton(SWITCH_LEFT));
  }
}
