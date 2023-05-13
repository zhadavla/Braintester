#include "ledGame.h"

// Define global variables
int ledSelectedOption = LED_SEL1;
int LEN_OF_SEQUENCE = 3;
int MAX_LEN_OF_SEQUENCE = 10;
int ledSequence[10];
bool isSequenceCorrect;

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
    flashLedSequence() ;
    //    ledUserInput();
    //    checkSequence();
    delay(100);
    while (!Esplora.readButton(SWITCH_RIGHT));
  }
}

int getJoystickPosition() {
  int x, y;

  while (true) {
    x = Esplora.readJoystickX();
    y = Esplora.readJoystickY();

    if (y > 500 && -THRESHOLD < x && x < THRESHOLD) {
      Serial.println("Joystick position: DOWN");
      return DOWN;
    }
    else if (y < -500 && -THRESHOLD < x && x < THRESHOLD) {
      Serial.println("Joystick position: UP");
      return UP;
    }
    else if (x < -500 && -THRESHOLD < y && y < THRESHOLD) {
      Serial.println("Joystick position: RIGHT");
      return RIGHT;
    }
    else if (x > 500 && -THRESHOLD < y && y < THRESHOLD) {
      Serial.println("Joystick position: LEFT");
      return LEFT;
    }

    if (!Esplora.readButton(SWITCH_LEFT)) {
      menuState = MATH_SEL;
      prevGameState = SELECTION;
      menuInit();
      return -1;
    }

  }
}

void ledUserInput() {

  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(0, 255, 255);
  EsploraTFT.setTextSize(2);
  EsploraTFT.text("Repeat the Sequence!", 10, 5);
  EsploraTFT.text("Use joystick!", 20, 15);
  EsploraTFT.stroke(0, 255, 0);
  EsploraTFT.text("UP", 50, 50);
//  EsploraTFT.text("Up: Green, Down: Red", 10, 25);
//  EsploraTFT.text("Left: Blue, Right: Yellow", 10, 35);



  // input one color and check if it's right, then go to next color
  isSequenceCorrect = true;
  for (int i = 0; i < LEN_OF_SEQUENCE; i++) {
    int colorGetted = getJoystickPosition();
    if (colorGetted == -1)
      return;
    EsploraTFT.stroke(0, 0, 255);
    EsploraTFT.text("Your input: ", 5, 55);

    switch (colorGetted) {
      case RED:
        EsploraTFT.stroke(0, 0, 255);
        EsploraTFT.text("RED", 5, 75 + i * 10);
        break;
      case GREEN:
        EsploraTFT.stroke(0, 255, 0);
        EsploraTFT.text("GREEN", 5 , 75 + i * 10);
        break;
      case BLUE:
        EsploraTFT.stroke(255, 0, 0);
        EsploraTFT.text("BLUE", 5 , 75 + i * 10);
        break;
      case YELLOW:
        EsploraTFT.stroke(0, 255, 255);
        EsploraTFT.text("YELLOW", 5 , 75 + i * 10);
        break;

    }

    if (colorGetted != ledSequence[i]) {
      isSequenceCorrect = false;
      EsploraTFT.text("WHICH IS INCORRECT!", 5, 75 + i * 10 + 10);
      break;
    }



    delay(333);
  }
  // if user correctly repeats the sequence increase level
  if (isSequenceCorrect) {
    MAX_LEN_OF_SEQUENCE++;
    //    winScreen();
  }
}

//void winScreen(){
//  EsploraTFT.text()
//}

void flashLedSequence() {
  // Define possible colors
  int green[3] = {0, 255, 0};
  int red[3] = {255, 0, 0};
  int blue[3] = {0, 0, 255};
  int yellow[3] = {255, 255, 0};
  int* colors[4] = {green, red, blue, yellow};

  // Flash random LED sequence LEN_OF_SEQUENCE times
  for (int i = 0; i < LEN_OF_SEQUENCE; i++) {
    // Generate random color option
    ColorOption colorOption = static_cast<ColorOption>(random(4));

    // Set RGB LED to random color
    Esplora.writeRGB(colors[colorOption][0], colors[colorOption][1], colors[colorOption][2]);

    // Remember flashed color option in sequence
    ledSequence[i] = static_cast<int>(colorOption);
    delay(500);

    // Turn off RGB LED
    Esplora.writeRGB(0, 0, 0);
    delay(500);
  }
  ledUserInput();
}
