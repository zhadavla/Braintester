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
    flashLedSequence() ;
    ledUserInput();
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

    while (Esplora.readJoystickButton() == LOW) {
      // Wait for button press
    }
  }
}



void ledUserInput() {
 
  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(255, 255, 255);
  EsploraTFT.setTextSize(1);
  EsploraTFT.text("Use joystick to enter LED sequence", 0, 0);
  EsploraTFT.text("Up: Red, Down: Green, Left: Blue", 0, 20);

 int colorGetted = getJoystickPosition();
}

void flashLedSequence() {
  // Define possible colors
  int green[3] = {0, 255, 0};
  int red[3] = {255, 0, 0};
  int blue[3] = {0, 0, 255};
  int* colors[4] = {green, red, blue};

  // Flash random LED sequence LEN_OF_SEQUENCE times
  for (int i = 0; i < LEN_OF_SEQUENCE; i++) {
    // Generate random color option
    ColorOption colorOption = static_cast<ColorOption>(random(3));

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
  ledUserInput();
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
