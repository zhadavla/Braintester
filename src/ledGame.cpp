#include "ledGame.h"

// Define global variables
int LED_MAX_SCORE = 0;
int LEN_OF_SEQUENCE = 2;
int MAX_LEN_OF_SEQUENCE = 12;
ColorOption ledSequence[12];
bool isSequenceCorrect;

void ledGameInit() {
  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(0, 255, 255);
  EsploraTFT.setTextSize(3);
  EsploraTFT.text("Led Game", 0, 0);
  EsploraTFT.setTextSize(2);
  EsploraTFT.stroke(0, 0, 255);
  EsploraTFT.text("Press", 10, 40);
  EsploraTFT.text("right switch", 10, 60);
  EsploraTFT.text("to start!", 10, 80);
  EsploraTFT.stroke(0, 255, 255);
}

void ledGameMain() {

  // if left button is pressed return to main menu
  if (!Esplora.readButton(SWITCH_LEFT)) {
    menuState = MATH_SEL;
    prevGameState = SELECTION;
    menuInit();
    delay(100);
    while (!Esplora.readButton(SWITCH_LEFT));
  }

  // confirm input
  if (!Esplora.readButton(SWITCH_RIGHT)) {
    flashLedSequence();
    delay(100);
    while (!Esplora.readButton(SWITCH_RIGHT));
  }
}

ColorOption getJoystickPosition() {
  int x, y;

  // while position isn't detected
  while (true) {
    x = Esplora.readJoystickX();
    y = Esplora.readJoystickY();

    if (y > 500 && -THRESHOLD < x && x < THRESHOLD) { // joystick down
      return RED;
    } else if (y < -500 && -THRESHOLD < x && x < THRESHOLD) { // joystick up
      return BLUE;
    } else if (x < -500 && -THRESHOLD < y && y < THRESHOLD) { // joystick right
      return GREEN;
    } else if (x > 500 && -THRESHOLD < y && y < THRESHOLD) { // joystick left
      return YELLOW;
    }

    // return to the main menu
    if (!Esplora.readButton(SWITCH_LEFT)) {
      menuState = MATH_SEL;
      prevGameState = SELECTION;
      menuInit();
      return NONE;
    }

  }
}

void showHelper(){
  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(0, 0, 255);
  EsploraTFT.setTextSize(2);
  EsploraTFT.text("Use joystick!", 0, 5);
  EsploraTFT.stroke(255, 0, 0); // blue at the hight
  EsploraTFT.text("*", 15, 25); 
  EsploraTFT.stroke(0, 255, 255); // yellow at the right
  EsploraTFT.text("*", 5, 35);
  EsploraTFT.stroke(0, 255, 0); // green at the left
  EsploraTFT.text("*", 25, 35);
  EsploraTFT.stroke(0, 5, 255);
  EsploraTFT.text("*", 15, 45); // red at the bottom
}

void ledUserInput() {
  showHelper();
  
  // input one color and check if it's right, then go to the next color
  isSequenceCorrect = true; // variable to check is sequence correct
  for (int i = 0; i < LEN_OF_SEQUENCE; i++) {
    // get color from joystick
    ColorOption colorGetted = getJoystickPosition();

    // show what user inputed
    EsploraTFT.setTextSize(1);
    EsploraTFT.stroke(255, 255, 255);
    EsploraTFT.text("Your input: ", 60, 55);

    switch (colorGetted) {
      case RED:
        EsploraTFT.stroke(0, 0, 255);
        EsploraTFT.text("*", 65 + i * 10, 65);
        break;
      case GREEN:
        EsploraTFT.stroke(0, 255, 0);
        EsploraTFT.text("*", 65 + i * 10, 65);
        break;
      case BLUE:
        EsploraTFT.stroke(255, 0, 0);
        EsploraTFT.text("*", 65 + i * 10, 65 );
        break;
      case YELLOW:
        EsploraTFT.stroke(0, 255, 255);
        EsploraTFT.text("*", 65 + i * 10, 65 );
        break;
    }

    if (colorGetted != ledSequence[i]) { // if color isn't at the sequence, break the cycle
      isSequenceCorrect = false;
      LEN_OF_SEQUENCE = 2;
      EsploraTFT.stroke(0, 0, 255);
      EsploraTFT.text("INCORRECT!", 5, 100);
      EsploraTFT.text("Press RIGHT to retry", 5, 110);
      break;
    }
    delay(333);
  }

  // if user correctly repeats the sequence increase the level
  if (isSequenceCorrect) {
    // renew LED_MAX_SCORE
    if (LEN_OF_SEQUENCE > LED_MAX_SCORE)
      LED_MAX_SCORE = LEN_OF_SEQUENCE;
    LEN_OF_SEQUENCE++;
    
    EsploraTFT.stroke(0, 123, 0);
    EsploraTFT.text("CORRECT!", 5, 100);
    EsploraTFT.text("Press RIGHT to continue", 5, 110);
    delay(100);
  }

  // if player correctly repeats the sequence with len MAX_LEN_OF_SEQUENCE, he wins
  if (LEN_OF_SEQUENCE == MAX_LEN_OF_SEQUENCE) {
    EsploraTFT.background(0, 0, 0);
    EsploraTFT.stroke(0, 255, 255);
    EsploraTFT.setTextSize(7);
    EsploraTFT.text("WIN!", 10, 30);
    EsploraTFT.setTextSize(2);
  }
}

void flashLedSequence() {
  // Define colors
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
    ledSequence[i] = colorOption;
    Serial.println(ledSequence[i]);
    delay(500);

    // Turn off RGB LED
    Esplora.writeRGB(0, 0, 0);
    delay(500);
  }
  ledUserInput();
}
