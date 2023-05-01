#include "mathGame.h"

void mathGameLabel() {
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.stroke(255, 255, 0);
    EsploraTFT.setTextSize(3);
    EsploraTFT.text("Math game", 0, 0);
}

void mathGameMain() {
  mathGameLabel();
}
