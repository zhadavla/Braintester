#include "mathGame.h"
int MATH_SCORE;

void mathGameInit() {
  EsploraTFT.background(0, 0, 0);
  EsploraTFT.stroke(255, 255, 0);
  EsploraTFT.setTextSize(3);
  EsploraTFT.text("Math game", 0, 0);
  EsploraTFT.setTextSize(2);
}

int result1, result2, correctResult, a, b;
int difficultyLevel = 1;
int mathSelectedOption = SEL1;
int mathGameState = SUM;
char currentSign = '+';
int coordinates[3];

void mathGameMain() {
  if (!Esplora.readButton(SWITCH_LEFT)) {
    menuState = MATH_SEL;
    gameState = SELECTION;
    menuInit();
    delay(100);
    while (!Esplora.readButton(SWITCH_LEFT));
  }

  if (!Esplora.readButton(SWITCH_RIGHT)) {
    displayMathMenu();
    delay(100);
    while (!Esplora.readButton(SWITCH_RIGHT));
  }

  if (!Esplora.readButton(SWITCH_UP)) {
    mathSwitchUp();
    displayAnswers();

    delay(100);
    while (!Esplora.readButton(SWITCH_UP));
  }

  if (!Esplora.readButton(SWITCH_DOWN)) {
    mathSwitchDown();
    displayAnswers();
    delay(100);
    while (!Esplora.readButton(SWITCH_DOWN));
  }

  mathGameSwitch();
}

void displayMathMenu() {
  displayExpresion();
  displayAnswers();
}

void displayExpresion() {
  mathGameInit();

  EsploraTFT.stroke(100, 255, 0);
  const char *strEquation = makeEquationString(a, b, currentSign);
  EsploraTFT.text(strEquation, 0, 50);
  delete[] (strEquation);
}

void displayAnswers() {
  getRandomCoordinates();
  
  char *sResult1, *sResult2, *sCorrectResult;
  // {30, 50, 70};
  switch (mathSelectedOption) {
    case SEL1:
      EsploraTFT.stroke(255, 0, 0);
      sResult1 = intToCStr(result1);
      EsploraTFT.text((const char *) sResult1, 120, 30);
      EsploraTFT.stroke(0, 255, 0);
      sResult2 = intToCStr(result2);
      EsploraTFT.text((const char *) sResult2, 120, 50);
      sCorrectResult = intToCStr(correctResult);
      EsploraTFT.text((const char *) sCorrectResult, 120, 70);
      break;
    case SEL2:
      EsploraTFT.stroke(0, 255, 0);
      sResult1 = intToCStr(result1);
      EsploraTFT.text((const char *) sResult1, 120, 30);
      EsploraTFT.stroke(255, 0, 0);
      sResult2 = intToCStr(result2);
      EsploraTFT.text((const char *) sResult2, 120, 50);
      EsploraTFT.stroke(0, 255, 0);
      sCorrectResult = intToCStr(correctResult);
      EsploraTFT.text((const char *) sCorrectResult, 120, 70);
      break;
    case SEL3:
      EsploraTFT.stroke(0, 255, 0);
      sResult1 = intToCStr(result1);
      EsploraTFT.text((const char *) sResult1, 120, 30);
      sResult2 = intToCStr(result2);
      EsploraTFT.text((const char *) sResult2, 120, 50);
      sCorrectResult = intToCStr(correctResult);
      EsploraTFT.stroke(255, 0, 0);
      EsploraTFT.text((const char *) sCorrectResult, 120, 70);
      break;
  }

  delete[] (sResult1);
  delete[] (sResult2);
  delete[] (sCorrectResult);
}

//void updatemathSelectedOption(int y) {
//
//  EsploraTFT.stroke(255, 0, 0);
//  EsploraTFT.text(, x, y);
//  EsploraTFT.stroke(0, 255, 255);
//  if (y == 25) {
//    EsploraTFT.text("LEDs", 50, 50);
//    EsploraTFT.text("Highest score", 5, 75);
//  } else if (y == 50) {
//    EsploraTFT.text("Math game", 30, 25);
//    EsploraTFT.text("Highest score", 5, 75);
//  } else {
//    EsploraTFT.text("Math game", 30, 25);
//    EsploraTFT.text("LEDs", 50, 50);
//  }
//}

void mathSwitchDown() {
  switch (mathSelectedOption) {
    case SEL3:
      mathSelectedOption = SEL1;
      break;
    case SEL1:
      mathSelectedOption = SEL2;
      break;
    case SEL2:
      mathSelectedOption = SEL3;
      break;
  }
}

void mathSwitchUp() {
  switch (mathSelectedOption) {
    case SEL3:
      mathSelectedOption = SEL2;
      break;
    case SEL2:
      mathSelectedOption = SEL1;
      break;
    case SEL1:
      mathSelectedOption = SEL3;
      break;
  }
}

void mathGameSwitch() {
  switch (gameState) {
    case SUM:
      getSum();
      currentSign = '+';
      break;
    default:
      break;
  }
}

void getRandomCoordinates() {
  int possibleCoordinates[] = {30, 50, 70};
  int randomIndex = rand() % 3;

  coordinates[0] = possibleCoordinates[randomIndex];
  coordinates[1] = possibleCoordinates[(randomIndex + 1) % 3];
  coordinates[2] = possibleCoordinates[(randomIndex + 2) % 3];
}

void getSum() {

  a = rand() % (difficultyLevel * 10 + 1);
  b = rand() % (difficultyLevel * 10 + 1);

  result1 = rand() % 5 * (a + b);
  result2 = rand() % 4 * (a + b);

  correctResult = a + b; // calculate the result
}

void getProduct() {
  a = rand() % (difficultyLevel * 10 + 1);
  b = rand() % (difficultyLevel * 10 + 1);

  result1 = rand() % 5 * (a * b);
  result2 = rand() % 4 * (a * b);

  correctResult = a * b;
}
