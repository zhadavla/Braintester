#include "ledGame.h"

// Define global variables
int ledSelectedOption = LED_SEL1;
int LEN_OF_SEQUENCE = 5;
int ledSequence[5];

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

  if (!Esplora.readButton(SWITCH_RIGHT)) {
//    ledUserInput();
    flashLedSequence() ;
//    displayMathMenu();
    delay(100);
    while (!Esplora.readButton(SWITCH_RIGHT));
  }

  if (!Esplora.readButton(SWITCH_UP)) {

    ledSwitchUp();
//    displayAnswers();

    delay(100);
    while (!Esplora.readButton(SWITCH_UP));
  }

  if (!Esplora.readButton(SWITCH_DOWN)) {

    ledSwitchDown();
//    displayAnswers();


    delay(100);
    while (!Esplora.readButton(SWITCH_DOWN));
  }

}

void ledUserInput() {

}

void flashLedSequence() {
  // Define possible colors
  int green[3] = {0, 255, 0};
  int yellow[3] = {255, 255, 0};
  int red[3] = {255, 0, 0};
  int blue[3] = {0, 0, 255};
  int* colors[4] = {green, yellow, red, blue};

  // Flash random LED sequence LEN_OF_SEQUENCE times
  for (int i = 0; i < LEN_OF_SEQUENCE; i++) {
    // Generate random color option
    ColorOption colorOption = static_cast<ColorOption>(random(4));

    // Set RGB LED to random color
    Esplora.writeRGB(colors[colorOption][0], colors[colorOption][1], colors[colorOption][2]);

    // Remember flashed color option in sequence
    ledSequence[i] = static_cast<int>(colorOption);

    // Delay for 500ms
    delay(500);

    // Turn off RGB LED
    Esplora.writeRGB(0, 0, 0);

    // Delay for 500ms
    delay(500);
  }
}

void ledSwitchDown() {
  switch (ledSelectedOption) {
    case LED_SEL3:
      ledSelectedOption = LED_SEL1;
      break;
    case LED_SEL1:
      ledSelectedOption = LED_SEL2;
      break;
    case LED_SEL2:
      ledSelectedOption = LED_SEL3;
      break;
  }
}

void ledSwitchUp() {
  switch (ledSelectedOption) {
    case LED_SEL3:
      ledSelectedOption = LED_SEL2;
      break;
    case LED_SEL2:
      ledSelectedOption = LED_SEL1;
      break;
    case LED_SEL1:
      ledSelectedOption = LED_SEL3;
      break;
  }
}
